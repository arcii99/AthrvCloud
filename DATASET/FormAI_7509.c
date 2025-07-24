//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define NUM_ELEMENTS 118
#define MAX_NAME_SIZE 15

// Define struct for elements
typedef struct element 
{
    char name[MAX_NAME_SIZE];
    char symbol[3];
    int number;
    float atomic_weight;
} Element;

// Function to generate random integer between 0 and max_value-1
int generate_random(int max_value) 
{
    return rand() % max_value;
}

// Function to create new element
Element create_element(char name[], char symbol[], int number, float atomic_weight) 
{
    Element new_element;
    strcpy(new_element.name, name);
    strcpy(new_element.symbol, symbol);
    new_element.number = number;
    new_element.atomic_weight = atomic_weight;
    return new_element;
}

int main() 
{
    // Create array of elements
    Element elements[NUM_ELEMENTS] = {
        create_element("Hydrogen", "H", 1, 1.008),
        create_element("Helium", "He", 2, 4.003),
        create_element("Lithium", "Li", 3, 6.941),
        create_element("Beryllium", "Be", 4, 9.012),
        create_element("Boron", "B", 5, 10.81),
        create_element("Carbon", "C", 6, 12.01),
        create_element("Nitrogen", "N", 7, 14.01),
        create_element("Oxygen", "O", 8, 16.00),
        create_element("Fluorine", "F", 9, 19.00),
        create_element("Neon", "Ne", 10, 20.18),
        create_element("Sodium", "Na", 11, 22.99),
        create_element("Magnesium", "Mg", 12, 24.31),
        create_element("Aluminum", "Al", 13, 26.98),
        create_element("Silicon", "Si", 14, 28.09),
        create_element("Phosphorus", "P", 15, 30.97),
        create_element("Sulfur", "S", 16, 32.06),
        create_element("Chlorine", "Cl", 17, 35.45),
        create_element("Argon", "Ar", 18, 39.95),
        create_element("Potassium", "K", 19, 39.09),
        create_element("Calcium", "Ca", 20, 40.08),
        create_element("Scandium", "Sc", 21, 44.96),
        create_element("Titanium", "Ti", 22, 47.87),
        create_element("Vanadium", "V", 23, 50.94),
        create_element("Chromium", "Cr", 24, 52.00),
        create_element("Manganese", "Mn", 25, 54.94),
        create_element("Iron", "Fe", 26, 55.85),
        create_element("Cobalt", "Co", 27, 58.93),
        create_element("Nickel", "Ni", 28, 58.69),
        create_element("Copper", "Cu", 29, 63.55),
        create_element("Zinc", "Zn", 30, 65.38),
        create_element("Gallium", "Ga", 31, 69.72),
        create_element("Germanium", "Ge", 32, 72.63),
        create_element("Arsenic", "As", 33, 74.92),
        create_element("Selenium", "Se", 34, 78.96),
        create_element("Bromine", "Br", 35, 79.90),
        create_element("Krypton", "Kr", 36, 83.80),
        create_element("Rubidium", "Rb", 37, 85.47),
        create_element("Strontium", "Sr", 38, 87.62),
        create_element("Yttrium", "Y", 39, 88.91),
        create_element("Zirconium", "Zr", 40, 91.22),
        create_element("Niobium", "Nb", 41, 92.91),
        create_element("Molybdenum", "Mo", 42, 95.94),
        create_element("Technetium", "Tc", 43, 98.00),
        create_element("Ruthenium", "Ru", 44, 101.07),
        create_element("Rhodium", "Rh", 45, 102.91),
        create_element("Palladium", "Pd", 46, 106.42),
        create_element("Silver", "Ag", 47, 107.87),
        create_element("Cadmium", "Cd", 48, 112.41),
        create_element("Indium", "In", 49, 114.82),
        create_element("Tin", "Sn", 50, 118.71),
        create_element("Antimony", "Sb", 51, 121.76),
        create_element("Tellurium", "Te", 52, 127.60),
        create_element("Iodine", "I", 53, 126.90),
        create_element("Xenon", "Xe", 54, 131.29),
        create_element("Cesium", "Cs", 55, 132.91),
        create_element("Barium", "Ba", 56, 137.33),
        create_element("Lanthanum", "La", 57, 138.91),
        create_element("Cerium", "Ce", 58, 140.12),
        create_element("Praseodymium", "Pr", 59, 140.91),
        create_element("Neodymium", "Nd", 60, 144.24),
        create_element("Promethium", "Pm", 61, 145.00),
        create_element("Samarium", "Sm", 62, 150.36),
        create_element("Europium", "Eu", 63, 151.96),
        create_element("Gadolinium", "Gd", 64, 157.25),
        create_element("Terbium", "Tb", 65, 158.93),
        create_element("Dysprosium", "Dy", 66, 162.50),
        create_element("Holmium", "Ho", 67, 164.93),
        create_element("Erbium", "Er", 68, 167.26),
        create_element("Thulium", "Tm", 69, 168.93),
        create_element("Ytterbium", "Yb", 70, 173.05),
        create_element("Lutetium", "Lu", 71, 174.97),
        create_element("Hafnium", "Hf", 72, 178.49),
        create_element("Tantalum", "Ta", 73, 180.95),
        create_element("Tungsten", "W", 74, 183.84),
        create_element("Rhenium", "Re", 75, 186.21),
        create_element("Osmium", "Os", 76, 190.23),
        create_element("Iridium", "Ir", 77, 192.22),
        create_element("Platinum", "Pt", 78, 195.08),
        create_element("Gold", "Au", 79, 196.97),
        create_element("Mercury", "Hg", 80, 200.59),
        create_element("Thallium", "Tl", 81, 204.38),
        create_element("Lead", "Pb", 82, 207.2),
        create_element("Bismuth", "Bi", 83, 208.98),
        create_element("Polonium", "Po", 84, 209.00),
        create_element("Astatine", "At", 85, 210.00),
        create_element("Radon", "Rn", 86, 222.00),
        create_element("Francium", "Fr", 87, 223.00),
        create_element("Radium", "Ra", 88, 226.03),
        create_element("Actinium", "Ac", 89, 227.03),
        create_element("Thorium", "Th", 90, 232.04),
        create_element("Protactinium", "Pa", 91, 231.04),
        create_element("Uranium", "U", 92, 238.03),
        create_element("Neptunium", "Np", 93, 237.05),
        create_element("Plutonium", "Pu", 94, 244.06),
        create_element("Americium", "Am", 95, 243.06),
        create_element("Curium", "Cm", 96, 247.07),
        create_element("Berkelium", "Bk", 97, 247.07),
        create_element("Californium", "Cf", 98, 251.08),
        create_element("Einsteinium", "Es", 99, 252.08),
        create_element("Fermium", "Fm", 100, 257.10),
        create_element("Mendelevium", "Md", 101, 258.10),
        create_element("Nobelium", "No", 102, 259.10),
        create_element("Lawrencium", "Lr", 103, 262.11),
        create_element("Rutherfordium", "Rf", 104, 261.11),
        create_element("Dubnium", "Db", 105, 262.11),
        create_element("Seaborgium", "Sg", 106, 266.12),
        create_element("Bohrium", "Bh", 107, 264.12),
        create_element("Hassium", "Hs", 108, 267.13),
        create_element("Meitnerium", "Mt", 109, 268.14),
        create_element("Darmstadtium", "Ds", 110, 271.15),
        create_element("Roentgenium", "Rg", 111, 272.15),
        create_element("Copernicium", "Cn", 112, 277.16),
        create_element("Nihonium", "Nh", 113, 284.18),
        create_element("Flerovium", "Fl", 114, 289.19),
        create_element("Moscovium", "Mc", 115, 288.19),
        create_element("Livermorium", "Lv", 116, 293.20),
        create_element("Tennessine", "Ts", 117, 294.21),
        create_element("Oganesson", "Og", 118, 294.21)
    };

    // Initialize variables
    int score = 0;
    int num_questions = 0;
    int option;
    int random_indices[4];
    int i, j;
    float ans;
    char name_guess[MAX_NAME_SIZE];
    char symbol_guess[3];

    // Initialize random seed
    srand(time(NULL));

    // Print welcome message and instructions
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be given a series of questions. For each question, you will be given the name or symbol of a randomly selected element.\n");
    printf("Your task is to correctly identify the corresponding symbol or name, respectively.\n");
    printf("Enter 1 to start the quiz, or 2 to quit: ");
    scanf("%d", &option);

    // User chose to start the quiz
    if (option == 1) 
    {
        // Loop until user chooses to quit
        while (1) 
        {
            // Generate 4 random indices for answer options
            for (i = 0; i < 4; i++)
            {
                random_indices[i] = generate_random(NUM_ELEMENTS);
            }

            // Generate random index for question
            int question_index = generate_random(NUM_ELEMENTS);

            // Determine whether to ask for name or symbol
            if (generate_random(2) == 0) 
            {
                // Ask for symbol
                printf("\nWhat is the symbol of \"%s\"?\n", elements[question_index].name);

                // Print answer choices
                printf("A. %s\n", elements[random_indices[0]].symbol);
                printf("B. %s\n", elements[random_indices[1]].symbol);
                printf("C. %s\n", elements[random_indices[2]].symbol);
                printf("D. %s\n", elements[random_indices[3]].symbol);

                // Prompt user for answer and evaluate
                printf("Enter your answer (A, B, C, or D): ");
                scanf(" %c", &name_guess);

                if (name_guess[0] == elements[question_index].symbol[0])
                {
                    printf("Correct!\n");
                    score++;
                }
                else
                {
                    printf("Incorrect. The correct answer is \"%s\".\n", elements[question_index].symbol);
                }
            }
            else 
            {
                // Ask for name
                printf("\nWhat is the name of \"%s\"?\n", elements[question_index].symbol);

                // Print answer choices
                printf("A. %s\n", elements[random_indices[0]].name);
                printf("B. %s\n", elements[random_indices[1]].name);
                printf("C. %s\n", elements[random_indices[2]].name);
                printf("D. %s\n", elements[random_indices[3]].name);

                // Prompt user for answer and evaluate
                printf("Enter your answer (A, B, C, or D): ");
                scanf(" %c", &symbol_guess);

                if (symbol_guess[0] == elements[question_index].name[0])
                {
                    printf("Correct!\n");
                    score++;
                }
                else
                {
                    printf("Incorrect. The correct answer is \"%s\".\n", elements[question_index].name);
                }
            }

            // Increment number of questions asked
            num_questions++;

            // Ask user if they want to continue
            printf("Enter 1 to continue, or 2 to quit: ");
            scanf("%d", &option);
            if (option == 2)
            {
                break;
            }
        }

        // Print final score
        printf("\nFinal Score: %d/%d\n", score, num_questions);
    }
    // User chose to quit
    else 
    {
        printf("Thank you for playing the Periodic Table Quiz!\n");
    }

    return 0;
}