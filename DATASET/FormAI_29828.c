//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ELEMENTS 118 //total number of elements in periodic table

int generateRandomNumber(int min, int max); //function to generate random numbers

int main() {
    char elements[ELEMENTS][3] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"}; //array containing all elements in periodic table
    int randomIndices[10],answers[10],score = 0; //arrays to hold random indices, answers and score
    srand(time(NULL)); //seed the random generator
   
    for(int i = 0; i < 10; i++) {
        randomIndices[i] = generateRandomNumber(0, ELEMENTS-1); //get random index for current quiz question
        printf("What is the symbol for element %d in the periodic table?\n", randomIndices[i]+1); //ask question
        scanf("%s", &answers[i]); //get user input
        if(answers[i] == elements[randomIndices[i]]) { //check if answer is correct
            printf("Correct!\n");
            score += 10; //increase score by 10
        } else {
            printf("Incorrect!\n");
        }
    }
    printf("Your score is %d\n", score); //display final score
    return 0;
}

int generateRandomNumber(int min, int max) {
    return rand() % (max-min+1) + min;
}