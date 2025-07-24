//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Element {
    int atomic_number;
    char symbol[3];
    char name[30];
    float atomic_mass;
    char category[20];
};

typedef struct Element Element;

int main() {
    int random_array[10];
    int score = 0;
    int i, j, k;
    int option;
    int random_option;
    Element periodic_table[118];

    // Populate periodic table array with data
    // Data has been omitted for brevity

    // Initialize random array with unique random numbers
    for(i = 0; i < 10; i++) {
        random_array[i] = i+1;
    }

    // Shuffle random array using Fisher-Yates algorithm
    for(i = 9; i > 0; i--) {
        j = rand() % (i+1);
        k = random_array[i];
        random_array[i] = random_array[j];
        random_array[j] = k;
    }

    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("Answer 10 multiple choice questions to test your knowledge of the periodic table.\n");
    printf("Choose the correct answer from the options provided.\n");

    for(i = 0; i < 10; i++) {
        printf("\nQuestion %d:\n", i+1);
        random_option = rand() % 4;

        switch(random_option) {
            case 0:
                printf("What is the symbol for the element with the atomic number %d?\n", periodic_table[random_array[i]].atomic_number);
                printf("a) %s\n", periodic_table[random_array[i]].symbol);
                printf("b) %s\n", periodic_table[random_array[(i+1)%10]].symbol);
                printf("c) %s\n", periodic_table[random_array[(i+2)%10]].symbol);
                printf("d) %s\n", periodic_table[random_array[(i+3)%10]].symbol);
                option = getchar();
                while(getchar() != '\n');
                if(option == 'a') {
                    score++;
                    printf("Correct!\n");
                }
                else{
                    printf("Incorrect, the correct answer was %s.\n", periodic_table[random_array[i]].symbol);
                }
                break;
            case 1:
                printf("What is the name of the element with the symbol %s?\n", periodic_table[random_array[i]].symbol);
                printf("a) %s\n", periodic_table[random_array[i]].name);
                printf("b) %s\n", periodic_table[random_array[(i+1)%10]].name);
                printf("c) %s\n", periodic_table[random_array[(i+2)%10]].name);
                printf("d) %s\n", periodic_table[random_array[(i+3)%10]].name);
                option = getchar();
                while(getchar() != '\n');
                if(option == 'a') {
                    score++;
                    printf("Correct!\n");
                }
                else{
                    printf("Incorrect, the correct answer was %s.\n", periodic_table[random_array[i]].name);
                }
                break;
            case 2:
                printf("What is the atomic number of the element with the symbol %s?\n", periodic_table[random_array[i]].symbol);
                printf("a) %d\n", periodic_table[random_array[i]].atomic_number);
                printf("b) %d\n", periodic_table[random_array[(i+1)%10]].atomic_number);
                printf("c) %d\n", periodic_table[random_array[(i+2)%10]].atomic_number);
                printf("d) %d\n", periodic_table[random_array[(i+3)%10]].atomic_number);
                option = getchar();
                while(getchar() != '\n');
                if(option == 'a') {
                    score++;
                    printf("Correct!\n");
                }
                else{
                    printf("Incorrect, the correct answer was %d.\n", periodic_table[random_array[i]].atomic_number);
                }
                break;
            case 3:
                printf("What is the category of the element with the symbol %s?\n", periodic_table[random_array[i]].symbol);
                printf("a) %s\n", periodic_table[random_array[i]].category);
                printf("b) %s\n", periodic_table[random_array[(i+1)%10]].category);
                printf("c) %s\n", periodic_table[random_array[(i+2)%10]].category);
                printf("d) %s\n", periodic_table[random_array[(i+3)%10]].category);
                option = getchar();
                while(getchar() != '\n');
                if(option == 'a') {
                    score++;
                    printf("Correct!\n");
                }
                else{
                    printf("Incorrect, the correct answer was %s.\n", periodic_table[random_array[i]].category);
                }
                break;
        }
    }

    printf("\nYou scored %d out of 10.\n", score);

    return 0;
}