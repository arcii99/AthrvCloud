//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ELEMENTS 118

typedef struct {
    char name[30];
    char symbol[5];
    int atomic_number;
    float atomic_mass;
} Element;

Element periodic_table[ELEMENTS] = {
    {"Hydrogen", "H", 1, 1.008},
    {"Helium", "He", 2, 4.003},
    {"Lithium", "Li", 3, 6.941},
    //... and so on
    {"Livermorium", "Lv", 116, 293},
    {"Tennessine", "Ts", 117, 294},
    {"Oganesson", "Og", 118, 294}
};

int main() {
    int i, j, answer, score = 0;
    char buffer[30];
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("I will give you the symbol of an element, and you tell me the name.\n");
    printf("Are you ready? Let's start!\n");
    for (i = 0; i < 10; i++) {
        printf("\nQuestion #%d:\n", i+1);
        j = rand() % ELEMENTS;
        printf("What is the name for the element '%s'?\n", periodic_table[j].symbol);
        printf("Answer: ");
        fgets(buffer, 30, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strcasecmp(buffer, periodic_table[j].name) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", periodic_table[j].name);
        }
    }
    printf("\nQuiz completed! You scored %d out of 10.\n", score);
    return 0;
}