//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// Structure to store element information
typedef struct element {
    int atomic_num;
    char symbol[3];
    char name[20];
} element;

// Array of type element to store periodic table
element ptable[] = {
    {1, "H", "Hydrogen"},
    {2, "He", "Helium"},
    {3, "Li", "Lithium"},
    {4, "Be", "Berylium"},
    {5, "B", "Boron"},
    {6, "C", "Carbon"},
    {7, "N", "Nitrogen"},
    {8, "O", "Oxygen"},
    {9, "F", "Fluorine"},
    {10, "Ne", "Neon"},
    {11, "Na", "Sodium"},
    {12, "Mg", "Magnesium"},
    {13, "Al", "Aluminum"},
    {14, "Si", "Silicon"},
    {15, "P", "Phosphorus"},
    {16, "S", "Sulfur"},
    {17, "Cl", "Chlorine"},
    {18, "Ar", "Argon"},
    {19, "K", "Potassium"},
    {20, "Ca", "Calcium"},
    {21, "Sc", "Scandium"},
    {22, "Ti", "Titanium"},
    {23, "V", "Vanadium"},
    {24, "Cr", "Chromium"},
    {25, "Mn", "Manganese"},
    {26, "Fe", "Iron"},
    {27, "Co", "Cobalt"},
    {28, "Ni", "Nickel"},
    {29, "Cu", "Copper"},
    {30, "Zn", "Zinc"},
    {31, "Ga", "Gallium"},
    {32, "Ge", "Germanium"},
    {33, "As", "Arsenic"},
    {34, "Se", "Selenium"},
    {35, "Br", "Bromine"},
    {36, "Kr", "Krypton"},
    {37, "Rb", "Rubidium"},
    {38, "Sr", "Strontium"},
    {39, "Y", "Yttrium"},
    {40, "Zr", "Zirconium"},
    {41, "Nb", "Niobium"},
    {42, "Mo", "Molybdenum"},
    {43, "Tc", "Technetium"},
    {44, "Ru", "Ruthenium"},
    {45, "Rh", "Rhodium"},
    {46, "Pd", "Palladium"},
    {47, "Ag", "Silver"},
    {48, "Cd", "Cadmium"},
    {49, "In", "Indium"},
    {50, "Sn", "Tin"},
    {51, "Sb", "Antimony"},
    {52, "Te", "Tellurium"},
    {53, "I", "Iodine"},
    {54, "Xe", "Xenon"},
    {55, "Cs", "Cesium"},
    {56, "Ba", "Barium"},
    {57, "La", "Lanthanum"},
    {58, "Ce", "Cerium"},
    {59, "Pr", "Praseodymium"},
    {60, "Nd", "Neodymium"},
    {61, "Pm", "Promethium"},
    {62, "Sm", "Samarium"},
    {63, "Eu", "Europium"},
    {64, "Gd", "Gadolinium"},
    {65, "Tb", "Terbium"},
    {66, "Dy", "Dysprosium"},
    {67, "Ho", "Holmium"},
    {68, "Er", "Erbium"},
    {69, "Tm", "Thulium"},
    {70, "Yb", "Ytterbium"},
    {71, "Lu", "Lutetium"},
    {72, "Hf", "Hafnium"},
    {73, "Ta", "Tantalum"},
    {74, "W", "Tungsten"},
    {75, "Re", "Rhenium"},
    {76, "Os", "Osmium"},
    {77, "Ir", "Iridium"},
    {78, "Pt", "Platinum"},
    {79, "Au", "Gold"},
    {80, "Hg", "Mercury"},
    {81, "Tl", "Thallium"},
    {82, "Pb", "Lead"},
    {83, "Bi", "Bismuth"},
    {84, "Po", "Polonium"},
    {85, "At", "Astatine"},
    {86, "Rn", "Radon"},
    {87, "Fr", "Francium"},
    {88, "Ra", "Radium"},
    {89, "Ac", "Actinium"},
    {90, "Th", "Thorium"},
    {91, "Pa", "Protactinium"},
    {92, "U", "Uranium"},
    {93, "Np", "Neptunium"},
    {94, "Pu", "Plutonium"},
    {95, "Am", "Americium"},
    {96, "Cm", "Curium"},
    {97, "Bk", "Berkelium"},
    {98, "Cf", "Californium"},
    {99, "Es", "Einsteinium"},
    {100, "Fm", "Fermium"},
    {101, "Md", "Mendelevium"},
    {102, "No", "Nobelium"},
    {103, "Lr", "Lawrencium"},
    {104, "Rf", "Rutherfordium"},
    {105, "Db", "Dubnium"},
    {106, "Sg", "Seaborgium"},
    {107, "Bh", "Bohrium"},
    {108, "Hs", "Hassium"},
    {109, "Mt", "Meitnerium"},
    {110, "Ds", "Darmstadtium"},
    {111, "Rg", "Roentgenium"},
    {112, "Cn", "Copernicium"},
    {113, "Nh", "Nihonium"},
    {114, "Fl", "Flerovium"},
    {115, "Mc", "Moscovium"},
    {116, "Lv", "Livermorium"},
    {117, "Ts", "Tennessine"},
    {118, "Og", "Oganesson"}
};

// Function to get random integer (used for shuffling questions)
int get_random_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(0));  // Seed random number generator with current time

    int correct = 0;  // Counter for number of correct answers
    int total = 0;  // Counter for total number of questions
    int q_num = 0;  // Counter for current question number

    // Welcome message and instructions
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be presented with 10 multiple choice questions about elements in the periodic table.\n");
    printf("For each question, enter the number of the correct answer and press enter.\n");
    printf("Let's get started!\n\n");

    for (int i=0; i<10; i++) {
        // Shuffle ptable array to get new random question
        for (int j=0; j<118; j++) {
            int r = get_random_int(0, 117);
            element temp = ptable[j];
            ptable[j] = ptable[r];
            ptable[r] = temp;
        }

        // Create question
        element q = ptable[0];
        int correct_choice = get_random_int(1, 4);
        char choices[4][20];

        if (correct_choice == 1) {
            strcpy(choices[0], q.name);
            element e1 = ptable[1];
            element e2 = ptable[2];
            element e3 = ptable[3];
            strcpy(choices[1], e1.name);
            strcpy(choices[2], e2.name);
            strcpy(choices[3], e3.name);
        } else if (correct_choice == 2) {
            element e1 = ptable[1];
            strcpy(choices[1], e1.name);
            strcpy(choices[0], q.name);
            element e2 = ptable[2];
            element e3 = ptable[3];
            strcpy(choices[2], e2.name);
            strcpy(choices[3], e3.name);
        } else if (correct_choice == 3) {
            element e1 = ptable[1];
            element e2 = ptable[2];
            strcpy(choices[2], e2.name);
            strcpy(choices[0], q.name);
            strcpy(choices[1], e1.name);
            element e3 = ptable[3];
            strcpy(choices[3], e3.name);
        } else {
            element e1 = ptable[1];
            element e2 = ptable[2];
            element e3 = ptable[3];
            strcpy(choices[3], e3.name);
            strcpy(choices[0], q.name);
            strcpy(choices[1], e1.name);
            strcpy(choices[2], e2.name);
        }

        // Print question
        q_num++;
        printf("Question %d:\n", q_num);
        printf("What is the symbol for %s?\n", q.name);
        printf("1. %s\n", choices[0]);
        printf("2. %s\n", choices[1]);
        printf("3. %s\n", choices[2]);
        printf("4. %s\n\n", choices[3]);

        // Get user input
        int choice = 0;
        while (choice < 1 || choice > 4) {
            printf("Enter your choice (1-4): ");
            scanf("%d", &choice);
        }

        // Check if answer is correct
        if (choice == correct_choice) {
            printf("Correct!\n\n");
            correct++;
        } else {
            printf("Incorrect. The correct answer is %d. %s\n\n", correct_choice, q.symbol);
        }

        total++;
    }

    // Print results
    printf("You got %d out of %d questions correct.\n", correct, total);

    return 0;
}