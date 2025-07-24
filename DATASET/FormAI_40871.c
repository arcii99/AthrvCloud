//FormAI DATASET v1.0 Category: Ebook reader ; Style: lively
#include <stdio.h>

struct ebook {
    char title[50];
    char author[50];
    int year;
    char genre[50];
    float price;
    int pages;
};

int main() {
    struct ebook library[5];

    strcpy(library[0].title, "The Great Gatsby");
    strcpy(library[0].author, "F. Scott Fitzgerald");
    library[0].year = 1925;
    strcpy(library[0].genre, "Classics");
    library[0].price = 9.99;
    library[0].pages = 180;

    strcpy(library[1].title, "To Kill a Mockingbird");
    strcpy(library[1].author, "Harper Lee");
    library[1].year = 1960;
    strcpy(library[1].genre, "Fiction");
    library[1].price = 11.99;
    library[1].pages = 281;

    strcpy(library[2].title, "The Hobbit");
    strcpy(library[2].author, "J.R.R. Tolkien");
    library[2].year = 1937;
    strcpy(library[2].genre, "Fantasy");
    library[2].price = 8.99;
    library[2].pages = 310;

    strcpy(library[3].title, "The Da Vinci Code");
    strcpy(library[3].author, "Dan Brown");
    library[3].year = 2003;
    strcpy(library[3].genre, "Thriller");
    library[3].price = 7.99;
    library[3].pages = 454;

    strcpy(library[4].title, "Harry Potter and the Philosopher's Stone");
    strcpy(library[4].author, "J.K. Rowling");
    library[4].year = 1997;
    strcpy(library[4].genre, "Young Adult");
    library[4].price = 10.99;
    library[4].pages = 223;

    int choice, i;
    printf("Welcome to the Ebook Library!\n");
    printf("What book would you like to read today?\n");
    for (i = 0; i < 5; i++) {
        printf("%d. %s by %s\n", i+1, library[i].title, library[i].author);
    }
    do {
        printf("\nPlease enter your choice (1-5): ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 5) {
            printf("Invalid choice, please try again.\n");
        }
    } while (choice < 1 || choice > 5);
    printf("\nYou have chosen %s by %s.\n\n", library[choice-1].title, library[choice-1].author);
    printf("The ebook has %d pages and costs $%0.2f.\n", library[choice-1].pages, library[choice-1].price);
    printf("Enjoy reading!");

    return 0;
}