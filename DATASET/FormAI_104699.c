//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEMENTS 118

char* elements[ELEMENTS] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon", 
                            "Sodium", "Magnesium", "Aluminum", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium", 
                            "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc", "Gallium", 
                            "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton", "Rubidium", "Strontium", "Yttrium", "Zirconium", "Niobium", 
                            "Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium", "Indium", "Tin", "Antimony", 
                            "Tellurium", "Iodine", "Xenon", "Cesium", "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium", "Promethium", 
                            "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium", "Lutetium", 
                            "Hafnium", "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum", "Gold", "Mercury", "Thallium", "Lead", 
                            "Bismuth", "Polonium", "Astatine", "Radon", "Francium", "Radium", "Actinium", "Thorium", "Protactinium", "Uranium", 
                            "Neptunium", "Plutonium", "Americium", "Curium", "Berkelium", "Californium", "Einsteinium", "Fermium", "Mendelevium", 
                            "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium", "Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium", 
                            "Roentgenium", "Copernicium", "Nihonium", "Flerovium", "Moscovium", "Livermorium", "Tennessine", "Oganesson"};

int main()
{
    srand(time(NULL)); // Seed for randomness

    int i, score = 0, questionCount = 0;

    // Quiz Instructions
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Guess the chemical symbol for each element shown\n");
    printf("Type 'exit' to quit the quiz anytime\n");
    printf("Ready? Let's begin!\n\n");

    int tryAgain = 1;
    while (tryAgain) {
        int randomIndexes[4];

        // Generate 4 random numbers between 0 and ELEMENTS - 1
        for (i = 0; i < 4; i++) {
            randomIndexes[i] = rand() % ELEMENTS;
        }

        // Output the chemical symbols for the random elements
        printf("Which symbol represents:\n");
        for (i = 0; i < 4; i++) {
            printf("%d. %s\t", i+1, elements[randomIndexes[i]]);
        }
        printf("\n\n");

        int correctAnswer = rand() % 4 + 1; // Randomly choose correct answer
        printf("Answer: ");
        
        char answer[6];
        scanf("%s", answer);

        if (strcmp(answer, "exit") == 0) {
            tryAgain = 0;
            break;
        }

        else if (atoi(answer) == correctAnswer) {
            printf("Correct!\n");
            score++;
        }

        else {
            printf("Incorrect. The correct answer was %d\n", correctAnswer);
        }

        questionCount++;

        if (questionCount == 10) { // Quiz ends after 10 questions
            printf("Quiz complete. You answered %d out of %d questions correctly.\n", score, questionCount);
            tryAgain = 0;
        }
    }

    return 0;
}