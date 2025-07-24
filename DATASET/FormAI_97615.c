//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: complex
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Structure to store the details of each element 
struct element
{
    char name[20];
    char symbol[3];
    int atomic_number;
    float atomic_weight;
};

typedef struct element Element;

// Function to create a new element
Element create_element(char* name, char* symbol, int atomic_number, float atomic_weight)
{
    Element e;
    strcpy(e.name, name);
    strcpy(e.symbol, symbol);
    e.atomic_number = atomic_number;
    e.atomic_weight = atomic_weight;
    return e;
}

int main()
{
    // Creating an array of the first 20 elements
    Element elements[20];
    elements[0] = create_element("Hydrogen", "H", 1, 1.008);
    elements[1] = create_element("Helium", "He", 2, 4.003);
    elements[2] = create_element("Lithium", "Li", 3, 6.941);
    elements[3] = create_element("Beryllium", "Be", 4, 9.012);
    elements[4] = create_element("Boron", "B", 5, 10.81);
    elements[5] = create_element("Carbon", "C", 6, 12.01);
    elements[6] = create_element("Nitrogen", "N", 7, 14.01);
    elements[7] = create_element("Oxygen", "O", 8, 16.00);
    elements[8] = create_element("Fluorine", "F", 9, 19.00);
    elements[9] = create_element("Neon", "Ne", 10, 20.18);
    elements[10] = create_element("Sodium", "Na", 11, 22.99);
    elements[11] = create_element("Magnesium", "Mg", 12, 24.31);
    elements[12] = create_element("Aluminum", "Al", 13, 26.98);
    elements[13] = create_element("Silicon", "Si", 14, 28.09);
    elements[14] = create_element("Phosphorus", "P", 15, 30.97);
    elements[15] = create_element("Sulfur", "S", 16, 32.07);
    elements[16] = create_element("Chlorine", "Cl", 17, 35.45);
    elements[17] = create_element("Argon", "Ar", 18, 39.95);
    elements[18] = create_element("Potassium", "K", 19, 39.10);
    elements[19] = create_element("Calcium", "Ca", 20, 40.08);

    // Main quiz loop
    while(1)
    {
        printf("Welcome to the Periodic Table Quiz!\n");
        printf("Please select an option:\n");
        printf("1. Quiz me on an element\n");
        printf("2. List all the elements\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);
        getchar(); // Clear the input buffer

        switch(choice)
        {
            case 1:
            {
                // Quiz the user on a random element
                printf("OK, here's your question:\n");
                int index = rand() % 20;
                printf("What is the symbol for %s? ", elements[index].name);

                char answer[3];
                scanf("%s", answer);
                getchar(); // Clear the input buffer

                if(strcmp(answer, elements[index].symbol) == 0)
                {
                    printf("Correct! Well done!\n");
                }
                else
                {
                    printf("Sorry, the correct answer is %s.\n", elements[index].symbol);
                }
                break;
            }
            case 2:
            {
                // List all the elements
                printf("Here are the first 20 elements of the periodic table:\n");
                printf("Name\t\tSymbol\t\tAtomic Number\t\tAtomic Weight\n");
                for(int i=0; i<20; i++)
                {
                    printf("%-12s\t%-3s\t\t%-3d\t\t\t%-4.2f\n", elements[i].name, elements[i].symbol, elements[i].atomic_number, elements[i].atomic_weight);
                }
                break;
            }
            case 3:
            {
                // Exit the program
                printf("Exiting the program...\n");
                exit(0);
                break;
            }
            default:
            {
                printf("Invalid choice. Please choose again.\n");
                break;
            }
        }
    }
    return 0;
}