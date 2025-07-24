//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 118 //total elements in periodic table

int main(){
    
    int score = 0, i, ans, option;
    char choice;
    int elements[SIZE][4] = {{1, 1, 1, 1}, {2, 1, 1, 1}, {3, 2, 1, 0}, {4, 2, 2, 0}, {5, 2, 3, 0}, {6, 2, 4, 0},
                            {7, 2, 5, 1}, {8, 2, 6, 2}, {9, 2, 7, 3}, {10, 2, 8, 4}, {11, 3, 1, 0}, {12, 3, 2, 0},
                            {13, 3, 3, 0}, {14, 3, 4, 1}, {15, 3, 5, 2}, {16, 3, 6, 3}, {17, 3, 7, 4}, {18, 3, 8, 5},
                            {19, 4, 1, 0}, {20, 4, 2, 0}, {21, 4, 3, 0}, {22, 4, 4, 0}, {23, 4, 5, 1}, {24, 4, 6, 2},
                            {25, 4, 7, 3}, {26, 4, 8, 4}, {27, 4, 9, 5}, {28, 4, 10, 4}, {29, 4, 11, 1}, {30, 4, 12, 2},
                            {31, 4, 13, 3}, {32, 4, 14, 4}, {33, 4, 15, 3}, {34, 4, 16, 2}, {35, 4, 17, 1}, {36, 4, 18, 0},
                            {37, 5, 1, 0}, {38, 5, 2, 0}, {39, 5, 3, 0}, {40, 5, 4, 0}, {41, 5, 5, 0}, {42, 5, 6, 0},
                            {43, 5, 7, 1}, {44, 5, 8, 2}, {45, 5, 9, 3}, {46, 5, 10, 4}, {47, 5, 11, 5}, {48, 5, 12, 4},
                            {49, 5, 13, 3}, {50, 5, 14, 2}, {51, 5, 15, 3}, {52, 5, 16, 4}, {53, 5, 17, 5}, {54, 5, 18, 6},
                            {55, 6, 1, 0}, {56, 6, 2, 0}, {57, 6, 3, 0}, {58, 6, 4, 0}, {59, 6, 5, 0}, {60, 6, 6, 0},
                            {61, 6, 7, 0}, {62, 6, 8, 0}, {63, 6, 9, 0}, {64, 6, 10, 0}, {65, 6, 11, 0}, {66, 6, 12, 0},
                            {67, 6, 13, 0}, {68, 6, 14, 0}, {69, 6, 15, 0}, {70, 6, 16, 0}, {71, 6, 17, 0}, {72, 6, 18, 0},
                            {73, 7, 1, 0}, {74, 7, 2, 0}, {75, 7, 3, 0}, {76, 7, 4, 0}, {77, 7, 5, 0}, {78, 7, 6, 0},
                            {79, 7, 7, 1}, {80, 7, 8, 2}, {81, 7, 9, 3}, {82, 7, 10, 4}, {83, 7, 11, 5}, {84, 7, 12, 4},
                            {85, 7, 13, 3}, {86, 7, 14, 2}, {87, 7, 15, 1}, {88, 7, 16, 0}, {89, 7, 17, 0}, {90, 7, 18, 0},
                            {91, 8, 1, 0}, {92, 8, 2, 0}, {93, 8, 3, 0}, {94, 8, 4, 0}, {95, 8, 5, 0}, {96, 8, 6, 0},
                            {97, 8, 7, 0}, {98, 8, 8, 0}, {99, 8, 9, 0}, {100, 8, 10, 0}, {101, 8, 11, 0}, {102, 8, 12, 0},
                            {103, 8, 13, 0}, {104, 8, 14, 0}, {105, 8, 15, 0}, {106, 8, 16, 0}, {107, 8, 17, 0}, {108, 8, 18, 0},
                            {109, 9, 1, 0}, {110, 9, 2, 0}, {111, 9, 3, 0}, {112, 9, 4, 0}, {113, 9, 5, 1}, {114, 9, 6, 2},
                            {115, 9, 7, 3}, {116, 9, 8, 4}, {117, 9, 9, 5}, {118, 9, 10, 6}};
    char *ELEMENT_NAMES[] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon",
                             "Nitrogen", "Oxygen", "Fluorine", "Neon", "Sodium", "Magnesium",
                             "Aluminium", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon",
                             "Potassium", "Calcium", "Scandium", "Titanium", "Vanadium",
                             "Chromium", "Manganese", "Iron", "Cobalt", "Nickel", "Copper",
                             "Zinc", "Gallium", "Germanium", "Arsenic", "Selenium", "Bromine",
                             "Krypton", "Rubidium", "Strontium", "Yttrium", "Zirconium",
                             "Niobium", "Molybdenum", "Technetium", "Ruthenium", "Rhodium",
                             "Palladium", "Silver", "Cadmium", "Indium", "Tin", "Antimony",
                             "Tellurium", "Iodine", "Xenon", "Cesium", "Barium", "Lanthanum",
                             "Cerium", "Praseodymium", "Neodymium", "Promethium", "Samarium",
                             "Europium", "Gadolinium", "Terbium", "Dysprosium", "Holmium",
                             "Erbium", "Thulium", "Ytterbium", "Lutetium", "Hafnium",
                             "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium",
                             "Platinum", "Gold", "Mercury", "Thallium", "Lead", "Bismuth",
                             "Polonium", "Astatine", "Radon", "Francium", "Radium", "Actinium",
                             "Thorium", "Protactinium", "Uranium", "Neptunium", "Plutonium",
                             "Americium", "Curium", "Berkelium", "Californium", "Einsteinium",
                             "Fermium", "Mendelevium", "Nobelium", "Lawrencium", "Rutherfordium",
                             "Dubnium", "Seaborgium", "Bohrium", "Hassium", "Meitnerium",
                             "Darmstadtium", "Roentgenium", "Copernicium", "Nihonium",
                             "Flerovium", "Moscovium", "Livermorium", "Tennessine", "Oganesson"};

    srand(time(0)); //seed rand function with current time

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("To begin, enter 1 to start or 0 to exit: ");
    scanf("%d", &option);

    while(option == 1){
        i = rand() % SIZE; //generate random element

        printf("\nWhat is the atomic number of %s? ", ELEMENT_NAMES[elements[i][0]-1]); //print element name

        scanf("%d", &ans); //get user's answer

        if(ans == elements[i][0]){ //check if answer is correct
            score++;
            printf("Correct! Your score is %d.\n", score);
        } else {
            printf("Incorrect. The correct answer is %d. Your score is %d.\n", elements[i][0], score);
        }

        //ask if user wants to continue playing
        printf("Do you want to continue? (y/n) ");
        scanf(" %c", &choice);

        if(choice == 'n'){
            printf("Thanks for playing! Your final score is %d.\n", score);
            break;
        }
    }

    return 0;
}