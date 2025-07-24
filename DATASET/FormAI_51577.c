//FormAI DATASET v1.0 Category: Ebook reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the maximum number of threads
#define MAX_THREADS 10

// Initialize the mutex lock globally
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Create a struct for the Ebook
typedef struct Ebook {
   char title[50];
   char author[50];
   char filename[50];
   int page_count;
} Ebook;

// Define the Ebook reader thread function
void *ebook_reader(void *arg) {
   Ebook *book = (Ebook *) arg;
   pthread_mutex_lock(&mutex);
   printf("\nReading Ebook \"%s\" by %s...\n", book->title, book->author);
   printf("Page 1/%d\n", book->page_count);
   for(int i = 2; i <= book->page_count; i++) {
      printf("Page %d/%d\n", i, book->page_count);
   }
   printf("Finished reading Ebook \"%s\" by %s.\n", book->title, book->author);
   pthread_mutex_unlock(&mutex);
   return NULL;
}

// Define the main function
int main() {
   // Declare an array of Ebook structs
   Ebook books[MAX_THREADS];
   
   // Populate the array with sample data
   strcpy(books[0].title, "The Catcher in the Rye");
   strcpy(books[0].author, "J.D. Salinger");
   strcpy(books[0].filename, "catcher.txt");
   books[0].page_count = 100;

   strcpy(books[1].title, "To Kill a Mockingbird");
   strcpy(books[1].author, "Harper Lee");
   strcpy(books[1].filename, "mockingbird.txt");
   books[1].page_count = 200;
 
   // Declare an array of thread IDs for the Ebook readers
   pthread_t threads[MAX_THREADS];

   // Loop through each Ebook and create a thread to read it
   for(int i = 0; i < MAX_THREADS; i++) {
      if(pthread_create(&threads[i], NULL, ebook_reader, (void *) &books[i]) != 0) {
         perror("Thread creation failed.\n");
         exit(EXIT_FAILURE);
      }
   }

   // Wait for all threads to finish
   for(int i = 0; i < MAX_THREADS; i++) {
      if(pthread_join(threads[i], NULL) != 0) {
         perror("Thread join failed.\n");
         exit(EXIT_FAILURE);
      }
   }

   // Destroy the mutex lock
   pthread_mutex_destroy(&mutex);

   return 0;
}