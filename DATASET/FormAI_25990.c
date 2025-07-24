//FormAI DATASET v1.0 Category: Recursive ; Style: happy
#include<stdio.h>

void happyFunc(int x){
    if(x==0){
        printf("Happiness overload!\n");
    }else{
        printf("Yay, ");
        happyFunc(x-1);
    }
}

int main(){
    printf("Welcome to the happiness generating program!\n");
    printf("How happy are you feeling on a scale of 1 to 10? ");
    int happinessLevel;
    scanf("%d", &happinessLevel);
    if(happinessLevel<1){
        printf("Oops, that's a negative number. Maybe you need some happiness.\n");
        happinessLevel=1;
    }else if(happinessLevel>10){
        printf("Woah, that's off the happiness charts! Let's tone it down a bit.\n");
        happinessLevel=10;
    }
    printf("Generating happiness...\n");
    happyFunc(happinessLevel);
    printf("Happy coding!\n");
    return 0;
}