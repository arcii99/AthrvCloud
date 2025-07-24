//FormAI DATASET v1.0 Category: Funny ; Style: minimalist
#include <stdio.h>

int main(){

    int i, sum = 0;

    for(i = 1; i <= 10; i++){
        sum += i;
    }

    printf("The sum of the numbers from 1 to 10 is %d\n", sum);
    
    if(sum > 50){
        printf("Wow! That's a big sum!\n");
    }
    else if(sum > 30 && sum <= 50){
        printf("Not too shabby!\n");
    }
    else{
        printf("You can do better than that!\n");
    }

    return 0;
}