//FormAI DATASET v1.0 Category: File handling ; Style: energetic
#include <stdio.h>

int main() {
    char filename[20];
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "w+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Enter some text to write to the file:\n");
    char input[100];
    scanf(" %[^\n]", input);

    fputs(input, fp);

    printf("Successfully wrote to file!\n");

    fseek(fp, 0, SEEK_SET);

    printf("The contents of the file are:\n");
    char ch = fgetc(fp);
    while (ch != EOF) {
        printf("%c", ch);
        ch = fgetc(fp);
    }

    fclose(fp);
    printf("File closed!\n");

    return 0;
}