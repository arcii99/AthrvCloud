//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    char filepath[MAX_SIZE], character;
    int index = 0;
    printf("Enter file path: ");
    scanf("%s", filepath);
    FILE *fp;
    fp = fopen(filepath, "r");
    if (fp == NULL) {
        printf("Error opening file. \n");
        return 0;
    }
    printf("\nScanning for virus in %s.....\n\n", filepath);
    printf("*****************************\n");
    printf("**********Antivirus**********\n");
    printf("*****************************\n\n");
    int i=0;
    while(!feof(fp)) {
        character = getc(fp);
        if (character == 'v') {
            while (character != '\n' && !feof(fp)) {
                character = getc(fp); 
            }
            printf("Virus Detected!!\n");
            printf("Line number: %d\n\n",i);
        }
        i++;
    }
    printf("Scan Complete!\n");
    printf("No Viruses Detected.\n");
    fclose(fp);
    return 0;
}