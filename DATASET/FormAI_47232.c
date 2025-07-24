//FormAI DATASET v1.0 Category: Ebook reader ; Style: protected
#include<stdio.h>
#include<stdlib.h>

typedef struct ebook {
    char title[50];
    char author[50];
    int year_published;
    char format[10];
    int file_size;
    char* content;
} Ebook;

int main() {
    Ebook myEbook;

    printf("Enter the title of the Ebook: ");
    fgets(myEbook.title, sizeof(myEbook.title), stdin);

    printf("Enter the author of the Ebook: ");
    fgets(myEbook.author, sizeof(myEbook.author), stdin);

    printf("Enter the year the Ebook was published: ");
    scanf("%d", &myEbook.year_published);

    printf("Enter the format of the Ebook: ");
    fgets(myEbook.format, sizeof(myEbook.format), stdin);

    printf("Enter the file size of the Ebook: ");
    scanf("%d", &myEbook.file_size);

    myEbook.content = (char*) malloc(myEbook.file_size * sizeof(char));
    printf("Enter the content of the Ebook: ");
    fgets(myEbook.content, myEbook.file_size, stdin);

    printf("\nEbook details:\n");
    printf("Title: %s\n", myEbook.title);
    printf("Author: %s\n", myEbook.author);
    printf("Year Published: %d\n", myEbook.year_published);
    printf("Format: %s\n", myEbook.format);
    printf("File Size: %d\n", myEbook.file_size);
    printf("Content: %s\n", myEbook.content);

    free(myEbook.content);

    return 0;
}