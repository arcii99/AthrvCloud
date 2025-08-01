//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum number of elements in the periodic table
#define MAX_ELEMENTS 118

// define the maximum length of an element name
#define MAX_NAME_LEN 20

// define the maximum number of questions in the quiz
#define MAX_QUESTIONS 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[3]; // includes null terminator
    int atomic_number;
} Element;

Element periodic_table[MAX_ELEMENTS] = {
    {"Hydrogen", "H", 1},
    {"Helium", "He", 2},
    {"Lithium", "Li", 3},
    {"Beryllium", "Be", 4},
    {"Boron", "B", 5},
    {"Carbon", "C", 6},
    {"Nitrogen", "N", 7},
    {"Oxygen", "O", 8},
    {"Fluorine", "F", 9},
    {"Neon", "Ne", 10},
    {"Sodium", "Na", 11},
    {"Magnesium", "Mg", 12},
    {"Aluminum", "Al", 13},
    {"Silicon", "Si", 14},
    {"Phosphorus", "P", 15},
    {"Sulphur", "S", 16},
    {"Chlorine", "Cl", 17},
    {"Argon", "Ar", 18},
    {"Potassium", "K", 19},
    {"Calcium", "Ca", 20},
    {"Scandium", "Sc", 21},
    {"Titanium", "Ti", 22},
    {"Vanadium", "V", 23},
    {"Chromium", "Cr", 24},
    {"Manganese", "Mn", 25},
    {"Iron", "Fe", 26},
    {"Cobalt", "Co", 27},
    {"Nickel", "Ni", 28},
    {"Copper", "Cu", 29},
    {"Zinc", "Zn", 30},
    {"Gallium", "Ga", 31},
    {"Germanium", "Ge", 32},
    {"Arsenic", "As", 33},
    {"Selenium", "Se", 34},
    {"Bromine", "Br", 35},
    {"Krypton", "Kr", 36},
    {"Rubidium", "Rb", 37},
    {"Strontium", "Sr", 38},
    {"Yttrium", "Y", 39},
    {"Zirconium", "Zr", 40},
    {"Niobium", "Nb", 41},
    {"Molybdenum", "Mo", 42},
    {"Technetium", "Tc", 43},
    {"Ruthenium", "Ru", 44},
    {"Rhodium", "Rh", 45},
    {"Palladium", "Pd", 46},
    {"Silver", "Ag", 47},
    {"Cadmium", "Cd", 48},
    {"Indium", "In", 49},
    {"Tin", "Sn", 50},
    {"Antimony", "Sb", 51},
    {"Tellurium", "Te", 52},
    {"Iodine", "I", 53},
    {"Xenon", "Xe", 54},
    {"Cesium", "Cs", 55},
    {"Barium", "Ba", 56},
    {"Lanthanum", "La", 57},
    {"Cerium", "Ce", 58},
    {"Praseodymium", "Pr", 59},
    {"Neodymium", "Nd", 60},
    {"Promethium", "Pm", 61},
    {"Samarium", "Sm", 62},
    {"Europium", "Eu", 63},
    {"Gadolinium", "Gd", 64},
    {"Terbium", "Tb", 65},
    {"Dysprosium", "Dy", 66},
    {"Holmium", "Ho", 67},
    {"Erbium", "Er", 68},
    {"Thulium", "Tm", 69},
    {"Ytterbium", "Yb", 70},
    {"Lutetium", "Lu", 71},
    {"Hafnium", "Hf", 72},
    {"Tantalum", "Ta", 73},
    {"Tungsten", "W", 74},
    {"Rhenium", "Re", 75},
    {"Osmium", "Os", 76},
    {"Iridium", "Ir", 77},
    {"Platinum", "Pt", 78},
    {"Gold", "Au", 79},
    {"Mercury", "Hg", 80},
    {"Thallium", "Tl", 81},
    {"Lead", "Pb", 82},
    {"Bismuth", "Bi", 83},
    {"Polonium", "Po", 84},
    {"Astatine", "At", 85},
    {"Radon", "Rn", 86},
    {"Francium", "Fr", 87},
    {"Radium", "Ra", 88},
    {"Actinium", "Ac", 89},
    {"Thorium", "Th", 90},
    {"Protactinium", "Pa", 91},
    {"Uranium", "U", 92},
    {"Neptunium", "Np", 93},
    {"Plutonium", "Pu", 94},
    {"Americium", "Am", 95},
    {"Curium", "Cm", 96},
    {"Berkelium", "Bk", 97},
    {"Californium", "Cf", 98},
    {"Einsteinium", "Es", 99},
    {"Fermium", "Fm", 100},
    {"Mendelevium", "Md", 101},
    {"Nobelium", "No", 102},
    {"Lawrencium", "Lr", 103},
    {"Rutherfordium", "Rf", 104},
    {"Dubnium", "Db", 105},
    {"Seaborgium", "Sg", 106},
    {"Bohrium", "Bh", 107},
    {"Hassium", "Hs", 108},
    {"Meitnerium", "Mt", 109},
    {"Darmstadtium", "Ds", 110},
    {"Roentgenium", "Rg", 111},
    {"Copernicium", "Cn", 112},
    {"Nihonium", "Nh", 113},
    {"Flerovium", "Fl", 114},
    {"Moscovium", "Mc", 115},
    {"Livermorium", "Lv", 116},
    {"Tennessine", "Ts", 117},
    {"Oganesson", "Og", 118},
};

void print_table() {
    printf("---------------------------------------------------------------------------\n");
    printf("| Name                 | Symbol | Atomic Number | Name                 |\n");
    printf("---------------------------------------------------------------------------\n");

    // print the elements in four columns
    for (int i = 0; i < 118; i += 4) {
        printf("| %-20s| %-7s| %-14d|", periodic_table[i].name, periodic_table[i].symbol, periodic_table[i].atomic_number);
        if (i + 1 < 118) { // check bounds
            printf(" %-20s| %-7s| %-14d|", periodic_table[i+1].name, periodic_table[i+1].symbol, periodic_table[i+1].atomic_number);
        }
        if (i + 2 < 118) { // check bounds
            printf(" %-20s| %-7s| %-14d|", periodic_table[i+2].name, periodic_table[i+2].symbol, periodic_table[i+2].atomic_number);
        }
        if (i + 3 < 118) { // check bounds
            printf(" %-20s| %-7s| %-14d|", periodic_table[i+3].name, periodic_table[i+3].symbol, periodic_table[i+3].atomic_number);
        }
        printf("\n");
    }
    printf("---------------------------------------------------------------------------\n");
}

void shuffle_array(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        // generate a random index between 0 and i (inclusive)
        int j = rand() % (i + 1);

        // swap elements at indices i and j
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void take_quiz() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions about elements in the periodic table.\n", MAX_QUESTIONS);

    // generate an array of random indices for the quiz questions
    int question_indices[MAX_ELEMENTS];
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        question_indices[i] = i;
    }
    shuffle_array(question_indices, MAX_ELEMENTS);

    // keep track of the number of correct answers
    int num_correct = 0;

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        int index = question_indices[i];

        printf("\nQuestion %d: What is the symbol for %s?\n", i+1, periodic_table[index].name);

        char answer[3];
        scanf("%s", answer);

        if (strcmp(answer, periodic_table[index].symbol) == 0) {
            printf("Correct!\n");
            num_correct++;
        } else {
            printf("Incorrect. The correct symbol is %s.\n", periodic_table[index].symbol);
        }
    }

    printf("\nYour score: %d/%d\n", num_correct, MAX_QUESTIONS);
}

int main() {
    print_table();

    char choice;
    printf("\nTake the quiz? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y') {
        take_quiz();
    }

    printf("\nGoodbye!\n");

    return 0;
}