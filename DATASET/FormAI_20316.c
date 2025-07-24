//FormAI DATASET v1.0 Category: Ebook reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char title[50];
    char author[50];
    char filename[100];

    printf("The Happy C Ebook Reader\n");
    printf("Enter the book title: ");
    fgets(title, 50, stdin);
    printf("Enter the author's name: ");
    fgets(author, 50, stdin);
    printf("Enter the ebook filename: ");
    fgets(filename, 100, stdin);
    printf("\n");

    // Remove newline characters from user input
    title[strcspn(title, "\n")] = 0;
    author[strcspn(author, "\n")] = 0;
    filename[strcspn(filename, "\n")] = 0;

    // Read the file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Error: File not found\n");
        return 1;
    }

    printf("%s by %s\n\n", title, author);

    // Print out each line of the file
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }

    fclose(fp);

    return 0;
}