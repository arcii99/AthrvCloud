//FormAI DATASET v1.0 Category: File handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[20];
    printf("Enter filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    printf("File opened successfully!\n");
    fputs("Welcome to my file handling program!\n", fp);
    fputs("This is a test file.\n", fp);
    int number = 42;
    fprintf(fp, "The answer to life, the universe and everything is %d.\n", number);
    fclose(fp);
    printf("File closed.\n");
    printf("Do you want to read the contents of the file? (y/n) ");
    char answer;
    scanf(" %c", &answer);
    if(answer == 'y') {
        fp = fopen(filename, "r");
        if(fp == NULL) {
            printf("Error opening file!\n");
            exit(1);
        }
        char ch = fgetc(fp);
        while(ch != EOF) {
            printf("%c", ch);
            ch = fgetc(fp);
        }
        fclose(fp);
    }
    printf("Program completed successfully!\n");
    return 0;
}