//FormAI DATASET v1.0 Category: Ebook reader ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Ebook structure to store book information
typedef struct{
    char title[100];
    char author[50];
    float price;
    char format[10];
} ebook;

int main(){
    int n;
    printf("Enter the number of books you want to add: ");
    scanf("%d", &n);

    // Dynamic memory allocation for array of ebooks
    ebook* library = (ebook*)malloc(n * sizeof(ebook));
    
    // Loop to add books to library
    for(int i=0; i<n; i++){
        printf("\nEnter details for Book %d:\n", i+1);
        printf("Title: ");
        scanf("%s", (library+i)->title);
        printf("Author: ");
        scanf("%s", (library+i)->author);
        printf("Price: ");
        scanf("%f", &(library+i)->price);
        printf("Format: ");
        scanf("%s", (library+i)->format);
    }

    // Loop to display book details
    printf("\nLibrary:\n");
    for(int i=0; i<n; i++){
        printf("\nBook %d:\n", i+1);
        printf("Title: %s\n", (library+i)->title);
        printf("Author: %s\n", (library+i)->author);
        printf("Price: %.2f\n", (library+i)->price);
        printf("Format: %s\n", (library+i)->format);
    }

    // Deallocate memory for library
    free(library);
    return 0;
}