//FormAI DATASET v1.0 Category: Recursive ; Style: peaceful
#include <stdio.h>

/* This program is a simple Recursive function that will print all the numbers from 1 to 10, 
   giving a peaceful and calm output. */

void peaceful_print(int num){
    if(num<=10){
        printf("%d\n", num);
        num++;
        peaceful_print(num);
    }
    else{
        printf("All done :) \n");
        return;
    }
}

int main(){
    printf("Peaceful printing starts below:\n\n");
    peaceful_print(1);
    return 0;
}