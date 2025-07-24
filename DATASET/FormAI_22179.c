//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int score = 0;
    int questions = 0;
    char answer[3];
    char elements[118][3] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};
    
    printf("Welcome to the Periodic Table Quiz!\n\n");
    printf("Please type the symbol of the element corresponding to the given atomic number.\n\n");
    printf("You will be given 10 questions.\n\n");
    
    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        int atomic_number = rand()%118 + 1;
        printf("Question %d: What is the symbol of the element with atomic number %d?\n", i+1, atomic_number);
        scanf("%s", answer);
        questions++;
        if(strcmp(answer, elements[atomic_number-1]) == 0){
            score++;
            printf("Correct!\n");
        }
        else{
            printf("Incorrect. The correct answer is %s.\n", elements[atomic_number-1]);
        }
    }
    
    printf("\nYou have answered %d out of 10 questions correctly.\n", score);
    if(score < 5){
        printf("Better luck next time!\n");
    }
    else if(score >= 5 && score < 10){
        printf("Good job!\n");
    }
    else{
        printf("Excellent work! You answered all questions correctly!\n");
    }
    
    return 0;
}