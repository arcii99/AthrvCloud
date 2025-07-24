//FormAI DATASET v1.0 Category: Recursive ; Style: romantic
#include<stdio.h>

void love(int depth){
    if(depth == 0){
        printf("My love for you is endless...\n");
        return;
    }
    printf("I'll keep loving you until the end of time...\n");
    love(depth-1);
}

int main(){
    printf("Welcome to our little world of love...\n");
    printf("Oh my beautiful angel, with eyes so bright and deep...\n");
    printf("I can't help but feel my heart skip a beat...\n");
    printf("With every breath, I think of you...\n");
    printf("With every thought, I love you more...\n");
    printf("My sweet love, my passion, my desire...\n");
    printf("I'll never let you go, I'll always keep you near...\n");
    printf("Together we share a love so rare...\n");
    printf("Our love will only grow, nothing will ever compare...\n");

    love(10);

    printf("I'll love you forever, my dear...\n");
    printf("Until the end of time, I'll always be here...\n");

    return 0;
}