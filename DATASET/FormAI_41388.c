//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <filename> \n", argv[0]);
        return 1;
    }
    char* filename = argv[1];
    FILE *fp;
    char line[MAX_LINE_LENGTH];

    fp = fopen(filename, "r");
    if(!fp) {
        printf("Could not open file %s. Aborting...\n", argv[1]);
        return 1;
    }
    int hasInfected = 0;
    int lineNumber = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        lineNumber++;
        if (strstr(line, "infected")) {
            printf("Virus detected on line %d: %s\n", lineNumber, line);
            hasInfected = 1;
        } 
    }

    fclose(fp);
    if(hasInfected) {
        printf("The file %s is infected with a virus.\n", filename);   
    } else {
        printf("No viruses detected in file %s.\n", filename);
    }
       
    return 0;
}