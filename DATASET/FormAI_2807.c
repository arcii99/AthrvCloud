//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: curious
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 10000
#define SEARCH_NUMBER 53

int search_array(int arr[], int size, int search_num) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == search_num) {
            return i;
        }
    }
    return -1;
}

bool is_prime(int num) {
    if (num == 1 || num == 0) {
        return false;
    }
    int i;
    for (i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void generate_array(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
}

void sieve_of_eratosthenes(int arr[], int size) {
    bool primes[size + 1];
    int i, j;
    for (i = 0; i < size + 1; i++) {
        primes[i] = true;
    }

    for (i = 2; i * i <= size; i++) {
        if (primes[i] == true) {
            for (j = i * i; j <= size; j += i) {
                primes[j] = false;
            }
        }
    }

    int k = 0;
    for (i = 2; i <= size; i++) {
        if (primes[i] == true) {
            arr[k] = i;
            k++;
        }
    }
}

int main() {
    int arr[ARRAY_SIZE];
    generate_array(arr, ARRAY_SIZE);

    sieve_of_eratosthenes(arr, ARRAY_SIZE);

    int result = search_array(arr, ARRAY_SIZE, SEARCH_NUMBER);

    if (result == -1) {
        printf("Number %d not found in array.\n", SEARCH_NUMBER);
    } else {
        printf("Number %d found at index %d in array.\n", SEARCH_NUMBER, result);
    }
    return 0;
}