//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, ans, score = 0;
    int option[4][2];
    char elements[118][3] = {"H ", "He", "Li", "Be", "B ", "C ", "N ", "O ", "F ", "Ne",
                             "Na", "Mg", "Al", "Si", "P ", "S ", "Cl", "Ar", "K ", "Ca",
                             "Sc", "Ti", "V ", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
                             "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y ", "Zr",
                             "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
                             "Sb", "Te", "I ", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
                             "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
                             "Lu", "Hf", "Ta", "W ", "Re", "Os", "Ir", "Pt", "Au", "Hg",
                             "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
                             "Pa", "U ", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
                             "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
                             "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};
    int atomic_num[118] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                           21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
                           40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58,
                           59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77,
                           78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96,
                           97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112,
                           113, 114, 115, 116, 117, 118};

    srand(time(NULL)); 

    printf("          Welcome to the Periodic Table Quiz!\n\nRule: Enter the atomic number of the element!\n\n");

    for (i = 1; i <= 10; i++)
    {
        printf("Question #%d:\n\n", i);
        ans = rand() % 118;

        printf("%s?\n\n", elements[ans]);

        for (j = 0; j < 4; j++)
        {
            option[j][0] = rand() % 118;
            option[j][1] = 0;

            if (option[j][0] == ans) 
            {
                j--;
                continue;
            }

            if (j == 0)
                printf("A. %d\n", atomic_num[option[j][0]]);
            else if (j == 1)
                printf("B. %d\n", atomic_num[option[j][0]]);
            else if (j == 2)
                printf("C. %d\n", atomic_num[option[j][0]]);
            else if (j == 3)
                printf("D. %d\n", atomic_num[option[j][0]]);
        }

        answer:
            printf("\nYour answer: ");
            char user_input[5];
            scanf("%s", user_input);
            if (isdigit(user_input[0]))
            {
                if (atoi(user_input) == atomic_num[ans])
                {
                    printf("CORRECT! \n");
                    score++;
                }
                else
                {
                    printf("WRONG - The correct answer is %d. \n", atomic_num[ans]);
                }
            }
            else
            {
                printf("Invalid input! Please enter a number. \n");
                goto answer; 
            }

        printf("\n------------------------------------------------------\n");
    }

    printf("\n\nYou have scored %d out of 10! \n\nThanks for playing the Periodic Table Quiz. \n", score);

    return 0;
}