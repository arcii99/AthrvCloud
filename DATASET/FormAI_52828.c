//FormAI DATASET v1.0 Category: Ebook reader ; Style: Cryptic
#include <stdio.h>

#define MAX_BOOKS 1000

// define Book struct
typedef struct{
    char title[50];
    char author[50];
    char genre[20];
    int pageCount;
    int totalPages;
    char* pages;
}Book;

// define library struct
typedef struct{
    int numBooks;
    Book books[MAX_BOOKS];
}Library;

// define EbookReader struct
typedef struct{
    char* name;
    Book* currentBook;
    Library* library;
}EbookReader;

// EbookReader functions
void showCurrentBook(EbookReader* reader);
void showLibrary(Library* library);
void addBookToLibrary(Library* library, Book book);
void removeBookFromLibrary(Library* library, int index);
void setCurrentBook(EbookReader* reader, int bookIndex);

// main function
int main(){
    // create library
    Library library;
    library.numBooks = 0;
    addBookToLibrary(&library, (Book){"The Catcher in the Rye", "J.D. Salinger", "Fiction", 224, 224, "This is the content of the book."});
    addBookToLibrary(&library, (Book){"To Kill a Mockingbird", "Harper Lee", "Fiction", 281, 281, "This is the content of the book."});
    addBookToLibrary(&library, (Book){"1984", "George Orwell", "Fiction", 328, 328, "This is the content of the book."});

    // create EbookReader
    EbookReader reader;
    reader.name = "John Doe";
    reader.currentBook = NULL;
    reader.library = &library;

    // set current book
    setCurrentBook(&reader, 0);

    // show current book
    showCurrentBook(&reader);

    // show library
    showLibrary(&library);

    // remove book from library
    removeBookFromLibrary(&library, 1);

    // show library
    showLibrary(&library);

    return 0;
}

void showCurrentBook(EbookReader* reader){
    printf("Current Book: %s by %s\n", reader->currentBook->title, reader->currentBook->author);
    printf("Genre: %s\n", reader->currentBook->genre);
    printf("Page Count: %d\n", reader->currentBook->pageCount);
    printf("Total Pages: %d\n", reader->currentBook->totalPages);
    printf("Pages:\n%s\n", reader->currentBook->pages);
}

void showLibrary(Library* library){
    printf("Library:\n");
    for(int i=0; i<library->numBooks; i++){
        printf("%d. %s\n", i+1, library->books[i].title);
    }
}

void addBookToLibrary(Library* library, Book book){
    library->books[library->numBooks] = book;
    library->numBooks++;
}

void removeBookFromLibrary(Library* library, int index){
    for(int i=index; i<library->numBooks-1; i++){
        library->books[i] = library->books[i+1];
    }
    library->numBooks--;
}

void setCurrentBook(EbookReader* reader, int bookIndex){
    reader->currentBook = &reader->library->books[bookIndex];
}