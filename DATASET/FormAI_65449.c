//FormAI DATASET v1.0 Category: Weather simulation ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(0));
    int temperature = rand() % 50;
    printf("Current temperature is %d degrees Celsius.\n", temperature);
    if(temperature < 0){
        printf("It's very cold outside! Don't forget to wear a warm coat.\n");
    }
    else if(temperature < 10){
        printf("It is quite chilly outside. Don't forget to bring a sweater.\n");
    }
    else if(temperature < 20){
        printf("The temperature is comfortable. Enjoy the nice weather!\n");
    }
    else if(temperature < 30){
        printf("It's getting quite hot outside. Don't forget to stay hydrated.\n");
    }
    else{
        printf("It's scorching hot out there! Stay indoors and cool off.\n");
    }
    return 0;
}