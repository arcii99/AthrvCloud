//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

int main(){
    int strength;
    printf("Enter the strength of Wi-Fi signal between 0 and 100: ");
    scanf("%d", &strength);
    printf("\n");

    if(strength < 0 || strength > 100){
        printf("Invalid input!");
        return 0;
    }
    else if(strength >= 0 && strength <=20){
        printf("Signal strength is very weak.");
        return 0;
    }
    else if(strength >20 && strength <= 40){
        printf("Signal strength is weak.");
        return 0;
    }
    else if(strength > 40 && strength <= 60){
        printf("Signal strength is moderate.");
        return 0;
    }
    else if(strength > 60 && strength <= 80){
        printf("Signal strength is strong.");
        return 0;
    }
    else if(strength > 80 && strength <= 100){
        printf("Signal strength is very strong.");
        return 0;
    }
}