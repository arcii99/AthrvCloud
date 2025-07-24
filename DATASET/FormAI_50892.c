//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: shape shifting
#include<stdio.h>

//ShapeShifting elements of the program
#define int float
#define printf(x, ...) printf("Jellyfish says: " x, ##__VA_ARGS__)
#define scanf(x, ...) scanf("Please enter " x, ##__VA_ARGS__)
#define return return 0

int main() {
    float amount, rate, emi;
    int time;

    printf("Welcome to the Jellyfish Mortgage Calculator!\n");
    printf("I will help you calculate your monthly EMI.\n");

    scanf("loan amount: %f", &amount);
    scanf("interest rate: %f", &rate);
    scanf("loan duration (in years): %d", &time);

    rate = rate / 12 / 100;
    time = time * 12;

    emi = (amount * rate * pow(1 + rate, time)) / (pow(1 + rate, time) - 1);

    printf("Your monthly EMI is: %.2f\n", emi);
    printf("Thank you for using the Jellyfish Mortgage Calculator!");

    return;
}