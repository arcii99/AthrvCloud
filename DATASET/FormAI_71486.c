//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Here's how it works: we will show you an element's symbol and you have to guess its name.\n");
    printf("You will get 5 questions, so let's get started!\n");

    // List of elements and their corresponding symbols and names
    char *elements[118][2] = {
            {"H",  "Hydrogen"},
            {"He", "Helium"},
            {"Li", "Lithium"},
            {"Be", "Beryllium"},
            {"B",  "Boron"},
            {"C",  "Carbon"},
            {"N",  "Nitrogen"},
            {"O",  "Oxygen"},
            {"F",  "Fluorine"},
            {"Ne", "Neon"},
            {"Na", "Sodium"},
            {"Mg", "Magnesium"},
            {"Al", "Aluminum"},
            {"Si", "Silicon"},
            {"P",  "Phosphorus"},
            {"S",  "Sulfur"},
            {"Cl", "Chlorine"},
            {"Ar", "Argon"},
            {"K",  "Potassium"},
            {"Ca", "Calcium"},
            {"Sc", "Scandium"},
            {"Ti", "Titanium"},
            {"V",  "Vanadium"},
            {"Cr", "Chromium"},
            {"Mn", "Manganese"},
            {"Fe", "Iron"},
            {"Co", "Cobalt"},
            {"Ni", "Nickel"},
            {"Cu", "Copper"},
            {"Zn", "Zinc"},
            {"Ga", "Gallium"},
            {"Ge", "Germanium"},
            {"As", "Arsenic"},
            {"Se", "Selenium"},
            {"Br", "Bromine"},
            {"Kr", "Krypton"},
            {"Rb", "Rubidium"},
            {"Sr", "Strontium"},
            {"Y",  "Yttrium"},
            {"Zr", "Zirconium"},
            {"Nb", "Niobium"},
            {"Mo", "Molybdenum"},
            {"Tc", "Technetium"},
            {"Ru", "Ruthenium"},
            {"Rh", "Rhodium"},
            {"Pd", "Palladium"},
            {"Ag", "Silver"},
            {"Cd", "Cadmium"},
            {"In", "Indium"},
            {"Sn", "Tin"},
            {"Sb", "Antimony"},
            {"Te", "Tellurium"},
            {"I",  "Iodine"},
            {"Xe", "Xenon"},
            {"Cs", "Cesium"},
            {"Ba", "Barium"},
            {"La", "Lanthanum"},
            {"Ce", "Cerium"},
            {"Pr", "Praseodymium"},
            {"Nd", "Neodymium"},
            {"Pm", "Promethium"},
            {"Sm", "Samarium"},
            {"Eu", "Europium"},
            {"Gd", "Gadolinium"},
            {"Tb", "Terbium"},
            {"Dy", "Dysprosium"},
            {"Ho", "Holmium"},
            {"Er", "Erbium"},
            {"Tm", "Thulium"},
            {"Yb", "Ytterbium"},
            {"Lu", "Lutetium"},
            {"Hf", "Hafnium"},
            {"Ta", "Tantalum"},
            {"W",  "Tungsten"},
            {"Re", "Rhenium"},
            {"Os", "Osmium"},
            {"Ir", "Iridium"},
            {"Pt", "Platinum"},
            {"Au", "Gold"},
            {"Hg", "Mercury"},
            {"Tl", "Thallium"},
            {"Pb", "Lead"},
            {"Bi", "Bismuth"},
            {"Po", "Polonium"},
            {"At", "Astatine"},
            {"Rn", "Radon"},
            {"Fr", "Francium"},
            {"Ra", "Radium"},
            {"Ac", "Actinium"},
            {"Th", "Thorium"},
            {"Pa", "Protactinium"},
            {"U",  "Uranium"},
            {"Np", "Neptunium"},
            {"Pu", "Plutonium"},
            {"Am", "Americium"},
            {"Cm", "Curium"},
            {"Bk", "Berkelium"},
            {"Cf", "Californium"},
            {"Es", "Einsteinium"},
            {"Fm", "Fermium"},
            {"Md", "Mendelevium"},
            {"No", "Nobelium"},
            {"Lr", "Lawrencium"},
            {"Rf", "Rutherfordium"},
            {"Db", "Dubnium"},
            {"Sg", "Seaborgium"},
            {"Bh", "Bohrium"},
            {"Hs", "Hassium"},
            {"Mt", "Meitnerium"},
            {"Ds", "Darmstadtium"},
            {"Rg", "Roentgenium"},
            {"Cn", "Copernicium"},
            {"Nh", "Nihonium"},
            {"Fl", "Flerovium"},
            {"Mc", "Moscovium"},
            {"Lv", "Livermorium"},
            {"Ts", "Tennessine"},
            {"Og", "Oganesson"}
    };

    // Shuffle the elements array
    srand(time(NULL));
    for (int i = 0; i < 118; i++) {
        int j = rand() % 118;
        char *temp_symbol = elements[i][0];
        char *temp_name = elements[i][1];
        elements[i][0] = elements[j][0];
        elements[i][1] = elements[j][1];
        elements[j][0] = temp_symbol;
        elements[j][1] = temp_name;
    }

    // Ask the user for input and check if the answer is correct
    int score = 0;
    for (int i = 0; i < 5; i++) {
        printf("Question %d:\n", i + 1);
        printf("%s\n", elements[i][0]);
        char answer[20];
        scanf("%s", answer);
        if (!strcmp(answer, elements[i][1])) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The answer is %s\n", elements[i][1]);
        }
    }

    // Print the final score
    printf("You got %d out of 5 questions correct! Well done!\n", score);

    return 0;
}