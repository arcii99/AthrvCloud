//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element {
    char symbol[3];
    char name[20];
    int atomic_number;
    float atomic_mass;
    char state[10];
};

typedef struct element Element;

void print_table(Element table[], int size, int index) {
    printf("What is the element with atomic number %d?\n\n", table[index].atomic_number);
    for (int i=0; i<size; i++) {
        printf("%d. %s\n", table[i].atomic_number, table[i].symbol);
    }
    printf("\nEnter your answer (atomic number): ");
    int answer;
    scanf("%d", &answer);
    if (answer == table[index].atomic_number) {
        printf("\nCorrect!\n");
    } else {
        printf("\nIncorrect! The correct answer is %d (%s)\n", table[index].atomic_number, table[index].symbol);
    }
    printf("\n");
    if (index < size-1) {
        print_table(table, size, index+1);
    }
}

int main() {
    Element table[118] = {
        {"H", "Hydrogen", 1, 1.008, "Gas"},
        {"He", "Helium", 2, 4.003, "Gas"},
        {"Li", "Lithium", 3, 6.941, "Solid"},
        {"Be", "Beryllium", 4, 9.012, "Solid"},
        {"B", "Boron", 5, 10.81, "Solid"},
        {"C", "Carbon", 6, 12.01, "Solid"},
        {"N", "Nitrogen", 7, 14.01, "Gas"},
        {"O", "Oxygen", 8, 16.00, "Gas"},
        {"F", "Fluorine", 9, 19.00, "Gas"},
        {"Ne", "Neon", 10, 20.18, "Gas"},
        {"Na", "Sodium", 11, 22.99, "Solid"},
        {"Mg", "Magnesium", 12, 24.31, "Solid"},
        {"Al", "Aluminium", 13, 26.98, "Solid"},
        {"Si", "Silicon", 14, 28.09, "Solid"},
        {"P", "Phosphorus", 15, 30.97, "Solid"},
        {"S", "Sulfur", 16, 32.07, "Solid"},
        {"Cl", "Chlorine", 17, 35.45, "Gas"},
        {"Ar", "Argon", 18, 39.95, "Gas"},
        {"K", "Potassium", 19, 39.10, "Solid"},
        {"Ca", "Calcium", 20, 40.08, "Solid"},
        {"Sc", "Scandium", 21, 44.96, "Solid"},
        {"Ti", "Titanium", 22, 47.87, "Solid"},
        {"V", "Vanadium", 23, 50.94, "Solid"},
        {"Cr", "Chromium", 24, 52.00, "Solid"},
        {"Mn", "Manganese", 25, 54.94, "Solid"},
        {"Fe", "Iron", 26, 55.85, "Solid"},
        {"Co", "Cobalt", 27, 58.93, "Solid"},
        {"Ni", "Nickel", 28, 58.69, "Solid"},
        {"Cu", "Copper", 29, 63.55, "Solid"},
        {"Zn", "Zinc", 30, 65.38, "Solid"},
        {"Ga", "Gallium", 31, 69.72, "Solid"},
        {"Ge", "Germanium", 32, 72.63, "Solid"},
        {"As", "Arsenic", 33, 74.92, "Solid"},
        {"Se", "Selenium", 34, 78.96, "Solid"},
        {"Br", "Bromine", 35, 79.90, "Liquid"},
        {"Kr", "Krypton", 36, 83.80, "Gas"},
        {"Rb", "Rubidium", 37, 85.47, "Solid"},
        {"Sr", "Strontium", 38, 87.62, "Solid"},
        {"Y", "Yttrium", 39, 88.91, "Solid"},
        {"Zr", "Zirconium", 40, 91.22, "Solid"},
        {"Nb", "Niobium", 41, 92.91, "Solid"},
        {"Mo", "Molybdenum", 42, 95.94, "Solid"},
        {"Tc", "Technetium", 43, 98.00, "Solid"},
        {"Ru", "Ruthenium", 44, 101.07, "Solid"},
        {"Rh", "Rhodium", 45, 102.91, "Solid"},
        {"Pd", "Palladium", 46, 106.42, "Solid"},
        {"Ag", "Silver", 47, 107.87, "Solid"},
        {"Cd", "Cadmium", 48, 112.41, "Solid"},
        {"In", "Indium", 49, 114.82, "Solid"},
        {"Sn", "Tin", 50, 118.71, "Solid"},
        {"Sb", "Antimony", 51, 121.76, "Solid"},
        {"Te", "Tellurium", 52, 127.60, "Solid"},
        {"I", "Iodine", 53, 126.90, "Solid"},
        {"Xe", "Xenon", 54, 131.29, "Gas"},
        {"Cs", "Caesium", 55, 132.91, "Solid"},
        {"Ba", "Barium", 56, 137.33, "Solid"},
        {"La", "Lanthanum", 57, 138.91, "Solid"},
        {"Ce", "Cerium", 58, 140.12, "Solid"},
        {"Pr", "Praseodymium", 59, 140.91, "Solid"},
        {"Nd", "Neodymium", 60, 144.24, "Solid"},
        {"Pm", "Promethium", 61, 145.00, "Solid"},
        {"Sm", "Samarium", 62, 150.36, "Solid"},
        {"Eu", "Europium", 63, 151.96, "Solid"},
        {"Gd", "Gadolinium", 64, 157.25, "Solid"},
        {"Tb", "Terbium", 65, 158.93, "Solid"},
        {"Dy", "Dysprosium", 66, 162.50, "Solid"},
        {"Ho", "Holmium", 67, 164.93, "Solid"},
        {"Er", "Erbium", 68, 167.26, "Solid"},
        {"Tm", "Thulium", 69, 168.93, "Solid"},
        {"Yb", "Ytterbium", 70, 173.05, "Solid"},
        {"Lu", "Lutetium", 71, 174.97, "Solid"},
        {"Hf", "Hafnium", 72, 178.49, "Solid"},
        {"Ta", "Tantalum", 73, 180.95, "Solid"},
        {"W", "Tungsten", 74, 183.84, "Solid"},
        {"Re", "Rhenium", 75, 186.21, "Solid"},
        {"Os", "Osmium", 76, 190.23, "Solid"},
        {"Ir", "Iridium", 77, 192.22, "Solid"},
        {"Pt", "Platinum", 78, 195.08, "Solid"},
        {"Au", "Gold", 79, 196.97, "Solid"},
        {"Hg", "Mercury", 80, 200.59, "Liquid"},
        {"Tl", "Thallium", 81, 204.38, "Solid"},
        {"Pb", "Lead", 82, 207.2, "Solid"},
        {"Bi", "Bismuth", 83, 208.98, "Solid"},
        {"Po", "Polonium", 84, 209.00, "Solid"},
        {"At", "Astatine", 85, 210.00, "Solid"},
        {"Rn", "Radon", 86, 222.00, "Gas"},
        {"Fr", "Francium", 87, 223.00, "Solid"},
        {"Ra", "Radium", 88, 226.03, "Solid"},
        {"Ac", "Actinium", 89, 227.03, "Solid"},
        {"Th", "Thorium", 90, 232.04, "Solid"},
        {"Pa", "Protactinium", 91, 231.04, "Solid"},
        {"U", "Uranium", 92, 238.03, "Solid"},
        {"Np", "Neptunium", 93, 237.05, "Solid"},
        {"Pu", "Plutonium", 94, 244.06, "Solid"},
        {"Am", "Americium", 95, 243.06, "Solid"},
        {"Cm", "Curium", 96, 247.07, "Solid"},
        {"Bk", "Berkelium", 97, 247.07, "Solid"},
        {"Cf", "Californium", 98, 251.08, "Solid"},
        {"Es", "Einsteinium", 99, 252.08, "Solid"},
        {"Fm", "Fermium", 100, 257.10, "Solid"},
        {"Md", "Mendelevium", 101, 258.10, "Solid"},
        {"No", "Nobelium", 102, 259.10, "Solid"},
        {"Lr", "Lawrencium", 103, 262.11, "Solid"},
        {"Rf", "Rutherfordium", 104, 267.12, "Unknown"},
        {"Db", "Dubnium", 105, 270.13, "Unknown"},
        {"Sg", "Seaborgium", 106, 271.13, "Unknown"},
        {"Bh", "Bohrium", 107, 270.13, "Unknown"},
        {"Hs", "Hassium", 108, 277.15, "Unknown"},
        {"Mt", "Meitnerium", 109, 276.15, "Unknown"},
        {"Ds", "Darmstadtium", 110, 281.16, "Unknown"},
        {"Rg", "Roentgenium", 111, 280.16, "Unknown"},
        {"Cn", "Copernicium", 112, 285.18, "Unknown"},
        {"Nh", "Nihonium", 113, 284.18, "Unknown"},
        {"Fl", "Flerovium", 114, 289.19, "Unknown"},
        {"Mc", "Moscovium", 115, 288.19, "Unknown"},
        {"Lv", "Livermorium", 116, 293.21, "Unknown"},
        {"Ts", "Tennessine", 117, 294.21, "Unknown"},
        {"Og", "Oganesson", 118, 294.21, "Unknown"}
    };
    print_table(table, 118, 0);
    return 0;
}