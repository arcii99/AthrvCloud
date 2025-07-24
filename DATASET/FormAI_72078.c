//FormAI DATASET v1.0 Category: Ebook reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define book structure
struct Book {
    char title[50];
    char author[50];
    int pages;
};

// Define ebook structure, which inherits from book
struct Ebook {
    struct Book book;
    char file[50];
    int size;
};

// Function to read ebook
void read_ebook(struct Ebook ebook) {
    printf("Title: %s\n", ebook.book.title);
    printf("Author: %s\n", ebook.book.author);
    printf("Pages: %d\n", ebook.book.pages);
    printf("File: %s\n", ebook.file);
    printf("Size: %d KB\n", ebook.size);
    printf("Start Reading!\n");
    
    // Code to read ebook goes here
}

int main() {
    struct Ebook ebooks[10]; // Array of 10 ebooks
    
    // Initialize ebooks
    
    // Ebook 1
    strcpy(ebooks[0].book.title, "The Hitchhiker's Guide to the Galaxy");
    strcpy(ebooks[0].book.author, "Douglas Adams");
    ebooks[0].book.pages = 224;
    strcpy(ebooks[0].file, "hitchhikers_guide.pdf");
    ebooks[0].size = 1024;
    
    // Ebook 2
    strcpy(ebooks[1].book.title, "1984");
    strcpy(ebooks[1].book.author, "George Orwell");
    ebooks[1].book.pages = 328;
    strcpy(ebooks[1].file, "1984.epub");
    ebooks[1].size = 512;
    
    // Ebook 3
    strcpy(ebooks[2].book.title, "Harry Potter and the Sorcerer's Stone");
    strcpy(ebooks[2].book.author, "J.K. Rowling");
    ebooks[2].book.pages = 309;
    strcpy(ebooks[2].file, "harry_potter_mobi.mobi");
    ebooks[2].size = 2048;
    
    // Ebook 4
    strcpy(ebooks[3].book.title, "The Lord of the Rings");
    strcpy(ebooks[3].book.author, "J.R.R. Tolkien");
    ebooks[3].book.pages = 1178;
    strcpy(ebooks[3].file, "lord_of_the_rings.txt");
    ebooks[3].size = 4096;
    
    // Ebook 5
    strcpy(ebooks[4].book.title, "To Kill a Mockingbird");
    strcpy(ebooks[4].book.author, "Harper Lee");
    ebooks[4].book.pages = 281;
    strcpy(ebooks[4].file, "to_kill_a_mockingbird.pdf");
    ebooks[4].size = 1024;
    
    // Ebook 6
    strcpy(ebooks[5].book.title, "Pride and Prejudice");
    strcpy(ebooks[5].book.author, "Jane Austen");
    ebooks[5].book.pages = 424;
    strcpy(ebooks[5].file, "pride_and_prejudice.epub");
    ebooks[5].size = 512;
    
    // Ebook 7
    strcpy(ebooks[6].book.title, "The Great Gatsby");
    strcpy(ebooks[6].book.author, "F. Scott Fitzgerald");
    ebooks[6].book.pages = 180;
    strcpy(ebooks[6].file, "the_great_gatsby_mobi.mobi");
    ebooks[6].size = 2048;
    
    // Ebook 8
    strcpy(ebooks[7].book.title, "The Catcher in the Rye");
    strcpy(ebooks[7].book.author, "J.D. Salinger");
    ebooks[7].book.pages = 234;
    strcpy(ebooks[7].file, "catcher_in_the_rye.txt");
    ebooks[7].size = 4096;
    
    // Ebook 9
    strcpy(ebooks[8].book.title, "The Hobbit");
    strcpy(ebooks[8].book.author, "J.R.R. Tolkien");
    ebooks[8].book.pages = 310;
    strcpy(ebooks[8].file, "the_hobbit.pdf");
    ebooks[8].size = 1024;
    
    // Ebook 10
    strcpy(ebooks[9].book.title, "The Da Vinci Code");
    strcpy(ebooks[9].book.author, "Dan Brown");
    ebooks[9].book.pages = 489;
    strcpy(ebooks[9].file, "da_vinci_code.epub");
    ebooks[9].size = 512;
    
    printf("Welcome to our Ebook Reader! We have %d ebooks available for you to read!\n", sizeof(ebooks)/sizeof(ebooks[0]));
    printf("Enter the number of the ebook you would like to read: ");
    
    int selection;
    scanf("%d", &selection);
    
    if(selection >= 1 && selection <= sizeof(ebooks)/sizeof(ebooks[0])) {
        printf("You selected the ebook '%s' by %s.\n", ebooks[selection-1].book.title, ebooks[selection-1].book.author);
        read_ebook(ebooks[selection-1]);
    }
    else {
        printf("Invalid selection. Please enter a valid number.\n");
    }
    
    return 0;
}