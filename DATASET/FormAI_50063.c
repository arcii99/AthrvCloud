//FormAI DATASET v1.0 Category: Ebook reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 100

typedef struct {
    int id;
    char* title;
    char* author;
    char* content;
} Ebook;

Ebook library[MAX_SIZE];
int num_ebooks = 0;

pthread_mutex_t mutex;

void* read_ebook(void* args) {
    int ebook_index = *(int*)args;
    Ebook ebook = library[ebook_index];
    printf("Reading ebook: %s\n", ebook.title);
    // display ebook content
    printf("%s", ebook.content);
    // release lock
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    // initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // add some example ebooks to library
    Ebook ebook1 = {1, "The Great Gatsby", "F. Scott Fitzgerald", "This is the ebook content."};
    Ebook ebook2 = {2, "To Kill a Mockingbird", "Harper Lee", "This is another ebook content."};
    library[0] = ebook1;
    library[1] = ebook2;
    num_ebooks = 2;

    // random ebook to read
    int ebook_index = rand() % num_ebooks;

    // acquire lock
    pthread_mutex_lock(&mutex);

    // create thread to read ebook
    pthread_t thread;
    pthread_create(&thread, NULL, read_ebook, &ebook_index);

    // re-acquire lock
    pthread_mutex_lock(&mutex);

    printf("Finished reading ebook.\n");

    // cleanup
    pthread_mutex_destroy(&mutex);

    return 0;
}