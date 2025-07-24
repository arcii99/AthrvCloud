//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 118

int main(){
    char elements[MAX][3] = {"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Nh","Fl","Mc","Lv","Ts","Og"};
    int atomic_num[MAX] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118};
    int num_of_questions = 5; //set number of questions for quiz
    int score = 0;
    srand(time(0)); //to generate random element number for question

    printf("\nWelcome to the Surrealist Periodic Table Quiz!\n\n");
    printf("In this quiz, you will be given the atomic number of an element,\n");
    printf("and you have to enter its corresponding symbol.\n");
    printf("You will be given 5 questions. The score will be displayed at the end.\n\n");

    for(int i=0; i<num_of_questions; i++){
        int random_num = rand() % MAX;
        printf("Question %d: What is the symbol of the element with atomic number %d?\n", i+1, atomic_num[random_num]);
        char answer[3];
        scanf("%s", answer);
        if(strcmp(answer, elements[random_num]) == 0){
            score++;
            printf("Correct answer!\n");
        }
        else{
            printf("Incorrect answer. The correct answer is %s.\n", elements[random_num]);
        }
    }

    printf("\nCorrectly answered %d out of %d questions.\n", score, num_of_questions);
    printf("Thanks for participating in the Surrealist Periodic Table Quiz!\n\n");
    return 0;
}