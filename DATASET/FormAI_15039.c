//FormAI DATASET v1.0 Category: Benchmarking ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE 1000
#define MAX_ITERATIONS 1000000

struct crypto {
    unsigned char key[16];
    unsigned char iv[16];
};

struct crypto generate_crypto() {
    struct crypto c;
    srand(time(NULL));
    for (int i = 0; i < 16; i++) {
        c.key[i] = rand() % 256;
        c.iv[i] = rand() % 256;
    }
    return c;
}

double benchmark() {
    struct crypto c = generate_crypto();
    double start = clock();

    unsigned char buff[MAX_ARRAY_SIZE];
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        // encryption code here
        for (int j = 0; j < MAX_ARRAY_SIZE; j++) {
            buff[j] = (buff[j] ^ c.key[j % 16]) + c.iv[j % 16];
        }

        // decryption code here
        for (int j = MAX_ARRAY_SIZE - 1; j >= 0; j--) {
            buff[j] = (buff[j] - c.iv[j % 16]) ^ c.key[j % 16];
        }
    }

    double end = clock();
    return (end - start) / CLOCKS_PER_SEC;
}

int main() {
    double time_taken = benchmark();
    printf("Benchmark took %f seconds\n", time_taken);

    return 0;
}