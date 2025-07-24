//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 20

// Define the structure of an element
typedef struct Element {
    char symbol[3];
    char name[NAME_LENGTH];
    int group;
    double atomic_mass;
} Element;

// Define the structure of a node in a linked list
typedef struct Node {
    Element element;
    struct Node *next;
} Node;

// Function prototypes
void print_title();
void print_menu();
void print_element(Element elem);
void print_table(Node *nodes[]);
void quiz(Node *nodes[]);
void read_elements(Node *nodes[]);
int get_choice();

// Main function
int main() {
    Node *nodes[18]; // Array of linked lists for each group
    for (int i=0; i<18; i++) {
        nodes[i] = NULL;
    }

    read_elements(nodes);

    int choice;
    do {
        print_title();
        print_menu();
        choice = get_choice();
        switch (choice) {
            case 1:
                print_table(nodes);
                break;
            case 2:
                quiz(nodes);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Prints the program title
void print_title() {
    printf("**************************************************\n");
    printf("*                                                *\n");
    printf("*              C Periodic Table Quiz              *\n");
    printf("*                     by AI Bot                   *\n");
    printf("*                                                *\n");
    printf("**************************************************\n");
}

// Prints the program menu
void print_menu() {
    printf("\n");
    printf("Main Menu:\n");
    printf("----------\n");
    printf("1. View the periodic table\n");
    printf("2. Take the quiz\n");
    printf("3. Exit\n");
    printf("\n");
}

// Prints information about an element
void print_element(Element elem) {
    printf("%s - %s (Group %d, Atomic mass = %.4f)\n",
           elem.symbol, elem.name, elem.group, elem.atomic_mass);
}

// Prints the full periodic table
void print_table(Node *nodes[]) {
    printf("Periodic Table:\n");
    printf("---------------\n");
    for (int i=0; i<7; i++) { // Rows 1-7
        printf("|");
        for (int j=0; j<18; j++) { // Elements 1-18
            Node *node = nodes[j];
            while (node != NULL && node->element.group < i) {
                node = node->next;
            }
            if (node == NULL || node->element.group > i) {
                printf("          |"); // Empty cell
            } else {
                print_element(node->element); // Element cell
                node = node->next;
            }
            nodes[j] = node;
        }
        printf("\n");
    }
    printf("\n");
}

// Runs the quiz
void quiz(Node *nodes[]) {
    int score = 0;
    int total = 0;
    for (int i=0; i<18; i++) {
        Node *node = nodes[i];
        while (node != NULL) {
            printf("What is the symbol for %s? ", node->element.name);
            char symbol[3];
            scanf("%s", symbol);
            if (strcmp(symbol, node->element.symbol) == 0) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect! The answer is %s.\n", node->element.symbol);
            }
            total++;
            node = node->next;
        }
    }
    printf("Quiz complete! Score: %d/%d\n", score, total);
}

// Reads the elements from a file and creates linked lists for each group
void read_elements(Node *nodes[]) {
    FILE *fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error: failed to open elements.txt\n");
        exit(EXIT_FAILURE);
    }

    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL) {
        Element elem;
        sscanf(line, "%s %s %d %lf", elem.symbol, elem.name, &elem.group, &elem.atomic_mass);
        elem.group--; // Groups start from 0
        Node *node = (Node *) malloc(sizeof(Node));
        node->element = elem;
        node->next = nodes[elem.group];
        nodes[elem.group] = node;
    }

    fclose(fp);
}

// Gets the user's menu choice
int get_choice() {
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    return choice;
}