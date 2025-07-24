//FormAI DATASET v1.0 Category: Ebook reader ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 50
#define MAX_CHAPTER_LENGTH 1000
#define MAX_BOOK_LENGTH 100

typedef struct chapter {
    int chapter_number;
    char chapter_title[MAX_TITLE_LENGTH];
    char content[MAX_CHAPTER_LENGTH];
} Chapter;

typedef struct book {
    char title[MAX_TITLE_LENGTH];
    int num_chapters;
    Chapter chapters[MAX_BOOK_LENGTH];
} Book;

char* generate_password(){
    char password[10];

    srand(time(NULL));

    for(int i=0; i<10; i++){
        password[i] = "abcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"[rand() % 62];
    }

    return password;
}

void read_book(Book* book){
    printf("Enter the title of the book: ");
    fgets(book->title, MAX_TITLE_LENGTH, stdin);
    printf("\n");

    printf("Enter the number of chapters: ");
    scanf("%d", &book->num_chapters);

    for(int i=0; i<book->num_chapters; i++){
        book->chapters[i].chapter_number = i+1;

        printf("\nEnter the title of chapter %d: ", i+1);
        fgets(book->chapters[i].chapter_title, MAX_TITLE_LENGTH, stdin);

        printf("\nEnter the content of chapter %d: ", i+1);
        fgets(book->chapters[i].content, MAX_CHAPTER_LENGTH, stdin);
    }

}

void print_book(Book book){
    printf("Title: %s\n", book.title);
    printf("Number of chapters: %d\n\n", book.num_chapters);

    for(int i=0; i<book.num_chapters; i++){
        printf("Chapter %d - %s\n\n", book.chapters[i].chapter_number, book.chapters[i].chapter_title);
        printf("%s", book.chapters[i].content);
    }
}

int main(){
    char password[10];
    strcpy(password, generate_password());

    printf("Welcome to the Ebook reader program.\n");
    printf("Please enter the password to access the programs features (Default password: %s): ", password);

    char user_password[10];
    scanf("%s", user_password);

    if(strcmp(user_password, password) != 0){
        printf("Incorrect password entered. Aborting program.");
        exit(EXIT_FAILURE);
    }

    char choice = 'a';
    Book book;

    while(choice != 'q'){
        printf("\n\na - Read a book\n");
        printf("b - Add a book\n");
        printf("q - Quit program\n");

        printf("\n\nPlease enter your choice: ");
        scanf(" %c", &choice);

        switch(choice){
            case 'a':
                print_book(book);
                break;
            case 'b':
                read_book(&book);
                break;
            case 'q':
                printf("Thank you for using Ebook reader.");
                break;
            default:
                printf("Invalid choice entered. Try again.");
        }
    }

    return 0;
}