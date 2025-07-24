//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 118

// Element struct for holding information about each element
typedef struct {
    char symbol[3];
    char name[20];
    int atomic_number;
} Element;

// Function to shuffle an array using Fisher-Yates algorithm
void shuffle_array(int arr[], int size) {
    int i, j, temp;
    for (i = size - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Create array of element struct
    Element elements[MAX_ELEMENTS] = {
        {"H", "Hydrogen", 1},
        {"He", "Helium", 2},
        {"Li", "Lithium", 3},
        {"Be", "Beryllium", 4},
        {"B", "Boron", 5},
        {"C", "Carbon", 6},
        {"N", "Nitrogen", 7},
        {"O", "Oxygen", 8},
        {"F", "Fluorine", 9},
        {"Ne", "Neon", 10},
        {"Na", "Sodium", 11},
        {"Mg", "Magnesium", 12},
        {"Al", "Aluminum", 13},
        {"Si", "Silicon", 14},
        {"P", "Phosphorus", 15},
        {"S", "Sulfur", 16},
        {"Cl", "Chlorine", 17},
        {"Ar", "Argon", 18},
        {"K", "Potassium", 19},
        {"Ca", "Calcium", 20},
        {"Sc", "Scandium", 21},
        {"Ti", "Titanium", 22},
        {"V", "Vanadium", 23},
        {"Cr", "Chromium", 24},
        {"Mn", "Manganese", 25},
        {"Fe", "Iron", 26},
        {"Co", "Cobalt", 27},
        {"Ni", "Nickel", 28},
        {"Cu", "Copper", 29},
        {"Zn", "Zinc", 30},
        {"Ga", "Gallium", 31},
        {"Ge", "Germanium", 32},
        {"As", "Arsenic", 33},
        {"Se", "Selenium", 34},
        {"Br", "Bromine", 35},
        {"Kr", "Krypton", 36},
        {"Rb", "Rubidium", 37},
        {"Sr", "Strontium", 38},
        {"Y", "Yttrium", 39},
        {"Zr", "Zirconium", 40},
        {"Nb", "Niobium", 41},
        {"Mo", "Molybdenum", 42},
        {"Tc", "Technetium", 43},
        {"Ru", "Ruthenium", 44},
        {"Rh", "Rhodium", 45},
        {"Pd", "Palladium", 46},
        {"Ag", "Silver", 47},
        {"Cd", "Cadmium", 48},
        {"In", "Indium", 49},
        {"Sn", "Tin", 50},
        {"Sb", "Antimony", 51},
        {"Te", "Tellurium", 52},
        {"I", "Iodine", 53},
        {"Xe", "Xenon", 54},
        {"Cs", "Cesium", 55},
        {"Ba", "Barium", 56},
        {"La", "Lanthanum", 57},
        {"Ce", "Cerium", 58},
        {"Pr", "Praseodymium", 59},
        {"Nd", "Neodymium", 60},
        {"Pm", "Promethium", 61},
        {"Sm", "Samarium", 62},
        {"Eu", "Europium", 63},
        {"Gd", "Gadolinium", 64},
        {"Tb", "Terbium", 65},
        {"Dy", "Dysprosium", 66},
        {"Ho", "Holmium", 67},
        {"Er", "Erbium", 68},
        {"Tm", "Thulium", 69},
        {"Yb", "Ytterbium", 70},
        {"Lu", "Lutetium", 71},
        {"Hf", "Hafnium", 72},
        {"Ta", "Tantalum", 73},
        {"W", "Tungsten", 74},
        {"Re", "Rhenium", 75},
        {"Os", "Osmium", 76},
        {"Ir", "Iridium", 77},
        {"Pt", "Platinum", 78},
        {"Au", "Gold", 79},
        {"Hg", "Mercury", 80},
        {"Tl", "Thallium", 81},
        {"Pb", "Lead", 82},
        {"Bi", "Bismuth", 83},
        {"Po", "Polonium", 84},
        {"At", "Astatine", 85},
        {"Rn", "Radon", 86},
        {"Fr", "Francium", 87},
        {"Ra", "Radium", 88},
        {"Ac", "Actinium", 89},
        {"Th", "Thorium", 90},
        {"Pa", "Protactinium", 91},
        {"U", "Uranium", 92},
        {"Np", "Neptunium", 93},
        {"Pu", "Plutonium", 94},
        {"Am", "Americium", 95},
        {"Cm", "Curium", 96},
        {"Bk", "Berkelium", 97},
        {"Cf", "Californium", 98},
        {"Es", "Einsteinium", 99},
        {"Fm", "Fermium", 100},
        {"Md", "Mendelevium", 101},
        {"No", "Nobelium", 102},
        {"Lr", "Lawrencium", 103},
        {"Rf", "Rutherfordium", 104},
        {"Db", "Dubnium", 105},
        {"Sg", "Seaborgium", 106},
        {"Bh", "Bohrium", 107},
        {"Hs", "Hassium", 108},
        {"Mt", "Meitnerium", 109},
        {"Ds", "Darmstadtium", 110},
        {"Rg", "Roentgenium", 111},
        {"Cn", "Copernicium", 112},
        {"Nh", "Nihonium", 113},
        {"Fl", "Flerovium", 114},
        {"Mc", "Moscovium", 115},
        {"Lv", "Livermorium", 116},
        {"Ts", "Tennessine", 117},
        {"Og", "Oganesson", 118}
    };
    
    // Generate random order for elements to ask about
    int element_order[MAX_ELEMENTS];
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        element_order[i] = i;
    }
    shuffle_array(element_order, MAX_ELEMENTS);
    
    // Print instructions and start quiz
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be shown the symbol or name of an element and asked to provide its corresponding atomic number.\n");
    printf("Enter '-1' at any time to quit the quiz.\n");
    printf("\n");
    
    int score = 0;
    char input[20];
    int answer;
    int continue_quiz = 1;
    
    for (int i = 0; i < MAX_ELEMENTS && continue_quiz; i++) {
        printf("\nQuestion %d:\n", i + 1);
        
        // Choose whether to ask for symbol or name
        int attribute_choice = rand() % 2;
        if (attribute_choice == 0) {
            printf("What is the atomic number of the element with symbol '%s'? ", elements[element_order[i]].symbol);
        } else {
            printf("What is the atomic number of the element '%s'? ", elements[element_order[i]].name);
        }
        
        // Get user input and check if it is valid
        scanf("%s", input);
        answer = atoi(input);
        while (answer < -1 || answer > 118 || (answer > 0 && strcmp(input, elements[answer - 1].symbol) != 0 && strcmp(input, elements[answer - 1].name) != 0)) {
            printf("Invalid input. What is the atomic number of the element? ");
            scanf("%s", input);
            answer = atoi(input);
        }
        
        if (answer == -1) {
            continue_quiz = 0;
        } else if (answer == elements[element_order[i]].atomic_number) {
            score++;
            printf("Correct! Your score is now %d.\n", score);
        } else {
            printf("Incorrect. The correct answer is %d for %s.\n", elements[element_order[i]].atomic_number, 
                                                                  attribute_choice == 0 ? elements[element_order[i]].symbol : elements[element_order[i]].name);
        }
    }
    
    printf("\nQuiz complete. Your final score is %d out of %d.\n", score, MAX_ELEMENTS);
    
    return 0;
}