//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Define the periodic table elements
    char *element[118] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron","Carbon", "Nitrogen", "Oxygen", "Fluorine","Neon", "Sodium", "Magnesium", "Aluminum", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium", "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc", "Gallium","Germanium", "Arsenic", "Selenium", "Bromine","Krypton","Rubidium", "Strontium", "Yttrium", "Zirconium", "Niobium", "Molybdenum","Technetium","Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium","Indium", "Tin", "Antimony", "Tellurium", "Iodine", "Xenon", "Cesium", "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium", "Promethium", "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium", "Holmium","Erbium", "Thulium", "Ytterbium", "Lutetium", "Hafnium", "Tantalum", "Tungsten","Rhenium","Osmium", "Iridium", "Platinum", "Gold", "Mercury", "Thallium", "Lead", "Bismuth", "Polonium", "Astatine", "Radon", "Francium", "Radium", "Actinium", "Thorium", "Protactinium", "Uranium", "Neptunium", "Plutonium", "Americium", "Curium", "Berkelium", "Californium", "Einsteinium", "Fermium", "Mendelevium", "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium", "Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium", "Roentgenium", "Copernicium", "Nihonium", "Flerovium", "Moscovium", "Livermorium", "Tennessine", "Oganesson"};
    int number[118] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118};
    char *symbol[118] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};
    int atomicNumber, choice, i;

    printf("Welcome to the Periodic Table Quiz!\n\n");
    printf("1 - Identify element by its symbol\n");
    printf("2 - Identify element by its atomic number\n");
    printf("3 - Quit\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);

    while (choice != 3) {
        if (choice == 1) {
            // Identify element by its symbol
            char userInput[3];
            printf("Enter the symbol of an element: ");
            scanf("%s", userInput);

            int found = 0;
            for (i = 0; i < 118; i++) {
                if (strcmp(userInput, symbol[i]) == 0) {
                    printf("The element with symbol %s is %s\n\n", userInput, element[i]);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Sorry, the symbol %s is not in the periodic table.\n\n", userInput);
            }
        } else if (choice == 2) {
            // Identify element by its atomic number
            printf("Enter the atomic number of an element: ");
            scanf("%d", &atomicNumber);
            if (atomicNumber < 1 || atomicNumber > 118) {
                printf("Invalid input, atomic number must be between 1 and 118.\n\n");
            } else {
                printf("The element with atomic number %d is %s\n\n", atomicNumber, element[atomicNumber - 1]);
            }
        } else {
            printf("Invalid choice, please enter 1, 2, or 3.\n\n");
        }

        printf("1 - Identify element by its symbol\n");
        printf("2 - Identify element by its atomic number\n");
        printf("3 - Quit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
    }

    printf("Thank you for playing the Periodic Table Quiz!\n");
    
    return 0;
}