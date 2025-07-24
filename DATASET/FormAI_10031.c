//FormAI DATASET v1.0 Category: Online Examination System ; Style: high level of detail
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define NUM_QUESTIONS 10
#define MAX_ANS_LEN 16

struct question {
    char prompt[128];
    char options[4][128];
    int correct_option;
};

struct answer {
    int question_num;
    char user_sel[MAX_ANS_LEN];
};

int main() {
    struct question q[NUM_QUESTIONS] = {
        {"What is the capital of Spain?", {"Madrid", "Barcelona", "Seville", "Valencia"}, 0},
        {"What is the largest planet in our solar system?", {"Jupiter", "Saturn", "Neptune", "Uranus"}, 0},
        {"What is the boiling point of water?", {"100C", "50C", "150C", "200C"}, 0},
        {"Who is the founder of Microsoft?", {"Steve Jobs", "Bill Gates", "Mark Zuckerberg", "Tim Cook"}, 1},
        {"What is the square root of 49?", {"4", "5", "7", "9"}, 2},
        {"What color are most stop signs?", {"Red", "Yellow", "Blue", "Green"}, 0},
        {"What is the most popular pet in the world?", {"Dog", "Cat", "Fish", "Bird"}, 1},
        {"Who is the author of the Harry Potter series?", {"J.K. Rowling", "George R. R. Martin", "Stephen King", "Dan Brown"}, 0},
        {"What is the smallest country in the world?", {"China", "Russia", "Vatican City", "Monaco"}, 2},
        {"What is the highest mountain in the world?", {"Kilimanjaro", "Everest", "Mount Fuji", "Annapurna"}, 1},
    };
    struct answer a[NUM_QUESTIONS];

    srand(time(NULL)); // seed the random number generator

    printf("--- Welcome to the online examination system ---\n\n");

    // present questions in random order
    int order[NUM_QUESTIONS];
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        order[i] = i;
    }
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        int r = rand() % NUM_QUESTIONS;
        int temp = order[i];
        order[i] = order[r];
        order[r] = temp;
    }

    // ask each question and get user's answer
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        printf("%d. %s\n", i+1, q[order[i]].prompt);
        for (int j = 0; j < 4; j++) {
            printf("%c. %s\n", 'A'+j, q[order[i]].options[j]);
        }
        printf("Your answer (A/B/C/D): ");
        char ans[MAX_ANS_LEN];
        scanf("%s", ans);
        strncpy(a[i].user_sel, ans, MAX_ANS_LEN-1); // copy answer into answer struct
        a[i].question_num = order[i];
        printf("\n");
    }

    // show correct answers and user's score
    int score = 0;
    printf("--- Your score ---\n");
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        printf("%d. %s\n", i+1, q[a[i].question_num].prompt);
        printf("   Your answer: %s\n", a[i].user_sel);
        printf("   Correct answer: %s\n", q[a[i].question_num].options[q[a[i].question_num].correct_option]);
        if (strcmp(a[i].user_sel, q[a[i].question_num].options[q[a[i].question_num].correct_option]+2) == 0) {
            score++;
        }
    }
    printf("Your score is %d/%d\n", score, NUM_QUESTIONS);

    printf("\n--- Thank you for using the online examination system ---\n");

    return 0;
}