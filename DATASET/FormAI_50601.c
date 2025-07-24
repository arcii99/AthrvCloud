//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_QUESTIONS 10

typedef struct element {
    int atomicNumber;
    char symbol[3];
    char name[20];
    float atomicMass;
} Element;

Element periodicTable[MAX_ELEMENTS] = {
    {1, "H", "Hydrogen", 1.008},
    {2, "He", "Helium", 4.003},
    {3, "Li", "Lithium", 6.941},
    {4, "Be", "Beryllium", 9.012},
    {5, "B", "Boron", 10.81},
    {6, "C", "Carbon", 12.01},
    {7, "N", "Nitrogen", 14.01},
    {8, "O", "Oxygen", 16.00},
    {9, "F", "Fluorine", 19.00},
    {10, "Ne", "Neon", 20.18},
    {11, "Na", "Sodium", 22.99},
    {12, "Mg", "Magnesium", 24.31},
    {13, "Al", "Aluminum", 26.98},
    {14, "Si", "Silicon", 28.09},
    {15, "P", "Phosphorus", 30.97},
    {16, "S", "Sulfur", 32.07},
    {17, "Cl", "Chlorine", 35.45},
    {18, "Ar", "Argon", 39.95},
    {19, "K", "Potassium", 39.10},
    {20, "Ca", "Calcium", 40.08},
    {21, "Sc", "Scandium", 44.96},
    {22, "Ti", "Titanium", 47.87},
    {23, "V", "Vanadium", 50.94},
    {24, "Cr", "Chromium", 52.00},
    {25, "Mn", "Manganese", 54.94},
    {26, "Fe", "Iron", 55.85},
    {27, "Co", "Cobalt", 58.93},
    {28, "Ni", "Nickel", 58.69},
    {29, "Cu", "Copper", 63.55},
    {30, "Zn", "Zinc", 65.38},
    {31, "Ga", "Gallium", 69.72},
    {32, "Ge", "Germanium", 72.63},
    {33, "As", "Arsenic", 74.92},
    {34, "Se", "Selenium", 78.96},
    {35, "Br", "Bromine", 79.90},
    {36, "Kr", "Krypton", 83.80},
    {37, "Rb", "Rubidium", 85.47},
    {38, "Sr", "Strontium", 87.62},
    {39, "Y", "Yttrium", 88.91},
    {40, "Zr", "Zirconium", 91.22},
    {41, "Nb", "Niobium", 92.91},
    {42, "Mo", "Molybdenum", 95.94},
    {43, "Tc", "Technetium", 98},
    {44, "Ru", "Ruthenium", 101.1},
    {45, "Rh", "Rhodium", 102.9},
    {46, "Pd", "Palladium", 106.4},
    {47, "Ag", "Silver", 107.9},
    {48, "Cd", "Cadmium", 112.4},
    {49, "In", "Indium", 114.8},
    {50, "Sn", "Tin", 118.7},
    {51, "Sb", "Antimony", 121.8},
    {52, "Te", "Tellurium", 127.6},
    {53, "I", "Iodine", 126.9},
    {54, "Xe", "Xenon", 131.3},
    {55, "Cs", "Cesium", 132.9},
    {56, "Ba", "Barium", 137.3},
    {57, "La", "Lanthanum", 138.9},
    {58, "Ce", "Cerium", 140.1},
    {59, "Pr", "Praseodymium", 140.9},
    {60, "Nd", "Neodymium", 144.2},
    {61, "Pm", "Promethium", 145},
    {62, "Sm", "Samarium", 150.4},
    {63, "Eu", "Europium", 151.9},
    {64, "Gd", "Gadolinium", 157.3},
    {65, "Tb", "Terbium", 158.9},
    {66, "Dy", "Dysprosium", 162.5},
    {67, "Ho", "Holmium", 164.9},
    {68, "Er", "Erbium", 167.3},
    {69, "Tm", "Thulium", 168.9},
    {70, "Yb", "Ytterbium", 173.1},
    {71, "Lu", "Lutetium", 175},
    {72, "Hf", "Hafnium", 178.5},
    {73, "Ta", "Tantalum", 180.9},
    {74, "W", "Tungsten", 183.8},
    {75, "Re", "Rhenium", 186.2},
    {76, "Os", "Osmium", 190.2},
    {77, "Ir", "Iridium", 192.2},
    {78, "Pt", "Platinum", 195.1},
    {79, "Au", "Gold", 197},
    {80, "Hg", "Mercury", 200.6},
    {81, "Tl", "Thallium", 204.4},
    {82, "Pb", "Lead", 207.2},
    {83, "Bi", "Bismuth", 208.9},
    {84, "Po", "Polonium", 209},
    {85, "At", "Astatine", 210},
    {86, "Rn", "Radon", 222},
    {87, "Fr", "Francium", 223},
    {88, "Ra", "Radium", 226.0},
    {89, "Ac", "Actinium", 227.0},
    {90, "Th", "Thorium", 232.0},
    {91, "Pa", "Protactinium", 231.0},
    {92, "U", "Uranium", 238.0},
    {93, "Np", "Neptunium", 237.0},
    {94, "Pu", "Plutonium", 244.0},
    {95, "Am", "Americium", 243.0},
    {96, "Cm", "Curium", 247.0},
    {97, "Bk", "Berkelium", 247.0},
    {98, "Cf", "Californium", 251.0},
    {99, "Es", "Einsteinium", 252.0},
    {100, "Fm", "Fermium", 257.0},
    {101, "Md", "Mendelevium", 258.0},
    {102, "No", "Nobelium", 259.0},
    {103, "Lr", "Lawrencium", 266.0},
    {104, "Rf", "Rutherfordium", 267.0},
    {105, "Db", "Dubnium", 268.0},
    {106, "Sg", "Seaborgium", 271.0},
    {107, "Bh", "Bohrium", 270.0},
    {108, "Hs", "Hassium", 277.0},
    {109, "Mt", "Meitnerium", 276.0},
    {110, "Ds", "Darmstadtium", 281.0},
    {111, "Rg", "Roentgenium", 280.0},
    {112, "Cn", "Copernicium", 285.0},
    {113, "Nh", "Nihonium", 284.0},
    {114, "Fl", "Flerovium", 289.0},
    {115, "Mc", "Moscovium", 288.0},
    {116, "Lv", "Livermorium", 293.0},
    {117, "Ts", "Tennessine", 294.0},
    {118, "Og", "Oganesson", 294.0},
};

void shuffleArray(int arr[], int size) {
    // Shuffle array using Fisher-Yates algorithm
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void printElement(int atomicNumber) {
    Element e = periodicTable[atomicNumber - 1];
    printf("Element %d: %s (%s) - Atomic Mass: %.3f\n", e.atomicNumber, e.symbol, e.name, e.atomicMass);
}

int main() {
    srand(time(NULL));
    int questions[MAX_QUESTIONS];
    int score = 0;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d multiple choice questions about elements from the periodic table.\n", MAX_QUESTIONS);

    // Generate random questions without repetition
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        questions[i] = rand() % MAX_ELEMENTS + 1;
        for (int j = 0; j < i; j++) {
            if (questions[i] == questions[j]) {
                i--;
                break;
            }
        }
    }

    // Main quiz loop
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        // Shuffle answer choices
        int choices[4] = { questions[i], rand() % MAX_ELEMENTS + 1, rand() % MAX_ELEMENTS + 1, rand() % MAX_ELEMENTS + 1 };
        shuffleArray(choices, 4);

        // Print question and answer choices
        printf("\nQuestion %d of %d:", i + 1, MAX_QUESTIONS);
        printf("\nWhat is the symbol of ");
        printElement(questions[i]);
        printf("A) %s\tB) %s\tC) %s\tD) %s\n", periodicTable[choices[0] - 1].symbol, periodicTable[choices[1] - 1].symbol, periodicTable[choices[2] - 1].symbol, periodicTable[choices[3] - 1].symbol);

        // Get user input and validate
        char answer;
        printf("Enter your answer (A, B, C, or D): ");
        while (1) {
            scanf(" %c", &answer);
            if (answer == 'A' || answer == 'B' || answer == 'C' || answer == 'D') {
                break;
            }
            printf("Invalid input. Please enter A, B, C, or D: ");
        }

        // Check if answer is correct and update score
        if (answer == 'A' && choices[0] == questions[i]) {
            printf("Correct!\n");
            score++;
        } else if (answer == 'B' && choices[1] == questions[i]) {
            printf("Correct!\n");
            score++;
        } else if (answer == 'C' && choices[2] == questions[i]) {
            printf("Correct!\n");
            score++;
        } else if (answer == 'D' && choices[3] == questions[i]) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer was %s.\n", periodicTable[questions[i] - 1].symbol);
        }
    }

    // Print final score
    printf("\nYou scored %d/%d.\n", score, MAX_QUESTIONS);

    return 0;
}