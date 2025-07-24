//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define NUM_ELEMENTS 118

typedef struct {
    char symbol[3];
    char name[25];
    int atomic_num;
    double atomic_weight;
} Element;

void init_elements(Element arr[]);
int get_num_correct(char user_input[], char correct_answers[]);
void print_results(int num_correct, int total_questions);

int main(void) {
    Element elements[NUM_ELEMENTS];
    char user_answer[5];
    char correct_answers[NUM_ELEMENTS][3];
    int i, j, num_correct = 0, total_questions = 0;

    init_elements(elements);

    /* Generate array of correct answers */
    for(i = 0; i < NUM_ELEMENTS; i++) {
        strncpy(correct_answers[i], elements[i].symbol, 3);
    }

    /* Shuffle elements array to present questions in random order */
    srand(time(NULL));
    for(i = NUM_ELEMENTS - 1; i > 0; i--) {
        j = rand() % (i + 1);
        Element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }

    /* Loop through elements array to present quiz questions */
    for(i = 0; i < NUM_ELEMENTS; i++) {
        printf("What is the chemical symbol for %s? ", elements[i].name);
        fgets(user_answer, 5, stdin);
        /* Convert user answer to uppercase */
        for(j = 0; j < strlen(user_answer); j++) {
            user_answer[j] = toupper(user_answer[j]);
        }
        num_correct += get_num_correct(user_answer, correct_answers[i]);
        total_questions++;
    }

    print_results(num_correct, total_questions);

    return 0;
}

/* Initializes elements array with data from periodic table */
void init_elements(Element arr[]) {
    strcpy(arr[0].symbol, "H");
    strcpy(arr[0].name, "Hydrogen");
    arr[0].atomic_num = 1;
    arr[0].atomic_weight = 1.008;

    /* Continued initialization for all elements in periodic table */
    /* ... */
    /* ... */
}

/* Compares user input to correct answer and returns number correct */
int get_num_correct(char user_input[], char correct_answers[]) {
    if(strcmp(user_input, correct_answers) == 0) {
        printf("Correct!\n");
        return 1;
    }
    else {
        printf("Incorrect! The correct answer is %s.\n", correct_answers);
        return 0;
    }
}

/* Prints results of quiz */
void print_results(int num_correct, int total_questions) {
    double percent_correct;
    if(total_questions == 0) {
        percent_correct = 0.0;
    }
    else {
        percent_correct = (double) num_correct / total_questions * 100;
    }
    printf("You answered %d out of %d questions correctly (%.2f%%).\n", num_correct, total_questions, percent_correct);
}