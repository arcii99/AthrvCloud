//FormAI DATASET v1.0 Category: System boot optimizer ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define MAX 100000000

// Function to find the factors of a number
int factors(int n) {
    int i, count = 0;
    for (i = 1; i <= n; ++i) {
        if (n % i == 0) {
            ++count;
        }
    }
    return count;
}

int main() {
    int i, j, num, temp, fact;
    int arr[MAX], steps[MAX];

    // Initialize the arrays
    for (i = 0; i < MAX; ++i) {
        arr[i] = i + 1;
        steps[i] = 0;
    }

    for (i = 0; i < MAX; ++i) {
        // Find the factors of the current number
        num = arr[i];
        fact = factors(num);

        // Check if the current number is a perfect square
        if (sqrt(num) == (int) sqrt(num)) {
            temp = sqrt(num);
        } else {
            temp = sqrt(num) + 1;
        }

        // Add up the factors of the number
        for (j = 2; j <= temp; ++j) {
            if (num % j == 0) {
                fact += j + (num / j);
            }
        }

        // Check if the sum of the factors is greater than the original number
        if (fact > num) {
            steps[fact - 1] += 1;
        }
    }

    // Print the numbers that have more than 50 steps
    for (i = 0; i < MAX; ++i) {
        if (steps[i] >= 50) {
            printf("%d\n", i + 1);
        }
    }

    return 0;
}