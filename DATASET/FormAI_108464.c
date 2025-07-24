//FormAI DATASET v1.0 Category: Online Examination System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_QUESTIONS 10
#define NUM_THREADS 4

int score = 0;

typedef struct {
    int q_num;
    char q_text[100];
    char choices[4][50];
    int ans_index;
} Question;

Question questions[NUM_QUESTIONS] = {
    {1, "What is the capital of France?", {"A. Paris", "B. Berlin", "C. Madrid", "D. London"}, 0},
    {2, "What is the largest planet in our solar system?", {"A. Venus", "B. Neptune", "C. Jupiter", "D. Mars"}, 2},
    {3, "What year did World War II end?", {"A. 1945", "B. 1939", "C. 1918", "D. 1914"}, 0},
    {4, "What is the fastest land animal?", {"A. Elephant", "B. Cheetah", "C. Rhino", "D. Hippo"}, 1},
    {5, "What is the smallest country in the world?", {"A. Monaco", "B. Vatican City", "C. San Marino", "D. Liechtenstein"}, 1},
    {6, "What is the name of the highest mountain in Africa?", {"A. Kilimanjaro", "B. Mount Everest", "C. Mount Elbrus", "D. Mont Blanc"}, 0},
    {7, "Who painted the Mona Lisa?", {"A. Leonardo da Vinci", "B. Michelangelo", "C. Rembrandt", "D. Van Gogh"}, 0},
    {8, "What is the chemical symbol for gold?", {"A. Go", "B. Gu", "C. Ge", "D. Au"}, 3},
    {9, "What is the largest mammal in the world?", {"A. Dolphin", "B. Blue whale", "C. Rhino", "D. Elephant"}, 1},
    {10, "What is the capital of Japan?", {"A. Beijing", "B. Shanghai", "C. Tokyo", "D. Hong Kong"}, 2}
};

void *run_exam(void *id)
{
    int q_per_thread = NUM_QUESTIONS / NUM_THREADS;
    int start_index = ((int)id - 1) * q_per_thread;
    int end_index = start_index + q_per_thread;
    if ((int)id == NUM_THREADS) end_index = NUM_QUESTIONS;

    for (int i = start_index; i < end_index; i++)
    {
        char response;
        printf("\nQuestion %d: %s\n", questions[i].q_num, questions[i].q_text);
        printf("%s\n%s\n%s\n%s\n", questions[i].choices[0], questions[i].choices[1], questions[i].choices[2], questions[i].choices[3]);
        printf("Enter your answer: ");
        scanf("%c", &response);
        getchar();
        if (response == 'A' || response == 'a') {
            if (questions[i].ans_index == 0) score++;
        }
        else if (response == 'B' || response == 'b') {
            if (questions[i].ans_index == 1) score++;
        }
        else if (response == 'C' || response == 'c') {
            if (questions[i].ans_index == 2) score++;
        }
        else if (response == 'D' || response == 'd') {
            if (questions[i].ans_index == 3) score++;
        }
    }

    pthread_exit(NULL);
}

int main()
{
    srand(time(NULL));

    // shuffle questions array
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        int j = rand() % NUM_QUESTIONS;
        Question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }

    // create threads and run exam
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        int thread_id = i + 1;
        pthread_create(&threads[i], NULL, run_exam, (void *)thread_id);
    }

    // join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // calculate score and output result
    float percentage = ((float)score / NUM_QUESTIONS) * 100;
    printf("\nExam complete. You answered %d questions correctly out of %d.\n", score, NUM_QUESTIONS);
    printf("Your score is %.2f%%.\n", percentage);

    return 0;
}