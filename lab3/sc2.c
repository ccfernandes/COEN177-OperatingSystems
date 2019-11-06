#include <stdio.h>
#include <stdlib.h>

int parseArguments(int argc, char *argv[]) {
    int tableSize;
    if(argc == 2 && (tableSize = atoi(argv[1]))) {
        return tableSize;
    }
    fprintf(stderr, "Wrong arguments. Pass tableSize as an argument\n");
    exit(-1);
}

int isInMemory(int pageRequest, int *pageTable, int tableSize) {
    int i;
    for(i = 0; i < tableSize; i++) {
        if(pageRequest == pageTable[i]) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int tableSize = parseArguments(argc, argv);    
    int pageRequest, pageTableIndex = 0, numRequest = 0, numMisses = 0;
    int *pageTable = (int *) malloc(sizeof(int)*tableSize);
    int *refTable = (int *) malloc(sizeof(int)*tableSize); //parallel array to store reference bits

    int counter=0;

    char *input = NULL;
    size_t inputAllocated = 0;
    ssize_t bytesRead;
   
    FILE *fp;
    fp = fopen("Chelsea_output_sc.txt", "w");

    while((bytesRead = getline(&input, &inputAllocated, stdin)) != -1) {
        pageRequest = atoi(input);
        if(pageRequest == 0) {
            continue;
        }
        numRequest++;
        if(!isInMemory(pageRequest, pageTable, tableSize)) {//number not in memory, insert it 
            fprintf(fp, "Page %d caused a page fault.\n", pageRequest);
            numMisses++;
            if(pageTableIndex < tableSize) {
                pageTable[pageTableIndex] = pageRequest;//insert it 
            	refTable[pageTableIndex++]=0;
	        }
            else {	
            //the array is full, get rid of the oldest one that has ref bit 0 and insert new number in that place
                if(counter==tableSize-1 || counter==tableSize){ //reached end of array, reset "head pointer" to beginning of array 
                        counter=0;
                }
                else{
                    counter++;
                }
                // int i;
                while(refTable[counter]==1){ //loop through array until a ref bit is 0 
                    refTable[counter]=0;
                    counter=(++counter)%tableSize;
                }
                //we have reached an elt with a ref bit of 0. we replace that one with new value. 
                pageTable[counter]=pageRequest;

            }
        } // else probably want to update something in pageTable so that lru and second chance work correctly
    	else{ //the value is already present in memory, change reference bit 
            int i;
            int index;
            for(i=0; i<tableSize; i++){ //find the index of page currently in memory
                if(pageRequest==pageTable[i]){
                    index=i;
                    break;	
                }
            }
            refTable[index]=1; //the value is already in memory, give second chance and set to 1. 
        }
    }
    fprintf(fp,"Hit rate = %f\n", (numRequest-numMisses)/(double)numRequest);
    printf("Hit rate = %f\n", (numRequest-numMisses)/(double)numRequest);
    
    fclose(fp);
    free(input);
    free(pageTable);
    return 0;
}
