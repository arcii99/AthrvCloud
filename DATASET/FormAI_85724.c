//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//C Automated Fortune Teller
void fortune_teller()
{
    int fortune_number;
    srand(time(NULL));
    fortune_number=rand()%5;//generate random number between 0 and 4
    switch(fortune_number)
    {
        case 0:
            printf("You will soon embark on a great adventure.\n");
            break;
        case 1:
            printf("A special person will come into your life this month.\n");
            break;
        case 2:
            printf("Your hard work will pay off very soon.\n");
            break;
        case 3:
            printf("A financial windfall is coming your way.\n");
            break;
        case 4:
            printf("You will receive unexpected good news.\n");
            break;
    }
}
//main function
int main()
{
    char choice;
    printf("Welcome to the Automated Fortune Teller.\n");
    printf("Press 'y' to get your fortune or 'n' to exit.\n");
    scanf("%c",&choice);//get user's choice
    while(choice=='y' || choice=='Y')//keep giving fortunes until user decides to exit
    {
        fortune_teller();//call the function to generate a fortune
        printf("Press 'y' to get your fortune or 'n' to exit.\n");
        scanf(" %c",&choice);//get user's choice again
    }
    printf("Thank you for visiting the Automated Fortune Teller!\n");
    return 0;
}