//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The number of elements
#define NUM_ELEMENTS 118

// The maximum length of an element name
#define MAX_NAME_LENGTH 15

// The maximum length of an element symbol
#define MAX_SYMBOL_LENGTH 3

// The maximum length of a user's answer
#define MAX_ANSWER_LENGTH 50

// The scores for each difficulty level
#define EASY_SCORE 2
#define MEDIUM_SCORE 4
#define HARD_SCORE 6

// The structure of an element
typedef struct Element {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
} Element;

// The list of elements
Element elements[NUM_ELEMENTS];

// Initialize the list of elements
void init_elements() {
    int i;
    char *names[NUM_ELEMENTS] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon", "Sodium", "Magnesium", "Aluminum", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium", "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc", "Gallium", "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton", "Rubidium", "Strontium", "Yttrium", "Zirconium", "Niobium", "Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium", "Indium", "Tin", "Antimony", "Tellurium", "Iodine", "Xenon", "Cesium", "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium", "Promethium", "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium", "Lutetium", "Hafnium", "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum", "Gold", "Mercury", "Thallium", "Lead", "Bismuth", "Polonium", "Astatine", "Radon", "Francium", "Radium", "Actinium", "Thorium", "Protactinium", "Uranium", "Neptunium", "Plutonium", "Americium", "Curium", "Berkelium", "Californium", "Einsteinium", "Fermium", "Mendelevium", "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium", "Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium", "Roentgenium", "Copernicium", "Nihonium", "Flerovium", "Moscovium", "Livermorium", "Tennessine", "Oganesson"};
    char *symbols[NUM_ELEMENTS] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};
    int atomic_numbers[NUM_ELEMENTS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118};

    for (i = 0; i < NUM_ELEMENTS; i++) {
        strcpy(elements[i].name, names[i]);
        strcpy(elements[i].symbol, symbols[i]);
        elements[i].atomic_number = atomic_numbers[i];
    }
}

// Display the menu and prompt user for their choice
int show_menu() {
    int choice = 0;

    printf("Welcome to the Periodic Table Quiz!\n\n");
    printf("Please choose a difficulty level:\n");
    printf("1. Easy (Guess element symbols)\n");
    printf("2. Medium (Guess element names)\n");
    printf("3. Hard (Guess element atomic numbers)\n\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    return choice;
}

// Get a random element
Element get_random_element() {
    return elements[rand() % NUM_ELEMENTS];
}

// Play the game
void play_game(int difficulty) {
    char answer[MAX_ANSWER_LENGTH];
    int guessed = 0;
    int score = 0;
    Element element;

    printf("You have chosen difficulty level %d.\n", difficulty);

    while (!guessed) {
        element = get_random_element();

        switch (difficulty) {
            case 1:
                printf("What is the symbol for %s? ", element.name);
                scanf("%s", answer);
                if (strcmp(answer, element.symbol) == 0) {
                    printf("Correct!\n");
                    score += EASY_SCORE;
                } else {
                    printf("Incorrect. The correct answer is %s.\n", element.symbol);
                }
                break;
            case 2:
                printf("What is the name of %s (hint: its symbol is %s)? ", element.symbol, element.symbol);
                scanf("%s", answer);
                if (strcmp(answer, element.name) == 0) {
                    printf("Correct!\n");
                    score += MEDIUM_SCORE;
                } else {
                    printf("Incorrect. The correct answer is %s.\n", element.name);
                }
                break;
            case 3:
                printf("What is the atomic number of %s? ", element.name);
                scanf("%s", answer);
                if (atoi(answer) == element.atomic_number) {
                    printf("Correct!\n");
                    score += HARD_SCORE;
                } else {
                    printf("Incorrect. The correct answer is %d.\n", element.atomic_number);
                }
                break;
            default:
                printf("Invalid difficulty level.\n");
                break;
        }

        printf("Your current score is %d.\n", score);

        printf("Do you want to continue playing? (y/n) ");
        scanf("%s", answer);
        if (strcmp(answer, "n") == 0) {
            guessed = 1;
        }
    }

    printf("Your final score is %d.\n", score);
}

int main() {
    srand(time(NULL));
    init_elements();
    int difficulty = show_menu();
    play_game(difficulty);
    return 0;
}