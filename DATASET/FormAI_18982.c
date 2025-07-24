//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct element {
    char symbol[3];
    char name[30];
    int atomic_number;
    float atomic_weight;
} element;

void shuffle(int *array, int size) {
    srand(time(NULL));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int main() {
    element table[118] = {
        {"H", "Hydrogen", 1, 1.008},
        {"He", "Helium", 2, 4.003},
        {"Li", "Lithium", 3, 6.941},
        {"Be", "Beryllium", 4, 9.012},
        {"B", "Boron", 5, 10.81},
        {"C", "Carbon", 6, 12.01},
        {"N", "Nitrogen", 7, 14.01},
        {"O", "Oxygen", 8, 16.00},
        {"F", "Fluorine", 9, 19.00},
        {"Ne", "Neon", 10, 20.18},
        {"Na", "Sodium", 11, 22.99},
        {"Mg", "Magnesium", 12, 24.30},
        {"Al", "Aluminum", 13, 26.98},
        {"Si", "Silicon", 14, 28.09},
        {"P", "Phosphorus", 15, 30.97},
        {"S", "Sulfur", 16, 32.06},
        {"Cl", "Chlorine", 17, 35.45},
        {"Ar", "Argon", 18, 39.95},
        {"K", "Potassium", 19, 39.10},
        {"Ca", "Calcium", 20, 40.08},
        {"Sc", "Scandium", 21, 44.96},
        {"Ti", "Titanium", 22, 47.87},
        {"V", "Vanadium", 23, 50.94},
        {"Cr", "Chromium", 24, 52.00},
        {"Mn", "Manganese", 25, 54.94},
        {"Fe", "Iron", 26, 55.85},
        {"Ni", "Nickel", 28, 58.69},
        {"Cu", "Copper", 29, 63.55},
        {"Zn", "Zinc", 30, 65.38},
        {"Ga", "Gallium", 31, 69.72},
        {"Ge", "Germanium", 32, 72.63},
        {"As", "Arsenic", 33, 74.92},
        {"Se", "Selenium", 34, 78.96},
        {"Br", "Bromine", 35, 79.90},
        {"Kr", "Krypton", 36, 83.80},
        {"Rb", "Rubidium", 37, 85.47},
        {"Sr", "Strontium", 38, 87.62},
        {"Y", "Yttrium", 39, 88.91},
        {"Zr", "Zirconium", 40, 91.22},
        {"Nb", "Niobium", 41, 92.91},
        {"Mo", "Molybdenum", 42, 95.94},
        {"Tc", "Technetium", 43, 98.00},
        {"Ru", "Ruthenium", 44, 101.1},
        {"Rh", "Rhodium", 45, 102.9},
        {"Pd", "Palladium", 46, 106.4},
        {"Ag", "Silver", 47, 107.9},
        {"Cd", "Cadmium", 48, 112.4},
        {"In", "Indium", 49, 114.8},
        {"Sn", "Tin", 50, 118.7},
        {"Sb", "Antimony", 51, 121.8},
        {"Te", "Tellurium", 52, 127.6},
        {"I", "Iodine", 53, 126.9},
        {"Xe", "Xenon", 54, 131.3},
        {"Cs", "Cesium", 55, 132.9},
        {"Ba", "Barium", 56, 137.3},
        {"La", "Lanthanum", 57, 138.9},
        {"Ce", "Cerium", 58, 140.1},
        {"Pr", "Praseodymium", 59, 140.9},
        {"Nd", "Neodymium", 60, 144.2},
        {"Pm", "Promethium", 61, 145},
        {"Sm", "Samarium", 62, 150.4},
        {"Eu", "Europium", 63, 151.9},
        {"Gd", "Gadolinium", 64, 157.3},
        {"Tb", "Terbium", 65, 158.9},
        {"Dy", "Dysprosium", 66, 162.5},
        {"Ho", "Holmium", 67, 164.9},
        {"Er", "Erbium", 68, 167.3},
        {"Tm", "Thulium", 69, 168.9},
        {"Yb", "Ytterbium", 70, 173.1},
        {"Lu", "Lutetium", 71, 175},
        {"Hf", "Hafnium", 72, 178.5},
        {"Ta", "Tantalum", 73, 180.9},
        {"W", "Tungsten", 74, 183.8},
        {"Re", "Rhenium", 75, 186.2},
        {"Os", "Osmium", 76, 190.2},
        {"Ir", "Iridium", 77, 192.2},
        {"Pt", "Platinum", 78, 195.1},
        {"Au", "Gold", 79, 197},
        {"Hg", "Mercury", 80, 200.6},
        {"Tl", "Thallium", 81, 204.4},
        {"Pb", "Lead", 82, 207.2},
        {"Bi", "Bismuth", 83, 208.9},
        {"Th", "Thorium", 90, 232.0},
        {"Pa", "Protactinium", 91, 231.0},
        {"U", "Uranium", 92, 238.0},
        {"Np", "Neptunium", 93, 237.0},
        {"Pu", "Plutonium", 94, 244.0},
        {"Am", "Americium", 95, 243.0},
        {"Cm", "Curium", 96, 247.0},
        {"Bk", "Berkelium", 97, 247.0},
        {"Cf", "Californium", 98, 251.0},
        {"Es", "Einsteinium", 99, 252.0},
        {"Fm", "Fermium", 100, 257.0},
        {"Md", "Mendelevium", 101, 258.0},
        {"No", "Nobelium", 102, 259.0},
        {"Lr", "Lawrencium", 103, 262},
        {"Rf", "Rutherfordium", 104, 267},
        {"Db", "Dubnium", 105, 270},
        {"Sg", "Seaborgium", 106, 271},
        {"Bh", "Bohrium", 107, 270},
        {"Hs", "Hassium", 108, 277},
        {"Mt", "Meitnerium", 109, 276},
        {"Ds", "Darmstadtium", 110, 281},
        {"Rg", "Roentgenium", 111, 280},
        {"Cn", "Copernicium", 112, 285},
        {"Nh", "Nihonium", 113, 284},
        {"Fl", "Flerovium", 114, 289},
        {"Mc", "Moscovium", 115, 288},
        {"Lv", "Livermorium", 116, 293},
        {"Ts", "Tennessine", 117, 294},
        {"Og", "Oganesson", 118, 294}
    };

    int symbols_given[8], i, j, k, score = 0;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be given 8 random elements by their atomic symbols, and you will have to enter their names.\n");
    printf("Each correct answer will give you 10 points.\n");
    printf("Let's begin!\n\n");

    while (1) {
        // Select 8 random elements from the table
        for (i = 0; i < 8; i++) {
            symbols_given[i] = rand() % 118;
        }
        // Shuffle the array to randomize the elements
        shuffle(symbols_given, 8);
        // Print out the symbols of the elements to the user
        printf("Enter the names of these elements:\n");
        for (i = 0; i < 8; i++) {
            printf("%s ", table[symbols_given[i]].symbol);
        }
        printf("\n");
        // Get the user's answers
        for (i = 0; i < 8; i++) {
            printf("%d. ", i + 1);
            scanf("%s", table[symbols_given[i]].name);
        }
        // Check the user's answers and calculate the score
        for (i = 0; i < 8; i++) {
            if (strcmp(table[symbols_given[i]].name, table[symbols_given[i]].name) == 0) {
                score += 10;
            }
            else {
                printf("Incorrect. The correct name is %s.\n", table[symbols_given[i]].name);
            }
        }
        // Print the score and ask the user if they want to play again
        printf("Your score is %d.\n", score);
        printf("Do you want to play again? (y/n) ");
        scanf("%s", table[0].symbol);
        if (strcmp(table[0].symbol, "n") == 0) {
            break;
        }
        else {
            score = 0;
        }
    }

    printf("Thanks for playing!\n");

    return 0;
}