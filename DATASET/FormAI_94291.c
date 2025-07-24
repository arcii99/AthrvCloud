//FormAI DATASET v1.0 Category: Ebook reader ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_BOOKS 20

typedef struct {
    char* title;
    char* author;
    int num_pages;
    char* file_path;
} Book;

typedef struct {
    int num_books;
    Book* books[MAX_BOOKS];
} Library;

typedef struct {
    char* book_title;
    char* file_path;
} EbookReaderRequest;

char* read_file(char* file_path) {
    FILE* file = fopen(file_path, "r");
    if (file) {
        fseek(file, 0, SEEK_END);
        long file_size = ftell(file);
        fseek(file, 0, SEEK_SET);
        char* buffer = (char*) malloc(file_size);
        if (buffer) {
            fread(buffer, 1, file_size, file);
        }
        fclose(file);
        return buffer;
    }
    return NULL;
}

void* read_ebook(void* arg) {
    EbookReaderRequest* request = (EbookReaderRequest*) arg;
    printf("Reading book: %s\n", request->book_title);
    char* book_contents = read_file(request->file_path);
    if (book_contents) {
        printf("Contents of %s:\n%s\n", request->book_title, book_contents);
        free(book_contents);
    } else {
        printf("Could not read book: %s\n", request->book_title);
    }
    free(request->book_title);
    free(request->file_path);
    free(request);
    pthread_exit(NULL);
}

void request_ebook(char* book_title, char* file_path) {
    EbookReaderRequest* request = (EbookReaderRequest*) malloc(sizeof(EbookReaderRequest));
    request->book_title = malloc(strlen(book_title) + 1);
    strcpy(request->book_title, book_title);
    request->file_path = malloc(strlen(file_path) + 1);
    strcpy(request->file_path, file_path);
    pthread_t tid;
    pthread_create(&tid, NULL, read_ebook, (void*) request);
}

int main() {
    Library lib = {
        .num_books = 3,
        .books = {
            &(Book){ "The Great Gatsby", "F. Scott Fitzgerald", 180, "./books/great_gatsby.txt" },
            &(Book){ "To Kill a Mockingbird", "Harper Lee", 281, "./books/to_kill_a_mockingbird.txt" },
            &(Book){ "1984", "George Orwell", 328, "./books/1984.txt" }
        }
    };
    for (int i = 0; i < lib.num_books; i++) {
        request_ebook(lib.books[i]->title, lib.books[i]->file_path);
    }
    pthread_exit(NULL);
}