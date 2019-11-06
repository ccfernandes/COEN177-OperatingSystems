//lru2.c

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
    int *ageTable = (int *)malloc(sizeof(int)*tableSize);

    char *input = NULL;
    size_t inputAllocated = 0;
    ssize_t bytesRead;
   
    FILE *fp;
    fp = fopen("Chelsea_output_lru.txt", "w");

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
            	ageTable[pageTableIndex++] = numRequest;
	    } else {	
		//the array is full, get rid of the oldest one and insert new number in that place
            int i;
            int oldest=-1;
            int oldest_index;
            for(i=0; i<tableSize; i++){//determine the oldest in the table 
                if(oldest==-1 || (oldest>ageTable[i])){
                    oldest=ageTable[i];
                    oldest_index=i;
                }	
            }
            pageTable[oldest_index]=pageRequest;//insert new at the old index
            ageTable[oldest_index]=numRequest; //update age of page at old index (now the newest/youngest)
            }
        } // else probably want to update something in pageTable so that lru and second chance work correctly
    	else{ //the value is already present in memory, change reference bit 
            int index;
            int i;
            for(i=0; i<tableSize; i++){//find the oldest page with same val
                if(pageRequest==pageTable[i]){
                    index=i;		
                    break;
                }
            }
            ageTable[index]=numRequest;//just update its age 
        }
    }
    fprintf(fp,"Hit rate = %f\n", (numRequest-numMisses)/(double)numRequest);
    printf("Hit rate = %f\n", (numRequest-numMisses)/(double)numRequest);
    
    fclose(fp);
    free(input);
    free(pageTable);
    return 0;
} 

