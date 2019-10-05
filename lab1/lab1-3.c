/*
	Chelsea Fernandes
	file: lab1-3.c
	info: Program that creates a total of 14 child processes. Each process has exactly 2 children, 
	      where one of the children is the parent of the next 2 children. See readMe.txt for exact structure. 
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	int max=3;
	int status;
	int count=0;
	
	int n; //number of levels (create 6)
	while(n<7){
		if(fork()!=0){
			if(fork()!=0){
				waitpid(-1, &status, 0);
				break;
			}
			else{
				printf("child: %d parent: %d\n", getpid(), getppid());
				//count++;
			}
			waitpid(-1, &status, 0);
			break;
		}
		else{
			printf("child: %d parent: %d\n", getpid(), getppid()); 
			//count++;
			//printf("&d", count);
		}
		n++;
	}
