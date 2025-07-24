//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10 // maximum number of questions in quiz
#define MAX_ANSWERS 4 // maximum number of answers per question

typedef struct {
    char *elementName; // element name eg. Hydrogen
    char symbol[3]; // atomic symbol eg. H
    int atomicNumber; // atomic number eg. 1
} Element;

Element periodicTable[118] = {
    {"Hydrogen", "H ", 1},
    {"Helium", "He", 2},
    {"Lithium", "Li", 3},
    {"Beryllium", "Be", 4},
    {"Boron", "B ", 5},
    {"Carbon", "C ", 6},
    {"Nitrogen", "N ", 7},
    {"Oxygen", "O ", 8},
    {"Fluorine", "F ", 9},
    {"Neon", "Ne", 10},
    {"Sodium", "Na", 11},
    {"Magnesium", "Mg", 12},
    {"Aluminum", "Al", 13},
    {"Silicon", "Si", 14},
    {"Phosphorus", "P ", 15},
    {"Sulfur", "S ", 16},
    {"Chlorine", "Cl", 17},
    {"Argon", "Ar", 18},
    {"Potassium", "K ", 19},
    {"Calcium", "Ca", 20},
    {"Scandium", "Sc", 21},
    {"Titanium", "Ti", 22},
    {"Vanadium", "V ", 23},
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
    {"Yttrium", "Y ", 39},
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
    {"Iodine", "I ", 53},
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
    {"Tungsten", "W ", 74},
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
    {"Uranium", "U ", 92},
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

char *questions[MAX_QUESTIONS] = {
    "What is the symbol for the element with atomic number 55?",
    "What is the atomic number of the element with symbol Mg?",
    "What is the symbol for the element with atomic number 30?",
    "What is the atomic number of the element with symbol Se?",
    "What is the symbol for the element with atomic number 8?",
    "What is the atomic number of the element with symbol Pb?",
    "What is the symbol for the element with atomic number 109?",
    "What is the atomic number of the element with symbol Hf?",
    "What is the symbol for the element with atomic number 86?",
    "What is the atomic number of the element with symbol Na?"
};

char *answers[MAX_QUESTIONS][MAX_ANSWERS] = {
    {"Cs", "K ", "Rb", "Ba"},
    {"10", "12", "14", "24"},
    {"Zn", "Cu", "Ni", "Fe"},
    {"16", "33", "44", "68"},
    {"O ", "N ", "H ", "C "},
    {"82", "32", "78", "15"},
    {"Mt", "Fl", "Mc", "Lv"},
    {"72", "65", "67", "58"},
    {"Kr", "Ne", "He", "Ar"},
    {"11", "19", "24", "48"}
};

void shuffle_answers(char **answers_arr, int correct_answer_index);
void display_question(int question_num);
void quiz();

int main() {
    // seed the random number generator
    srand(time(NULL));
    
    // start the quiz
    quiz();
    
    return 0;
}

void shuffle_answers(char **answers_arr, int correct_answer_index) {
    // shuffle the first 4 elements of the array, which are the answers
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        char *temp = answers_arr[i];
        answers_arr[i] = answers_arr[j];
        answers_arr[j] = temp;
    }
    
    // find the new index of the correct answer
    for (int i = 0; i < 4; i++) {
        if (answers_arr[i] == answers[MAX_ANSWERS-1][correct_answer_index]) {
            int j = rand() % 4;
            char *temp = answers_arr[i];
            answers_arr[i] = answers_arr[j];
            answers_arr[j] = temp;
        }
    }
}

void display_question(int question_num) {
    printf("%d. %s\n", question_num+1, questions[question_num]);
    
    // generate an array of the possible answers
    char *possible_answers[MAX_ANSWERS];
    for (int i = 0; i < MAX_ANSWERS-1; i++) {
        possible_answers[i] = answers[question_num][i];
    }
    possible_answers[MAX_ANSWERS-1] = periodicTable[atoi(answers[question_num][MAX_ANSWERS-1])-1].symbol;
    
    // shuffle the possible answers and display them
    shuffle_answers(possible_answers, atoi(answers[question_num][MAX_ANSWERS-1])-1);
    for (int i = 0; i < MAX_ANSWERS; i++) {
        printf("%c. %s\n", i+'A', possible_answers[i]);
    }
}

void quiz() {
    int score = 0;
    printf("Welcome to the Periodic Table Quiz!\n");
    
    // loop through each question
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        // display the question and get the user's answer
        display_question(i);
        char answer;
        printf("Enter your answer: ");
        scanf(" %c", &answer);
        
        // check if the user's answer is correct
        if (answer == periodicTable[atoi(answers[i][MAX_ANSWERS-1])-1].symbol[0]) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Incorrect! The correct answer is %s.\n", periodicTable[atoi(answers[i][MAX_ANSWERS-1])-1].symbol);
        }
    }
    
    // display the user's final score
    printf("Your final score is %d out of %d.\n", score, MAX_QUESTIONS);
}