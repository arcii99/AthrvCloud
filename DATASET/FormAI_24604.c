//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: genious
#include<stdio.h>
#include<stdlib.h>

int main(){
    char logFile[100];
    printf("Enter the log file path: ");
    scanf("%s", logFile);
    FILE *fptr;
    fptr = fopen(logFile, "r");

    if(fptr == NULL){
        printf("Could not open file.");
        exit(1);
    }

    char line[512];
    int count = 0;

    while(fgets(line, sizeof(line), fptr)){
        if(strstr(line, "error") || strstr(line, "attack")){
            printf("Possible intrusion detected in line %d: \n %s", count, line);
        }
        count++;
    }

    fclose(fptr);
    return 0;
}