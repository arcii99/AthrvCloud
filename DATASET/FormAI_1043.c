//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118

typedef struct element {
    char symbol[3];
    int atomic_number;
    char name[30];
} Element;

Element chemical_elements[MAX_ELEMENTS];

void initialize_elements() {
    strcpy(chemical_elements[0].symbol, "H");
    chemical_elements[0].atomic_number = 1;
    strcpy(chemical_elements[0].name, "Hydrogen");
    
    strcpy(chemical_elements[1].symbol, "He");
    chemical_elements[1].atomic_number = 2;
    strcpy(chemical_elements[1].name, "Helium");
    
    // Rest of the elements initialization goes here...
}

int binary_search(Element arr[], int left, int right, char* search_symbol) 
{ 
    if (right >= left) { 
        int mid = left + (right - left) / 2; 
  
        if (strcmp(arr[mid].symbol, search_symbol) == 0) 
            return mid; 
  
        if (strcmp(arr[mid].symbol, search_symbol) > 0) 
            return binary_search(arr, left, mid - 1, search_symbol); 
  
        return binary_search(arr, mid + 1, right, search_symbol); 
    } 

    return -1; 
} 

void take_quiz() {
    char answer[3];
    printf("Enter an element symbol or 'quit' to exit: ");
    scanf("%s", answer);
    if (strcmp(answer, "quit") == 0) {
        printf("Goodbye\n");
        return;
    }

    int index = binary_search(chemical_elements, 0, MAX_ELEMENTS - 1, answer);
    
    if (index == -1) {
        printf("Incorrect, try again\n");
        take_quiz();
    } else {
        printf("Correct, the element is %s (atomic number %d, symbol %s)\n", chemical_elements[index].name, chemical_elements[index].atomic_number, chemical_elements[index].symbol);
        take_quiz();
    }
}

int main() {
    initialize_elements();
    take_quiz();
    return 0;
}