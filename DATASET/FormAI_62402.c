//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void delay(int); // Function to create delays for suspense

int main()
{
    char response[50]; // Array to store user input
    int correct_input = 0; // Flag to check for correct user input
    printf("Welcome to the surreal adventure game!\n");
    delay(1500);
    printf("You wake up in a dark, empty room. The walls are covered in surreal paintings, and you have no idea how you got here.\n");
    delay(3000);
    printf("You notice a door in front of you. What do you do?\n");
    while(!correct_input) // Loop to get correct user input
    {
        scanf("%s", response);
        if(strcmp(response, "open") == 0 || strcmp(response, "Open") == 0)
        {
            correct_input = 1;
            printf("You open the door and find yourself in a room filled with mirrors. The mirrors show distorted versions of yourself. What do you do?\n");
            delay(2000);
            printf("A voice echoes through the room: 'If you want to escape, you must find the key.'\n");
            delay(2500);
            printf("You notice a key floating in the center of the room. However, the mirrors are making it difficult to reach. What is your plan?\n");
            correct_input = 0;
            while(!correct_input) // Nested loop for correct user input
            {
                scanf("%s", response);
                if(strcmp(response, "break") == 0 || strcmp(response, "Break") == 0)
                {
                    correct_input = 1;
                    printf("You break one of the mirrors, causing a chain reaction that shatters all the mirrors. The key falls to the ground. You grab the key and find the door to escape. Congratulations, you escaped the surreal adventure game.\n");
                }
                else if(strcmp(response, "climb") == 0 || strcmp(response, "Climb") == 0) 
                {
                    correct_input = 1;
                    printf("You climb over the mirrors and reach the key. You find the door to escape. Congratulations, you escaped the surreal adventure game.\n");
                }
                else
                {
                    printf("That doesn't seem like a good plan. Try again.\n");
                }
            }
        }
        else if(strcmp(response, "sleep") == 0 || strcmp(response, "Sleep") == 0)
        {
            correct_input = 1;
            printf("You fall asleep and wake up to find yourself in a different, but equally surreal room. The adventure continues...\n");
        }
        else
        {
            printf("That doesn't seem like a good idea. Try again.\n");
        }
    }
    return 0;
}

void delay(int milliseconds) // Delay function using clock ticks
{
    clock_t start_time = clock();
    while(clock() < start_time + milliseconds);
}