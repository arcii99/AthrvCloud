//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursive function to build CSV reader
void read_csv(char *filename, char **data) {
    FILE *fp;
    char buffer[1024], *line;
    int i = 0;

    // Try to open the file provided
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Failed to open file %s\n", filename);
        exit(1);
    }

    // Read data from file line by line
    while(fgets(buffer, 1024, fp)) {
        line = strtok(buffer, ",");
        while(line != NULL) {
            // Allocate memory to store string data
            data[i] = (char*) malloc(strlen(line) + 1);
            strcpy(data[i], line);
            i++;

            // Call recursive function to read next line
            read_csv(NULL, data);
            
            line = strtok(NULL, ",");
        }
    }
    
    // Close the file
    fclose(fp);
}

int main() {
    char *data[50];

    printf("Reading CSV file...\n");
    read_csv("example.csv", data);
    
    // Display data that was read from file
    for(int i=0; i<50; i++) {
        if(data[i] != NULL) {
            printf("%s\n", data[i]);
        }
    }
    
    return 0;
}