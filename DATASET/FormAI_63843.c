//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: unmistakable
#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 50
#define MAX_SYMBOL_LENGTH 3

typedef struct Element {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomicNumber;
} Element;

void printTable(Element table[]) {
    printf("Periodic Table of Elements:\n\n");
    printf("Name\t\tSymbol\tAtomic Number\n");
    printf("----------------------------------\n");
    for(int i=0; i<MAX_ELEMENTS; i++) {
        printf("%-14s\t%-3s\t%d\n", table[i].name, table[i].symbol, table[i].atomicNumber);
    }
}

void quiz(Element table[]) {
    char input[MAX_SYMBOL_LENGTH];
    int score = 0;
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Enter the symbol for the element with the given atomic number.\n");
    printf("Enter \"quit\" at any time to exit the quiz.\n\n");
    
    for(int i=0; i<MAX_ELEMENTS; i++) {
        printf("What is the symbol for element %d?\n", table[i].atomicNumber);
        scanf("%s", input);
        if(strcmp(input, "quit") == 0) {
            break;
        }
        if(strcmp(input, table[i].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct symbol is %s.\n", table[i].symbol);
        }
    }
    
    printf("Quiz complete! You scored %d out of %d.\n", score, MAX_ELEMENTS);
}

int main() {
    Element periodicTable[MAX_ELEMENTS] = {
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
        {"Sulfur", "S", 16},
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
    
    printTable(periodicTable);
    quiz(periodicTable);
    
    return 0;
}