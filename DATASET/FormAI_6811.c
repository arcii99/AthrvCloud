//FormAI DATASET v1.0 Category: Ebook reader ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_FILE_LENGTH 100000

struct Book {
    char title[MAX_TITLE_LENGTH];
    char fileName[MAX_TITLE_LENGTH];
    char content[MAX_FILE_LENGTH];
    int pageCount;
};

void openBook(struct Book* book){
    FILE *fp = fopen(book->fileName, "r");
    if(fp == NULL){
        printf("Error opening book file.\n");
        return;
    } 
    fread(book->content, sizeof(char), MAX_FILE_LENGTH-1, fp);
    fclose(fp);
}

void printPage(struct Book* book, int pageNum){
    int startIndex = (pageNum-1) * MAX_FILE_LENGTH/book->pageCount;
    int endIndex = startIndex + MAX_FILE_LENGTH/book->pageCount;
    printf("%.*s", endIndex-startIndex, book->content+startIndex);
}

int main(){
    // Create a book object
    struct Book book1 = {.title = "The Art of Programming", .fileName = "book1.txt", .pageCount = 50};
    
    // Load the book
    openBook(&book1);
    
    // Print the first page
    printPage(&book1, 1);
    
    return 0;
}