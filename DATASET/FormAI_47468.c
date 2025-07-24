//FormAI DATASET v1.0 Category: Weather simulation ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void weather(){
    srand(time(NULL));
    int temperature = rand() % 41;
    int humidity = rand() % 101;

    if(temperature > 30 && humidity > 80){
        printf("It's hot and humid today! You might wanna stay indoors and turn on the AC.\n");
    }
    else if(temperature > 30 && humidity <= 80){
        printf("It's hot and dry today! Make sure to drink a lot of water and avoid the sun.\n");
    }
    else if(temperature <= 30 && humidity > 80){
        printf("It's cool and humid today! You might wanna carry an umbrella and wear light clothes.\n");
    }
    else{
        printf("It's a beautiful day outside! Perfect weather for a walk in the park!\n");
    }
}

int main(){
    weather();
    return 0;
}