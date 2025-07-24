//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ELEMENTS 118
#define MAX_NAME_LEN 50

struct Element {
    char name[MAX_NAME_LEN];
    char symbol[MAX_NAME_LEN];
    int atomicNumber;
    float atomicWeight;
};

void clearScreen();
int getRandomIndex();
void printElement(struct Element element);
int getGuess();
void checkAnswer(struct Element element, int guess);
void playGame();

// Define all of the elements in the periodic table
struct Element elements[NUM_ELEMENTS] = {
        {"Hydrogen", "H", 1, 1.008},
        {"Helium", "He", 2, 4.003},
        {"Lithium", "Li", 3, 6.941},
        {"Beryllium", "Be", 4, 9.012},
        {"Boron", "B", 5, 10.81},
        {"Carbon", "C", 6, 12.01},
        {"Nitrogen", "N", 7, 14.01},
        {"Oxygen", "O", 8, 16.00},
        {"Fluorine", "F", 9, 19.00},
        {"Neon", "Ne", 10, 20.18},
        {"Sodium", "Na", 11, 22.99},
        {"Magnesium", "Mg", 12, 24.31},
        {"Aluminum", "Al", 13, 26.98},
        {"Silicon", "Si", 14, 28.09},
        {"Phosphorus", "P", 15, 30.97},
        {"Sulfur", "S", 16, 32.07},
        {"Chlorine", "Cl", 17, 35.45},
        {"Argon", "Ar", 18, 39.95},
        {"Potassium", "K", 19, 39.10},
        {"Calcium", "Ca", 20, 40.08},
        {"Scandium", "Sc", 21, 44.96},
        {"Titanium", "Ti", 22, 47.87},
        {"Vanadium", "V", 23, 50.94},
        {"Chromium", "Cr", 24, 52.00},
        {"Manganese", "Mn", 25, 54.94},
        {"Iron", "Fe", 26, 55.85},
        {"Cobalt", "Co", 27, 58.93},
        {"Nickel", "Ni", 28, 58.69},
        {"Copper", "Cu", 29, 63.55},
        {"Zinc", "Zn", 30, 65.38},
        {"Gallium", "Ga", 31, 69.72},
        {"Germanium", "Ge", 32, 72.63},
        {"Arsenic", "As", 33, 74.92},
        {"Selenium", "Se", 34, 78.96},
        {"Bromine", "Br", 35, 79.90},
        {"Krypton", "Kr", 36, 83.80},
        {"Rubidium", "Rb", 37, 85.47},
        {"Strontium", "Sr", 38, 87.62},
        {"Yttrium", "Y", 39, 88.91},
        {"Zirconium", "Zr", 40, 91.22},
        {"Niobium", "Nb", 41, 92.91},
        {"Molybdenum", "Mo", 42, 95.94},
        {"Technetium", "Tc", 43, 98.00},
        {"Ruthenium", "Ru", 44, 101.07},
        {"Rhodium", "Rh", 45, 102.91},
        {"Palladium", "Pd", 46, 106.42},
        {"Silver", "Ag", 47, 107.87},
        {"Cadmium", "Cd", 48, 112.41},
        {"Indium", "In", 49, 114.82},
        {"Tin", "Sn", 50, 118.71},
        {"Antimony", "Sb", 51, 121.76},
        {"Tellurium", "Te", 52, 127.60},
        {"Iodine", "I", 53, 126.90},
        {"Xenon", "Xe", 54, 131.29},
        {"Cesium", "Cs", 55, 132.91},
        {"Barium", "Ba", 56, 137.33},
        {"Lanthanum", "La", 57, 138.91},
        {"Cerium", "Ce", 58, 140.12},
        {"Praseodymium", "Pr", 59, 140.91},
        {"Neodymium", "Nd", 60, 144.24},
        {"Promethium", "Pm", 61, 145.00},
        {"Samarium", "Sm", 62, 150.36},
        {"Europium", "Eu", 63, 151.96},
        {"Gadolinium", "Gd", 64, 157.25},
        {"Terbium", "Tb", 65, 158.93},
        {"Dysprosium", "Dy", 66, 162.50},
        {"Holmium", "Ho", 67, 164.93},
        {"Erbium", "Er", 68, 167.26},
        {"Thulium", "Tm", 69, 168.93},
        {"Ytterbium", "Yb", 70, 173.05},
        {"Lutetium", "Lu", 71, 174.97},
        {"Hafnium", "Hf", 72, 178.49},
        {"Tantalum", "Ta", 73, 180.95},
        {"Tungsten", "W", 74, 183.84},
        {"Rhenium", "Re", 75, 186.21},
        {"Osmium", "Os", 76, 190.23},
        {"Iridium", "Ir", 77, 192.22},
        {"Platinum", "Pt", 78, 195.08},
        {"Gold", "Au", 79, 196.97},
        {"Mercury", "Hg", 80, 200.59},
        {"Thallium", "Tl", 81, 204.38},
        {"Lead", "Pb", 82, 207.2},
        {"Bismuth", "Bi", 83, 208.98},
        {"Polonium", "Po", 84, 209.00},
        {"Astatine", "At", 85, 210.00},
        {"Radon", "Rn", 86, 222.00},
        {"Francium", "Fr", 87, 223.00},
        {"Radium", "Ra", 88, 226.03},
        {"Actinium", "Ac", 89, 227.03},
        {"Thorium", "Th", 90, 232.04},
        {"Protactinium", "Pa", 91, 231.04},
        {"Uranium", "U", 92, 238.03},
        {"Neptunium", "Np", 93, 237.05},
        {"Plutonium", "Pu", 94, 244.06},
        {"Americium", "Am", 95, 243.06},
        {"Curium", "Cm", 96, 247.07},
        {"Berkelium", "Bk", 97, 247.07},
        {"Californium", "Cf", 98, 251.08},
        {"Einsteinium", "Es", 99, 252.08},
        {"Fermium", "Fm", 100, 257.10},
        {"Mendelevium", "Md", 101, 258.10},
        {"Nobelium", "No", 102, 259.10},
        {"Lawrencium", "Lr", 103, 262.11},
        {"Rutherfordium", "Rf", 104, 267.12},
        {"Dubnium", "Db", 105, 270.13},
        {"Seaborgium", "Sg", 106, 271.13},
        {"Bohrium", "Bh", 107, 270.13},
        {"Hassium", "Hs", 108, 277.15},
        {"Meitnerium", "Mt", 109, 276.15},
        {"Darmstadtium", "Ds", 110, 281.16},
        {"Roentgenium", "Rg", 111, 280.16},
        {"Copernicium", "Cn", 112, 285.18},
        {"Nihonium", "Nh", 113, 284},
        {"Flerovium", "Fl", 114, 289},
        {"Moscovium", "Mc", 115, 288},
        {"Livermorium", "Lv", 116, 293},
        {"Tennessine", "Ts", 117, 294},
        {"Oganesson", "Og", 118, 294}
};

int main() {
    playGame();

    return 0;
}

// Clear the console screen
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Get a random index into the elements array
int getRandomIndex() {
    return rand() % NUM_ELEMENTS;
}

// Print out the specified element
void printElement(struct Element element) {
    printf("\nElement Name: %s\n", element.name);
    printf("Symbol: %s\n", element.symbol);
    printf("Atomic Number: %d\n", element.atomicNumber);
    printf("Atomic Weight: %f\n", element.atomicWeight);
}

// Prompt the user for a guess and return their input
int getGuess() {
    int guess;
    printf("\nGuess the atomic number: ");
    scanf("%d", &guess);
    return guess;
}

// Check if the user's guess is correct or not
void checkAnswer(struct Element element, int guess) {
    if (guess == element.atomicNumber) {
        printf("\nCorrect!!\n");
    } else {
        printf("\nIncorrect. The answer is %d.\n", element.atomicNumber);
    }
}

// Play the game
void playGame() {
    char input[10];
    int playing = 1;
    while (playing) {
        clearScreen();
        printf("Welcome to the Periodic Table Quiz!\n");
        printf("Type 'play' to start a game or 'quit' to exit.\n");
        printf(">> ");
        scanf("%s", input);
        if (strcmp(input, "play") == 0) {
            int numCorrect = 0;
            while (1) {
                struct Element element = elements[getRandomIndex()];
                printElement(element);
                int guess = getGuess();
                checkAnswer(element, guess);
                numCorrect += (guess == element.atomicNumber);
                printf("Current Score: %d\n", numCorrect);
                printf("Type 'quit' to end the game or press any other key to continue.\n");
                printf(">> ");
                scanf("%s", input);
                if (strcmp(input, "quit") == 0) {
                    printf("\nFinal Score: %d\n", numCorrect);
                    printf("Thanks for playing!\n");
                    break;
                }
                clearScreen();
            }
        } else if (strcmp(input, "quit") == 0) {
            playing = 0;
        } else {
            printf("\nInvalid input. Please try again.\n");
        }
    }
}