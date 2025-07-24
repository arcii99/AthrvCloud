//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_COLS 20
#define MAX_LINE_LENGTH 200

int main(int argc, char* argv[]) {
    FILE *fp;
    char delimeter;
    char csvLine[MAX_LINE_LENGTH];
    char *words[MAX_COLS];
    int numCols = 0;
    int i = 0;
    int j = 0;
    
    //check if correct number of arguments provided
    if(argc <= 2) {
        printf("Usage: csvreader filename delimeter\n");
        return -1;
    }
    
    //open file
    fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("Unable to open file\n");
        return -1;
    }
    
    //set delimeter
    delimeter = argv[2][0];
    
    //read csv line by line
    while(fgets(csvLine, MAX_LINE_LENGTH, fp) != NULL) {
        
        //initialize words array
        memset(words, 0, sizeof(words));
        i = 0;
        
        //parse csv line using delimeter
        words[i] = strtok(csvLine, &delimeter);
        while(words[i] != NULL && i < MAX_COLS - 1) {
            i++;
            words[i] = strtok(NULL, &delimeter);
        }
        
        //print the data
        numCols = i;
        for(j = 0; j < numCols; j++) {
            printf("%s ", words[j]);
        }
        printf("\n");
    }
    
    //close file
    fclose(fp);
    
    return 0;
}