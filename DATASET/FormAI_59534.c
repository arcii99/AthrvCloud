//FormAI DATASET v1.0 Category: Ebook reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char title[50];
    char author[50];
    int year;
    char filename[50];
}Book;

typedef struct{
    int size;
    Book *books;
}Library;

typedef struct{
    char chapter_title[50];
    char text[500];
}Chapter;

typedef struct{
    int size;
    Chapter *chapters;
}BookContent;

void display_menu(){
    printf("Menu\n");
    printf("1. View Library\n");
    printf("2. Read Book\n");
    printf("3. Exit\n");
}

Library create_library(Book *books, int size){
    Library lib;
    lib.books = books;
    lib.size = size;
    return lib;
}

BookContent create_book_content(Chapter *chapters, int size){
    BookContent content;
    content.chapters = chapters;
    content.size = size;
    return content;
}

void print_book(Book book){
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Year: %d\n", book.year);
}

void print_library(Library library){
    for(int i = 0; i < library.size; i++){
        printf("%d. %s by %s (%d)\n", i+1, library.books[i].title, library.books[i].author, library.books[i].year);
    }
}

void print_chapter(Chapter chapter){
    printf("Chapter: %s\n", chapter.chapter_title);
    printf("%s\n", chapter.text);
}

void read_book(Book book){
    printf("Opening book: %s...\n", book.title);
    FILE *fp = fopen(book.filename, "r");

    if(fp == NULL){
        printf("Error opening file.\n");
        return;
    }

    int num_chapters;
    fscanf(fp, "%d", &num_chapters);
    Chapter chapters[num_chapters];

    for(int i = 0; i < num_chapters; i++){
        char title[50];
        char text[500];
        fscanf(fp, "%s", title);

        fgets(text, 500, fp);
        fgets(text, 500, fp);

        Chapter chapter;
        strcpy(chapter.chapter_title, title);
        strcpy(chapter.text, text);

        chapters[i] = chapter;
    }

    BookContent content = create_book_content(chapters, num_chapters);

    for(int i = 0; i < content.size; i++){
        print_chapter(content.chapters[i]);
    }

    fclose(fp);
}

int main(){
    Book books[3];
    strcpy(books[0].title, "The Great Gatsby");
    strcpy(books[0].author, "F. Scott Fitzgerald");
    books[0].year = 1925;
    strcpy(books[0].filename, "great_gatsby.txt");

    strcpy(books[1].title, "To Kill a Mockingbird");
    strcpy(books[1].author, "Harper Lee");
    books[1].year = 1960;
    strcpy(books[1].filename, "mockingbird.txt");

    strcpy(books[2].title, "1984");
    strcpy(books[2].author, "George Orwell");
    books[2].year = 1949;
    strcpy(books[2].filename, "1984.txt");

    Library library = create_library(books, 3);
    int choice;

    do{
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                print_library(library);
                break;
            case 2:
                int book_choice;
                print_library(library);
                printf("Enter the number of the book to read: ");
                scanf("%d", &book_choice);
                read_book(library.books[book_choice-1]);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }while(choice != 3);

    return 0;
}