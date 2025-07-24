//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// maximum buffer size for text
#define BUFFER_SIZE 100000

// maximum number of sentences in summarized text
#define MAX_SENTENCES 5

// mutex for accessing buffer and summary
pthread_mutex_t mutex;

// condition variable for signaling when new text is available
pthread_cond_t new_text_available;

// condition variable for signaling when new summary is available
pthread_cond_t new_summary_available;

// buffer for storing input text
char buffer[BUFFER_SIZE];

// summary of input text
char summary[BUFFER_SIZE];

// flag for indicating if new text is available for summarizing
int new_text_flag = 0;

// flag for indicating if new summary is available
int new_summary_flag = 0;

// function for summarizing text
void summarize(char *input_text, char *output_summary) {
    // tokenize input text into sentences
    char *sentence = strtok(input_text, ".!?");
    
    // array for storing pointers to sentences
    char *sentences[MAX_SENTENCES];
    int num_sentences = 0;
    
    // loop through sentences and add to array
    while (sentence != NULL && num_sentences < MAX_SENTENCES) {
        sentences[num_sentences++] = sentence;
        sentence = strtok(NULL, ".!?");
    }
    
    // concatenate sentences to form summary
    int i;
    int summary_size = 0;
    for (i = 0; i < num_sentences; i++) {
        strncat(output_summary, sentences[i], BUFFER_SIZE - summary_size);
        summary_size = strlen(output_summary);
    }
}

// function for reading input text from user
void *read_text(void *arg) {
    // loop until user enters valid text
    while (1) {
        // lock mutex before accessing buffer
        pthread_mutex_lock(&mutex);
        
        // prompt user to enter text
        printf("Enter text to summarize:\n");
        fgets(buffer, BUFFER_SIZE, stdin);
        
        // check if input is valid
        if (strlen(buffer) > 1) {
            // set flag to indicate new text is available
            new_text_flag = 1;
            
            // signal new text available to other threads
            pthread_cond_signal(&new_text_available);
            
            // unlock mutex before exiting
            pthread_mutex_unlock(&mutex);
            return NULL;
        }
        
        // unlock mutex before looping
        pthread_mutex_unlock(&mutex);
    }
}

// function for summarizing input text
void *summarize_text(void *arg) {
    // loop forever
    while (1) {
        // lock mutex before accessing flags and buffers
        pthread_mutex_lock(&mutex);
        
        // wait for new text to be available
        while (!new_text_flag) {
            pthread_cond_wait(&new_text_available, &mutex);
        }
        
        // set flag to indicate new summary is not available yet
        new_summary_flag = 0;
        
        // summarize input text
        summarize(buffer, summary);
        
        // set flag to indicate new summary is available
        new_summary_flag = 1;
        
        // signal new summary available to other threads
        pthread_cond_signal(&new_summary_available);
        
        // reset flag to indicate no new text is available
        new_text_flag = 0;
        
        // unlock mutex before looping
        pthread_mutex_unlock(&mutex);
    }
}

// function for displaying summary
void *display_summary(void *arg) {
    // loop forever
    while (1) {
        // lock mutex before accessing flags and buffers
        pthread_mutex_lock(&mutex);
        
        // wait for new summary to be available
        while (!new_summary_flag) {
            pthread_cond_wait(&new_summary_available, &mutex);
        }
        
        // display summary
        printf("Summary:\n%s\n", summary);
        
        // reset flag to indicate no new summary is available
        new_summary_flag = 0;
        
        // unlock mutex before looping
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    // initialize mutex and condition variables
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&new_text_available, NULL);
    pthread_cond_init(&new_summary_available, NULL);
    
    // create threads for reading input text, summarizing, and displaying summary
    pthread_t read_thread, summarize_thread, display_thread;
    pthread_create(&read_thread, NULL, read_text, NULL);
    pthread_create(&summarize_thread, NULL, summarize_text, NULL);
    pthread_create(&display_thread, NULL, display_summary, NULL);
    
    // wait for threads to complete
    pthread_join(read_thread, NULL);
    pthread_join(summarize_thread, NULL);
    pthread_join(display_thread, NULL);
    
    // destroy mutex and condition variables
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&new_text_available);
    pthread_cond_destroy(&new_summary_available);
    
    return 0;
}