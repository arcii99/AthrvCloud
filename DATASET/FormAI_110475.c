//FormAI DATASET v1.0 Category: Online Examination System ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 4

// The exam questions
char *questions[] = {
    "What is the capital city of France?",
    "What is the largest continent in the world?",
    "What is the formula for the area of a circle?",
    "What is the command to list files in a directory?"
};

// The correct answers
char *answers[] = {
    "Paris",
    "Asia",
    "Pi * r^2",
    "ls"
};

// The user's answers
char *user_answers[NUM_THREADS];

// The score
int score = 0;

// The thread function to administer the exam
void *administer_exam(void *arg) {
    int id = *(int *) arg;

    printf("Question %d: %s\n", id+1, questions[id]);
    printf("Answer: ");
    scanf("%s", user_answers[id]);

    pthread_exit(NULL);
}

// The thread function to grade the exam
void *grade_exam(void *arg) {
    for (int i = 0; i < NUM_THREADS; i++) {
        if (strcmp(user_answers[i], answers[i]) == 0) {
            score++;
        }
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Initialize user_answers array
    for (int i = 0; i < NUM_THREADS; i++) {
        user_answers[i] = (char *) malloc(50 * sizeof(char));
    }

    // Create threads to administer exam
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, administer_exam, &thread_ids[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Create thread to grade exam
    pthread_t grade_thread;
    pthread_create(&grade_thread, NULL, grade_exam, NULL);
    pthread_join(grade_thread, NULL);

    printf("Your score is: %d/%d\n", score, NUM_THREADS);

    // Free memory
    for (int i = 0; i < NUM_THREADS; i++) {
        free(user_answers[i]);
    }
    
    return 0;
}