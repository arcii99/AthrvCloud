//FormAI DATASET v1.0 Category: Ebook reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    int pages;
    double price;
} eBook;

int main() {
    eBook book1 = {"C Programming", "Dennis Ritchie", 272, 12.99};
    eBook book2 = {"Programming in C++", "Bjarne Stroustrup", 976, 34.99};
    eBook book3 = {"Java: The Complete Reference", "Herbert Schildt", 1248, 49.99};
    eBook library[3] = {book1, book2, book3};
    
    char selection[20];
    int choice = 0;
    
    printf("Welcome to My eReader!\n");
    
    while (choice != 4) { //4 is the exit option
        printf("\nSelect an option:\n");
        printf("1. Show eBooks\n");
        printf("2. Add an eBook\n");
        printf("3. Remove an eBook\n");
        printf("4. Exit\n");
        
        fgets(selection, sizeof(selection), stdin); //get user input
        
        //convert selection string to integer
        if (selection[0] >= '0' && selection[0] <= '9') {
            choice = atoi(selection);
        } else {
            printf("Invalid selection. Please choose a number.\n");
            continue;
        }
        
        switch (choice) {
            case 1: //show eBooks
                printf("\nYour library contains:\n");
                for (int i = 0; i < 3; i++) {
                    printf("%d. Title: %s | Author: %s | Pages: %d | Price: $%.2f\n",
                            i+1, library[i].title, library[i].author, library[i].pages, library[i].price);
                }
                break;
            
            case 2: //add eBook
                if (sizeof(library)/sizeof(eBook) < 10) { //check if there is room for more eBooks
                    char title[100], author[100];
                    int pages;
                    double price;
                    printf("Enter the eBook title: ");
                    fgets(title, sizeof(title), stdin);
                    printf("Enter the author name: ");
                    fgets(author, sizeof(author), stdin);
                    printf("Enter the number of pages: ");
                    fgets(selection, sizeof(selection), stdin);
                    pages = atoi(selection);
                    printf("Enter the price: ");
                    fgets(selection, sizeof(selection), stdin);
                    price = atof(selection);
                    //create new eBook and add to library array
                    eBook newBook = {title, author, pages, price};
                    library[sizeof(library)/sizeof(eBook)] = newBook;
                    printf("Added new eBook to library.\n");
                } else {
                    printf("Sorry, your library is full! Please remove an eBook to make room for a new one.\n");
                }
                break;
            
            case 3: //remove eBook
                int index;
                printf("Enter the eBook number to remove: ");
                fgets(selection, sizeof(selection), stdin);
                index = atoi(selection);
                if (index > 0 && index <= sizeof(library)/sizeof(eBook)) {
                    for (int i = index-1; i < sizeof(library)/sizeof(eBook)-1; i++) {
                        library[i] = library[i+1];
                    }
                    printf("Removed eBook from library.\n");
                } else {
                    printf("Invalid selection. Please choose a number between 1 and %d.\n", sizeof(library)/sizeof(eBook));
                }
                break;
                
            case 4: //exit program
                printf("Exiting My eReader. Goodbye!\n");
                break;
            
            default: //invalid input
                printf("Invalid selection. Please choose a number between 1 and 4.\n");
                break;
        }
    }
    
    return 0;
}