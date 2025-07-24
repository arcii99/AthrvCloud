//FormAI DATASET v1.0 Category: Ebook reader ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for Ebook
struct Ebook {
    char title[50];
    char author[50];
    int pageCount;
    float price;
    char publisher[50];
};

// Define function to display Ebook details
void displayEbook(struct Ebook ebook) {
    printf("\nTitle: %s\n", ebook.title);
    printf("Author: %s\n", ebook.author);
    printf("Page Count: %d\n", ebook.pageCount);
    printf("Price: %.2f\n", ebook.price);
    printf("Publisher: %s\n", ebook.publisher);
}

int main() {
    // Define array of Ebook struct
    struct Ebook ebooks[5];
    
    // Define variables
    int choice, i;
    char search[50];
    
    // Populate array of Ebook struct
    strcpy(ebooks[0].title, "The Alchemist");
    strcpy(ebooks[0].author, "Paulo Coelho");
    ebooks[0].pageCount = 163;
    ebooks[0].price = 10.99;
    strcpy(ebooks[0].publisher, "HarperCollins");
    
    strcpy(ebooks[1].title, "To Kill a Mockingbird");
    strcpy(ebooks[1].author, "Harper Lee");
    ebooks[1].pageCount = 324;
    ebooks[1].price = 12.99;
    strcpy(ebooks[1].publisher, "Grand Central Publishing");
    
    strcpy(ebooks[2].title, "1984");
    strcpy(ebooks[2].author, "George Orwell");
    ebooks[2].pageCount = 328;
    ebooks[2].price = 8.99;
    strcpy(ebooks[2].publisher, "Penguin Books");
    
    strcpy(ebooks[3].title, "Brave New World");
    strcpy(ebooks[3].author, "Aldous Huxley");
    ebooks[3].pageCount = 288;
    ebooks[3].price = 9.99;
    strcpy(ebooks[3].publisher, "HarperPerennial");
    
    strcpy(ebooks[4].title, "The Catcher in the Rye");
    strcpy(ebooks[4].author, "J.D. Salinger");
    ebooks[4].pageCount = 224;
    ebooks[4].price = 7.99;
    strcpy(ebooks[4].publisher, "Little, Brown and Company");
    
    // Display main menu
    do {
        printf("\nEbook Reader\n");
        printf("----------------------------------------\n");
        printf("1. Display all Ebooks\n");
        printf("2. Search for an Ebook by title\n");
        printf("3. Exit\n");
        printf("----------------------------------------\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // Display all Ebooks
                printf("\nEbook List\n");
                printf("----------------------------------------\n");
                for (i = 0; i < 5; i++) {
                    displayEbook(ebooks[i]);
                    printf("----------------------------------------\n");
                }
                break;
            case 2:
                // Search for an Ebook by title
                printf("\nEnter the title to search: ");
                scanf("%s", search);
                for (i = 0; i < 5; i++) {
                    if (strcmp(search, ebooks[i].title) == 0) {
                        printf("\nSearch Result\n");
                        printf("----------------------------------------\n");
                        displayEbook(ebooks[i]);
                        printf("----------------------------------------\n");
                        break;
                    }
                }
                if (i == 5) {
                    printf("\nEbook not found\n");
                }
                break;
            case 3:
                // Exit program
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice\n");
                break;
        }
    } while (choice != 3);
    
    return 0;
}