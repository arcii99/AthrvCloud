//FormAI DATASET v1.0 Category: Recursive ; Style: funny
#include<stdio.h>

void recursive_joke(int x){
    if(x==0){
        printf("Why was the computer cold?");
        printf("\nBecause it left its Windows open!\n");
    }
    else{
        printf("Why did the chicken cross the road?\n");
        recursive_joke(x-1);
    }
}

int main(){
    int times_told = 5;
    recursive_joke(times_told);
    return 0;
}