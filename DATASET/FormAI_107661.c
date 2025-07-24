//FormAI DATASET v1.0 Category: Ebook reader ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30
#define MAX_PAGES 1000

struct Book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int num_pages;
    char* page_contents[MAX_PAGES]; // pointer to strings holding content of each page
};

struct Library {
    struct Book books[MAX_BOOKS];
    int num_books;
};

int main() {
    // create a new library and add some books
    struct Library my_library;
    my_library.num_books = 0;

    struct Book lotr;
    strcpy(lotr.title, "The Lord of the Rings");
    strcpy(lotr.author, "J.R.R. Tolkien");
    lotr.num_pages = 150;
    lotr.page_contents[0] = "It is a truth universally acknowledged";
    // ... add more page contents here ...
    my_library.books[0] = lotr;
    my_library.num_books++;

    // display menu options
    int option;
    printf("Welcome to Ebook Reader!\n");
    printf("1. View Books\n");
    printf("2. Read Book\n");
    printf("3. Add Book\n");
    printf("4. Quit\n");

    // accept user input and perform the selected action
    while (1) {
        printf("Enter option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                // view all books in the library
                printf("All Books:\n");
                for (int i = 0; i < my_library.num_books; i++) {
                    printf("%s by %s\n", my_library.books[i].title, my_library.books[i].author);
                }
                break;
            case 2:
                // read a book by selected title
                char search_title[MAX_TITLE_LENGTH];
                printf("Enter book title: ");
                scanf("%s", search_title);
                for (int i = 0; i < my_library.num_books; i++) {
                    if (strcmp(my_library.books[i].title, search_title) == 0) {
                        printf("Reading %s by %s:\n", my_library.books[i].title, my_library.books[i].author);
                        for (int j = 0; j < my_library.books[i].num_pages; j++) {
                            printf("%s\n", my_library.books[i].page_contents[j]);
                        }
                        break;
                    }
                }
                break;
            case 3:
                // add a new book to the library
                struct Book new_book;
                printf("Enter book title: ");
                scanf("%s", new_book.title);
                printf("Enter author name: ");
                scanf("%s", new_book.author);
                printf("Enter number of pages: ");
                scanf("%d", &new_book.num_pages);
                for (int i = 0; i < new_book.num_pages; i++) {
                    printf("Enter contents of page %d: ", i+1);
                    new_book.page_contents[i] = malloc(MAX_PAGES*sizeof(char));
                    scanf("%s", new_book.page_contents[i]);
                }
                my_library.books[my_library.num_books] = new_book;
                my_library.num_books++;
                break;
            case 4:
                // quit the program
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}