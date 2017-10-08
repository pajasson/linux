#ifndef _LINUX_PROCESSINFO_H
#define _LINUX_PROCESSINFO_H


asmlinkage long sys_processInfo(int* proc, int* sigs, long int* fd);


#endif /* _LINUX_PROCESSINFO_H */
