#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/sched.h>
#include <linux/errno.h>
#include <linux/pid.h>
#include <linux/rwlock.h>
#include <linux/cred.h>

asmlinkage long set_myFlag(pid_t pid, int flag){
    struct task_struct* p=0;
    if(current_cred()->uid.val != 0) return -EPERM;
    if(flag != 0 && flag != 1) return -EINVAL;

    read_lock(&tasklist_lock);
    p = find_task_by_vpid(pid);
    if(p==0){
        read_unlock(&tasklist_lock);
        return -EINVAL;
    }
    task_lock(p);
    printk("[SETMYFLAG] PID=%d , FLAG_OLD= %d\n",p->pid,p->myFlag);
    p->myFlag = flag;
    printk("[SETMYFLAG] PID=%d , FLAG_NEW= %d\n",p->pid,p->myFlag);
    task_unlock(p);
    read_unlock(&tasklist_lock);

    return 0;
}
