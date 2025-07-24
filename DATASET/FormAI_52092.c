//FormAI DATASET v1.0 Category: Data mining ; Style: modular
#include<stdio.h>
#include<stdlib.h>

// function prototypes
void read_input(int*, int*);
void data_mine(int*, int*, int*);
void display_results(int, int);

int main() {
    int x, y, result;  // variables to hold input and result

    read_input(&x, &y);  // read input from user

    data_mine(&x, &y, &result);  // perform data mining

    display_results(result, x);  // display results

    return 0;
}

void read_input(int *x, int *y) {
    printf("Enter two integer values: ");
    scanf("%d %d", x, y);
}

void data_mine(int *x, int *y, int *result) {
    int i;
    *result = 0;  // initialize result

    for (i = *x; i <= *y; i++) {
        if (i % 2 == 0) {
            *result += i;  // add even numbers to result
        }
    }
}

void display_results(int result, int x) {
    printf("The sum of all even numbers between %d and %d is %d\n", x, x + 10, result);
}