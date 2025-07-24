//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Element {
    char symbol[3];
    char name[30];
    int atomic_num;
    float atomic_weight;
} Element;

Element periodic_table[118];

void initialize_table() {
    strcpy(periodic_table[0].symbol, "H");
    strcpy(periodic_table[0].name, "Hydrogen");
    periodic_table[0].atomic_num = 1;
    periodic_table[0].atomic_weight = 1.008f;
    strcpy(periodic_table[1].symbol, "He");
    strcpy(periodic_table[1].name, "Helium");
    periodic_table[1].atomic_num = 2;
    periodic_table[1].atomic_weight = 4.0026f;
    strcpy(periodic_table[2].symbol, "Li");
    strcpy(periodic_table[2].name, "Lithium");
    periodic_table[2].atomic_num = 3;
    periodic_table[2].atomic_weight = 6.94f;
    strcpy(periodic_table[3].symbol, "Be");
    strcpy(periodic_table[3].name, "Beryllium");
    periodic_table[3].atomic_num = 4;
    periodic_table[3].atomic_weight = 9.0122f;
    // and so on for the rest of the periodic table
}

void shuffle_table() {
    srand(time(NULL));
    for (int i = 0; i < 118; i++) {
        int rand_idx = rand() % 118;
        Element temp = periodic_table[i];
        periodic_table[i] = periodic_table[rand_idx];
        periodic_table[rand_idx] = temp;
    }
}

int main() {
    initialize_table();
    shuffle_table();

    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("You will be given the name or symbol of an element and must provide the other.\n");
    printf("Type q to quit at any time.\n");

    char input[30];
    int score = 0;
    int num_questions = 0;
    for (int i = 0; i < 118; i++) {
        printf("\nQuestion #%d:\n", i+1);
        int symbol_or_name = rand() % 2; // 0 = symbol, 1 = name
        if (symbol_or_name == 0) {
            printf("What is the symbol for %s? ", periodic_table[i].name);
            scanf("%s", input);
            if (strcmp(input, "q") == 0) break;
            if (strcmp(input, periodic_table[i].symbol) == 0) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect. The correct answer is %s.\n", periodic_table[i].symbol);
            }
        } else {
            printf("What is the name for %s? ", periodic_table[i].symbol);
            scanf("%s", input);
            if (strcmp(input, "q") == 0) break;
            if (strcmp(input, periodic_table[i].name) == 0) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect. The correct answer is %s.\n", periodic_table[i].name);
            }
        }
        num_questions++;
    }

    float percent_correct = (float)score / (float)num_questions * 100.0;
    printf("\nYou got %d out of %d questions correct (%.2f%%).\n", score, num_questions, percent_correct);

    return 0;
}