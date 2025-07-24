//FormAI DATASET v1.0 Category: Ebook reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>

/* Define Book Structure */
typedef struct{
    char title[50];
    char author[50];
    int pages;
}Book;

/* Function to display book information */
void display_book(Book b){
    printf("Title: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Pages: %d\n", b.pages);
}

int main(){
    /* Declare and initialize array of books */
    Book library[5] = { {"C Programming", "Dennis Ritchie", 300},
                        {"Data Structures and Algorithms", "Adam Drozdek", 400},
                        {"Clean Code", "Robert C. Martin", 200},
                        {"The Pragmatic Programmer", "Andrew Hunt and David Thomas", 350},
                        {"Code Complete", "Steve McConnell", 500}
                      };
    
    int choice = 0;
    /* Display Menu Options */
    printf("Welcome to My Ebook Reader!\n\n");
    printf("Enter 1 to Display All Books\n");
    printf("Enter 2 to Search for a Book\n");
    printf("Enter 3 to Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    
    while(choice != 3){
        switch(choice){
            /* Display all books */
            case 1:
                printf("All Books:\n\n");
                for(int i = 0; i < 5; i++){
                    display_book(library[i]);
                }
                break;
            /* Search for a book */
            case 2:
                char search_title[50];
                printf("Enter Title to Search: ");
                scanf("%s", search_title);
                int found = 0;
                for(int i = 0; i < 5; i++){
                    if(strcmp(search_title, library[i].title) == 0){
                        display_book(library[i]);
                        found = 1;
                        break;
                    }
                }
                if(!found){
                    printf("Sorry, Book Not Found!\n\n");
                }
                break;
            /* Invalid Choice */
            default:
                printf("Invalid Choice! Try Again.\n\n");
                break;
        }
        /* Re-display Menu Options */
        printf("Enter 1 to Display All Books\n");
        printf("Enter 2 to Search for a Book\n");
        printf("Enter 3 to Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
    }
    /* Exit Program */
    printf("Thank You for Using My Ebook Reader!\n");
    return 0;
}