//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ELEMENTS 118

/*
 * Define a struct to hold information about each element in the periodic table
 */
typedef struct {
    char *symbol;
    char *name;
    int atomicNumber;
    float atomicMass;
    char *category;
} element;

int main() {
    // Initialize an array of elements
    element periodicTable[NUM_ELEMENTS] = {
        {"H", "Hydrogen", 1, 1.008, "Nonmetal"},
        {"He", "Helium", 2, 4.003, "Noble Gas"},
        {"Li", "Lithium", 3, 6.941, "Alkali Metal"},
        {"Be", "Beryllium", 4, 9.012, "Alkaline Earth Metal"},
        {"B", "Boron", 5, 10.81, "Metalloid"},
        {"C", "Carbon", 6, 12.01, "Nonmetal"},
        {"N", "Nitrogen", 7, 14.01, "Nonmetal"},
        {"O", "Oxygen", 8, 16.00, "Nonmetal"},
        {"F", "Fluorine", 9, 19.00, "Halogen"},
        {"Ne", "Neon", 10, 20.18, "Noble Gas"},
        {"Na", "Sodium", 11, 22.99, "Alkali Metal"},
        {"Mg", "Magnesium", 12, 24.31, "Alkaline Earth Metal"},
        {"Al", "Aluminum", 13, 26.98, "Metal"},
        {"Si", "Silicon", 14, 28.09, "Metalloid"},
        {"P", "Phosphorus", 15, 30.97, "Nonmetal"},
        {"S", "Sulfur", 16, 32.07, "Nonmetal"},
        {"Cl", "Chlorine", 17, 35.45, "Halogen"},
        {"Ar", "Argon", 18, 39.95, "Noble Gas"},
        {"K", "Potassium", 19, 39.10, "Alkali Metal"},
        {"Ca", "Calcium", 20, 40.08, "Alkaline Earth Metal"},
        {"Sc", "Scandium", 21, 44.96, "Transition Metal"},
        {"Ti", "Titanium", 22, 47.87, "Transition Metal"},
        {"V", "Vanadium", 23, 50.94, "Transition Metal"},
        {"Cr", "Chromium", 24, 52.00, "Transition Metal"},
        {"Mn", "Manganese", 25, 54.94, "Transition Metal"},
        {"Fe", "Iron", 26, 55.85, "Transition Metal"},
        {"Co", "Cobalt", 27, 58.93, "Transition Metal"},
        {"Ni", "Nickel", 28, 58.69, "Transition Metal"},
        {"Cu", "Copper", 29, 63.55, "Transition Metal"},
        {"Zn", "Zinc", 30, 65.38, "Transition Metal"},
        {"Ga", "Gallium", 31, 69.72, "Metal"},
        {"Ge", "Germanium", 32, 72.63, "Metalloid"},
        {"As", "Arsenic", 33, 74.92, "Metalloid"},
        {"Se", "Selenium", 34, 78.96, "Nonmetal"},
        {"Br", "Bromine", 35, 79.90, "Halogen"},
        {"Kr", "Krypton", 36, 83.80, "Noble Gas"},
        {"Rb", "Rubidium", 37, 85.47, "Alkali Metal"},
        {"Sr", "Strontium", 38, 87.62, "Alkaline Earth Metal"},
        {"Y", "Yttrium", 39, 88.91, "Transition Metal"},
        {"Zr", "Zirconium", 40, 91.22, "Transition Metal"},
        {"Nb", "Niobium", 41, 92.91, "Transition Metal"},
        {"Mo", "Molybdenum", 42, 95.94, "Transition Metal"},
        {"Tc", "Technetium", 43, 98, "Transition Metal"},
        {"Ru", "Ruthenium", 44, 101.07, "Transition Metal"},
        {"Rh", "Rhodium", 45, 102.91, "Transition Metal"},
        {"Pd", "Palladium", 46, 106.42, "Transition Metal"},
        {"Ag", "Silver", 47, 107.87, "Transition Metal"},
        {"Cd", "Cadmium", 48, 112.41, "Transition Metal"},
        {"In", "Indium", 49, 114.82, "Metal"},
        {"Sn", "Tin", 50, 118.71, "Metal"},
        {"Sb", "Antimony", 51, 121.76, "Metalloid"},
        {"Te", "Tellurium", 52, 127.60, "Metalloid"},
        {"I", "Iodine", 53, 126.90, "Halogen"},
        {"Xe", "Xenon", 54, 131.29, "Noble Gas"},
        {"Cs", "Cesium", 55, 132.91, "Alkali Metal"},
        {"Ba", "Barium", 56, 137.33, "Alkaline Earth Metal"},
        {"La", "Lanthanum", 57, 138.91, "Lanthanide"},
        {"Ce", "Cerium", 58, 140.12, "Lanthanide"},
        {"Pr", "Praseodymium", 59, 140.91, "Lanthanide"},
        {"Nd", "Neodymium", 60, 144.24, "Lanthanide"},
        {"Pm", "Promethium", 61, 145, "Lanthanide"},
        {"Sm", "Samarium", 62, 150.36, "Lanthanide"},
        {"Eu", "Europium", 63, 151.96, "Lanthanide"},
        {"Gd", "Gadolinium", 64, 157.25, "Lanthanide"},
        {"Tb", "Terbium", 65, 158.93, "Lanthanide"},
        {"Dy", "Dysprosium", 66, 162.50, "Lanthanide"},
        {"Ho", "Holmium", 67, 164.93, "Lanthanide"},
        {"Er", "Erbium", 68, 167.26, "Lanthanide"},
        {"Tm", "Thulium", 69, 168.93, "Lanthanide"},
        {"Yb", "Ytterbium", 70, 173.05, "Lanthanide"},
        {"Lu", "Lutetium", 71, 174.97, "Lanthanide"},
        {"Hf", "Hafnium", 72, 178.49, "Transition Metal"},
        {"Ta", "Tantalum", 73, 180.95, "Transition Metal"},
        {"W", "Tungsten", 74, 183.84, "Transition Metal"},
        {"Re", "Rhenium", 75, 186.21, "Transition Metal"},
        {"Os", "Osmium", 76, 190.23, "Transition Metal"},
        {"Ir", "Iridium", 77, 192.22, "Transition Metal"},
        {"Pt", "Platinum", 78, 195.08, "Transition Metal"},
        {"Au", "Gold", 79, 196.97, "Transition Metal"},
        {"Hg", "Mercury", 80, 200.59, "Transition Metal"},
        {"Tl", "Thallium", 81, 204.38, "Metal"},
        {"Pb", "Lead", 82, 207.2, "Metal"},
        {"Bi", "Bismuth", 83, 208.98, "Metal"},
        {"Po", "Polonium", 84, 209, "Metalloid"},
        {"At", "Astatine", 85, 210, "Metalloid"},
        {"Rn", "Radon", 86, 222, "Noble Gas"},
        {"Fr", "Francium", 87, 223, "Alkali Metal"},
        {"Ra", "Radium", 88, 226, "Alkaline Earth Metal"},
        {"Ac", "Actinium", 89, 227, "Actinide"},
        {"Th", "Thorium", 90, 232.04, "Actinide"},
        {"Pa", "Protactinium", 91, 231.04, "Actinide"},
        {"U", "Uranium", 92, 238.03, "Actinide"},
        {"Np", "Neptunium", 93, 237, "Actinide"},
        {"Pu", "Plutonium", 94, 244, "Actinide"},
        {"Am", "Americium", 95, 243, "Actinide"},
        {"Cm", "Curium", 96, 247, "Actinide"},
        {"Bk", "Berkelium", 97, 247, "Actinide"},
        {"Cf", "Californium", 98, 251, "Actinide"},
        {"Es", "Einsteinium", 99, 252, "Actinide"},
        {"Fm", "Fermium", 100, 257, "Actinide"},
        {"Md", "Mendelevium", 101, 258, "Actinide"},
        {"No", "Nobelium", 102, 259, "Actinide"},
        {"Lr", "Lawrencium", 103, 266, "Transition Metal"},
        {"Rf", "Rutherfordium", 104, 267, "Transition Metal"},
        {"Db", "Dubnium", 105, 270, "Transition Metal"},
        {"Sg", "Seaborgium", 106, 271, "Transition Metal"},
        {"Bh", "Bohrium", 107, 270, "Transition Metal"},
        {"Hs", "Hassium", 108, 277, "Transition Metal"},
        {"Mt", "Meitnerium", 109, 278, "Transition Metal"},
        {"Ds", "Darmstadtium", 110, 281, "Transition Metal"},
        {"Rg", "Roentgenium", 111, 282, "Transition Metal"},
        {"Cn", "Copernicium", 112, 285, "Transition Metal"},
        {"Nh", "Nihonium", 113, 284, "Unknown"},
        {"Fl", "Flerovium", 114, 289, "Post-transition Metal"},
        {"Mc", "Moscovium", 115, 288, "Unknown"},
        {"Lv", "Livermorium", 116, 293, "Post-transition Metal"},
        {"Ts", "Tennessine", 117, 294, "Metalloid"},
        {"Og", "Oganesson", 118, 294, "Unknown"}
    };

    // Print welcome message and instructions
    printf("Welcome to the Periodic Table Quiz!\n\n");
    printf("You will be given the symbol or name of an element and you must provide the corresponding name or symbol, respectively.\n");
    printf("Enter 'q' at any time to quit the quiz.\n\n");

    // Shuffle the elements for a random quiz order
    srand(time(NULL));
    int i, j;
    for (i = 0; i < NUM_ELEMENTS - 1; i++) {
        j = i + (rand() % (NUM_ELEMENTS - i));
        element temp = periodicTable[j];
        periodicTable[j] = periodicTable[i];
        periodicTable[i] = temp;
    }

    // Initialize scorekeeping variables
    int numQuestions = 0;
    int numCorrect = 0;

    // Begin the quiz loop
    char input[20];
    int index;
    for (i = 0; i < NUM_ELEMENTS; i++) {
        // Print the current question
        printf("Question %d:\n", i + 1);
        if (rand() % 2 == 0) { // Ask for name of element
            printf("What element has the symbol %s?\n", periodicTable[i].symbol);
            printf("Answer: ");
            scanf("%s", input);
            if (strcmp(input, "q") == 0) { // Quit the quiz
                printf("You ended the quiz early. Better luck next time!\n");
                return 0;
            }
            if (strcmp(input, periodicTable[i].name) == 0) { // Correct answer
                printf("Correct!\n\n");
                numCorrect++;
            } else { // Incorrect answer
                printf("Incorrect. The correct answer was %s.\n\n", periodicTable[i].name);
            }
        } else { // Ask for symbol of element
            printf("What is the symbol for %s?\n", periodicTable[i].name);
            printf("Answer: ");
            scanf("%s", input);
            if (strcmp(input, "q") == 0) { // Quit the quiz
                printf("You ended the quiz early. Better luck next time!\n");
                return 0;
            }
            if (strcmp(input, periodicTable[i].symbol) == 0) { // Correct answer
                printf("Correct!\n\n");
                numCorrect++;
            } else { // Incorrect answer
                printf("Incorrect. The correct answer was %s.\n\n", periodicTable[i].symbol);
            }
        }
        numQuestions++;
    }

    // Print final score
    printf("You got %d out of %d questions correct! Thanks for playing!\n", numCorrect, numQuestions);

    return 0;
}