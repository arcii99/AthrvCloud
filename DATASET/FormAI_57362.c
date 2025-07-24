//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>  // for rand() and srand()
#include <time.h>    // for time()
#include <string.h>  // for strcmp() and strlen()

#define NUM_ELEMENTS 118   // total number of elements in the periodic table
#define MAX_QUESTIONS 10   // maximum number of questions in the quiz
#define MAX_CHOICES 4      // maximum number of choices per question

int main() {
    // seed the random number generator with the current time
    srand(time(NULL));
    
    // define the elements array with the atomic symbol and name for each element
    char *elements[NUM_ELEMENTS][2] = {
        {"H", "Hydrogen"}, {"He", "Helium"}, {"Li", "Lithium"}, {"Be", "Beryllium"},
        {"B", "Boron"}, {"C", "Carbon"}, {"N", "Nitrogen"}, {"O", "Oxygen"},
        {"F", "Fluorine"}, {"Ne", "Neon"}, {"Na", "Sodium"}, {"Mg", "Magnesium"},
        {"Al", "Aluminum"}, {"Si", "Silicon"}, {"P", "Phosphorous"}, {"S", "Sulfur"},
        {"Cl", "Chlorine"}, {"Ar", "Argon"}, {"K", "Potassium"}, {"Ca", "Calcium"},
        {"Sc", "Scandium"}, {"Ti", "Titanium"}, {"V", "Vanadium"}, {"Cr", "Chromium"},
        {"Mn", "Manganese"}, {"Fe", "Iron"}, {"Co", "Cobalt"}, {"Ni", "Nickel"},
        {"Cu", "Copper"}, {"Zn", "Zinc"}, {"Ga", "Gallium"}, {"Ge", "Germanium"},
        {"As", "Arsenic"}, {"Se", "Selenium"}, {"Br", "Bromine"}, {"Kr", "Krypton"},
        {"Rb", "Rubidium"}, {"Sr", "Strontium"}, {"Y", "Yttrium"}, {"Zr", "Zirconium"},
        {"Nb", "Niobium"}, {"Mo", "Molybdenum"}, {"Tc", "Technetium"}, {"Ru", "Ruthenium"},
        {"Rh", "Rhodium"}, {"Pd", "Palladium"}, {"Ag", "Silver"}, {"Cd", "Cadmium"},
        {"In", "Indium"}, {"Sn", "Tin"}, {"Sb", "Antimony"}, {"Te", "Tellurium"},
        {"I", "Iodine"}, {"Xe", "Xenon"}, {"Cs", "Cesium"}, {"Ba", "Barium"},
        {"La", "Lanthanum"}, {"Ce", "Cerium"}, {"Pr", "Praseodymium"}, {"Nd", "Neodymium"},
        {"Pm", "Promethium"}, {"Sm", "Samarium"}, {"Eu", "Europium"}, {"Gd", "Gadolinium"},
        {"Tb", "Terbium"}, {"Dy", "Dysprosium"}, {"Ho", "Holmium"}, {"Er", "Erbium"},
        {"Tm", "Thulium"}, {"Yb", "Ytterbium"}, {"Lu", "Lutetium"}, {"Hf", "Hafnium"},
        {"Ta", "Tantalum"}, {"W", "Tungsten"}, {"Re", "Rhenium"}, {"Os", "Osmium"},
        {"Ir", "Iridium"}, {"Pt", "Platinum"}, {"Au", "Gold"}, {"Hg", "Mercury"},
        {"Tl", "Thallium"}, {"Pb", "Lead"}, {"Bi", "Bismuth"}, {"Po", "Polonium"},
        {"At", "Astatine"}, {"Rn", "Radon"}, {"Fr", "Francium"}, {"Ra", "Radium"},
        {"Ac", "Actinium"}, {"Th", "Thorium"}, {"Pa", "Protactinium"}, {"U", "Uranium"},
        {"Np", "Neptunium"}, {"Pu", "Plutonium"}, {"Am", "Americium"}, {"Cm", "Curium"},
        {"Bk", "Berkelium"}, {"Cf", "Californium"}, {"Es", "Einsteinium"}, {"Fm", "Fermium"},
        {"Md", "Mendelevium"}, {"No", "Nobelium"}, {"Lr", "Lawrencium"}, {"Rf", "Rutherfordium"},
        {"Db", "Dubnium"}, {"Sg", "Seaborgium"}, {"Bh", "Bohrium"}, {"Hs", "Hassium"},
        {"Mt", "Meitnerium"}, {"Ds", "Darmstadtium"}, {"Rg", "Roentgenium"}, {"Cn", "Copernicium"},
        {"Nh", "Nihonium"}, {"Fl", "Flerovium"}, {"Mc", "Moscovium"}, {"Lv", "Livermorium"},
        {"Ts", "Tennessine"}, {"Og", "Oganesson"}
    };
    
    // define the questions array with the atomic symbol for the first element in each question
    char *questions[MAX_QUESTIONS] = {
        "What is the atomic symbol for the element with the highest atomic number?",   // answer: Og
        "What is the atomic symbol for the element with the lowest melting point?",   // answer: H
        "What is the atomic symbol for the element with the highest density?",        // answer: Os
        "What is the atomic symbol for the element that is a liquid at room temperature?",  // answer: Hg
        "What is the atomic symbol for the element that is used to make computer chips?",    // answer: Si
        "What is the atomic symbol for the element with the highest boiling point?",  // answer: W
        "What is the atomic symbol for the element with the lowest atomic number?",   // answer: H
        "What is the atomic symbol for the only radioactive element that occurs in nature?",  // answer: U
        "What is the atomic symbol for the rarest element in the Earth's crust?",     // answer: Au
        "What is the atomic symbol for the element with the lowest density?"         // answer: H
    };
    
    // define the choices array with the possible choices for each question
    char *choices[MAX_QUESTIONS][MAX_CHOICES] = {
        {"Og", "Uup", "Uus", "Uuo"},
        {"H", "He", "Fr", "Be"},
        {"Os", "Ir", "Au", "Pb"},
        {"Hg", "Br", "Cs", "Ne"},
        {"Si", "Ge", "Ga", "As"},
        {"W", "Mo", "Ta", "Re"},
        {"H", "He", "Ne", "Ar"},
        {"U", "Pu", "Cm", "Am"},
        {"Au", "Ir", "Os", "Pt"},
        {"H", "He", "Li", "Na"}
    };
    
    // define an array to keep track of which questions have already been asked
    int asked[MAX_QUESTIONS] = {0};
    
    // define a variable to keep track of the user's score
    int score = 0;
    
    // welcome the user to the periodic table quiz
    printf("Welcome to the periodic table quiz!\n");
    
    // start the quiz loop
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        // generate a random index between 0 and NUM_ELEMENTS-1 to choose the element for this question
        int index = rand() % NUM_ELEMENTS;
        
        // check if this question has already been asked
        while (asked[i] == 1) {
            index = rand() % NUM_ELEMENTS;
        }
        
        // mark this question as asked
        asked[i] = 1;
        
        // print the question
        printf("\n%d. What is the atomic symbol for %s?\n", i+1, elements[index][1]);
        
        // shuffle the choices for this question
        for (int j = 0; j < MAX_CHOICES; j++) {
            // swap the current choice with a random other choice
            int random_index = rand() % MAX_CHOICES;
            char *temp = choices[i][j];
            choices[i][j] = choices[i][random_index];
            choices[i][random_index] = temp;
        }
        
        // print the choices for this question
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("%c) %s\n", 65+j, elements[index_of(choices[i][j], elements)][0]);
        }
        
        // prompt the user for their answer
        char answer[2];
        printf("Your answer: ");
        scanf("%s", answer);
        
        // check the user's answer for this question
        if (strcmp(answer, elements[index][0]) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", elements[index][0]);
        }
    }
    
    // print the user's final score
    printf("\nQuiz complete! Your final score is %d out of %d.\n", score, MAX_QUESTIONS);
    
    return 0;
}

// function to find the index of a string in a 2D array
int index_of(char *str, char arr[][2]) {
    int index = -1;
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        if (strcmp(str, arr[i]) == 0) {
            index = i;
            break;
        }
    }
    return index;
}