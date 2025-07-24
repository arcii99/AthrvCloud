//FormAI DATASET v1.0 Category: Ebook reader ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ebook {
    char title[100];
    char author[100];
    double price;
    int pages;
};

int main() {
    int n = 0;
    printf("Enter the number of Ebooks you want to read: ");
    scanf("%d", &n);

    struct Ebook *library = (struct Ebook*) malloc(n * sizeof(struct Ebook));

    for(int i = 0; i < n; i++) {
        printf("Enter the title of Ebook %d: ", i+1);
        scanf("%s", library[i].title);

        printf("Enter the author of Ebook %d: ", i+1);
        scanf("%s", library[i].author);

        printf("Enter the price of Ebook %d: ", i+1);
        scanf("%lf", &library[i].price);

        printf("Enter the number of pages in Ebook %d: ", i+1);
        scanf("%d", &library[i].pages);

        printf("\n");
    }

    printf("***************************\n");
    printf("****** My Ebook Library ****\n");
    printf("***************************\n\n");

    for(int i = 0; i < n; i++) {
        printf("Ebook %d - %s\n", i+1, library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Price: $%.2f\n", library[i].price);
        printf("Pages: %d\n\n", library[i].pages);
    }

    free(library);

    return 0;
}