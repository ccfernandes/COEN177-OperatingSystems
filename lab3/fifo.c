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

    char *input = NULL;
    size_t inputAllocated = 0;
    ssize_t bytesRead;
   
    FILE *fp;
    fp = fopen("Chelsea_output_fifo.txt", "w");

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
                pageTable[pageTableIndex++] = pageRequest;//insert it 
            } else {	
		//the array is full, get rid of the oldest one and insert new number in that place
	    	int i;
		for(i=1; i<tableSize; i++){
			
			pageTable[i-1]=pageTable[i];
		}
		pageTable[tableSize-1]=pageRequest;
	    }
        } // else probably want to update something in pageTable so that lru and second chance work correctly
    	else{ 
	    }
    }
    fprintf(fp,"Hit rate = %f\n", (numRequest-numMisses)/(double)numRequest);
    printf("Hit rate = %f\n", (numRequest-numMisses)/(double)numRequest);
    fclose(fp);
    free(input);
    free(pageTable);
    return 0;
}
