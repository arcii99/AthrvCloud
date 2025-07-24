//FormAI DATASET v1.0 Category: Log analysis ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char buff[255];
    char *token;
    int sum=0;
    int count=0;
    float avg;
    
    fp = fopen("log.txt", "r");
    if(fp == NULL) {
        perror("Error opening file");
        return(-1);
    }

    while(fgets(buff, 255, (FILE*)fp)) {
        token = strtok(buff," ");
        while(token != NULL) {
            if(isdigit(*token)) {
                int num = atoi(token);
                sum+=num;
                count++;
            }
            token = strtok(NULL, " ");
        }
    }
    
    avg = (float)sum/count;
    
    printf("Total numbers in log file: %d \n", count);
    printf("Sum of numbers in log file: %d \n", sum);
    printf("Average of numbers in log file: %.2f \n", avg);
    
    fclose(fp);
    
    return 0;
}