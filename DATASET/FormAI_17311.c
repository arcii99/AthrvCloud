//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the symbols and names of the elements
#define NUM_ELEMENTS 118
const char* SYMBOLS[NUM_ELEMENTS] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg",
                                     "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr",
                                     "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br",
                                     "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd",
                                     "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La",
                                     "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er",
                                     "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
                                     "Hg", "Tl", "Pb", "Bi", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm",
                                     "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh",
                                     "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv"};

const char* NAMES[NUM_ELEMENTS] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon",
                                    "Nitrogen", "Oxygen", "Fluorine", "Neon", "Sodium", "Magnesium",
                                    "Aluminum", "Silicon", "Phosphorous", "Sulfur", "Chlorine",
                                    "Argon", "Potassium", "Calcium", "Scandium", "Titanium",
                                    "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel",
                                    "Copper", "Zinc", "Gallium", "Germanium", "Arsenic", "Selenium",
                                    "Bromine", "Krypton", "Rubidium", "Strontium", "Yttrium",
                                    "Zirconium", "Niobium", "Molybdenum", "Technetium", "Ruthenium",
                                    "Rhodium", "Palladium", "Silver", "Cadmium", "Indium", "Tin",
                                    "Antimony", "Tellurium", "Iodine", "Xenon", "Cesium", "Barium",
                                    "Lanthanum", "Cerium", "Praseodymium", "Neodymium",
                                    "Promethium", "Samarium", "Europium", "Gadolinium", "Terbium",
                                    "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium",
                                    "Lutetium", "Hafnium", "Tantalum", "Tungsten", "Rhenium",
                                    "Osmium", "Iridium", "Platinum", "Gold", "Mercury", "Thallium",
                                    "Lead", "Bismuth", "Thorium", "Protactinium", "Uranium",
                                    "Neptunium", "Plutonium", "Americium", "Curium", "Berkelium",
                                    "Californium", "Einsteinium", "Fermium", "Mendelevium",
                                    "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium",
                                    "Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium",
                                    "Roentgenium", "Copernicium", "Nihonium", "Flerovium",
                                    "Moscovium", "Livermorium", "Tennessine", "Oganesson"};

// Define the number of questions and possible answer choices
#define NUM_QUESTIONS 10
#define NUM_CHOICES 4

// Define a struct for each question
typedef struct {
    int number; // The number of the question
    int element; // The number of the correct element
    char choices[NUM_CHOICES][3]; // Symbols of possible answer choices
    int answer; // The index of the correct answer choice
    int chosenAnswer; // The index of the answer chosen by the user
    int correct; // Whether or not the chosen answer is correct
} Question;

// Function to create a new question
Question createQuestion(int number, int element) {
    Question q;
    q.number = number;
    q.element = element;

    // Determine the correct answer and set it as choice 0
    int answerIndex = rand() % NUM_CHOICES;
    q.answer = answerIndex;
    char correctSymbol[3];
    sprintf(correctSymbol, "%s", SYMBOLS[element]);
    sprintf(q.choices[answerIndex], "%s", correctSymbol);

    // Determine the remaining answer choices
    for (int i = 0; i < NUM_CHOICES; i++) {
        if (i == answerIndex) {
            continue;
        }
        int incorrectElement;
        do {
            incorrectElement = rand() % NUM_ELEMENTS;
        } while (incorrectElement == element || !strcmp(SYMBOLS[incorrectElement], q.choices[0]));
        sprintf(q.choices[i], "%s", SYMBOLS[incorrectElement]);
    }

    return q;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create an array of random questions
    Question questions[NUM_QUESTIONS];
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        questions[i] = createQuestion(i+1, rand() % NUM_ELEMENTS);
    }

    // Display the welcome message
    printf("Welcome to the Periodic Table Quiz!\n"
           "You will be asked %d multiple-choice questions about the elements in the periodic table.\n"
           "Enter the number of the answer you think is correct.\n", NUM_QUESTIONS);

    // Loop through each question and ask the user
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        printf("\nQuestion %d:\n", questions[i].number);
        printf("What is the symbol for %s?\n", NAMES[questions[i].element]);
        for (int j = 0; j < NUM_CHOICES; j++) {
            printf("%d: %s\n", j+1, questions[i].choices[j]);
        }
        printf("Enter your answer: ");
        scanf("%d", &questions[i].chosenAnswer);
        if (questions[i].chosenAnswer == questions[i].answer+1) {
            questions[i].correct = 1;
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %d: %s.\n", questions[i].answer+1, SYMBOLS[questions[i].element]);
        }
    }

    // Display the final score
    int score = 0;
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        score += questions[i].correct;
    }
    printf("\nYou scored %d out of %d.\n", score, NUM_QUESTIONS);

    // Display a message based on the user's score
    if (score == NUM_QUESTIONS) {
        printf("Perfect score! You really know your elements!\n");
    } else if (score >= NUM_QUESTIONS*0.9) {
        printf("Excellent job! You almost got them all right!\n");
    } else if (score >= NUM_QUESTIONS*0.8) {
        printf("Great work! You know your elements pretty well!\n");
    } else {
        printf("Good effort! Keep studying your periodic table!\n");
    }

    return 0;
}