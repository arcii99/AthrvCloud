//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to display the periodic table
void display_table()
{
    printf("\nSymbol\tElement\tAtomic Number\tBlock\n");
    printf("------\t-------\t-------------\t-----\n");
    printf("H\tHydrogen\t1\t\ts\n");
    printf("He\tHelium\t\t2\t\tp\n");
    printf("Li\tLithium\t\t3\t\ts\n");
    printf("Be\tBeryllium\t4\t\ts\n");
    printf("B\tBoron\t\t5\t\tp\n");
    printf("C\tCarbon\t\t6\t\tp\n");
    printf("N\tNitrogen\t7\t\tp\n");
    printf("O\tOxygen\t\t8\t\tp\n");
    printf("F\tFluorine\t9\t\tp\n");
    printf("Ne\tNeon\t\t10\t\tp\n");
    printf("Na\tSodium\t\t11\t\ts\n");
    printf("Mg\tMagnesium\t12\t\ts\n");
    printf("Al\tAluminium\t13\t\tp\n");
    printf("Si\tSilicon\t\t14\t\tp\n");
    printf("P\tPhosphorus\t15\t\tp\n");
    printf("S\tSulfur\t\t16\t\tp\n");
    printf("Cl\tChlorine\t17\t\tp\n");
    printf("Ar\tArgon\t\t18\t\tp\n");
}

// Function to generate random questions
void generate_questions(int num_questions)
{
    int i, question_num, answer;
    srand(time(0)); // sets seed value for random number generation

    for(i=0; i<num_questions; i++)
    {
        question_num = rand() % 18; // generates random number between 0 and 17

        // switch case to choose question based on generated random number
        switch(question_num)
        {
            case 0:
                printf("\nWhat is the atomic number of Hydrogen?");
                answer = 1;
                break;
            case 1:
                printf("\nWhat is the symbol for Carbon?");
                answer = 'C';
                break;
            case 2:
                printf("\nWhat is the element that has an atomic number of 8?");
                answer = "Oxygen";
                break;
            case 3:
                printf("\nWhat is the symbol for Sodium?");
                answer = 'Na';
                break;
            case 4:
                printf("\nWhat is the block that Carbon is in the periodic table?");
                answer = 'p';
                break;
            case 5:
                printf("\nWhat is the element that has an atomic number of 18?");
                answer = "Argon";
                break;
            case 6:
                printf("\nWhat is the symbol for Neon?");
                answer = 'Ne';
                break;
            case 7:
                printf("\nWhat is the element that has an atomic number of 14?");
                answer = "Silicon";
                break;
            case 8:
                printf("\nWhat is the symbol for Phosphorus?");
                answer = 'P';
                break;
            case 9:
                printf("\nWhat is the element that has an atomic number of 9?");
                answer = "Fluorine";
                break;
            case 10:
                printf("\nWhat is the symbol for Magnesium?");
                answer = 'Mg';
                break;
            case 11:
                printf("\nWhat is the block that Nitrogen is in the periodic table?");
                answer = 'p';
                break;
            case 12:
                printf("\nWhat is the element that has an atomic number of 7?");
                answer = "Nitrogen";
                break;
            case 13:
                printf("\nWhat is the symbol for Helium?");
                answer = 'He';
                break;
            case 14:
                printf("\nWhat is the atomic number of Chlorine?");
                answer = 17;
                break;
            case 15:
                printf("\nWhat is the symbol for Beryllium?");
                answer = 'Be';
                break;
            case 16:
                printf("\nWhat is the element that has an atomic number of 15?");
                answer = "Phosphorus";
                break;
            case 17:
                printf("\nWhat is the element that has an atomic number of 5?");
                answer = "Boron";
                break;
        }

        printf("\nAnswer: ");
        // if the answer is a character, use %c to scan, else use %s to scan
        if (question_num==1 || question_num==3 || question_num==6 || question_num==8 || question_num==13 || question_num==15)
        {
            char user_answer;
            scanf(" %c", &user_answer);
            if (user_answer == answer)
            {
                printf("Correct!");
            }
            else
            {
                printf("Incorrect. The correct answer is %c", answer);
            }
        }
        else
        {
            char user_answer[20];
            scanf(" %s", user_answer);
            if (strcmp(user_answer, answer) == 0)
            {
                printf("Correct!");
            }
            else
            {
                printf("Incorrect. The correct answer is %s", answer);
            }
        }
    }
}

int main()
{
    int num_questions;

    printf("Welcome to the Periodic Table Quiz!\n");

    // Prompt user for number of questions to generate
    printf("How many questions would you like to generate? (max 18) ");
    scanf("%d", &num_questions);

    // Ensure that user inputs a value between 1 and 18
    while (num_questions<1 || num_questions>18)
    {
        printf("Invalid input. Please enter a value between 1 and 18: ");
        scanf("%d", &num_questions);
    }

    // display periodic table
    display_table();

    printf("\nLet's begin!\n");

    // generate questions
    generate_questions(num_questions);

    printf("\nThank you for playing!\n");

    return 0;
}