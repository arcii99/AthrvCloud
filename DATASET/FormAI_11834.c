//FormAI DATASET v1.0 Category: Log analysis ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char fileName[50];
    int count = 0, warningCount = 0, errorCount = 0;
    printf("Enter the name of the log file: ");
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "r");
    if(file == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    char line[1000];
    while(fgets(line, 1000, file) != NULL){
        count++;

        if(strstr(line, "WARNING")){
            warningCount++;
        }
        if(strstr(line, "ERROR")){
            errorCount++;
        }
    }

    fclose(file);

    printf("Total number of log entries: %d\n", count);
    printf("Number of warnings: %d\n", warningCount);
    printf("Number of errors: %d\n", errorCount);

    return 0;
}