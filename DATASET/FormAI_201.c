//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NUM_ELEMENTS 118 // number of elements in the periodic table

// struct to hold information about a single element
typedef struct {
    char symbol[3];
    char name[20];
    int atomic_number;
    float atomic_weight;
} Element;

// function to add a new element to the periodic table
void addElement(Element* table, int index, char* symbol, char* name, int atomic_number, float atomic_weight) {
    strcpy(table[index].symbol, symbol);
    strcpy(table[index].name, name);
    table[index].atomic_number = atomic_number;
    table[index].atomic_weight = atomic_weight;
}

// function to print out the periodic table
void printTable(Element* table) {
    printf("Periodic Table\n");
    printf("-----------------------\n");
    printf("%-3s  %-20s  %-3s  %-6s\n", " #", "Element Name", "Sym", "Weight");
    printf("-----------------------\n");
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        printf("%3i  %-20s  %-3s  %-6.2f\n", table[i].atomic_number, table[i].name, table[i].symbol, table[i].atomic_weight);
    }
}

// function to quiz the user on their knowledge of the periodic table
bool quiz(Element* table) {
    int score = 0; // keep track of user's score
    char answer[3];
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        printf("What is the symbol for %s? ", table[i].name);
        scanf("%s", answer);
        if (strcmp(answer, table[i].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("The correct symbol is %s\n", table[i].symbol);
        }
    }
    printf("Final score: %i/%i\n", score, NUM_ELEMENTS);
    if (score == NUM_ELEMENTS) {
        printf("Perfect score! Great job!\n");
        return true;
    } else {
        printf("Better luck next time!\n");
        return false;
    }
}

int main() {
    // create an array to hold the periodic table
    Element table[NUM_ELEMENTS];
    
    // add elements to the table
    addElement(table, 0, "H", "Hydrogen", 1, 1.008);
    addElement(table, 1, "He", "Helium", 2, 4.003);
    addElement(table, 2, "Li", "Lithium", 3, 6.941);
    addElement(table, 3, "Be", "Beryllium", 4, 9.012);
    // add more elements here...
    
    // print out the table
    printTable(table);
    
    // start the quiz
    quiz(table);
    
    return 0;
}