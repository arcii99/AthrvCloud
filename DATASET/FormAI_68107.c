//FormAI DATASET v1.0 Category: Data mining ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 128

int main(void) {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    char *token;
    int data[3];
    int counter = 0;
  
    fp = fopen("data.txt", "r");
    if(fp == NULL) {
        printf("Error: Failed to open file.\n");
        return 1;
    }

    printf("Reading data from file:\n");
    while(fgets(line, MAX_LINE_SIZE, fp) != NULL) {
        printf("%s", line);
        token = strtok(line, ",");
        for(int i = 0; i < 3 && token != NULL; i++) {
            sscanf(token, "%d", &data[i]);
            token = strtok(NULL, ",");
        }
        // Do some processing with the data here
        counter++;
    }
    fclose(fp);

    printf("\nTotal data read: %d\n", counter);

    return 0;
}