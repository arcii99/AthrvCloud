//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    
    // Define arrays for the element symbols and names
    const char* symbols[] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
                            "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
                            "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
                            "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
                            "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm",
                            "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W",
                            "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn",
                            "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf",
                            "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
                            "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};
    const char* names[] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen",
                            "Oxygen", "Fluorine", "Neon", "Sodium", "Magnesium", "Aluminium", "Silicon",
                            "Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium", "Scandium",
                            "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel",
                            "Copper", "Zinc", "Gallium", "Germanium", "Arsenic", "Selenium", "Bromine",
                            "Krypton", "Rubidium", "Strontium", "Yttrium", "Zirconium", "Niobium",
                            "Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver",
                            "Cadmium", "Indium", "Tin", "Antimony", "Tellurium", "Iodine", "Xenon",
                            "Cesium", "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium",
                            "Promethium", "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium",
                            "Holmium", "Erbium", "Thulium", "Ytterbium", "Lutetium", "Hafnium", "Tantalum",
                            "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum", "Gold", "Mercury",
                            "Thallium", "Lead", "Bismuth", "Polonium", "Astatine", "Radon", "Francium",
                            "Radium", "Actinium", "Thorium", "Protactinium", "Uranium", "Neptunium",
                            "Plutonium", "Americium", "Curium", "Berkelium", "Californium", "Einsteinium",
                            "Fermium", "Mendelevium", "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium",
                            "Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium", "Roentgenium",
                            "Copernicium", "Nihonium", "Flerovium", "Moscovium", "Livermorium", "Tennessine",
                            "Oganesson"};
    
    int score = 0;
    int total_questions = 10;
    
    // Welcome message
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be given a symbol and you have to enter the corresponding element name.\n");
    printf("There are a total of %d questions.\n\n", total_questions);
    
    // Start the quiz
    for (int i = 0; i < total_questions; i++)
    {
        // Generate a random element
        int index = rand() % 118;
        const char* symbol = symbols[index];
        const char* name = names[index];
        
        // Prompt the user for input
        char input[100];
        printf("Question %d: What is the element name for %s?\n", i+1, symbol);
        scanf("%s", input);
        
        // Check the answer
        if (strcmp(input, name) == 0)
        {
            printf("Correct! +1 point\n");
            score++;
        }
        else
        {
            printf("Incorrect. The correct answer is %s\n", name);
        }
        
        printf("\n");
    }
    
    // Display the final score
    printf("Quiz complete!\n");
    printf("Your score is %d/%d\n", score, total_questions);
    
    return 0;
}