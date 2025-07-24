//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to split the CSV line into separate strings
void splitLine(char* line, char* row[]) {
    const char* delimiter = ",";
    char* token;
    int i = 0;
    token = strtok(line, delimiter);
    while(token != NULL) {
        row[i] = token;
        i++;
        token = strtok(NULL, delimiter);
    }
}

int main() {
    char buffer[1024];
    char* row[5];   //Assuming the CSV file has 5 columns
    char* fileName = "example.csv";
    FILE* fp = fopen(fileName, "r");

    if(fp == NULL) {
        printf("Error: Could not open file %s\n", fileName);
        exit(1);
    }

    //Read the header line
    fgets(buffer, 1024, fp);

    printf("Header: %s", buffer);

    //Read the data lines and display them
    while(fgets(buffer, 1024, fp)) {
        splitLine(buffer, row);
        printf("Data: %s %s %s %s %s", row[0], row[1], row[2], row[3], row[4]);
    }

    fclose(fp);
    return 0;
}