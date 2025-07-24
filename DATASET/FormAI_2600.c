//FormAI DATASET v1.0 Category: File handling ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize file pointer
    FILE *fp;

    // Declare an array to store data
    char data[1000];

    // Open the file in write mode
    fp = fopen("secrets.txt", "w");

    // Generate random data
    srand(time(0));
    for (int i = 0; i < 1000; i++) {
        data[i] = rand() % 256;
    }

    // Write encrypted data to the file
    for (int i = 0; i < 1000; i++) {
        fputc((data[i] + 13) % 256, fp);
    }

    // Close the file
    fclose(fp);

    // Open the file again in read mode
    fp = fopen("secrets.txt", "r");

    // Read data from file and decrypt it
    for (int i = 0; i < 1000; i++) {
        data[i] = (fgetc(fp) - 13) % 256;
    }

    // Print decrypted data to console
    printf("Secrets:\n%s\n", data);

    // Close the file again
    fclose(fp);

    return 0;
}