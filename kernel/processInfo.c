#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/fdtable.h>
#include <linux/processInfo.h>
#include <linux/signal.h>

SYSCALL_DEFINE3(processInfo, int*, procs, int*, fds, int*, sigpends) {


    //uid_t uid = getuid_call();
    struct user_struct *user = find_user(get_current_user()->uid);

    put_user(user->processes.counter, procs);//fd
    put_user(user->epoll_watches.counter, fds);
    put_user(user->sigpending.counter, sigpends);
	
    printk("\nThe current user has:\n%d processes running\n%d filedescriptors watched\n%d signals pendning\n\n", processes, fd, pending);

    printk("According to user struct the count is:\n%d processes\n%d filedescriptors watched\n%d signals pending", user->processes.counter, user->epoll_watches.counter, user->sigpending.counter);
    free_uid(user);
  return 0;
}

unsigned long bitmaskSum(unsigned long bitmask){
	int sum = 0;

	while (bitmask > 0) {
		if ((bitmask & 1) == 1)
			sum++;
		bitmask >>= 1;
	}

	return sum;
}


