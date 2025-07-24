//FormAI DATASET v1.0 Category: Online Examination System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_QUESTIONS 100
#define NUM_THREADS 4

int questions[MAX_QUESTIONS];
int answers[MAX_QUESTIONS];

void *student(void *tid)
{
    int i;
    int thread_id = *((int *)tid);
    int start = thread_id * MAX_QUESTIONS / NUM_THREADS;
    int end = (thread_id + 1) * MAX_QUESTIONS / NUM_THREADS;

    printf("Student %d starting exam...\n", thread_id);

    for (i = start; i < end; i++)
    {
        printf("Q%d: %d\n", i+1, questions[i]);
        // Get answer from student
        scanf("%d", &answers[i]);
    }

    printf("Student %d finished exam.\n", thread_id);

    pthread_exit(NULL);
}

int main()
{
    int i;
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS] = {0, 1, 2, 3};

    // Generate random questions
    srand(time(NULL));
    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        questions[i] = rand() % 100 + 1;
    }

    // Start exam for each student in a separate thread
    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, student, (void *)&thread_ids[i]);
    }

    // Wait for all threads to finish
    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // Grade exam
    int num_correct = 0;
    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        if (answers[i] == questions[i])
        {
            num_correct++;
        }
    }

    // Print results
    printf("Exam finished. %d out of %d correct answers.\n", num_correct, MAX_QUESTIONS);

    return 0;
}