//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: sophisticated
/*
* Program to solve Tower of Hanoi problem using recursion in C
*/

#include<stdio.h>

void Towers(int n, char frompeg, char topeg, char auxpeg){

    if(n==1){
        printf("\n%c -> %c", frompeg, topeg);
        return;
    }

    Towers(n-1, frompeg, auxpeg, topeg);
    printf("\n%c -> %c", frompeg, topeg);
    Towers(n-1, auxpeg, topeg, frompeg);

}

int main(){

    int num;

    printf("Enter the number of disks: ");
    scanf("%d", &num);

    printf("The sequence of moves involved in the Tower of Hanoi are: \n");
    Towers(num, 'A', 'C', 'B');

    return 0;
}