#ifndef _LINUX_PROCESSINFO_H
#define _LINUX_PROCESSINFO_H


asmlinkage long sys_processInfo(int* procs, int* fds, int* sigpends);

unsigned long bitmaskSum(unsigned long bitmask);


#endif /* _LINUX_PROCESSINFO_H */
