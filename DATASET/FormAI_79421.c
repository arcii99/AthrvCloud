//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element {
    char symbol[3];
    char name[20];
    int atomic_number;
    float atomic_weight;
} Element;
// custom data structure for elements
typedef struct element Element;

Element periodic_table[] = {
    {"H", "Hydrogen", 1, 1.008},
    {"He", "Helium", 2, 4.003},
    {"Li", "Lithium", 3, 6.941},
    {"Be", "Beryllium", 4, 9.012},
    {"B", "Boron", 5, 10.81},
    {"C", "Carbon", 6, 12.01},
    {"N", "Nitrogen", 7, 14.01},
    {"O", "Oxygen", 8, 16.00},
    {"F", "Fluorine", 9, 19.00},
    {"Ne", "Neon", 10, 20.18},
};

int num_elements = 10;

char *to_uppercase(char *string) {
    // convert string to uppercase
    char *result = string;
    for (; *string; ++string) *string = toupper(*string);
    return result;
}

void print_element(Element *element) {
    // print element information to console
    printf("\nSymbol: %s\n", element -> symbol);
    printf("Name: %s\n", element -> name);
    printf("Atomic Number: %d\n", element -> atomic_number);
    printf("Atomic Weight: %.2f\n", element -> atomic_weight);
}

int main() {
    char input[20];
    // main program loop
    while (1) {
        printf("\nEnter an element symbol or name (enter 'exit' to quit): ");
        fgets(input, 20, stdin);
        input[strcspn(input, "\n")] = '\0';
        // compare user input to elements in the periodic table
        if (strcmp(to_uppercase(input), "EXIT") == 0) {
            // user wants to exit the program
            printf("\nGoodbye!\n");
            exit(0);
        } else {
            int found = 0;
            for (int i = 0; i < num_elements; i++) {
                if (strcmp(to_uppercase(input), to_uppercase(periodic_table[i].symbol)) == 0 || 
                strcmp(to_uppercase(input), to_uppercase(periodic_table[i].name)) == 0) {
                    // element was found
                    found = 1;
                    print_element(&periodic_table[i]);
                    break;
                }
            }
            if (!found) {
                printf("\n%s not found in the periodic table. Try again.\n", input);
            }
        }
    }
    return 0;
}