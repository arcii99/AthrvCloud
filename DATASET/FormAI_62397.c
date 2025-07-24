//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 50
#define MAX_QUESTIONS 10
#define NUM_ELEMENTS 118

typedef struct {
    char symbol[3];
    char name[MAX_NAME_LEN];
    int atomic_number;
} element;

element periodic_table[NUM_ELEMENTS] = {
        {"H", "Hydrogen", 1},
        {"He", "Helium", 2},
        {"Li", "Lithium", 3},
        {"Be", "Beryllium", 4},
        {"B", "Boron", 5},
        {"C", "Carbon", 6},
        {"N", "Nitrogen", 7},
        {"O", "Oxygen", 8},
        {"F", "Fluorine", 9},
        {"Ne", "Neon", 10},
        // etc...
};

void fetch_questions(int q_indices[], int num_questions) {
    for (int i = 0; i < num_questions; i++) {
        q_indices[i] = rand() % NUM_ELEMENTS;
    }
}

int get_correct_choice(int atomic_number) {
    printf("What is the correct choice for atomic number %d?\n", atomic_number);
    printf("\tA. %d\n", atomic_number - 1);
    printf("\tB. %d\n", atomic_number);
    printf("\tC. %d\n", atomic_number + 1);
    
    char choice[2];
    scanf("%s", choice);
    while (strcmp(choice, "A") != 0 && strcmp(choice, "B") != 0 && strcmp(choice, "C") != 0) {
        printf("Invalid choice. Please enter A, B, or C.\n");
        scanf("%s", choice);
    }
    
    return (strcmp(choice, "B") == 0);
}

int score_quiz(int num_questions) {
    int score = 0;
    int q_indices[num_questions];
    fetch_questions(q_indices, num_questions);
    
    for (int i = 0; i < num_questions; i++) {
        int index = q_indices[i];
        printf("Question %d: What is the atomic number for %s?\n", i+1, periodic_table[index].name);
        
        if (get_correct_choice(periodic_table[index].atomic_number)) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer was %d.\n", periodic_table[index].atomic_number);
        }
    }
    
    return score;
}

void print_table() {
    printf("Periodic Table:\n");
    printf("----------------------------------------------------\n");
    printf("|  Symbol  |          Name          | Atomic Number |\n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        printf("|    %s    | %20s |       %3d     |\n", periodic_table[i].symbol, periodic_table[i].name, periodic_table[i].atomic_number);
    }
    printf("----------------------------------------------------\n");
}

int main() {
    srand(time(NULL));
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions about the elements on the periodic table.\n", MAX_QUESTIONS);
    printf("For each question, there will be three choices: A, B, and C.\n");
    printf("Each question is worth one point.\n");
    printf("Let's begin!\n\n");
    
    int score = score_quiz(MAX_QUESTIONS);
    printf("\nYour score is %d out of %d.\n\n", score, MAX_QUESTIONS);
    print_table();
    
    return 0;
}