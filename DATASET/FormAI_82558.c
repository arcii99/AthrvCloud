//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENT_NAME_LEN 20

/* Struct representing an element in the periodic table */
typedef struct {
    int atomic_number;
    char symbol[3];
    char name[MAX_ELEMENT_NAME_LEN];
    float atomic_weight;
} Element;

/* Function to initialize an Element */
void init_element(Element *elem, int atomic_number, char symbol[3], char name[MAX_ELEMENT_NAME_LEN], float atomic_weight) {
    elem->atomic_number = atomic_number;
    strcpy(elem->symbol, symbol);
    strcpy(elem->name, name);
    elem->atomic_weight = atomic_weight;
}

/* Function to print the details of an Element */
void print_element(Element *elem) {
    printf("\nAtomic number: %d", elem->atomic_number);
    printf("\nSymbol: %s", elem->symbol);
    printf("\nName: %s", elem->name);
    printf("\nAtomic weight: %.2f", elem->atomic_weight);
}

/* Function to prompt the user for an integer */
int prompt_for_int(char prompt_msg[]) {
    int input;
    printf("%s", prompt_msg);
    scanf("%d", &input);
    return input;
}

/* Function to prompt the user for a string */
void prompt_for_string(char prompt_msg[], char output_string[], int max_len) {
    printf("%s", prompt_msg);
    fflush(stdin);
    fgets(output_string, max_len, stdin);
    output_string[strcspn(output_string, "\n")] = 0; // remove trailing newline character
}

/* Function to get an Element from the user */
void get_element_from_user(Element *elem) {
    printf("\nPlease provide details for the Element:");
    elem->atomic_number = prompt_for_int("\nAtomic number: ");
    prompt_for_string("\nSymbol: ", elem->symbol, 3);
    prompt_for_string("\nName: ", elem->name, MAX_ELEMENT_NAME_LEN);
    elem->atomic_weight = prompt_for_int("\nAtomic weight: ");
}

/* Function to generate a sample periodic table */
void generate_sample_periodic_table(Element periodic_table[], int max_len) {
    init_element(&periodic_table[0], 1, "H", "Hydrogen", 1.008);
    init_element(&periodic_table[1], 2, "He", "Helium", 4.003);
    init_element(&periodic_table[2], 3, "Li", "Lithium", 6.941);
    init_element(&periodic_table[3], 4, "Be", "Beryllium", 9.012);
    init_element(&periodic_table[4], 5, "B", "Boron", 10.81);
    init_element(&periodic_table[5], 6, "C", "Carbon", 12.01);
    init_element(&periodic_table[6], 7, "N", "Nitrogen", 14.01);
    init_element(&periodic_table[7], 8, "O", "Oxygen", 16.00);
    init_element(&periodic_table[8], 9, "F", "Fluorine", 19.00);
    init_element(&periodic_table[9], 10, "Ne", "Neon", 20.18);
}

/* Function to search for an Element by symbol in the periodic table */
Element *find_element_by_symbol(Element periodic_table[], int max_len, char symbol[3]) {
    int i;
    for (i = 0; i < max_len; i++) {
        if (strcmp(periodic_table[i].symbol, symbol) == 0) {
            return &periodic_table[i];
        }
    }
    return NULL;
}

int main() {
    int max_len = 10; // maximum number of elements in periodic table
    Element periodic_table[max_len];
    int choice;
    char search_symbol[3];
    Element *found_element;
    generate_sample_periodic_table(periodic_table, max_len);
    do {
        printf("\n\n--- Periodic Table Quiz ---");
        printf("\nChoose an option:");
        printf("\n1. View all Elements in the periodic table.");
        printf("\n2. Search for an Element by symbol.");
        printf("\n3. Add a new Element to the periodic table.");
        printf("\n4. Quit.");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\n--- All Elements in the periodic table ---");
                for (int i = 0; i < max_len ; i++) {
                    print_element(&periodic_table[i]);
                }
                break;
            case 2:
                prompt_for_string("Enter the symbol of the Element you would like to search for: ", search_symbol, 3);
                found_element = find_element_by_symbol(periodic_table, max_len, search_symbol);
                if (found_element == NULL) {
                    printf("\nElement with symbol %s not found in periodic table.", search_symbol);
                } else {
                    printf("\n--- Element details ---");
                    print_element(found_element);
                }
                break;
            case 3:
                if (max_len == 10) {
                    printf("\nCannot add a new Element, since the maximum capacity of the periodic table has been reached.");
                } else {
                    Element new_element;
                    get_element_from_user(&new_element);
                    init_element(&periodic_table[max_len], new_element.atomic_number, new_element.symbol, new_element.name, new_element.atomic_weight);
                    printf("\nNew Element added to the periodic table.");
                    max_len++;
                }
                break;
            case 4:
                printf("\nQuitting the Periodic Table Quiz.");
                break;
            default:
                printf("\nInvalid option chosen. Choose a valid option from the menu.");
        }
    } while (choice != 4);
    return 0;
}