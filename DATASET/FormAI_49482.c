//FormAI DATASET v1.0 Category: Data mining ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the maximum number of data entries we can handle
#define MAX_ENTRIES 100

// Define the size of each data entry in bytes
#define ENTRY_SIZE 32

// Define the file name for data input
#define FILE_NAME "data.txt"

// Define the output file name
#define OUTPUT_FILE "output.txt"

/**
 * Reads the data from the input file and stores it in an array
 */
void readData(char data[MAX_ENTRIES][ENTRY_SIZE], int* numEntries) {
    FILE *input;
    input = fopen(FILE_NAME, "r");

    if(input == NULL){
        printf("Error opening file\n");
        exit(1);
    }

    int i=0;
    char line[ENTRY_SIZE];

    while( fgets(line, ENTRY_SIZE, input) != NULL && i<MAX_ENTRIES ){
        strcpy(data[i], line);
        i++;
    }
    fclose(input);
    *numEntries = i;
}

/**
 * Writes the discovered patterns to the output file
 */
void writeOutput(char output[ENTRY_SIZE][MAX_ENTRIES], int numGroups, int numEntries[]) {
    FILE *outputFile;
    outputFile = fopen(OUTPUT_FILE,"w");

    for(int i=0; i<numGroups; i++){
        fprintf(outputFile, "Group %d: %d entries\n", i+1, numEntries[i]);
        for(int j=0;j<numEntries[i];j++){
            fprintf(outputFile, "%s\n", output[i][j]);
        }
        fprintf(outputFile, "\n");
    }
    fclose(outputFile);
}

/**
 * Takes the input data and separates it into groups based on patterns
 */
void groupData(char data[MAX_ENTRIES][ENTRY_SIZE], int numEntries, char output[ENTRY_SIZE][MAX_ENTRIES], int* numGroups, int numEntriesGroup[]) {
    // Initialization of sorted character array
    char sortedData[MAX_ENTRIES][ENTRY_SIZE];
    for(int i=0;i<numEntries;i++){
        strcpy(sortedData[i],data[i]);
        int len = strlen(data[i]);
        for(int j=0;j<len;j++){
            for(int k=0; k<(len-1); k++){
                if(sortedData[i][k]>sortedData[i][k+1]){
                    char temp = sortedData[i][k];
                    sortedData[i][k] = sortedData[i][k+1];
                    sortedData[i][k+1] = temp;
                }
            }
        }
    }

    // Assign each entry to its corresponding group
    int groupNum = 0;
    for(int i=0;i<numEntries;i++) {
        int found = 0;
        for(int j=0; j<groupNum; j++) {
            if(strcmp(sortedData[i], sortedData[numEntriesGroup[j]]) == 0) {
                 found = 1;
                 strcat(output[j][numEntriesGroup[j]], data[i]);
                 numEntriesGroup[j]++;
                 break;
            }
        }
        if(!found) {
            numEntriesGroup[groupNum] = 1;
            strcpy(output[groupNum][0], data[i]);
            strcpy(sortedData[numEntriesGroup[groupNum]-1], sortedData[i]);
            groupNum++;
        }
    }
    *numGroups = groupNum;
}

int main() {
    // Define the input data array
    char data[MAX_ENTRIES][ENTRY_SIZE];

    // Read the input data from file
    int numEntries;
    readData(data, &numEntries);

    // Define the output data array
    char output[ENTRY_SIZE][MAX_ENTRIES];
    int numEntriesGroup[MAX_ENTRIES];
    int numGroups;

    // Group the input data
    groupData(data, numEntries, output, &numGroups, numEntriesGroup);

    // Write the output to file
    writeOutput(output, numGroups, numEntriesGroup);

    return 0;
}