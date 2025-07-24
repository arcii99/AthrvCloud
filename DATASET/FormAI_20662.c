//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024 // define the maximum line length 

int main(int argc, char **argv){

    if(argc < 2){
        printf("Please enter a filename to read!\n");
        return 0;
    }

    FILE *csv_file = fopen(argv[1], "r"); //open csv file in read mode

    if(!csv_file){
        printf("Failed to open file: %s\n", argv[1]);
        return -1;
    }

    char *line = (char*) malloc(MAX_LINE_LENGTH * sizeof(char)); // allocate memory to store a line of csv

    while(fgets(line, MAX_LINE_LENGTH, csv_file) != NULL){ // read the csv line by line

        char *token = strtok(line, ","); // split the line into tokens

        while (token != NULL){

            printf("%s ", token); // print each token

            token = strtok(NULL, ",");
        }

        printf("\n");
    }

    fclose(csv_file); // close the csv file

    free(line); // free the memory allocated for line 

    return 0;
}