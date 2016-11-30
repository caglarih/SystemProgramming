#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#define NR_setmyflag 355

int main(void){
	pid_t childPID = 12345;
	int x,y;
	int i = 5;
	printf("Process is being started, you can check process list...\n");
	scanf("%d", &x);
	printf("Fork operation will be tried...\n");
	for(i=5;i>0;i--){
		childPID = fork();
		if(childPID < 0){
			printf("Fork unsuccesful.\n");
		}
		else if(childPID == 0){
			printf("Child process is started\n");
			sleep(15);
			printf("Child process terminates\n");
                        exit(EXIT_SUCCESS);
		}
		else{
			printf("PID value of child process after fork: %d\n",childPID);
			if(i==1){
				printf("myFlag will be set as 1...\n");
				y = syscall(NR_setmyflag,getpid(),1);
				if(y==-1){
					if(errno == EPERM)
						printf("You need root priviliages to use set_myFlag syscall\n");
					return -1;
				}
				if(y==0){
					printf("myFlag has been changed, exit function will be examined...\n");
				}
				sleep(4);
				exit(EXIT_SUCCESS);
			}
		}
	}
}
