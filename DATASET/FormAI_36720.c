//FormAI DATASET v1.0 Category: Database Indexing System ; Style: real-life
#include<stdio.h>
#include<string.h>

struct book {
    int bookId;
    char title[50];
    char author[50];
};

struct index {
    int bookId;
    int position;
};

int main() {
    //create an array of books
    struct book library[5] = {
        {1, "1984", "George Orwell"},
        {2, "To Kill a Mockingbird", "Harper Lee"},
        {3, "The Catcher in the Rye", "J.D. Salinger"},
        {4, "Lord of the Flies", "William Golding"},
        {5, "The Great Gatsby", "F. Scott Fitzgerald"}
    };

    //create an array of indexes for efficient searching
    struct index indexes[5];

    //populate the index array based on book ids in the library array
    for(int i=0; i<5; i++) {
        indexes[i].bookId = library[i].bookId;
        indexes[i].position = i;
    }

    //search for a book by its id using the index array
    int id = 3;
    int position = -1;
    for(int i=0; i<5; i++) {
        if(indexes[i].bookId == id) {
            position = indexes[i].position;
            break;
        }
    }
    if(position != -1) {
        printf("Book found at position: %d\n", position);
        printf("Title: %s\n", library[position].title);
        printf("Author: %s\n", library[position].author);
    } else {
        printf("Book not found!\n");
    }

    return 0;
}