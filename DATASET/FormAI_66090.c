//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a chemical element's name
#define MAX_NAME_LENGTH 25

// Define the number of known chemical elements
#define NUM_ELEMENTS 118

// Define the number of questions the quiz will ask
#define NUM_QUESTIONS 10

// Define a structure to hold information about a chemical element
typedef struct {
    int number;
    char symbol[3];
    char name[MAX_NAME_LENGTH];
} Element;

// Define an array to hold information about all the known chemical elements
Element elements[NUM_ELEMENTS] = {
    {1, "H", "Hydrogen"},
    {2, "He", "Helium"},
    {3, "Li", "Lithium"},
    {4, "Be", "Beryllium"},
    {5, "B", "Boron"},
    {6, "C", "Carbon"},
    {7, "N", "Nitrogen"},
    {8, "O", "Oxygen"},
    {9, "F", "Fluorine"},
    {10, "Ne", "Neon"},
    {11, "Na", "Sodium"},
    {12, "Mg", "Magnesium"},
    {13, "Al", "Aluminum"},
    {14, "Si", "Silicon"},
    {15, "P", "Phosphorus"},
    {16, "S", "Sulfur"},
    {17, "Cl", "Chlorine"},
    {18, "Ar", "Argon"},
    {19, "K", "Potassium"},
    {20, "Ca", "Calcium"},
    {21, "Sc", "Scandium"},
    {22, "Ti", "Titanium"},
    {23, "V", "Vanadium"},
    {24, "Cr", "Chromium"},
    {25, "Mn", "Manganese"},
    {26, "Fe", "Iron"},
    {27, "Co", "Cobalt"},
    {28, "Ni", "Nickel"},
    {29, "Cu", "Copper"},
    {30, "Zn", "Zinc"},
    {31, "Ga", "Gallium"},
    {32, "Ge", "Germanium"},
    {33, "As", "Arsenic"},
    {34, "Se", "Selenium"},
    {35, "Br", "Bromine"},
    {36, "Kr", "Krypton"},
    {37, "Rb", "Rubidium"},
    {38, "Sr", "Strontium"},
    {39, "Y", "Yttrium"},
    {40, "Zr", "Zirconium"},
    {41, "Nb", "Niobium"},
    {42, "Mo", "Molybdenum"},
    {43, "Tc", "Technetium"},
    {44, "Ru", "Ruthenium"},
    {45, "Rh", "Rhodium"},
    {46, "Pd", "Palladium"},
    {47, "Ag", "Silver"},
    {48, "Cd", "Cadmium"},
    {49, "In", "Indium"},
    {50, "Sn", "Tin"},
    {51, "Sb", "Antimony"},
    {52, "Te", "Tellurium"},
    {53, "I", "Iodine"},
    {54, "Xe", "Xenon"},
    {55, "Cs", "Cesium"},
    {56, "Ba", "Barium"},
    {57, "La", "Lanthanum"},
    {58, "Ce", "Cerium"},
    {59, "Pr", "Praseodymium"},
    {60, "Nd", "Neodymium"},
    {61, "Pm", "Promethium"},
    {62, "Sm", "Samarium"},
    {63, "Eu", "Europium"},
    {64, "Gd", "Gadolinium"},
    {65, "Tb", "Terbium"},
    {66, "Dy", "Dysprosium"},
    {67, "Ho", "Holmium"},
    {68, "Er", "Erbium"},
    {69, "Tm", "Thulium"},
    {70, "Yb", "Ytterbium"},
    {71, "Lu", "Lutetium"},
    {72, "Hf", "Hafnium"},
    {73, "Ta", "Tantalum"},
    {74, "W", "Tungsten"},
    {75, "Re", "Rhenium"},
    {76, "Os", "Osmium"},
    {77, "Ir", "Iridium"},
    {78, "Pt", "Platinum"},
    {79, "Au", "Gold"},
    {80, "Hg", "Mercury"},
    {81, "Tl", "Thallium"},
    {82, "Pb", "Lead"},
    {83, "Bi", "Bismuth"},
    {84, "Po", "Polonium"},
    {85, "At", "Astatine"},
    {86, "Rn", "Radon"},
    {87, "Fr", "Francium"},
    {88, "Ra", "Radium"},
    {89, "Ac", "Actinium"},
    {90, "Th", "Thorium"},
    {91, "Pa", "Protactinium"},
    {92, "U", "Uranium"},
    {93, "Np", "Neptunium"},
    {94, "Pu", "Plutonium"},
    {95, "Am", "Americium"},
    {96, "Cm", "Curium"},
    {97, "Bk", "Berkelium"},
    {98, "Cf", "Californium"},
    {99, "Es", "Einsteinium"},
    {100, "Fm", "Fermium"},
    {101, "Md", "Mendelevium"},
    {102, "No", "Nobelium"},
    {103, "Lr", "Lawrencium"},
    {104, "Rf", "Rutherfordium"},
    {105, "Db", "Dubnium"},
    {106, "Sg", "Seaborgium"},
    {107, "Bh", "Bohrium"},
    {108, "Hs", "Hassium"},
    {109, "Mt", "Meitnerium"},
    {110, "Ds", "Darmstadtium"},
    {111, "Rg", "Roentgenium"},
    {112, "Cn", "Copernicium"},
    {113, "Nh", "Nihonium"},
    {114, "Fl", "Flerovium"},
    {115, "Mc", "Moscovium"},
    {116, "Lv", "Livermorium"},
    {117, "Ts", "Tennessine"},
    {118, "Og", "Oganesson"}
};

// Shuffle the order of the questions
void shuffle(int *array, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int main() {
    // Seed the random number generator
    srand(42);

    // Populate an array with the numbers 1 through NUM_ELEMENTS
    int element_numbers[NUM_ELEMENTS];
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        element_numbers[i] = i + 1;
    }

    // Shuffle the order of the element numbers
    shuffle(element_numbers, NUM_ELEMENTS);

    // Print a welcome message
    printf("Welcome to the Periodic Table Quiz!\n\n");

    // Prompt the user to begin the quiz
    printf("Press enter to begin the quiz...");
    getchar();

    // Keep track of the number of correct answers
    int num_correct = 0;

    // Loop through each question
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        // Get the information for the current element
        Element element = elements[element_numbers[i] - 1];

        // Ask the question
        printf("%d. What is the chemical symbol for %s?\n", i + 1, element.name);

        // Get the user's answer
        char answer[3];
        fgets(answer, 3, stdin);
        answer[strcspn(answer, "\n")] = 0;

        // Check the user's answer
        if (strcmp(answer, element.symbol) == 0) {
            printf("Correct!\n");
            num_correct++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", element.symbol);
        }

        // Print the current score
        printf("Current score: %d/%d\n\n", num_correct, i + 1);
    }

    // Print the final score
    printf("\nQuiz complete!\nFinal Score: %d/%d\n", num_correct, NUM_QUESTIONS);

    return 0;
}