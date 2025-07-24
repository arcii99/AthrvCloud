//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: medieval
#include<stdio.h>

int main(){
    int i, n, t1 = 0, t2 = 1, next_term;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("\nFibonacci Sequence:\n");

    //1st term printed in a medieval style
    printf("0, thou first term doth be\n");

    //2nd term printed in a medieval style
    printf("1, thou second term doth be\n");
    
    //Displaying the remaining terms of the sequence
    for(i=3;i<=n;i++){
        next_term = t1 + t2;
        printf("%d, thou %d term doth be\n", next_term, i);
        t1 = t2;
        t2 = next_term;
    }
    return 0;
}