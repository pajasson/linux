#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/fdtable.h>
#include <linux/processInfo.h>
#include <linux/signal.h>

asmlinkage long sys_processInfo(int* proc, int* sigs, long int* fd){


	struct user_struct *user = find_user(get_current_user()->uid);

    int process, signal;
    long int filedesc;

    filedesc = atomic_long_read(&user->epoll_watches);
    signal = atomic_read(&user->sigpending);
    process = atomic_read(&user->processes);

    if(copy_to_user(proc, &process, sizeof(atomic_t))){
        	printk("\ncopying processes to user...");
        	return -1;
    }
    if(copy_to_user(fd, &filedesc, sizeof(atomic_long_t))){
    	printk("\ncopying filedescriptor to user...");
    	return -1;
    }
    if(copy_to_user(sigs, &signal, sizeof(atomic_t))){
    	printk("\ncopying pending signals to user...");
    	return -1;
    }


    printk("\nProcess information on current user is:\n%d processes\n%ld filedescriptors watched\n%d signals pending", process, filedesc, signal);
    free_uid(user);

    return 0;
}
