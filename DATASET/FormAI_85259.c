//FormAI DATASET v1.0 Category: Ebook reader ; Style: Cryptic
// Initializing the program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the maximum character length of the book name
#define MAX_BOOK_NAME 30

// Defining the maximum character length of the author name
#define MAX_AUTHOR_NAME 20

// Defining the maximum number of pages in the book
#define MAX_PAGES 500

// Defining the maximum number of bookmarks that can be added
#define MAX_BOOKMARKS 10

// Defining the maximum number of characters that can be displayed in a line
#define MAX_CHARACTERS_PER_LINE 80

// Defining the maximum character length of the book content
#define MAX_BOOK_CONTENT 50000

// Defining the maximum character length of the bookmark name
#define MAX_BOOKMARK_NAME 10

// Struct for storing book information
typedef struct{
    char book_name[MAX_BOOK_NAME];
    char author_name[MAX_AUTHOR_NAME];
    int page_count;
    char content[MAX_BOOK_CONTENT];
    char bookmarks[MAX_BOOKMARKS][MAX_BOOKMARK_NAME];
    int bookmark_pages[MAX_BOOKMARKS];
}Book;

// Function to display the menu
void display_menu(){
    printf("Welcome to the Ebook Reader!\n\n");
    printf("1. Add a book\n");
    printf("2. View a book\n");
    printf("3. Add a bookmark\n");
    printf("4. View bookmarks\n");
    printf("5. Exit\n");
}

// Function to add a book
void add_book(Book *books, int *book_count){
    // Creating a new book
    Book new_book;
    
    printf("Enter the name of the book (max %d characters): ", MAX_BOOK_NAME);
    scanf("%s", new_book.book_name);
    
    printf("Enter the name of the author (max %d characters): ", MAX_AUTHOR_NAME);
    scanf("%s", new_book.author_name);
    
    printf("Enter the number of pages in the book (max %d pages): ", MAX_PAGES);
    scanf("%d", &new_book.page_count);
    
    printf("Enter the content of the book (max %d characters): ", MAX_BOOK_CONTENT);
    scanf("%s", new_book.content);
    
    // Adding the new book to the books array
    books[*book_count] = new_book;
    
    // Incrementing book count
    (*book_count)++;
    
    printf("Book added successfully!\n");
}

// Function to view a book
void view_book(Book *books, int book_count){
    char book_name[MAX_BOOK_NAME];
    int i, j, bookmark_count;
    
    printf("Enter the name of the book to view: ");
    scanf("%s", book_name);
    
    // Finding the book index from the books array
    for(i=0;i<book_count;i++){
        if(strcmp(books[i].book_name, book_name) == 0){
            // Book found
            printf("Book Name: %s\n", books[i].book_name);
            printf("Author Name: %s\n", books[i].author_name);
            printf("Page Count: %d\n\n", books[i].page_count);
            
            // Setting default bookmark count
            bookmark_count = 0;
            
            // Displaying the bookmarks
            printf("Bookmarks:\n");
            for(j=0;j<MAX_BOOKMARKS;j++){
                if(strlen(books[i].bookmarks[j]) > 0){
                    printf("- %s (Page %d)\n", books[i].bookmarks[j], books[i].bookmark_pages[j]);
                    bookmark_count++;
                }
            }
            
            if(bookmark_count == 0){
                printf("No bookmarks found.\n");
            }
            
            // Displaying the book content
            printf("\nBook Content:\n");
            for(j=0;j<strlen(books[i].content);j++){
                printf("%c", books[i].content[j]);
                if((j+1) % MAX_CHARACTERS_PER_LINE == 0){
                    printf("\n");
                }
            }
            
            printf("\n\n");
            return;
        }
    }
    
    // Book not found
    printf("Book not found!\n");
}

// Function to add a bookmark
void add_bookmark(Book *books, int book_count){
    char book_name[MAX_BOOK_NAME];
    char bookmark_name[MAX_BOOKMARK_NAME];
    int bookmark_page, i, j;
    
    printf("Enter the name of the book to add bookmark: ");
    scanf("%s", book_name);
    
    // Finding the book index
    for(i=0;i<book_count;i++){
        if(strcmp(books[i].book_name, book_name) == 0){
            // Book found
            printf("Enter the name of the bookmark (max %d characters): ", MAX_BOOKMARK_NAME);
            scanf("%s", bookmark_name);
            
            printf("Enter the page number for the bookmark: ");
            scanf("%d", &bookmark_page);
            
            // Adding the bookmark
            for(j=0;j<MAX_BOOKMARKS;j++){
                if(strlen(books[i].bookmarks[j]) == 0){
                    // Free bookmark found
                    strcpy(books[i].bookmarks[j], bookmark_name);
                    books[i].bookmark_pages[j] = bookmark_page;
                    printf("Bookmark \"%s\" added successfully on page %d of \"%s\".\n", bookmark_name, bookmark_page, book_name);
                    return;
                }
            }
            
            // No free bookmarks found
            printf("Cannot add more bookmarks to this book!\n");
            return;
        }
    }
    
    // Book not found
    printf("Book not found!\n");
}

// Function to view bookmarks
void view_bookmarks(Book *books, int book_count){
    int i, j, bookmark_count;
    
    printf("Bookmarks:\n\n");
    
    // Iterating through all the books
    for(i=0;i<book_count;i++){
        if(strlen(books[i].bookmarks[0]) > 0){
            // Book has bookmarks
            printf("Book Name: %s\n", books[i].book_name);
            printf("Author Name: %s\n\n", books[i].author_name);
            
            // Displaying the bookmarks
            bookmark_count = 0;
            for(j=0;j<MAX_BOOKMARKS;j++){
                if(strlen(books[i].bookmarks[j]) > 0){
                    printf("- %s (Page %d)\n", books[i].bookmarks[j], books[i].bookmark_pages[j]);
                    bookmark_count++;
                }
            }
            
            if(bookmark_count == 0){
                printf("No bookmarks found.\n");
            }
            
            printf("\n\n");
        }
    }
}

int main(){
    // Initializing variables
    Book books[10];
    int choice, book_count=0;
    
    // Displaying the menu
    display_menu();
    
    // Receiving user input
    while(1){
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                add_book(books, &book_count);
                break;
            case 2:
                view_book(books, book_count);
                break;
            case 3:
                add_bookmark(books, book_count);
                break;
            case 4:
                view_bookmarks(books, book_count);
                break;
            case 5:
                printf("Thank you for using Ebook Reader!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    
    return 0;
}