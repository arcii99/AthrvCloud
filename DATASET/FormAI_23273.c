//FormAI DATASET v1.0 Category: Data recovery tool ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Function to recover data from a damaged file
void dataRecoveryTool(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Oops! The file doesn't exist!\n");
        return;
    }
    printf("Yeehaw! Let's recover some data!\n");
    char c;
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }
    printf("\nHooray! We recovered all the data!\n");
    fclose(fp);
}

int main() {
    char filename[100];
    printf("Welcome to the Data Recovery Tool!\n");
    printf("Please enter the name of the file you want to recover: ");
    scanf("%s", filename);
    dataRecoveryTool(filename);
    return 0;
}