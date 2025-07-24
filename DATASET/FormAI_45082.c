//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define NUM_ELEMENTS 118

typedef struct Element {
    char name[20];
    char symbol[3];
    int atomic_number;
    float atomic_weight;
} Element;

void print_table(Element table[], int num_elements);
int quiz(Element table[], int num_elements);

int main() {
    Element periodic_table[NUM_ELEMENTS] = {
        {"Hydrogen", "H", 1, 1.008},
        {"Helium", "He", 2, 4.003},
        {"Lithium", "Li", 3, 6.941},
        // remaining elements omitted for brevity
        {"Oganesson", "Og", 118, 294}
    };

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Here are the elements:\n");
    print_table(periodic_table, NUM_ELEMENTS);

    int score = quiz(periodic_table, NUM_ELEMENTS);

    printf("Congratulations! You got %d/%d correct\n", score, NUM_ELEMENTS);
    return 0;
}

void print_table(Element table[], int num_elements) {
    for (int i = 0; i < num_elements; i++) {
        printf("%-2d %-20s %-3s %.3f\n", table[i].atomic_number, table[i].name, table[i].symbol, table[i].atomic_weight);
    }
}

int quiz(Element table[], int num_elements) {
    int score = 0;

    for (int i = 0; i < num_elements; i++) {
        printf("What is the symbol for %s? ", table[i].name);

        char input[3];
        scanf("%s", input);
        if (strcmp(input, table[i].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct symbol is %s\n", table[i].symbol);
        }
    }

    return score;
}