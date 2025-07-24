//FormAI DATASET v1.0 Category: Math exercise ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate random numbers
int generateNumber(){
    int num;
    num = rand() % 101;
    return num;
}

int main(){
    int a, b, c, d, e, sum, average, product, max, min;

    // Generating 5 random numbers
    srand(time(0));
    a = generateNumber();
    b = generateNumber();
    c = generateNumber();
    d = generateNumber();
    e = generateNumber();

    // Finding the sum, average, product, max and min of the 5 numbers
    sum = a + b + c + d + e;
    average = sum / 5;
    product = a * b * c * d * e;
    max = (a > b)? (a > c? (a > d? (a > e? a : e) : (d > e? d : e)) : (c > d? (c > e? c: e) : (d > e? d : e))) 
                 : (b > c? (b > d? (b > e? b : e) : (d > e? d : e)) : (c > d? (c > e? c : e) : (d > e? d : e)));
    min = (a < b)? (a < c? (a < d? (a < e? a : e) : (d < e? d : e)) : (c < d? (c < e? c: e) : (d < e? d : e))) 
                 : (b < c? (b < d? (b < e? b : e) : (d < e? d : e)) : (c < d? (c < e? c : e) : (d < e? d : e)));

    printf("\nDear user, I am grateful that you chose my mathematics program.\n\n");
    printf("The 5 random numbers generated are: %d, %d, %d, %d, %d\n\n", a, b, c, d, e);
    printf("The sum of the 5 numbers is: %d\n\n", sum);
    printf("The average of the 5 numbers is: %d\n\n", average);
    printf("The product of the 5 numbers is: %d\n\n", product);
    printf("The maximum number is: %d\n\n", max);
    printf("The minimum number is: %d\n\n", min);

    printf("Thank you for using my program. I am always here to help you with your mathematical needs.\n");
    return 0;
}