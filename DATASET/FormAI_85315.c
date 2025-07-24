//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: shape shifting
#include <stdio.h>

// Shape shifting function to generate a unique public key
int shapeShift(int val, int key) {
    int sum = 0;
    while(val > 0) {
        sum += val % 10;
        val /= 10;
    }
    while(key > 0) {
        sum += key % 10;
        key /= 10;
    }
    return sum;
}

// Main function to generate and test the public key algorithm
int main() {
    int publicKey = 0, privateKey = 0, K = 0;
    printf("Enter a value for K: ");
    scanf("%d", &K);
    printf("Enter your private key: ");
    scanf("%d", &privateKey);
    publicKey = shapeShift(K, privateKey);
    printf("Your unique public key is: %d", publicKey);
    return 0;
}