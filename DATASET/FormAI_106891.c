//FormAI DATASET v1.0 Category: Log analysis ; Style: Alan Touring
// Alan Turing inspired C Log Analysis program
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to read input file and analyze logs
void analyzeLogs(char *fileName) {
    FILE *fp = fopen(fileName, "r"); // Opening file in read mode

    if(fp == NULL) {
        printf("Error: Unable to open file!\n"); // If file can't be opened
        return;
    }

    char line[100]; // Initializing array for each line
    int counter = 0;

    while(fgets(line, sizeof(line), fp)) { // Reading each line in file
        counter++;
        if(strstr(line, "ERROR") != NULL) { // Searching for string "ERROR"

            printf("Error found in Line %d: %s", counter, line); // Print line number and message
        }
    }

    fclose(fp); // Closing file after reading
    printf("Log Analysis completed!\n");
}

int main() {
    char fileName[50];

    printf("Enter name of log file: ");
    scanf("%s", fileName);

    analyzeLogs(fileName); // Calling function to analyze logs

    return 0;
}