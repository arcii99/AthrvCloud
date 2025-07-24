//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int i, j, num, temp, score = 0;
    char symbol[118][3] = {"H" , "He", "Li", "Be", "B" , "C" , "N" , "O" , "F" , "Ne",
                           "Na", "Mg", "Al", "Si", "P" , "S" , "Cl", "Ar", "K" , "Ca",
                           "Sc", "Ti", "V" , "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
                           "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y" , "Zr",
                           "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
                           "Sb", "Te", "I" , "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
                           "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
                           "Lu", "Hf", "Ta", "W" , "Re", "Os", "Ir", "Pt", "Au", "Hg",
                           "Tl", "Pb", "Bi", "Th", "Pa", "U" , "Np", "Pu", "Am", "Cm",
                           "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg",
                           "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv",
                           "Ts", "Og"};
    int atomic_num[118] = {1  , 2  , 3  , 4  , 5  , 6  , 7  , 8  , 9  , 10 ,
                           11 , 12 , 13 , 14 , 15 , 16 , 17 , 18 , 19 , 20 ,
                           21 , 22 , 23 , 24 , 25 , 26 , 27 , 28 , 29 , 30 ,
                           31 , 32 , 33 , 34 , 35 , 36 , 37 , 38 , 39 , 40 ,
                           41 , 42 , 43 , 44 , 45 , 46 , 47 , 48 , 49 , 50 ,
                           51 , 52 , 53 , 54 , 55 , 56 , 57 , 58 , 59 , 60 ,
                           61 , 62 , 63 , 64 , 65 , 66 , 67 , 68 , 69 , 70 ,
                           71 , 72 , 73 , 74 , 75 , 76 , 77 , 78 , 79 , 80 ,
                           81 , 82 , 83 , 90 , 91 , 92 , 93 , 94 , 95 , 96 ,
                           97 , 98 , 99 , 100, 101, 102, 103, 104, 105, 106,
                           107, 108, 109, 110, 111, 112, 113, 114, 115, 116,
                           117, 118};
    srand(time(0));
    printf("Welcome to the Periodic Table Quiz! You will be shown symbols and you have to guess the corresponding element's atomic number.\nEnter how many questions would you like to take:");
    scanf("%d", &num);
    for(i = 0; i < num; i++) {
        int rand_num = rand() % 118;
        printf("\n%s ", symbol[rand_num]);
        scanf("%d", &temp);
        if(temp == atomic_num[rand_num]) {
            printf("Correct! ");
            score++;
        }
        else {
            printf("Incorrect, the correct answer is %d. ", atomic_num[rand_num]);
        }
        printf("Current Score: %d\n", score);
    }
    printf("\n\nCongratulations you have completed the quiz!\nYour final score is %d", score);
    return  0;
}