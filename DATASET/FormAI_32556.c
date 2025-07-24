//FormAI DATASET v1.0 Category: Weather simulation ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(0));
    int weather = rand() % 3; // 0 = sunny, 1 = cloudy, 2 = rainy
    
    printf("Romeo: Oh Juliet, the sun shines brightly today,\n");
    if(weather == 0)
        printf("Juliet: Indeed, the birds sing and the flowers bloom in delight!\n");
    else if(weather == 1)
        printf("Juliet: Although the clouds hover above, it does not dim our love.\n");
    else
        printf("Juliet: It may rain, but our hearts are warm with passion.\n");

    printf("Romeo: But wait, what if the storm clouds gather and the winds howl?\n");
    int stormChance = rand() % 100; 
    if(stormChance >= 60){
        printf("Juliet: Fear not, my love, I shall be your shelter from the storm.\n");
        printf("Romeo: I could never doubt your love, dear Juliet.\n");
    } else {
        printf("Juliet: Then we shall dance in the rain and laugh in the face of adversity!\n");
        printf("Romeo: Truly, you are a force to be reckoned with, my sweet Juliet.\n");
    }
    return 0;
}