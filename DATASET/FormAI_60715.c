//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element {
    char symbol[3];
    char name[20];
    int atomic_number;
    char block[3];
    float atomic_mass;
} Element;

typedef struct Node {
    Element element;
    struct Node* next;
} Node;

Node* head = NULL;

Element createElement(char symbol[], char name[], int atomic_number, char block[], float atomic_mass) {
    Element element;
    strcpy(element.symbol, symbol);
    strcpy(element.name, name);
    element.atomic_number = atomic_number;
    strcpy(element.block, block);
    element.atomic_mass = atomic_mass;
    return element;
}

void insert(Element element) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->element = element;
    newNode->next = head;
    head = newNode;
}

void display() {
    Node* ptr = head;
    if (ptr == NULL) {
        printf("The periodic table is empty!\n");
        return;
    }
    printf("Symbol\tElement Name\tAtomic Number\tBlock\tAtomic Mass\n");
    while (ptr != NULL) {
        printf("%s\t%-12s\t%-13d\t%s\t%.4f\n", ptr->element.symbol, ptr->element.name, ptr->element.atomic_number, ptr->element.block, ptr->element.atomic_mass);
        ptr = ptr->next;
    }
}

void initialElements() {
    insert(createElement("H", "Hydrogen", 1, "s", 1.008));
    insert(createElement("He", "Helium", 2, "s", 4.003));
    insert(createElement("Li", "Lithium", 3, "s", 6.941));
    insert(createElement("Be", "Beryllium", 4, "s", 9.012));
    insert(createElement("B", "Boron", 5, "p", 10.811));
    insert(createElement("C", "Carbon", 6, "p", 12.011));
    insert(createElement("N", "Nitrogen", 7, "p", 14.007));
    insert(createElement("O", "Oxygen", 8, "p", 15.999));
    insert(createElement("F", "Fluorine", 9, "p", 18.998));
    insert(createElement("Ne", "Neon", 10, "p", 20.180));
}

int quiz() {
    Node* ptr = head;
    int score = 0;
    char answer[3];
    while (ptr != NULL) {
        printf("What is the atomic number of %s? ", ptr->element.name);
        scanf("%s", answer);
        if (strcmp(answer, "quit") == 0) {
            printf("Exited quiz mode.\n");
            return score;
        }
        if (atoi(answer) == ptr->element.atomic_number) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Sorry, the correct answer is %d.\n", ptr->element.atomic_number);
        }
        ptr = ptr->next;
    }
    printf("Your score: %d/%d\n", score, 10);
    return score;
}

void start() {
    int choice;
    do {
        printf("1. Display periodic table\n2. Start quiz\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display();
                break;
            case 2:
                printf("Enter 'quit' at any time to exit.\n");
                quiz();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);
}

int main() {
    initialElements();
    start();
    return 0;
}