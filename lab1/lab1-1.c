/*
	Chelsea Fernandes 
	file: lab1-1.c
	info: A simple shell program that terminates when a user enters "exit", and launches a helloworld program
		  in esponse to any other inputted string. 
*/
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

#define TRUE 1

int main(int arcc, char* argv[]){
	int status;
	char buffer[100]; //buffer array to store user input
	
	while(TRUE){
		printf("command: ");
		scanf("%s", buffer);

		if(strcmp(buffer, "exit")==0){//error, exit 
			return 0; //exit program
		}
		if(fork()!=0){//parent process
			waitpid(-1, &status, 0);//wait until children are done
		}
		else{//child process 
			execve("helloworld", NULL, 0);//replaces current process and goes to helloworld.c via executable
		}
	}
}
