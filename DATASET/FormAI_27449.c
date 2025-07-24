//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL)); //seed for random number generation
    char elements[118][3] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge",
                                "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu",
                                "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu",
                                "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr"};
    int num_questions, score = 0, random_elements[10];
    printf("Welcome to the Futuristic Periodic Table Quiz!\n");
    printf("Enter number of questions you want to attempt (max 10): ");
    scanf("%d", &num_questions);
    if (num_questions > 10){
        printf("You can only choose 10 or less questions!\n");
        return 0;
    }
    printf("You will be shown %d elements and you have to guess their atomic number.\nAnswer correctly to score points.\n", num_questions);

    //generate 10 random elements
    for (int i=0; i<num_questions; i++){
        random_elements[i] = (rand() % 118 ) + 1;
    }

    //ask questions
    for (int i=0; i<num_questions; i++){
        int atomic_number;
        printf("\nQuestion %d: What is the atomic number of %s? ", i+1, elements[random_elements[i]-1]);
        scanf("%d", &atomic_number);
        if (atomic_number == random_elements[i]){
            printf("Correct! You earned 1 point.\n");
            score++;
        }
        else{
            printf("Incorrect! The correct atomic number of %s is: %d\n", elements[random_elements[i]-1], random_elements[i]);
        }
    }

    printf("\nYou scored %d out of %d!\n", score, num_questions);

    return 0;
}