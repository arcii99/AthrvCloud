//FormAI DATASET v1.0 Category: File handling ; Style: distributed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int findCharCount(char ch, FILE* fp);

int main() {

    char filePath[] = "test.txt";

    FILE* fp = fopen(filePath, "r");
    if(fp == NULL) {
        printf("Error while opening the file!\n");
        exit(1);
    }

    char ch = 'e';
    int count = findCharCount(ch, fp);

    printf("Number of occurrences of %c in %s: %d\n", ch, filePath, count);    
    fclose(fp);
    return 0;    
}

int findCharCount(char ch, FILE* fp) {
    
    int count = 0;
    char c;

    while((c = fgetc(fp))!=EOF) {
        if(c == ch) {
            count++;
        }        
    }

    return count;
}