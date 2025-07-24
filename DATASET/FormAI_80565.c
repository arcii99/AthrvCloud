//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[20], buffer[100];
    printf("Enter the filename (don't forget to add .csv extension): ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File does not exist!");
        exit(1);
    } 
    printf("\nThe contents of the file are :\n");
    while (fgets(buffer, 100, fp) != NULL) {
        char *field = strtok(buffer, ",");
        printf("%-12s", field);
        while (field != NULL) {
            field = strtok(NULL, ",");
            if(field != NULL) {
                printf("%-12s", field);
            }
        }
        printf("\n");
    }
    fclose(fp);
    return 0;
}