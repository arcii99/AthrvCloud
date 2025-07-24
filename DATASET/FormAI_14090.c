//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define constants for array sizes
#define ELEMENT_NAME 20
#define SYMBOL 3

//create struct for each element in periodic table
struct Element {
    char name[ELEMENT_NAME];
    char symbol[SYMBOL];
    int atomic_number;
};

//prototypes for functions
void print_header();
void populate_periodic_table(struct Element *table);
void quiz_user(struct Element *table);
void print_table(struct Element *table);

int main() {

    //create dynamic array of Elements in periodic table
    struct Element *periodic_table = malloc(sizeof(struct Element) * 118);

    //exit if allocation failed
    if (periodic_table == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    //populate periodic table with data
    populate_periodic_table(periodic_table);

    //print header for quiz
    print_header();

    //quiz the user on elements
    quiz_user(periodic_table);

    //print entire periodic table
    print_table(periodic_table);

    //free allocated memory
    free(periodic_table);

    return 0;
}

//function to populate the periodic table with data
void populate_periodic_table(struct Element *table) {

    //data for each element (name, symbol, atomic number)
    char *names[] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon",
                     "Sodium", "Magnesium", "Aluminum", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium",
                     "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc",
                     "Gallium", "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton", "Rubidium", "Strontium", "Yttrium", "Zirconium",
                     "Niobium", "Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium", "Indium", "Tin",
                     "Antimony", "Tellurium", "Iodine", "Xenon", "Cesium", "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium",
                     "Promethium", "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium",
                     "Lutetium", "Hafnium", "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum", "Gold", "Mercury",
                     "Thallium", "Lead", "Bismuth", "Polonium", "Astatine", "Radon", "Francium", "Radium", "Actinium", "Thorium",
                     "Protactinium", "Uranium", "Neptunium", "Plutonium", "Americium", "Curium", "Berkelium", "Californium", "Einsteinium", "Fermium",
                     "Mendelevium", "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium", "Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium",
                     "Roentgenium", "Copernicium", "Nihonium", "Flerovium", "Moscovium", "Livermorium", "Tennessine", "Oganesson"};
    char *symbols[] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
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
    int atomic_numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                            11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                            21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
                            31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
                            41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
                            51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
                            61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
                            71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
                            81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
                            91, 92, 93, 94, 95, 96, 97, 98, 99, 100,
                            101, 102, 103, 104, 105, 106, 107, 108, 109, 110,
                            111, 112, 113, 114, 115, 116, 117, 118};

    //copy data into periodic table struct
    for (int i = 0; i < 118; i++) {
        strcpy(table[i].name, names[i]);
        strcpy(table[i].symbol, symbols[i]);
        table[i].atomic_number = atomic_numbers[i];
    }
}

//function to print header for quiz
void print_header() {

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Please enter the symbol for each element shown.\n");
    printf("Type 'quit' to exit the quiz.\n\n");
}

//function to quiz the user on elements
void quiz_user(struct Element *table) {

    char input[SYMBOL];
    int score = 0;
    int count = 0;

    //quiz user until they enter 'quit' or all elements have been shown
    while (strcmp(input, "quit") != 0 && count < 118) {
        //get random element from periodic table
        int index = rand() % 118;
        printf("Element #%d: %s\n", count+1, table[index].name);
        printf("Symbol: ");
        scanf("%s", input);

        //if user enters correct symbol, increment score
        if (strcmp(input, table[index].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
        }

        printf("\n");

        count++;
    }

    //print final score
    printf("Final Score: %d/%d\n\n", score, count);
}

//function to print out entire periodic table
void print_table(struct Element *table) {

    printf("Periodic Table:\n\n");

    for (int i = 0; i < 118; i++) {
        printf("%-20s %3s %3d\n", table[i].name, table[i].symbol, table[i].atomic_number);
    }

    printf("\n");
}