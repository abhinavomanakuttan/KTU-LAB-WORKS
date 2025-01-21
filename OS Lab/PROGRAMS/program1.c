#include  <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	
	printf("process ID of the curent porcess :%d \n ",getpid());
	int pid =fork();
	
	if(pid>0){
		printf("Parrent process waiting for the child to finsh .\n");
		wait(NULL);
		execlp("ls ","ls",NULL);
		perror("Excelp failed");
		exit(1);
		}
	else if (pid ==0){
		printf("Child process (ID :%d) starts and ends \n",getpid());
		exit(0);
		}
	else {
		perror("Fork failed");
		exit(1);
		}
		return 0;
		}
		
