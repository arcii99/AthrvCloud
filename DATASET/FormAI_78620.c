//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char elements[118][15] = {
        "Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", 
        "Nitrogen", "Oxygen", "Fluorine", "Neon", "Sodium", "Magnesium",
        "Aluminium", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon",
        "Potassium", "Calcium", "Scandium", "Titanium", "Vanadium", "Chromium",
        "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc", "Gallium",
        "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton", "Rubidium",
        "Strontium", "Yttrium", "Zirconium", "Niobium", "Molybdenum", "Technetium",
        "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium", "Indium",
        "Tin", "Antimony", "Tellurium", "Iodine", "Xenon", "Cesium",
        "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium",
        "Promethium", "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium",
        "Holmium", "Erbium", "Thulium", "Ytterbium", "Lutetium", "Hafnium",
        "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum",
        "Gold", "Mercury", "Thallium", "Lead", "Bismuth", "Polonium", "Astatine",
        "Radon", "Francium", "Radium", "Actinium", "Thorium", "Protactinium",
        "Uranium", "Neptunium", "Plutonium", "Americium", "Curium",
        "Berkelium", "Californium", "Einsteinium", "Fermium", "Mendelevium",
        "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium", "Seaborgium",
        "Bohrium", "Hassium", "Meitnerium", "Darmstadtium", "Roentgenium",
        "Copernicium", "Nihonium", "Flerovium", "Moscovium", "Livermorium",
        "Tennessine", "Oganesson"
    };

    int atomic_numbers[118] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 
        31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 
        51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 
        61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 
        71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 
        81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 
        91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 
        101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 
        111, 112, 113, 114, 115, 116, 117, 118
    };

    char input[15];
    int score = 0;

    printf("Welcome to the periodic table quiz!\n");
    printf("Enter the symbol or name of the element corresponding to the given atomic number.\n");

    for (int i = 0; i < 10; i++) {
        int atomic_num = atomic_numbers[rand() % 118];
        printf("Atomic number: %d\n", atomic_num);

        int index;
        for (int j = 0; j < 118; j++) {
            if (atomic_numbers[j] == atomic_num) {
                index = j;
                break;
            }
        }

        printf("Enter your guess: ");
        fgets(input, 15, stdin);

        // remove trailing newline character from input
        strtok(input, "\n");

        if (isdigit(input[0])) {
            // convert input string to integer
            int guess = atoi(input);
            if (guess == atomic_num) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect! The correct answer was %s.\n", elements[index]);
            }
        } else {
            // convert input string to uppercase
            char guess[15];
            strcpy(guess, input);
            for (int j = 0; guess[j]; j++) {
                guess[j] = toupper(guess[j]);
            }

            if (strcmp(guess, elements[index]) == 0) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect! The correct answer was %s.\n", elements[index]);
            }
        }
    }

    printf("You got %d out of 10 correct.\n", score);

    return 0;
}