//FormAI DATASET v1.0 Category: Ebook reader ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Open file
    FILE *fp = fopen("book.txt", "r");
    if(fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }
    // Read file
    char c;
    while((c = getc(fp)) != EOF) {
        printf("%c", c);
    }
    // Close file
    fclose(fp);
    return 0;
}