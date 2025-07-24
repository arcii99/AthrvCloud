//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: visionary
#include <stdio.h>
#include <string.h>

int main()
{
    char name[20];
    int player_choice, treasure_choice, correct_guesses = 0;
    printf("Welcome to the treasure hunt game!\n");
    printf("What's your name?\n");
    scanf("%s", name);
    printf("Greetings, %s. Your adventure begins now!\n", name);

    while (correct_guesses < 3)
    {
        printf("\nYou are standing in front of a castle. What do you do?\n");
        printf("1) Enter the castle\n");
        printf("2) Look for a map\n");
        printf("3) Run away\n");
        scanf("%d", &player_choice);

        if (player_choice == 1)
        {
            printf("\nYou enter the castle and encounter a guard. He asks for a password.\n");
            char password[20];
            printf("Enter the secret password: ");
            scanf("%s", password);
          
            if (strcmp(password, "open sesame") == 0)
            {
                printf("\nThe guard allows you to enter the main room of the castle.\n");
                printf("You see three chests in front of you. Which one do you choose?\n");
              
                printf("1) The gold chest\n");
                printf("2) The silver chest\n");
                printf("3) The wooden chest\n");
                scanf("%d", &treasure_choice);

                if (treasure_choice == 2)
                {
                    printf("\nCongratulations, %s! You have found the treasure and won the game!\n", name);
                    return 0;
                }
                else
                {
                    printf("\nWrong choice, %s. The treasure is not in this chest.\n", name);
                }
            }
            else
            {
                printf("\nInvalid password. You cannot enter the castle.\n");
            }
        }
        else if (player_choice == 2)
        {
            printf("\nYou find a map. It shows you a secret path to the treasure.\n");
            correct_guesses++;
        }
        else if (player_choice == 3)
        {
            printf("\nYou ran away. Please try again, %s.\n", name);
            return 0;
        }
        else 
        {
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    printf("\nCongratulations, %s! You have found the treasure and won the game!\n", name);
    return 0;
}