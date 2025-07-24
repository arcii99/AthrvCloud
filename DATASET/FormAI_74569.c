//FormAI DATASET v1.0 Category: Online Examination System ; Style: multi-threaded
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

/* Global variables */
int questions[10] = {1,2,3,4,5,6,7,8,9,10};
char answers[10] = {'A','B','C','D','A','B','C','D','A','B'};
char student_answers[10];
int index = 0;
int score = 0;

/* Function declarations */
void *take_test(void *arg);
void *submit_test(void *arg);

int main()
{
    /* Thread identifiers */
    pthread_t tid1, tid2;

    /* Create threads */
    pthread_create(&tid1, NULL, take_test, NULL);
    pthread_create(&tid2, NULL, submit_test, NULL);

    /* Wait for threads to finish */
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    /* Print student's score */
    printf("Congratulations! You have scored %d out of 10.\n", score);

    return 0;
}

/* This function displays the questions and collects the student's answers */
void *take_test(void *arg)
{
    /* Local variables */
    int i;

    printf("Welcome to the Online Examination System!\n\n");

    /* Display questions and collect answers */
    for(i = 0; i < 10; i++)
    {
        printf("Q%d. What is the capital of France?\n", questions[i]);
        printf("A. London      B. Berlin\n");
        printf("C. Rome        D. Paris\n");
        printf("Your answer: ");
        scanf(" %c", &student_answers[i]);
        printf("\n");
    }

    /* Exit thread */
    pthread_exit(NULL);
}

/* This function calculates the student's score */
void *submit_test(void *arg)
{
    /* Local variables */
    int i;

    /* Wait for student to finish taking test */
    sleep(60);

    /* Calculate student's score */
    for(i = 0; i < 10; i++)
    {
        if(student_answers[i] == answers[i])
        {
            score++;
        }
    }

    /* Exit thread */
    pthread_exit(NULL);
}