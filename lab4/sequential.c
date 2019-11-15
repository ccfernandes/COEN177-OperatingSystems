//Chelsea Fernandes
//sequential.c

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

#define BUFFER_LENGTH 1024 //read 1MB at a time

int main(int argc, char *argv[]){
    FILE *fp;
    long i;
    char* buffer; 
    long bytes_to_read = atol(argv[2]);
    printf("bytes: %ld\n", bytes_to_read);

    buffer = malloc(sizeof(char)*BUFFER_LENGTH);
    fp=fopen(argv[1], "r");
    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    printf("file Size: %ld\n", fileSize);
    
    if (fp == NULL){
        return 0; 
    }

    clock_t start_time = clock();
    for(i=0; i<bytes_to_read; i++){
        fread(buffer, BUFFER_LENGTH,1,fp);
        bytes_to_read-=BUFFER_LENGTH;
    }
    
    clock_t end_time = clock();
    long elapsed = (long) (end_time-start_time);
    double final = (double) end_time;
    double ctime = (double) final/CLOCKS_PER_SEC;

    printf("start time: %ld\n", start_time);
    printf("final time: %ld\n", end_time);
    printf("Time elapsed: %ld\n", elapsed);
    printf("clocks_per_sec: %f\n", ctime);

    fclose(fp); 
    free(buffer);
    return 0;
}
