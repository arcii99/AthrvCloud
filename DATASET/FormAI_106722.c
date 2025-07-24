//FormAI DATASET v1.0 Category: Weather simulation ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    srand(time(NULL));
    float temp = (rand() % 50) + 1; //random temperature between 1 to 50 degree Celsius
    float humidity = (rand() % 100); //random humidity between 0% to 100%
    float pressure = (rand() % 500) + 900; //random pressure between 900hPa to 1399hPa

    printf("\nWelcome to the Happy Weather Simulation Program!\n\n");

    printf("The temperature today is %.2f degree Celsius, which is perfect to have a picnic or go for a swim!\n", temp);

    if (humidity > 70){
        printf("The humidity is %.2f%%, which is quite high! But don't worry, it's still a perfect day to enjoy the rain!\n", humidity);
    }
    else{
        printf("The humidity is %.2f%%, which is perfect for people who love dry weather!\n", humidity);
    }

    if (pressure < 1000){
        printf("The pressure is quite low today, which means there might be some thunderstorms or heavy rain today, but don't forget to enjoy the rainbows!\n");
    }
    else if (pressure > 1200){
        printf("The pressure is quite high today, it means the sky is clear and people can enjoy the beautiful sunshine!\n");
    }
    else{
        printf("The pressure is normal today, which means it will be a wonderful day to go out and have some fun!\n");
    }

    printf("\nWe hope you enjoyed our Happy Weather Simulation Program today! Have a great day!\n");

    return 0;
}