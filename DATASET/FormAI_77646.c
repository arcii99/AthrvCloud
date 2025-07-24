//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: scientific
/*
Title: Greedy Algorithm for Egyptian Fraction
Author: [Your Name]
Date: [Date]

This program takes a rational number as input and outputs its representation in Egyptian Fraction using the Greedy Algorithm. The Greedy Algorithm tries to use the largest possible unit fraction (1/n, where n is a positive integer) at each step until the sum of unit fractions gives the given rational number. 
*/

#include <stdio.h>

int main() {
    int num, den, count = 0;
    printf("Enter the numerator and denominator of the rational number: ");
    scanf("%d %d", &num, &den);

    printf("%d/%d = ", num, den);

    while (num != 0) {
        // calculate the largest unit fraction that can be added to the sum
        int unit_den = (den + num - 1) / num;

        // print the unit fraction
        printf("1/%d", unit_den);

        // add the unit fraction to the sum
        num = num * unit_den - den;
        den = den * unit_den;

        // print a plus sign if there are more unit fractions to follow
        if (num != 0) {
            printf(" + ");
        }

        count++;
    }

    printf("\n");
    printf("The number of unit fractions in the sum is: %d\n", count);
    return 0;
}