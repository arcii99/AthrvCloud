//FormAI DATASET v1.0 Category: Temperature monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int temp = rand() % 101; // generate random temperature between 0 and 100
    printf("Current temperature: %d°C\n", temp);

    if(temp <= 0){
        printf("I am surprised it's freezing cold outside, make sure to wear warm clothes!\n");
    } else if(temp > 0 && temp <= 10){
        printf("I am surprised it's very cold outside, make sure to wear thick clothes!\n");
    } else if(temp > 10 && temp <= 20){
        printf("I am surprised it's chilly outside, make sure to wear a jacket!\n");
    } else if(temp > 20 && temp <= 30){
        printf("I am surprised it's warm outside, enjoy the weather!\n");
    } else if(temp > 30 && temp <= 40){
        printf("I am surprised it's hot outside, stay hydrated!\n");
    } else {
        printf("I am surprised it's scorching hot outside, avoid going out in the sun!\n");
    }

    return 0;
}