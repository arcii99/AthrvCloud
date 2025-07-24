//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWER_SIZE 10

const char* ELEMENTS[] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", 
    "Oxygen", "Fluorine", "Neon", "Sodium", "Magnesium", "Aluminum", "Silicon", "Phosphorus", "Sulfur", 
    "Chlorine", "Argon", "Potassium", "Calcium", "Scandium", "Titanium", "Vanadium", "Chromium", 
    "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc", "Gallium", "Germanium", "Arsenic", 
    "Selenium", "Bromine", "Krypton", "Rubidium", "Strontium", "Yttrium", "Zirconium", "Niobium", 
    "Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium", "Indium", 
    "Tin", "Antimony", "Tellurium", "Iodine", "Xenon", "Cesium", "Barium", "Lanthanum", 
    "Cerium", "Praseodymium", "Neodymium", "Promethium", "Samarium", "Europium", "Gadolinium", 
    "Terbium", "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium", "Lutetium", "Hafnium", 
    "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum", "Gold", "Mercury", "Thallium", 
    "Lead", "Bismuth", "Polonium", "Astatine", "Radon", "Francium", "Radium", "Actinium", "Thorium", 
    "Protactinium", "Uranium", "Neptunium", "Plutonium", "Americium", "Curium", "Berkelium", "Californium", 
    "Einsteinium", "Fermium", "Mendelevium", "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium", 
    "Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium", "Roentgenium", "Copernicium", 
    "Nihonium", "Flerovium", "Moscovium", "Livermorium", "Tennessine", "Oganesson"
};

int main() {
    // Set the seed for the random number generator
    srand(time(NULL));

    // Keep track of total score
    int total_score = 0;

    printf("Welcome to the Periodic Table Quiz! Here are the rules:\n");
    printf("- You will be asked %d questions about elements from the periodic table.\n", MAX_QUESTIONS);
    printf("- Each correct answer will earn you 10 points.\n");
    printf("- You will have 10 seconds to answer each question.\n");
    printf("- You may use the first letter of the element or its full name as your answer.\n");
    printf("- Good luck!\n\n");

    // Loop through the questions
    for (int i = 1; i <= MAX_QUESTIONS; i++) {
        // Select a random element
        int random_index = rand() % (sizeof(ELEMENTS) / sizeof(ELEMENTS[0]));
        const char* element = ELEMENTS[random_index];

        // Print the question and start the timer
        printf("Question %d: What element has the symbol '%c'?\n", i, toupper(element[0]));
        time_t start_time = time(NULL);

        // Get the user's answer
        char answer[MAX_ANSWER_SIZE];
        fgets(answer, MAX_ANSWER_SIZE, stdin);

        // Remove newline character from fgets
        answer[strcspn(answer, "\n")] = 0;

        // Calculate the elapsed time
        time_t end_time = time(NULL);
        int elapsed_time = (int) difftime(end_time, start_time);

        // Check if the answer is correct and adjust score accordingly
        if (strcasecmp(answer, element) == 0 || tolower(answer[0]) == tolower(element[0])) {
            printf("Correct! You took %d seconds.\n", elapsed_time);
            total_score += 10;
        } else {
            printf("Incorrect! The correct answer was '%s'. You took %d seconds.\n", element, elapsed_time);
        }

        printf("Your total score is %d.\n\n", total_score);
    }

    printf("Thanks for playing! Your final score is %d.\n", total_score);

    return 0;
}