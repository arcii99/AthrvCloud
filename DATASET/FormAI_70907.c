//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4
#define MAX_LEN 100

typedef struct {
    char symbol[3];
    char name[MAX_LEN];
} Element;

Element elements[118] = {
    {"H", "Hydrogen"}, {"He", "Helium"}, {"Li", "Lithium"}, {"Be", "Beryllium"}, {"B", "Boron"},
    {"C", "Carbon"}, {"N", "Nitrogen"}, {"O", "Oxygen"}, {"F", "Fluorine"}, {"Ne", "Neon"},
    {"Na", "Sodium"}, {"Mg", "Magnesium"}, {"Al", "Aluminum"}, {"Si", "Silicon"}, {"P", "Phosphorus"},
    {"S", "Sulfur"}, {"Cl", "Chlorine"}, {"Ar", "Argon"}, {"K", "Potassium"}, {"Ca", "Calcium"},
    {"Sc", "Scandium"}, {"Ti", "Titanium"}, {"V", "Vanadium"}, {"Cr", "Chromium"}, {"Mn", "Manganese"},
    {"Fe", "Iron"}, {"Co", "Cobalt"}, {"Ni", "Nickel"}, {"Cu", "Copper"}, {"Zn", "Zinc"},
    {"Ga", "Gallium"}, {"Ge", "Germanium"}, {"As", "Arsenic"}, {"Se", "Selenium"}, {"Br", "Bromine"},
    {"Kr", "Krypton"}, {"Rb", "Rubidium"}, {"Sr", "Strontium"}, {"Y", "Yttrium"}, {"Zr", "Zirconium"},
    {"Nb", "Niobium"}, {"Mo", "Molybdenum"}, {"Tc", "Technetium"}, {"Ru", "Ruthenium"}, {"Rh", "Rhodium"},
    {"Pd", "Palladium"}, {"Ag", "Silver"}, {"Cd", "Cadmium"}, {"In", "Indium"}, {"Sn", "Tin"},
    {"Sb", "Antimony"}, {"Te", "Tellurium"}, {"I", "Iodine"}, {"Xe", "Xenon"}, {"Cs", "Cesium"},
    {"Ba", "Barium"}, {"La", "Lanthanum"}, {"Ce", "Cerium"}, {"Pr", "Praseodymium"}, {"Nd", "Neodymium"},
    {"Pm", "Promethium"}, {"Sm", "Samarium"}, {"Eu", "Europium"}, {"Gd", "Gadolinium"}, {"Tb", "Terbium"},
    {"Dy", "Dysprosium"}, {"Ho", "Holmium"}, {"Er", "Erbium"}, {"Tm", "Thulium"}, {"Yb", "Ytterbium"},
    {"Lu", "Lutetium"}, {"Hf", "Hafnium"}, {"Ta", "Tantalum"}, {"W", "Tungsten"}, {"Re", "Rhenium"},
    {"Os", "Osmium"}, {"Ir", "Iridium"}, {"Pt", "Platinum"}, {"Au", "Gold"}, {"Hg", "Mercury"},
    {"Tl", "Thallium"}, {"Pb", "Lead"}, {"Bi", "Bismuth"}, {"Po", "Polonium"}, {"At", "Astatine"},
    {"Rn", "Radon"}, {"Fr", "Francium"}, {"Ra", "Radium"}, {"Ac", "Actinium"}, {"Th", "Thorium"},
    {"Pa", "Protactinium"}, {"U", "Uranium"}, {"Np", "Neptunium"}, {"Pu", "Plutonium"}, {"Am", "Americium"},
    {"Cm", "Curium"}, {"Bk", "Berkelium"}, {"Cf", "Californium"}, {"Es", "Einsteinium"}, {"Fm", "Fermium"},
    {"Md", "Mendelevium"}, {"No", "Nobelium"}, {"Lr", "Lawrencium"}, {"Rf", "Rutherfordium"}, {"Db", "Dubnium"},
    {"Sg", "Seaborgium"}, {"Bh", "Bohrium"}, {"Hs", "Hassium"}, {"Mt", "Meitnerium"}, {"Ds", "Darmstadtium"},
    {"Rg", "Roentgenium"}, {"Cn", "Copernicium"}, {"Nh", "Nihonium"}, {"Fl", "Flerovium"}, {"Mc", "Moscovium"},
    {"Lv", "Livermorium"}, {"Ts", "Tennessine"}, {"Og", "Oganesson"}};
    
char options[MAX_OPTIONS][3];

void shuffle_options() {
    int i, j;
    char temp[3];
    for (i = MAX_OPTIONS - 1; i > 0; i--) {
        j = rand() % (i + 1);
        strcpy(temp, options[j]);
        strcpy(options[j], options[i]);
        strcpy(options[i], temp);
    }
}

void initialize_options(int index) {
    int i;
    strcpy(options[0], elements[index].symbol);
    for (i = 1; i < MAX_OPTIONS; i++) {
        int rand_index;
        do {
            rand_index = rand() % 118;
        } while (rand_index == index);
        strcpy(options[i], elements[rand_index].symbol);
    }
    shuffle_options();
}

int get_user_choice() {
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void display_question(int index) {
    int i;
    printf("\n%s - What is the symbol for %s?\n", elements[index].name, elements[index].name);
    for (i = 0; i < MAX_OPTIONS; i++) {
        printf("%d. %s\n", i + 1, options[i]);
    }
}

void display_score(int score, int total_questions) {
    printf("\n\nYour score is %d out of %d!\n", score, total_questions);
}

int main() {
    srand(time(NULL));
    int i, score = 0;
    printf("\nWelcome to the Periodic Table Quiz!\n");
    printf("\nYou will be given %d randomly selected elements to identify by their symbols.\n", MAX_QUESTIONS);
    printf("\nFor each question, choose the correct symbol from the list of options provided.");
    printf("\nYou will be given four options to choose from.");
    printf("\n\nLet's begin!\n\n");
    for (i = 0; i < MAX_QUESTIONS; i++) {
        int rand_index = rand() % 118;
        initialize_options(rand_index);
        display_question(rand_index);
        int choice = get_user_choice();
        if (choice == 1 && strcmp(options[0], elements[rand_index].symbol) == 0) {
            printf("\nCongratulations, that's correct!\n");
            score++;
        } else {
            printf("\nSorry, the correct answer is %s.\n", elements[rand_index].symbol);
        }
    }
    display_score(score, MAX_QUESTIONS);
    printf("\nThank you for playing the Periodic Table Quiz!\n");
    return 0;
}