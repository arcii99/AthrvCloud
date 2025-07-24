//FormAI DATASET v1.0 Category: Database Indexing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for maximum length of title and author strings
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50

// Define structure for storing book information
struct book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;
};

// Define structure for storing index information
struct index {
    char key[MAX_TITLE_LENGTH];
    int offset;
};

// Define function prototypes
int search(struct index[], int, char[]);
void insert_index(struct index[], int*, char[], int);
void print_index(struct index[], int);
void print_books(FILE*, struct index[], int);

int main() {
    FILE *fp;
    struct book b;
    struct index index_list[1000];
    int num_index = 0;

    // Open file for writing
    fp = fopen("books.bin", "wb");

    // Check if file was opened successfully
    if (fp == NULL) {
        printf("Error: could not open file for writing\n");
        exit(1);
    }

    // Add some books to the file
    strcpy(b.title, "A Tale of Two Cities");
    strcpy(b.author, "Charles Dickens");
    b.year = 1859;
    fwrite(&b, sizeof(struct book), 1, fp);

    strcpy(b.title, "Pride and Prejudice");
    strcpy(b.author, "Jane Austen");
    b.year = 1813;
    fwrite(&b, sizeof(struct book), 1, fp);

    strcpy(b.title, "To Kill a Mockingbird");
    strcpy(b.author, "Harper Lee");
    b.year = 1960;
    fwrite(&b, sizeof(struct book), 1, fp);

    strcpy(b.title, "1984");
    strcpy(b.author, "George Orwell");
    b.year = 1949;
    fwrite(&b, sizeof(struct book), 1, fp);

    // Add index entries for each book
    insert_index(index_list, &num_index, "A Tale of Two Cities", 0);
    insert_index(index_list, &num_index, "Pride and Prejudice", sizeof(struct book));
    insert_index(index_list, &num_index, "To Kill a Mockingbird", 2 * sizeof(struct book));
    insert_index(index_list, &num_index, "1984", 3 * sizeof(struct book));
    
    // Print index entries
    print_index(index_list, num_index);

    // Print all books
    print_books(fp, index_list, num_index);

    // Close file
    fclose(fp);

    return 0;
}

// Function to search for a key in the index
int search(struct index index_list[], int num_index, char key[]) {
    int i;
    for (i = 0; i < num_index; i++) {
        if (strcmp(index_list[i].key, key) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to insert a new index entry
void insert_index(struct index index_list[], int *num_index, char key[], int offset) {
    int pos = search(index_list, *num_index, key);
    if (pos == -1) {
        // Key not found, so add new entry
        strcpy(index_list[*num_index].key, key);
        index_list[*num_index].offset = offset;
        (*num_index)++;
    } else {
        // Key already exists, so update offset
        index_list[pos].offset = offset;
    }
}

// Function to print all index entries
void print_index(struct index index_list[], int num_index) {
    int i;
    printf("Index entries:\n");
    for (i = 0; i < num_index; i++) {
        printf("%s: %d\n", index_list[i].key, index_list[i].offset);
    }
}

// Function to print all books
void print_books(FILE *fp, struct index index_list[], int num_index) {
    int i, j;
    struct book b;

    printf("Books:\n");
    for (i = 0; i < num_index; i++) {
        // Seek to offset of book
        fseek(fp, index_list[i].offset, SEEK_SET);
        // Read book information
        fread(&b, sizeof(struct book), 1, fp);
        // Print book information
        printf("%s by %s (%d)\n", b.title, b.author, b.year);
    }
}