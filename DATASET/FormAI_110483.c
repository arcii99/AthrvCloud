//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    printf("It was a dark and stormy night. I sat at my desk, hands on my keyboard, ready to solve the case. The only clue I had was a CSV file I had received earlier that day.");

    FILE *fp; // declare file pointer
    char* line = NULL; // pointer to hold line
    size_t len = 0; // size_t variable to hold length of line
    ssize_t read; // ssize_t variable to hold return value of getline()

    fp = fopen("example.csv", "r"); // open file for reading
    if (fp == NULL){
        printf("Failed to open file.\n");
        exit(EXIT_FAILURE);
    }

    char header[100]; // declare string to hold header row
    read = getline(&header, &len, fp); // read header row from csv file
    if (read == -1){ // check for error
        printf("Failed to read header row.\n");
        exit(EXIT_FAILURE);
    }

    printf("\nThe header row is: %s", header);

    while ((read = getline(&line, &len, fp)) != -1){ // read remaining rows from csv file
        char* ptr = strtok(line, ","); // tokenize line using comma as separator
        while (ptr != NULL) {
            printf("\n%s", ptr); // print each cell
            ptr = strtok(NULL, ",");
        }
    }

    fclose(fp); // close file

    if (line){ // check if memory has been allocated for variable line
        free(line); // free allocated memory
    }

    return 0;
}