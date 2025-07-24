//FormAI DATASET v1.0 Category: Online Examination System ; Style: Romeo and Juliet
/** 
 * Forsooth, lo! A program for testing one's wit and wisdom in the ways of C.
 * Yonder online examination system shall be built for this noble purpose.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Declare our arrays of questions and answers */
const char *questions[] = {
    "What is the difference between a char and an int?",
    "What are types of loops in C?",
    "What is a pointer in C?",
    "What is a function?",
    "What is recursion?"
};

const char *answers[] = {
    "A char holds a single character, while an int holds a number.",
    "C has three types of loops: for, while, and do-while.",
    "A pointer is a variable that holds a memory address.",
    "A function is a block of code that can be called from elsewhere in a program.",
    "Recursion is when a function calls itself."
};

/* Declare a function to shuffle our questions and answers */ 
void shuffle(char **array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        size_t j = i + rand() / (RAND_MAX / (size - i) + 1);
        char *temp = array[j];
        array[j] = array[i];
        array[i] = temp;
    }
}

int main() {
    int num_questions = sizeof(questions) / sizeof(questions[0]);

    printf("Welcome, gentle examinee, to our online examination system!\n");
    printf("Our fair questions shall test thy knowledge of C, so be thou prepared.\n");

    /* Shuffle our questions and answers so they appear in a random order */
    srand(time(NULL));
    shuffle((char **)questions, num_questions);
    shuffle((char **)answers, num_questions);

    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        printf("\nQuestion %d: %s\n", i+1, questions[i]);
        printf("Answer: ");
        char user_answer[1024];
        fgets(user_answer, sizeof(user_answer), stdin);
        user_answer[strcspn(user_answer, "\n")] = '\0'; /* Remove newline character */

        if (strcmp(user_answer, answers[i]) == 0) {
            printf("Verily, thou hast answered correctly!\n");
            score++;
        } else {
            printf("Alas, thy answer is not correct. The answer is: %s\n", answers[i]);
        }
    }

    printf("\nThou hast completed the examination with a score of %d out of %d.\n", score, num_questions);
    printf("Farewell, and good luck on thy journey through the world of C!\n");

    return 0;
}