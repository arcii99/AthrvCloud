//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* conspiracy_theories [10] = {"The moon landing was faked by the government","The Illuminati controls the world","9/11 was an inside job","Aliens have infiltrated the government","The Earth is flat","Vaccines are causing autism","The government is hiding the cure for cancer","Chemtrails are being used for mind control","The government is controlling the weather with HAARP","The reptilian elite are running the world"};

int main()
{
    srand(time(0));
    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("Here is your unique conspiracy theory for the day:\n");
    printf("%s\n", conspiracy_theories[rand() % 10]);

    printf("Do you want to generate another conspiracy theory? (y/n)\n");
    char choice;
    scanf("%s",&choice);

    if(choice == 'y')
    {
        printf("Here is your new conspiracy theory for the day:\n");
        printf("%s\n", conspiracy_theories[rand() % 10]);
    }
    else
    {
        printf("Thank you for using the Random Conspiracy Theory Generator. Stay woke!\n");
    }
    return 0;
}