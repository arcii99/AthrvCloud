//FormAI DATASET v1.0 Category: Ebook reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>

struct Book {
    int book_id;
    char book_title[50];
    char author_name[50];
    char ebook_file_name[50];
};

int main() {
    int num_books;
    printf("Enter the number of books to add: ");
    scanf("%d", &num_books);
    
    struct Book *library = (struct Book *) malloc(num_books * sizeof(struct Book));
    
    for(int i=0; i<num_books; i++) {
        printf("Enter the ID of Book %d: ", i+1);
        scanf("%d", &library[i].book_id);
        printf("Enter the Title of Book %d: ", i+1);
        scanf("%s", library[i].book_title);
        printf("Enter the Author of Book %d: ", i+1);
        scanf("%s", library[i].author_name);
        printf("Enter the EBook file name of Book %d: ", i+1);
        scanf("%s", library[i].ebook_file_name);
    }
    
    int book_id_to_read;
    printf("Enter the Book ID to read: ");
    scanf("%d", &book_id_to_read);
    
    for(int i=0; i<num_books; i++) {
        if(library[i].book_id == book_id_to_read) {
            printf("Opening the ebook reader...\n");
            printf("Title: %s\n", library[i].book_title);
            printf("Author: %s\n", library[i].author_name);
            printf("EBook File Name: %s\n", library[i].ebook_file_name);
            // Code to open the ebook file and display it
            printf("Closing the ebook reader...\n");
            return 0;
        }
    }
    
    printf("Book ID not found!\n");
    return 0;
}