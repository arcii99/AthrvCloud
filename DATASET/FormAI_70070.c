//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: cheerful
#include <stdio.h>

void printHeader(int num) {
    int i;
    printf("\n\t\t\t********** FIBONACCI SEQUENCE VISUALIZER **********\n\n");
    for(i=0;i<num;i++) printf("\t\t");
    printf("|| \n");
    for(i=1;i<=num;i++) printf("\t\t");
    printf("1 ");
}

void printFibonacciSequence(int n, int i, int j, int num) {
    if(n > num) return;

    printf("%d ", n);
    printFibonacciSequence(i+j, j, i+j, num);

    if(n == i+j) {
        printf("\n");
        int k;
        for(k=1;k<num;k++) printf("\t\t");
    }
}

int main() {
    int num;
    printf("\n   Enter the number of levels you want in the Fibonacci sequence: ");
    scanf("%d", &num);

    if(num < 1) {
        printf("\n   Invalid input!");
        return 0;
    }

    printf("\n");
    printHeader(num);
    printFibonacciSequence(1, 0, 1, num);

    return 0;
}