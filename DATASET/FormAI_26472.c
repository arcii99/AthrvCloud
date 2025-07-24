//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to shuffle elements of an array
void shuffle(int arr[], int n) {
    for(int i=0;i<n;i++) {
        int j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int elements[118] = { 1, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16,
    17, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34,
    35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
    52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68,
    69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85,
    86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101,
    102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115,
    116, 117, 118 };
    
    char symbols[118][3] = { "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Na", "Mg",
    "Al", "Si", "P", "S", "Cl", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co",
    "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Rb", "Sr", "Y", "Zr", "Nb", "Mo",
    "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Cs", "Ba",
    "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm",
    "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb",
    "Bi", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
    "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl",
    "Mc", "Lv", "Ts", "Og" };
    
    char names[118][15]={ "Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", 
    "Oxygen", "Fluorine", "Sodium", "Magnesium", "Aluminum", "Silicon", "Phosphorus", "Sulfur", "Chlorine",
    "Potassium", "Calcium", "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt",
    "Nickel", "Copper", "Zinc", "Gallium", "Germanium", "Arsenic", "Selenium", "Bromine", "Rubidium",
    "Strontium", "Yttrium", "Zirconium", "Niobium", "Molybdenum", "Technetium", "Ruthenium", "Rhodium",
    "Palladium", "Silver", "Cadmium", "Indium", "Tin", "Antimony", "Tellurium", "Iodine", "Cesium",
    "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium", "Promethium", "Samarium", "Europium",
    "Gadolinium", "Terbium", "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium", "Lutetium",
    "Hafnium", "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum", "Gold", "Mercury",
    "Thallium", "Lead", "Bismuth", "Thorium", "Protactinium", "Uranium", "Neptunium", "Plutonium",
    "Americium", "Curium", "Berkelium", "Californium", "Einsteinium", "Fermium", "Mendelevium",
    "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium", "Seaborgium", "Bohrium", "Hassium",
    "Meitnerium", "Darmstadtium", "Roentgenium", "Copernicium", "Nihonium", "Flerovium", "Moscovium",
    "Livermorium", "Tennessine", "Oganesson" };
    
    // Shuffle the elements array to randomize the element order
    srand(time(NULL));
    shuffle(elements, 118);
    
    int score = 0; // Keep track of the player's score
    
    printf("Welcome to the Periodic Table Quiz!\n\n");
    printf("Guess the element's symbol and name based on its atomic number.\n");
    printf("You will be given 10 questions.\n");
    
    for(int i=0;i<10;i++) {
        int atomic_num = elements[i];
        char symbol[3];
        char name[15];
        
        printf("\nQuestion %d:", i+1);
        printf("\nAtomic Number: %d\n", atomic_num);
        printf("Enter the element's symbol: ");
        scanf("%s", symbol);
        printf("Enter the element's name: ");
        scanf("%s", name);
        
        // Check if the player's answer is correct
        if(strcmp(symbol, symbols[atomic_num-1]) == 0 && strcmp(name, names[atomic_num-1]) == 0) {
            printf("\nCorrect! +10 points.\n");
            score += 10;
        }
        else {
            printf("\nIncorrect. The correct answer is:\n");
            printf("Symbol: %s\nName: %s\n", symbols[atomic_num-1], names[atomic_num-1]);
        }
    }
    
    printf("\n\nYour score: %d/100\n", score);
    
    return 0;
}