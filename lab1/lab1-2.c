/*
	Chelsea Fernandes
	file: lab1-2.c
	info: Program creates exactly six child processes (not including initial parent program). 
	      Each process has exactly one child process, connected like a chain. See readMe.txt for more information. 
*/
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
	int status;
	int n=0;
	while(n<6){//the number of levels in tree (6)
		if(fork()!=0){//parent process
			printf("parent id: %d\n", getpid());
			waitpid(-1, &status, 0);//wait for child processes to complete
			break;
		}
		else{//child process 
			printf("child #%d\n", n);
			printf("child: %d parent: %d\n", getpid(), getppid());
			n++;
		}
	}
	return 0;
}
