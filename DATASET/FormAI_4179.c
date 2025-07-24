//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    //initialize variables
    int choice1, choice2, choice3;
    char name[20];
    //seed the random generator with time
    srand(time(0));
    //welcome message
    printf("Welcome to the Random Conspiracy Theory Generator\n");
    printf("What is your name?\n");
    scanf("%s", name);
    printf("Hello %s, let's generate a new conspiracy theory for you\n", name);
    //prompt for the user's choices
    printf("Choose a number from 1-5:\n");
    printf("1. Government\n");
    printf("2. Aliens\n");
    printf("3. Illuminati\n");
    printf("4. Big Pharma\n");
    printf("5. Deep State\n");
    scanf("%d", &choice1);
    printf("Choose a number from 1-5:\n");
    printf("1. Mind Control\n");
    printf("2. Disease\n");
    printf("3. Weather Control\n");
    printf("4. Secret Societies\n");
    printf("5. Alien Invasion\n");
    scanf("%d", &choice2);
    printf("Choose a number from 1-5:\n");
    printf("1. Celebrities\n");
    printf("2. Royalty\n");
    printf("3. Major Corporations\n");
    printf("4. Religious Leaders\n");
    printf("5. World Leaders\n");
    scanf("%d", &choice3);
    //randomly generate a conspiracy theory based on user input
    int randNum = rand()%5 + 1;
    switch(randNum){
        case 1:
            printf("The %s is using %s to control the %s\n", choice1==1?"government":choice1==2?"aliens":choice1==3?"Illuminati":choice1==4?"Big Pharma":"Deep State", choice2==1?"mind control":choice2==2?"disease":choice2==3?"weather control":choice2==4?"secret societies":"alien invasion", choice3==1?"celebrities":choice3==2?"royalty":choice3==3?"major corporations":choice3==4?"religious leaders":"world leaders");
            break;
        case 2:
            printf("%s, %s, and %s are part of a secret society bent on taking over the world\n", choice1==1?"The government":choice1==2?"Aliens":choice1==3?"The Illuminati":choice1==4?"Big Pharma":"The Deep State", choice2==1?"mind control":choice2==2?"disease":choice2==3?"weather control":choice2==4?"secret societies":"alien invasion", choice3==1?"celebrities":choice3==2?"royalty":choice3==3?"major corporations":choice3==4?"religious leaders":"world leaders");
            break;
        case 3:
            printf("The %s created %s in order to further their goal of world domination\n", choice1==1?"government":choice1==2?"aliens":choice1==3?"Illuminati":choice1==4?"Big Pharma":"Deep State", choice2==1?"mind control":choice2==2?"disease":choice2==3?"weather control":choice2==4?"secret societies":"alien invasion");
            break;
        case 4:
            printf("%s is using %s to further their own agenda\n", choice1==1?"The government":choice1==2?"Aliens":choice1==3?"The Illuminati":choice1==4?"Big Pharma":"The Deep State", choice3==1?"celebrities":choice3==2?"royalty":choice3==3?"major corporations":choice3==4?"religious leaders":"world leaders");
            break;
        case 5:
            printf("%s is working with %s to achieve a common goal, but at what cost?\n", choice1==1?"The government":choice1==2?"Aliens":choice1==3?"The Illuminati":choice1==4?"Big Pharma":"The Deep State", choice3==1?"celebrities":choice3==2?"royalty":choice3==3?"major corporations":choice3==4?"religious leaders":"world leaders");
            break;
    }

    printf("Thank you for using the Random Conspiracy Theory Generator. Remember, the truth is out there...\n");

    return 0;
}