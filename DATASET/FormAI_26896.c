//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define NUM_ELEMENTS 118
#define MAX_ELEMENT_NAME_LENGTH 15
#define MAX_QUESTION_LENGTH 100

typedef struct {
    char name[MAX_ELEMENT_NAME_LENGTH];
    char symbol[3]; // Includes null terminator
    int atomic_number;
} Element;

// Initial list of elements
Element elements[NUM_ELEMENTS] = {
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
    {"Aluminium", "Al", 13},
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
    {"Oganesson", "Og", 118}
};

int main(void)
{
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("There are %d elements. Let's see how many you can name.\n", NUM_ELEMENTS);
    printf("For each question, please enter the atomic symbol of the element.\n");

    bool correct_answers[NUM_ELEMENTS] = {false}; // Array to track correct/incorrect answers
    
    // Generate 10 random element questions
    int question_indices[10] = {0};
    for (int i = 0; i < 10; i++) {
        int question_index = rand() % NUM_ELEMENTS;
        while (correct_answers[question_index]) {
            question_index = rand() % NUM_ELEMENTS;
        }
        question_indices[i] = question_index;
    }
    
    // Ask each question and check answer
    int num_correct = 0;
    for (int i = 0; i < 10; i++) {
        Element question_element = elements[question_indices[i]];
        char question[MAX_QUESTION_LENGTH];
        snprintf(question, MAX_QUESTION_LENGTH, "What is the atomic symbol for %s?", question_element.name);
        printf("%s\n", question);
        char user_answer[3];
        scanf("%s", user_answer);
        for (int j = 0; j < strlen(user_answer); j++) {
            user_answer[j] = toupper(user_answer[j]);
        }
        if (strcmp(question_element.symbol, user_answer) == 0) {
            printf("Correct!\n");
            correct_answers[question_indices[i]] = true;
            num_correct++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", question_element.symbol);
        }
    }
    
    // Output results
    printf("You got %d out of 10 questions correct.\n", num_correct);
    if (num_correct >= 8) {
        printf("Great job!\n");
    } else if (num_correct >= 6) {
        printf("Not bad!\n");
    } else {
        printf("Maybe study a bit more and try again?\n");
    }

    return 0;
}