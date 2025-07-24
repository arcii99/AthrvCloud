//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int score = 0; // Initialize the player's score

void checkAnswer(char *element, char *answer) { // Function to check the player's answer 
    if(strcmp(element, answer) == 0) { // If the answer is correct
        printf("Correct! You earned 10 points!\n");
        score += 10; // Add 10 points to the player's score
    }
    else { // If the answer is incorrect
        printf("Incorrect. The correct answer is %s.\n", element);
    }
}

int main() {
    char *elements[118] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon", "Sodium", "Magnesium", "Aluminum", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium",
                            "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc", "Gallium", "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton", "Rubidium", "Strontium", "Yttrium", "Zirconium",
                            "Niobium", "Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium", "Indium", "Tin", "Antimony", "Tellurium", "Iodine", "Xenon", "Cesium", "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium",
                            "Promethium", "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium", "Lutetium", "Hafnium", "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum", "Gold", "Mercury",
                            "Thallium", "Lead", "Bismuth", "Polonium", "Astatine", "Radon", "Francium", "Radium", "Actinium", "Thorium", "Protactinium", "Uranium", "Neptunium", "Plutonium", "Americium", "Curium", "Berkelium", "Californium", "Einsteinium",
                            "Fermium", "Mendelevium", "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium", "Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium", "Roentgenium", "Copernicium", "Nihonium", "Flerovium", "Moscovium", "Livermorium",
                            "Tennessine", "Oganesson"}; // Array of all elements in the periodic table

    int i, j;
    char answer[20];

    printf("Welcome to the Periodic Table Quiz!\n\n"); // Print the welcome message

    for(i = 0; i < 10; i++) { // Loop through 10 random elements
        srand(time(NULL)); // Set the seed for the random number generator
        j = rand() % 118; // Generate a random number between 0 and 117
        printf("What is the symbol for %s?\n", elements[j]); // Prompt the user for an answer
        scanf("%s", answer); // Read the user's answer

        // Convert the input answer to lowercase
        for(int k = 0; k < strlen(answer); k++) {
            answer[k] = tolower(answer[k]);
        }

        checkAnswer(elements[j], answer); // Check the answer
    }

    printf("Congratulations! You have finished the quiz!\n"); // Print the final score
    printf("You scored %d out of 100.\n", score);

    return 0;
}