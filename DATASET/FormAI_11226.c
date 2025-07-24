//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10

int main() {
    srand(time(NULL));

    char* elements[] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca"};
    int atomic_numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    int correct_answers = 0;
    int total_questions = 0;

    printf("Welcome to the Periodic Table Quiz!\n");

    while (total_questions < MAX_QUESTIONS) {
        int random_index = rand() % 20;
        char* element = elements[random_index];
        int atomic_number = atomic_numbers[random_index];

        printf("What is the atomic number of %s?\n", element);

        int answer;
        scanf("%d", &answer);

        if (answer == atomic_number) {
            printf("Correct!\n");
            correct_answers++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", atomic_number);
        }

        total_questions++;
    }

    printf("You got %d out of %d questions correct.\n", correct_answers, total_questions);
    
    return 0;
}