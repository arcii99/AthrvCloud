//FormAI DATASET v1.0 Category: Math exercise ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
 * This program is a math exercise which can be used by students to practice 
 * solving mathematical equations. The program generates random equations 
 * with various arithmetic operations.
 */

int main()
{
    int num_operations = 5; //number of operations in the equation
    int num_variables = 3; //number of variables in the equation
    int max_value = 10; //maximum value of variables
    int min_value = -10; //minimum value of variables

    char operations[] = {'+', '-', '*', '/'}; //arithmetic operations
    int result, answer, correct_answer_count = 0, incorrect_answer_count = 0; //variables for counting correct and incorrect answers

    srand(time(NULL)); //initialize random seed

    for (int i = 1; i <= 10; i++) //generate 10 equations
    {
        printf("Question %d:\n", i);

        int variables[num_variables]; //array to store values of variables
        char equation[num_operations + num_variables - 1]; //array to store the equation as a string

        for (int j = 0; j < num_variables; j++) //generate random values for variables
        {
            variables[j] = (rand() % (max_value - min_value + 1)) + min_value;
            printf("x%d = %d\n", j+1, variables[j]);
        }

        for (int j = 0; j < num_operations + num_variables - 1; j++) //generate random equation
        {
            if (j % 2 == 0)
            {
                int variable_index = rand() % num_variables;
                equation[j] = 'x' + variable_index + 1;
            }
            else
            {
                int operation_index = rand() % 4;
                equation[j] = operations[operation_index];
            }
        }

        int flag = 1;
        while (flag) //evaluate the equation and check if answer is an integer
        {
            result = equation[0] - 'x' + variables[0];
            for (int j = 1; j < num_operations + num_variables - 1; j += 2)
            {
                int variable_index = equation[j] - 'x';
                int operation_index = (j - 1) / 2;
                int value = variables[variable_index];
                char operation = equation[j + 1];

                switch (operation)
                {
                    case '+':
                        result += value;
                        break;
                    case '-':
                        result -= value;
                        break;
                    case '*':
                        result *= value;
                        break;
                    case '/':
                        if (value == 0)
                        {
                            flag = 0;
                            break;
                        }
                        else
                        {
                            result /= value;
                            break;
                        }
                }
            }

            if (flag == 1 && result % 1 == 0) //check if answer is an integer
            {
                printf("%s = ", equation);
                scanf("%d", &answer);

                if (answer == result) //check if answer is correct
                {
                    printf("Correct!\n");
                    correct_answer_count++;
                }
                else
                {
                    printf("Incorrect. The answer is %d.\n", result);
                    incorrect_answer_count++;
                }

                flag = 0;
            }
            else
            {
                for (int j = 0; j < num_variables; j++) //generate new values for variables
                {
                    variables[j] = (rand() % (max_value - min_value + 1)) + min_value;
                }

                for (int j = 0; j < num_operations + num_variables - 1; j++) //generate new equation
                {
                    if (j % 2 == 0)
                    {
                        int variable_index = rand() % num_variables;
                        equation[j] = 'x' + variable_index + 1;
                    }
                    else
                    {
                        int operation_index = rand() % 4;
                        equation[j] = operations[operation_index];
                    }
                }
            }
        }
    }

    printf("Results:\n");
    printf("Number of correct answers: %d\n", correct_answer_count);
    printf("Number of incorrect answers: %d\n", incorrect_answer_count);

    return 0;
}