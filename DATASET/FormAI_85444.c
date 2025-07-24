//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct element {
    char name[20];
    char symbol[3];
    int atomic_number;
    double atomic_weight;
    char category[20];
} Element;

Element periodic_table[118];

void initialize_periodic_table() {
    strcpy(periodic_table[0].name, "Hydrogen");
    strcpy(periodic_table[0].symbol, "H");
    periodic_table[0].atomic_number = 1;
    periodic_table[0].atomic_weight = 1.008;
    strcpy(periodic_table[0].category, "Nonmetal");
    
    strcpy(periodic_table[1].name, "Helium");
    strcpy(periodic_table[1].symbol, "He");
    periodic_table[1].atomic_number = 2;
    periodic_table[1].atomic_weight = 4.003;
    strcpy(periodic_table[1].category, "Noble gas");
  
    // initialization continues for all 118 elements
}

void display_menu() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Choose an option below:\n");
    printf("1. Quiz me on element symbol\n");
    printf("2. Quiz me on element name\n");
    printf("3. Quit\n");
}

bool answer_is_correct(char answer[], char solution[]) {
    return strcmp(answer, solution) == 0;
}

void quiz_element_symbol() {
    printf("Quiz me on element symbols!\n");
    int score = 0;
    for(int i=0;i<10;i++) {
        int random_index = rand() % 118;
        Element element = periodic_table[random_index];
        printf("What is the symbol for %s? ", element.name);
        char answer[3];
        scanf("%s", answer);
        if(answer_is_correct(answer, element.symbol)) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Sorry, the correct answer is %s.\n", element.symbol);
        }
    }
    printf("Your final score was %d out of 10.\n", score);
}

void quiz_element_name() {
    printf("Quiz me on element names!\n");
    int score = 0;
    for(int i=0;i<10;i++) {
        int random_index = rand() % 118;
        Element element = periodic_table[random_index];
        printf("What is the name of the element with symbol %s? ", element.symbol);
        char answer[20];
        scanf("%s", answer);
        if(answer_is_correct(answer, element.name)) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Sorry, the correct answer is %s.\n", element.name);
        }
    }
    printf("Your final score was %d out of 10.\n", score);
}

int main() {
    initialize_periodic_table();
    srand(0); // seed random generator with constant value for reproducibility
    
    int choice = 0;
    while(choice != 3) {
        display_menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                quiz_element_symbol();
                break;
            case 2:
                quiz_element_name();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}