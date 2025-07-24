//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to generate random number
int generateRandomNumber(int minNum, int maxNum)
{
    srand(time(NULL));
    int randomNumber = rand() % (maxNum - minNum + 1) + minNum;
    return randomNumber;
}

//function to print paranoid fortune messages
void printParanoidMessage(int randomNumber)
{
    switch(randomNumber)
    {
        case 1:
            printf("BEWARE! Your every move is being watched...\n");
            break;
        case 2:
            printf("The future is uncertain and you cannot trust anyone...\n");
            break;
        case 3:
            printf("Do not trust your dreams, they may be controlled by the government...\n");
            break;
        case 4:
            printf("Paranoia is the only way to stay alive in this world...\n");
            break;
        case 5:
            printf("They may be listening to our conversation right now...\n");
            break;
        case 6:
            printf("You're being followed, watch your back...\n");
            break;
        case 7:
            printf("The truth is out there but you may not be ready to handle it...\n");
            break;
        case 8:
            printf("They're manipulating your memories...\n");
            break;
        case 9:
            printf("The government is hiding something from us all...\n");
            break;
        case 10:
            printf("The shadows are moving, something is not right...\n");
            break;
        default:
            printf("Error: Could not generate fortune message\n");
            break;
    }
}

int main()
{
    int minNum = 1, maxNum = 10;
    int randomNumber = generateRandomNumber(minNum, maxNum);

    printf("Welcome to the Paranoid Fortune Teller...\n");
    printf("Your fortune for today is...\n");
    printParanoidMessage(randomNumber);

    return 0;
}