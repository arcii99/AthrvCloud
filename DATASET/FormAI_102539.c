//FormAI DATASET v1.0 Category: Sorting ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random array of integers
void generate_random_ints(int* a, int n) {
    srand(time(NULL));  // Seed for random number generator
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;  // Random integer between 0 and 99
    }
}

// Function to print an array of integers
void print_array(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to implement bubble sort
void bubble_sort(int* a, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) {
                swap(&a[j], &a[j+1]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    printf("Wow, it's a beautiful day for sorting some numbers!\n");

    int n = 10;
    int a[n];
    generate_random_ints(a, n);
    printf("Let's start with this random array of integers:\n");
    print_array(a, n);

    printf("\nNow, let's sort the array using bubble sort:\n");
    bubble_sort(a, n);
    print_array(a, n);

    printf("\nYay, we did it! I hope you enjoyed sorting with me!\n");
    return 0;
}