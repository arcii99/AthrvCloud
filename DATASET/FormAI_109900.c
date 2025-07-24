//FormAI DATASET v1.0 Category: Ebook reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main() {
    char file_name[20];
    printf("Enter the file name to open: ");
    scanf("%s", file_name);

    // Check if file name contains ".txt"
    int i, flag = 0;
    for (i = 0; i < 20; i++) {
        if (file_name[i] == '.') {
            if (file_name[i+1] == 't' && file_name[i+2] == 'x' && file_name[i+3] == 't') {
                flag = 1; // File name is valid
                break;
            }
        }
    }

    if (!flag) {
        printf("Invalid file name. Only .txt files are allowed.\n");
        exit(1);
    }

    // Check if file exists
    FILE *fp;
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("File does not exist.\n");
        exit(1);
    }

    printf("File successfully opened.\n");
    printf("Reading contents of file...\n");

    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }

    fclose(fp);
    return 0;
}