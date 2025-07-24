//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: inquisitive
#include <stdio.h>
#include <string.h>

// function to display the periodic table quiz
void display_periodic_table_quiz() {
    printf("***************\n");
    printf("PERIODIC TABLE QUIZ\n");
    printf("***************\n\n");

    // array of elements with their symbols and atomic numbers
    char elements[118][3] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Ni", "Co", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

    int score = 0; // initialize score to 0
    printf("Quiz starts now!\n\n");

    for(int i=0; i<10; i++) { // loop through 10 questions
        int random_num = rand() % 118; // select a random element from the array
        char symbol[3]; // variable to store the user's answer
        int atomic_num = 0; // variable to store the correct answer

        // loop through the array to find the element with the same symbol as the randomly selected element
        for(int j=0; j<118; j++) {
            if(strcmp(elements[random_num], elements[j]) == 0) {
                atomic_num = j+1;
                strcpy(symbol, elements[j]);
            }
        }

        // display the question and prompt the user for their answer
        printf("What is the atomic number of %s? ", symbol);
        int input_num;
        scanf("%d", &input_num);

        //check if the user's answer is correct and give feedback
        if(input_num == atomic_num) {
            printf("Correct!\n");
            score++;
        }
        else {
            printf("Sorry, the correct answer is %d\n", atomic_num);
        }
    }

    // display the final score
    printf("\nYour final score is %d/10\n", score);
}

int main() {
    display_periodic_table_quiz(); // call the function to start the quiz
    return 0;
}