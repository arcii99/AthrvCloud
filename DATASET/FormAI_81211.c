//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: minimalist
#include <stdio.h>
#include <string.h>

// Define the maximum number of elements in the periodic table
#define MAX_ELEMENTS 118

// Define the maximum number of questions in the quiz
#define MAX_QUESTIONS 5

// Define the maximum number of attempts for each question
#define MAX_ATTEMPTS 3

// Define a structure to hold data for each element
struct Element {
    char symbol[3];
    char name[30];
    int atomic_number;
};

// Create an array to hold all the elements in the periodic table
struct Element elements[MAX_ELEMENTS] = {
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

// Function to display a welcome message to the user
void display_welcome_message() {
    printf("Welcome to the C Periodic Table Quiz!\n\n");
    printf("This quiz will test your knowledge of the periodic table.\n");
    printf("You will be asked %d questions, and for each question you will have %d attempts to provide the correct answer.\n\n", MAX_QUESTIONS, MAX_ATTEMPTS);
}

// Function to get a random index within the range of the elements array
int get_random_index() {
    return rand() % MAX_ELEMENTS;
}

// Function to get a random element from the periodic table array
struct Element get_random_element() {
    int index = get_random_index();
    return elements[index];
}

// Function to get the answer from the user
void get_user_answer(char* answer, int max_length) {
    printf("Enter your answer: ");
    fgets(answer, max_length, stdin);
    strtok(answer, "\n"); // Remove newline character
}

// Function to check if the user's answer is correct
int is_correct_answer(struct Element element, char* answer) {
    return (strcasecmp(element.name, answer) == 0 || strcasecmp(element.symbol, answer) == 0 || atoi(answer) == element.atomic_number);
}

int main() {
    display_welcome_message();

    int correct_answers = 0;
    for (int i = 1; i <= MAX_QUESTIONS; i++) {
        struct Element element = get_random_element();
        printf("Question %d:\n", i);
        for (int j = 1; j <= MAX_ATTEMPTS; j++) {
            char answer[30];
            get_user_answer(answer, sizeof(answer));
            if (is_correct_answer(element, answer)) {
                printf("Correct!\n\n");
                correct_answers++;
                break;
            }
            else {
                printf("Incorrect. Please try again.\n");
            }
        }
        printf("The correct answer was: %s (%s, %d)\n\n", element.name, element.symbol, element.atomic_number);
    }

    printf("You answered %d out of %d questions correctly.\n", correct_answers, MAX_QUESTIONS);

    return 0;
}