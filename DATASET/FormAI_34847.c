//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure to store the elements of periodic table
struct element {
    char symbol[3];
    char name[50];
    int atomic_number;
    float atomic_weight;
};

//Recursive function to search for an element in periodic table using binary search algorithm
int search_element(struct element table[], char symbol[], int low, int high) {
    if(low > high)
        return -1;
    int mid = (low + high) / 2;
    if(strcmp(table[mid].symbol, symbol) == 0)
        return mid;
    else if(strcmp(table[mid].symbol, symbol) < 0)
        return search_element(table, symbol, mid+1, high);
    else
        return search_element(table, symbol, low, mid-1);
}

int main() {
    //Array of elements in periodic table
    struct element table[] = {{"H", "Hydrogen", 1, 1.008}, {"He", "Helium", 2, 4.003},
                              {"Li", "Lithium", 3, 6.941}, {"Be", "Beryllium", 4, 9.012},
                              {"B", "Boron", 5, 10.81}, {"C", "Carbon", 6, 12.01},
                              {"N", "Nitrogen", 7, 14.01}, {"O", "Oxygen", 8, 16.00},
                              {"F", "Fluorine", 9, 19.00}, {"Ne", "Neon", 10, 20.18}};
    int n = sizeof(table) / sizeof(table[0]);
    printf("Welcome to Periodic Table Quiz!\n");
    printf("Enter the symbol of an element to search: ");
    char symbol[3];
    scanf("%s", symbol);
    int result = search_element(table, symbol, 0, n-1);
    if(result == -1)
        printf("Element not found!\n");
    else {
        printf("You found it!\n");
        printf("Name: %s\n", table[result].name);
        printf("Atomic Number: %d\n", table[result].atomic_number);
        printf("Atomic Weight: %.3f\n", table[result].atomic_weight);
    }
    return 0;
}