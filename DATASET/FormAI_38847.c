//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void galaxy()
{
    printf("Welcome to the peaceful galaxy! You are the captain of a spaceship.\n");
    printf("Your mission is to survey the neighboring planets and collect data that will help us learn more about the universe.\n");
}

int planet()
{
    int temp,pressure,radiation;
    temp=rand()%201-100;
    pressure=rand()%101;
    radiation=rand()%51;

    printf("You have landed on a planet with the following parameters:\n");
    printf("Temperature: %d degrees Celsius\n",temp); 
    printf("Pressure: %d atm\n",pressure); 
    printf("Radiation: %d R/h\n",radiation);

    if(temp>=-30 && temp<=40 && pressure<=70 && radiation<=15)
    {
        printf("This planet is safe for human life.\n");
        return 1;
    }
    else
    {
        printf("This planet is unsafe for human life.\n");
        return 0;
    }
}

void mission()
{
    int planets_explored=0;
    int planets_safe=0;

    while(planets_explored<5)
    {
        printf("\n\n---------------- planet %d ----------------\n",planets_explored+1);
        planets_explored+=1;
        planets_safe+=planet();
    }

    printf("\n\n----------- mission report ------------\n");
    printf("Number of planets explored: %d\n",planets_explored);
    printf("Number of safe planets: %d\n",planets_safe);
    printf("Success rate: %.2f%%\n\n",(float)planets_safe/planets_explored*100);
}

int main()
{
    srand(time(0));
    galaxy();
    mission();
    return 0;
}