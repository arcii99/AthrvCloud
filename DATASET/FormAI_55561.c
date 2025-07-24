//FormAI DATASET v1.0 Category: Online Examination System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char username[20];
    char password[20];
    char answer[20];
    char correct_answer[] = {'a', 'b', 'c', 'd', 'a', 'b', 'c', 'd', 'a', 'b'};
    int correct_count = 0;
    int total_questions = 10;
    char question[200];
    char option1[20];
    char option2[20];
    char option3[20];
    char option4[20];

    printf("Welcome to the Online Examination System!\n");
    printf("Please enter your username: ");
    fgets(username, 20, stdin);
    strtok(username, "\n");

    printf("Please enter your password: ");
    fgets(password, 20, stdin);
    strtok(password, "\n");

    if (strcmp(username, "happy") != 0 || strcmp(password, "1234") != 0)
    {
        printf("Error: Invalid login credentials.\n");
        return 0;
    }

    printf("You have 10 questions to answer. Good luck!\n");

    for (int i=0; i<total_questions; i++)
    {
        printf("Question %d:\n", i+1);

        if (i == 0)
        {
            strcpy(question, "Which is the capital of India?");
            strcpy(option1, "a. New Delhi");
            strcpy(option2, "b. Mumbai");
            strcpy(option3, "c. Kolkata");
            strcpy(option4, "d. Chennai");
        }
        else if (i == 1)
        {
            strcpy(question, "What is the largest organ in the human body?");
            strcpy(option1, "a. Liver");
            strcpy(option2, "b. Lungs");
            strcpy(option3, "c. Skin");
            strcpy(option4, "d. Heart");
        }
        else if (i == 2)
        {
            strcpy(question, "Who invented the telephone?");
            strcpy(option1, "a. Thomas Edison");
            strcpy(option2, "b. Alexander Graham Bell");
            strcpy(option3, "c. Wright Brothers");
            strcpy(option4, "d. Isaac Newton");
        }
        else if (i == 3)
        {
            strcpy(question, "What is the chemical symbol for Gold?");
            strcpy(option1, "a. Au");
            strcpy(option2, "b. Ag");
            strcpy(option3, "c. Cu");
            strcpy(option4, "d. Fe");
        }
        else if (i == 4)
        {
            strcpy(question, "What is the tallest mammal?");
            strcpy(option1, "a. Elephant");
            strcpy(option2, "b. Giraffe");
            strcpy(option3, "c. Rhinoceros");
            strcpy(option4, "d. Hippopotamus");
        }
        else if (i == 5)
        {
            strcpy(question, "Who painted the Mona Lisa?");
            strcpy(option1, "a. Michelangelo");
            strcpy(option2, "b. Leonardo da Vinci");
            strcpy(option3, "c. Rembrandt");
            strcpy(option4, "d. Pablo Picasso");
        }
        else if (i == 6)
        {
            strcpy(question, "What is the smallest country in the world?");
            strcpy(option1, "a. Monaco");
            strcpy(option2, "b. Vatican City");
            strcpy(option3, "c. San Marino");
            strcpy(option4, "d. Andorra");
        }
        else if (i == 7)
        {
            strcpy(question, "What is the largest animal on earth?");
            strcpy(option1, "a. Killer Whale");
            strcpy(option2, "b. Elephant");
            strcpy(option3, "c. Blue Whale");
            strcpy(option4, "d. Giraffe");
        }
        else if (i == 8)
        {
            strcpy(question, "What continent is Egypt located in?");
            strcpy(option1, "a. Europe");
            strcpy(option2, "b. Asia");
            strcpy(option3, "c. Africa");
            strcpy(option4, "d. South America");
        }
        else if (i == 9)
        {
            strcpy(question, "What is the capital of Australia?");
            strcpy(option1, "a. Sydney");
            strcpy(option2, "b. Melbourne");
            strcpy(option3, "c. Brisbane");
            strcpy(option4, "d. Canberra");
        }

        printf("%s\n%s\n%s\n%s\n%s\n", question, option1, option2, option3, option4);

        printf("Enter your answer: ");
        fgets(answer, 20, stdin);
        strtok(answer, "\n");

        if (tolower(answer[0]) == correct_answer[i])
        {
            printf("Correct!\n");
            correct_count++;
        }
        else
        {
            printf("Incorrect!\n");
        }
    }

    printf("You answered %d out of %d questions correctly.\n", correct_count, total_questions);

    return 0;
}