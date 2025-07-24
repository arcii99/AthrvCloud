//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to wait for user input
void press_any_key()
{
    printf("Press any key to continue...");
    while(getchar() != '\n');
    getchar();
}

//Function to clear the terminal
void clear_screen()
{
    system("clear");
}

//Function to generate a random number
int generate_random(int limit)
{
    srand(time(NULL));
    return rand() % limit + 1;
}

//Function to display instructions
void display_instructions()
{
    printf("Welcome to Invasive, the ultimate terminal-based game!\n\n");
    printf("The rules are simple:\n");
    printf("-You are a virus that wants to invade the host cell.\n");
    printf("-The host cell has defenses that will try to stop you.\n");
    printf("-You have to dodge the defenses and make your way to the center of the cell.\n");
    printf("-Once you reach the center, you have invaded the cell and won the game!\n\n");
    press_any_key();
}

//Function to display the game board
void display_board(int cell_size, int virus_position)
{
    clear_screen();
    printf("  ");
    for(int i = 1; i <= cell_size; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    for(int i = 1; i <= cell_size; i++)
    {
        printf("%d ", i);
        for(int j = 1; j <= cell_size; j++)
        {
            if(i == cell_size / 2 && j == cell_size / 2)
            {
                printf("O ");
            }
            else if(j == virus_position)
            {
                printf("V ");
            }
            else
            {
                printf(". ");    
            }
        }
        printf("\n");
    }
}

int main()
{
    int cell_size = 10;
    int virus_position = generate_random(cell_size);
    int defense_1_position = generate_random(cell_size);
    int defense_2_position = generate_random(cell_size);

    display_instructions();

    while(1)
    {
        //Display the game board
        display_board(cell_size, virus_position);

        //Get the user input
        char input;
        printf("Enter your move (l/r): ");
        scanf("%c", &input);
        getchar();

        //Move the virus
        if(input == 'l')
        {
            virus_position--;
        }
        else if(input == 'r')
        {
            virus_position++;
        }

        //Check if the virus has invaded the center of the cell
        if(virus_position == cell_size / 2 && defense_1_position != virus_position && defense_2_position != virus_position)
        {
            display_board(cell_size, virus_position);
            printf("Congratulations! You have successfully invaded the cell!\n");
            break;
        }

        //Move the defenses
        defense_1_position = (defense_1_position + 1) % cell_size + 1;
        defense_2_position = (defense_2_position - 1) % cell_size + 1;

        //Check if any defense has hit the virus
        if(defense_1_position == virus_position || defense_2_position == virus_position)
        {
            display_board(cell_size, virus_position);
            printf("GAME OVER! The defenses have caught you!\n");
            break;
        }
    }

    return 0;
}