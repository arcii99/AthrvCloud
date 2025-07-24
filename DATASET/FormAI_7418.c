//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_ELEMENTS 118

const char *ELEMENTS[] = {
    "Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon",
    "Nitrogen", "Oxygen", "Fluorine", "Neon", "Sodium", "Magnesium",
    "Aluminum", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon",
    "Potassium", "Calcium", "Scandium", "Titanium", "Vanadium", "Chromium",
    "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc", "Gallium",
    "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton", "Rubidium",
    "Strontium", "Yttrium", "Zirconium", "Niobium", "Molybdenum", "Technetium",
    "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium", "Indium",
    "Tin", "Antimony", "Tellurium", "Iodine", "Xenon", "Cesium", "Barium",
    "Lanthanum", "Cerium", "Praseodymium", "Neodymium", "Promethium",
    "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium",
    "Holmium", "Erbium", "Thulium", "Ytterbium", "Lutetium", "Hafnium",
    "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum",
    "Gold", "Mercury", "Thallium", "Lead", "Bismuth", "Polonium",
    "Astatine", "Radon", "Francium", "Radium", "Actinium", "Thorium",
    "Protactinium", "Uranium", "Neptunium", "Plutonium", "Americium",
    "Curium", "Berkelium", "Californium", "Einsteinium", "Fermium",
    "Mendelevium", "Nobelium", "Lawrencium", "Rutherfordium",
    "Dubnium", "Seaborgium", "Bohrium", "Hassium", "Meitnerium",
    "Darmstadtium", "Roentgenium", "Copernicium", "Nihonium",
    "Flerovium", "Moscovium", "Livermorium", "Tennessine", "Oganesson"
};

int getRandomNumber(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

int main() {
    srand(time(0)); // Seed the random number generator with current time

    printf("Welcome to C Periodic Table Quiz!\n\n");

    printf("Rules:\n");
    printf("- You will be asked a random element's symbol, and you need to guess the element's name\n");
    printf("- You have 3 attempts to guess the correct element, otherwise, the game ends\n\n");

    printf("Let's start!\n\n");

    int score = 0;
    int numAttempts = 3;
    
    while (numAttempts > 0) {
        int randomIndex = getRandomNumber(0, TOTAL_ELEMENTS);
        const char *elementName = ELEMENTS[randomIndex];
        const char *elementSymbol = elementName;

        // Get the element symbol by taking the first letter(s) of the element name
        if (elementSymbol[0] == 'U' && elementSymbol[1] == 'u') {
            elementSymbol = "uu"; // Uranium's symbol is Uu
        } else {
            elementSymbol = elementName;
            while (*elementSymbol == ' ') {
                elementSymbol++; // Skip leading spaces
            }
            if (*elementSymbol == 'L' && *(elementSymbol + 1) == 'r') {
                elementSymbol = "Lr"; // Lawrencium's symbol is Lr
            } else {
                char *symbol = (char *)malloc(3 * sizeof(char));
                symbol[0] = *elementSymbol;
                int i = 1;
                do {
                    elementSymbol++;
                    if (*elementSymbol >= 'A' && *elementSymbol <= 'Z') {
                        symbol[i] = *elementSymbol;
                        i++;
                    }
                } while (*elementSymbol != '\0' && i < 3);
                symbol[i] = '\0'; // Null-terminate the symbol string
                elementSymbol = symbol;
            }
        }

        printf("What is the name of the element with the symbol \"%s\"?\n", elementSymbol);
        
        char guess[50];
        printf(">");
        fgets(guess, 50, stdin);
        
        // Remove newline character from input
        guess[strlen(guess) - 1] = '\0';
        
        // Convert guess to lowercase for case-insensitive comparison
        for (int i = 0; guess[i]; i++) {
            guess[i] = tolower(guess[i]);
        }

        if (strcmp(guess, elementName) == 0) {
            printf("Correct!\n");
            score++;
            numAttempts = 3;
        } else {
            printf("Incorrect. ");
            numAttempts--;
            if (numAttempts > 0) {
                printf("You have %d attempts left.\n", numAttempts);
            } else {
                printf("The correct answer was \"%s\".\n", elementName);
            }
        }

        printf("Your score: %d\n\n", score);
    }

    printf("Game over. Your final score is: %d\n", score);

    return 0;
}