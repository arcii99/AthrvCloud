//FormAI DATASET v1.0 Category: Smart home automation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to your cozy and hilarious smart home!\n");

    int temperature = 22; //default temperature
    int lightsOn = 0; //default lights state (off)

    printf("The current temperature is %d degrees Celsius.\n", temperature);

    printf("Would you like to turn on the lights? (y/n)\n");
    char answer = getchar();

    if(answer == 'y'){
        lightsOn = 1;
        printf("The lights are now on. Enjoy the brightness!\n");
    }
    else if(answer == 'n'){
        printf("Okay, we'll keep the lights off. It's spooky anyways...\n");
    }
    else{
        printf("I'm sorry, I don't understand. I'm just a simple program.\n");
    }

    printf("Would you like to adjust the temperature? (y/n)\n");
    answer = getchar();

    if(answer == 'y'){
        printf("Enter the desired temperature: ");
        scanf("%d", &temperature);
        printf("Ah, a smart choice. The temperature is now set to %d degrees Celsius.\n", temperature);
    }
    else if(answer == 'n'){
        printf("Alright then, I'll leave the temperature as is. Don't get too hot or cold now!\n");
    }
    else{
        printf("I give up, I can't handle your indecisiveness. I'm just a program for crying out loud...\n");
    }

    printf("Thanks for using our smart home system. Your bill will be outrageous, but at least you'll have a good laugh.\n");

    return 0;
}