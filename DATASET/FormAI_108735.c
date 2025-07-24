//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 15
#define MAX_SYMBOL_LENGTH 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
} Element;

void print_intro() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be shown the symbol of a random element.\n");
    printf("Enter the name of the element to score a point.\n");
    printf("You have 10 seconds to answer each question.\n");
    printf("----------------------------------------------\n");
}

void generate_elements(Element* elements) {
    char* element_names[MAX_ELEMENTS] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon",
                                         "Nitrogen", "Oxygen", "Fluorine", "Neon", "Sodium", "Magnesium",
                                         "Aluminum", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon",
                                         "Potassium", "Calcium", "Scandium", "Titanium", "Vanadium", "Chromium",
                                         "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc",
                                         "Gallium", "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton",
                                         "Rubidium", "Strontium", "Yttrium", "Zirconium", "Niobium", "Molybdenum",
                                         "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium",
                                         "Indium", "Tin", "Antimony", "Tellurium", "Iodine", "Xenon",
                                         "Cesium", "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium",
                                         "Promethium", "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium",
                                         "Holmium", "Erbium", "Thulium", "Ytterbium", "Lutetium", "Hafnium",
                                         "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum",
                                         "Gold", "Mercury", "Thallium", "Lead", "Bismuth", "Polonium",
                                         "Astatine", "Radon", "Francium", "Radium", "Actinium", "Thorium",
                                         "Protactinium", "Uranium", "Neptunium", "Plutonium", "Americium", "Curium",
                                         "Berkelium", "Californium", "Einsteinium", "Fermium", "Mendelevium", "Nobelium",
                                         "Lawrencium", "Rutherfordium", "Dubnium", "Seaborgium", "Bohrium", "Hassium",
                                         "Meitnerium", "Darmstadtium", "Roentgenium", "Copernicium", "Nihonium", "Flerovium",
                                         "Moscovium", "Livermorium", "Tennessine", "Oganesson"};

    char* element_symbols[MAX_ELEMENTS] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
                                           "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca",
                                           "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
                                           "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr",
                                           "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
                                           "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
                                           "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
                                           "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg",
                                           "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
                                           "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
                                           "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
                                           "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        strcpy(elements[i].name, element_names[i]);
        strcpy(elements[i].symbol, element_symbols[i]);
        elements[i].atomic_number = i + 1;
    }
}

Element get_random_element(Element* elements) {
    int random_index = rand() % MAX_ELEMENTS;
    return elements[random_index];
}

int main() {
    Element elements[MAX_ELEMENTS];
    generate_elements(elements);

    print_intro();

    int score = 0;
    while (1) {
        Element e = get_random_element(elements);
        printf("Element symbol: %s\n", e.symbol);

        time_t start_time = time(NULL);
        char answer[MAX_NAME_LENGTH];
        scanf("%s", answer);
        time_t end_time = time(NULL);

        if (strcmp(answer, e.name) == 0) {
            printf("Correct! You get a point.\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is %s.\n", e.name);
        }

        double elapsed_time = difftime(end_time, start_time);
        if (elapsed_time > 10) {
            printf("Time's up!\n");
            printf("Your final score is %d.\n", score);
            break;
        }
    }

    return 0;
}