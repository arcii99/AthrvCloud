//FormAI DATASET v1.0 Category: Recursive ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Recursive function for counting up to a given number, with a funny twist!
void countUp(int n){
    if(n==1){
        printf("1... Happy New Year!!!\n");
        return;
    }
    else{
        countUp(n-1);
        printf("%d... ", n);
    }
}

// Recursive function for counting down from a given number, with another funny twist!
void countDown(int n){
    if(n==0){
        printf("Blast Off!!!\n");
        return;
    } 
    else{
        printf("%d... ", n);
        countDown(n-1);
    }
}

int main(){
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if(num<1){
        printf("That's not a positive integer!\n");
        return 0;
    }

    printf("\nCounting up to %d...\n", num);
    countUp(num);

    printf("\nCounting down from %d...\n", num);
    countDown(num);

    return 0;
}