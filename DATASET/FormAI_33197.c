//FormAI DATASET v1.0 Category: Ebook reader ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_BOOKS 100
#define MAX_READERS 10

typedef struct {
    char title[50];
    char author[50];
    int year;
    char filename[50];
} Book;

Book library[MAX_BOOKS] = {
    {"The Lord of The Rings: The Fellowship of The Ring", "J.R.R. Tolkien", 1954, "lotr1.pdf"},
    {"The Lord of The Rings: The Two Towers", "J.R.R. Tolkien", 1954, "lotr2.pdf"},
    {"The Lord of The Rings: The Return of The King", "J.R.R. Tolkien", 1955, "lotr3.pdf"},
    {"To Kill A Mockingbird", "Harper Lee", 1960, "mockingbird.pdf"},
    {"1984", "George Orwell", 1949, "1984.pdf"},
    {"Animal Farm", "George Orwell", 1945, "animal_farm.pdf"},
    {"The Catcher in The Rye", "J.D. Salinger", 1951, "catcher.pdf"},
    {"The Great Gatsby", "F. Scott Fitzgerald", 1925, "gatsby.pdf"},
};

int num_books = 8;

typedef struct {
    pthread_t tid;
    int id;
    char book_titles[MAX_BOOKS][50];
    int num_books;
    sem_t sem;
} Reader;

Reader readers[MAX_READERS] = {
    {0, 1, {0}, 0},
    {0, 2, {0}, 0},
    {0, 3, {0}, 0},
    {0, 4, {0}, 0},
    {0, 5, {0}, 0},
    {0, 6, {0}, 0},
    {0, 7, {0}, 0},
    {0, 8, {0}, 0},
    {0, 9, {0}, 0},
    {0, 10, {0}, 0},
};

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t can_read = PTHREAD_COND_INITIALIZER;
pthread_cond_t can_write = PTHREAD_COND_INITIALIZER;
int readers_waiting = 0;
int writer_waiting = 0;
int readers_reading = 0;
int writer_writing = 0;
int book_index = -1;

void *reader_thread(void *arg)
{
    Reader *reader = (Reader *) arg;

    printf("Reader %d started\n", reader->id);

    while (1) {
        // Wait a random amount of time before trying to read
        sleep(rand() % 5);

        // Acquire the reader thread lock
        pthread_mutex_lock(&mutex);

        // Add this reader to the list of readers waiting to enter the library
        readers_waiting++;
        printf("Reader %d is waiting to enter the library\n", reader->id);

        // Wait until there are no writers writing
        while (writer_writing > 0) {
            pthread_cond_wait(&can_read, &mutex);
        }

        // Remove this reader from the list of readers waiting to enter the library
        readers_waiting--;
        printf("Reader %d has entered the library\n", reader->id);

        // Reader is now reading
        readers_reading++;

        // Permit other readers to enter the library if possible
        pthread_cond_broadcast(&can_read);

        // Release the reader thread lock
        pthread_mutex_unlock(&mutex);

        // Wait a random amount of time to simulate reading the book
        sleep(rand() % 10);

        // Acquire the reader thread lock
        pthread_mutex_lock(&mutex);

        // Reader is done reading
        readers_reading--;

        if (readers_reading == 0 && writer_waiting > 0) {
            // If this is the last reader to leave and there are writers waiting,
            // signal the writer thread to start writing
            pthread_cond_signal(&can_write);
        }

        // Release the reader thread lock
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

void *writer_thread(void *arg)
{
    printf("Writer started\n");

    while (1) {
        // Wait a random amount of time before trying to write
        sleep(rand() % 5);

        // Acquire the writer thread lock
        pthread_mutex_lock(&mutex);

        // Add this writer to the list of writers waiting to enter the library
        writer_waiting++;
        printf("Writer is waiting to enter the library\n");

        // Wait until there are no readers reading or writers writing
        while (readers_reading > 0 || writer_writing > 0) {
            pthread_cond_wait(&can_write, &mutex);
        }

        // Remove this writer from the list of writers waiting to enter the library
        writer_waiting--;
        printf("Writer has entered the library\n");

        // Writer is now writing
        writer_writing++;

        // Release the writer thread lock
        pthread_mutex_unlock(&mutex);

        // Simulate writing the book
        printf("Writer is writing the book\n");
        sleep(5);

        // Acquire the writer thread lock
        pthread_mutex_lock(&mutex);

        // Writer is done writing
        writer_writing--;

        // Signal all waiting readers and writers
        pthread_cond_broadcast(&can_read);
        pthread_cond_signal(&can_write);

        // Release the writer thread lock
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

void print_books()
{
    printf("Books in the library:\n");

    for (int i = 0; i < num_books; i++) {
        printf("[%d] %s (%s, %d)\n", i, library[i].title, library[i].author, library[i].year);
    }
}

void add_book()
{
    if (num_books < MAX_BOOKS) {
        printf("Enter book title: ");
        scanf("%s", library[num_books].title);
        printf("Enter book author: ");
        scanf("%s", library[num_books].author);
        printf("Enter book year: ");
        scanf("%d", &library[num_books].year);
        printf("Enter book filename: ");
        scanf("%s", library[num_books].filename);
        num_books++;
        printf("Book added to library.\n");
    }
    else {
        printf("The library is full. No more books can be added.\n");
    }
}

void remove_book()
{
    int index;

    printf("Enter the index of the book to remove: ");
    scanf("%d", &index);

    if (index >= 0 && index < num_books) {
        for (int i = index; i < num_books - 1; i++) {
            library[i] = library[i+1];
        }
        num_books--;
        printf("Book removed from library.\n");
    }
    else {
        printf("Invalid index selected.\n");
    }
}

void list_books(Reader *reader)
{
    printf("Books available to read:\n");

    for (int i = 0; i < num_books; i++) {
        printf("[%d] %s (%s, %d)\n", i, library[i].title, library[i].author, library[i].year);
        strcpy(reader->book_titles[i], library[i].title);
    }

    reader->num_books = num_books;
}

void read_book(Reader *reader)
{
    int index;

    printf("Enter the index of the book to read: ");
    scanf("%d", &index);

    if (index >= 0 && index < num_books) {
        // Acquire the reader thread lock
        pthread_mutex_lock(&mutex);

        // Wait until there are no writers writing
        while (writer_writing > 0) {
            pthread_cond_wait(&can_read, &mutex);
        }

        // Reader is now reading
        readers_reading++;

        // Permit other readers to enter the library if possible
        pthread_cond_broadcast(&can_read);

        // Release the reader thread lock
        pthread_mutex_unlock(&mutex);

        // Print the contents of the selected book
        printf("Opening book: %s (%s, %d)\n", library[index].title, library[index].author, library[index].year);
        printf("------------------------\n");

        char command[100];
        sprintf(command, "open %s", library[index].filename);
        system(command);

        // Wait for the book to be closed before ending the read
        printf("Book has been opened. Press any key to close.\n");
        getchar();
        getchar();

        // Acquire the reader thread lock
        pthread_mutex_lock(&mutex);

        // Reader is done reading
        readers_reading--;

        if (readers_reading == 0 && writer_waiting > 0) {
            // If this is the last reader to leave and there are writers waiting,
            // signal the writer thread to start writing
            pthread_cond_signal(&can_write);
        }

        // Release the reader thread lock
        pthread_mutex_unlock(&mutex);
    }
    else {
        printf("Invalid index selected.\n");
        return;
    }
}

int main(int argc, char **argv)
{
    srand(time(NULL));

    int choice;
    Reader *reader = NULL;

    // Create the reader and writer threads
    printf("Creating reader and writer threads\n");
    pthread_create(&readers[0].tid, NULL, writer_thread, NULL);
    for (int i = 1; i <= MAX_READERS; i++) {
        reader = &readers[i-1];
        pthread_create(&reader->tid, NULL, reader_thread, reader);
    }

    while (1) {
        printf("\n");
        printf("1 - View books\n");
        printf("2 - Add book\n");
        printf("3 - Remove book\n");
        printf("4 - Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_books();
                break;
            case 2:
                add_book();
                break;
            case 3:
                remove_book();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}