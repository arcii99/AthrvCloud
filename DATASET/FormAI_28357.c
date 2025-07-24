//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int main() {
    // Open the CSV file
    FILE* fp;
    fp = fopen("data.csv", "r");

    // Check if file was opened successfully
    if (fp == NULL) {
        printf("Error: Unable to open file!");
        return 1;
    }

    // Start reading the CSV file
    char line[MAX_LEN];
    char* token;    
    while(fgets(line, MAX_LEN, fp) != NULL) {
        token = strtok(line, ",");  
        while(token != NULL) {
            printf("%s\n", token);
            token = strtok(NULL, ",");
        }
    }

    // Close the file
    fclose(fp);

    return 0;
}