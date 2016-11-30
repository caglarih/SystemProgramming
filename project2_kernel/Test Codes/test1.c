#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#define NR_setmyflag 355


int main(void) {
	int y,choice,target;
	pid_t x,childPID=123;
	printf("\n1: This process PID\n2: Give by hand\nChoice? [1/2]  : ");
	scanf("%d",&choice);
	printf("\nPlease submit new flag number: ");
	scanf("%d",&target);
	if(choice==1){
		x = getpid();
		printf("\nCurrent pid=%d\n",x);
		y = syscall(NR_setmyflag,x,target);
		if(y==-1){
			if(errno == EPERM)
				printf("You need root priviliages to use set_myFlag syscall\n");
			return -1;
		}
		else if(y==0){
			printf("Positive result from system call.\n");
			printf("\nFork operation will be tried...\n");
			childPID = fork();
			if(childPID < 0){
				printf("Fork unsuccesful.\n");
			}
			else if(childPID == 0){
				printf("Child process is started and will be finished\n");
			}
			else{
				printf("PID value of child process after fork: %d\n",childPID);
			}
		}
	}
	else{
		printf("Please submit the PID: ");
		scanf("%d",&x);y = syscall(NR_setmyflag,x,target);
		if(y==-1){
			if(errno == EPERM)
				printf("You need root priviliages to use set_myFlag syscall\n");
			else if(errno == EINVAL)
				printf("You have submitted an invalid PID!\n");
			return -1;
		}
	}
	sleep(5);
	exit(EXIT_SUCCESS);
	return 0;
}
