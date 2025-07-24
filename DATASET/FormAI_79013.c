//FormAI DATASET v1.0 Category: File Encyptor ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_NAME_SIZE 100
#define KEY 3

void encrypt(FILE* fp, int key) {
    char c;
    while((c = fgetc(fp)) != EOF) {
        if(c >= 'A' && c <= 'Z') {
            c = (c + key - 'A') % 26 + 'A';
        } else if(c >= 'a' && c <= 'z') {
            c = (c + key - 'a') % 26 + 'a';
        }
        printf("%c", c);
    }
}

int main()
{
    char file_name[MAX_FILE_NAME_SIZE];
    printf("Enter file name: ");
    scanf("%s", file_name);

    FILE* fp = fopen(file_name, "r");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    encrypt(fp, KEY);
    fclose(fp);

    return 0;
}