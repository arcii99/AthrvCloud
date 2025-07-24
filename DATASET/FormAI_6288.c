//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: mathematical
#include<stdio.h>

void towers_of_hanoi(int n, char fromrod, char torod, char auxrod){
    if(n == 1){
        printf("\n Move disk 1 from rod %c to rod %c ", fromrod, torod);
        return;
    }
    towers_of_hanoi(n-1, fromrod, auxrod, torod);
    printf("\n Move disk %d from rod %c to rod %c ", n, fromrod, torod);
    towers_of_hanoi(n-1, auxrod, torod, fromrod);
}

int main(){
    int n;
    printf("Enter the number of discs: ");
    scanf("%d",&n);
    towers_of_hanoi(n, 'A', 'C', 'B');
    printf("\n");
    return 0;
}