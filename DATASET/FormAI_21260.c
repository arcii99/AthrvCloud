//FormAI DATASET v1.0 Category: Math exercise ; Style: protected
// C Math Exercise Example Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int generateRandomNumber(int min, int max);
bool isPrime(int number);
int gcd(int num1, int num2);
float calculateAverage(int array[], int size);
int factorial(int num);
float calculateDiscount(float price, float discountRate);

int main() {
    srand(time(NULL)); // seed the random number generator

    // Generate random number between 1 and 100
    int randomNumber = generateRandomNumber(1, 100);
    printf("Random number: %d\n", randomNumber);

    // Check if number is prime
    if (isPrime(randomNumber)) {
        printf("%d is prime.\n", randomNumber);
    }
    else {
        printf("%d is not prime.\n", randomNumber);
    }

    // Calculate gcd between two numbers
    int num1 = 12;
    int num2 = 18;
    int gcdResult = gcd(num1, num2);
    printf("GCD of %d and %d is %d.\n", num1, num2, gcdResult);

    // Calculate average of an array
    int arr[] = {2, 4, 6, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    float average = calculateAverage(arr, size);
    printf("Average of array is %.2f.\n", average);

    // Calculate factorial of a number
    int num = 5;
    int factorialResult = factorial(num);
    printf("Factorial of %d is %d.\n", num, factorialResult);

    // Calculate discount on a product
    float price = 50.00;
    float discountRate = 0.20;
    float finalPrice = calculateDiscount(price, discountRate);
    printf("Price before discount: $%.2f\n", price);
    printf("Discount rate: %.2f%%\n", discountRate * 100);
    printf("Final price after discount: $%.2f\n", finalPrice);

    return 0;
}

// Generates random number between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Returns true if number is prime, false otherwise
bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i <= number / 2; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

// Calculates gcd of two numbers using Euclid's algorithm
int gcd(int num1, int num2) {
    while (num2 != 0) {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}

// Calculates average of array of integers
float calculateAverage(int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return (float) sum / size;
}

// Calculates factorial of a number using recursion
int factorial(int num) {
    if (num == 0) {
        return 1;
    }
    else {
        return num * factorial(num - 1);
    }
}

// Calculates discounted price of a product given price and discount rate
float calculateDiscount(float price, float discountRate) {
    float discountAmount = price * discountRate;
    float finalPrice = price - discountAmount;
    return finalPrice;
}