//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const int NUM_ELEMENTS = 118; // Total number of known elements
const int NUM_QUESTIONS = 10; // Number of questions to ask in the quiz

struct Element {
    char name[20];
    char symbol[3];
    int atomic_number;
};

static const struct Element elements[] = {
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
    {"Oganesson", "Og", 118}
};

void shuffle_array(int *array, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

int main() {
    int question_num = 1; // Keep track of the current question number
    int correct_count = 0; // Keep track of how many questions the user answers correctly
    int answers[NUM_QUESTIONS]; // Keep track of the indices of the randomly selected elements
    char user_answer[10]; // Store the user's answer to each question

    // Print introductory message
    printf("Welcome to the Periodic Table Quiz!\nYou will be asked 10 random questions from the periodic table.\n");

    // Seed the random number generator
    srand(time(NULL));

    // Generate the indices for the random questions
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        answers[i] = rand() % NUM_ELEMENTS;
    }

    // Shuffle the order of the questions
    shuffle_array(answers, NUM_QUESTIONS);

    // Loop through each question
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        // Get the current question
        struct Element current_element = elements[answers[i]];

        // Print the current question number and the question itself
        printf("\nQuestion %d: What is the atomic number of %s?\n", question_num, current_element.name);

        // Get the user's answer
        scanf("%s", user_answer);

        // Convert the user's answer to an integer
        int user_answer_int = atoi(user_answer);

        // Check if the user's answer is correct
        if (user_answer_int == current_element.atomic_number) {
            printf("Correct!\n");
            correct_count++;
        } else {
            printf("Incorrect! The correct answer is %d.\n", current_element.atomic_number);
        }

        // Increment the question number
        question_num++;
    }

    // Print the user's score
    printf("\nYou answered %d out of %d questions correctly!\n", correct_count, NUM_QUESTIONS);

    return 0;
}