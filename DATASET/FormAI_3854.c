//FormAI DATASET v1.0 Category: Binary Converter ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

// Function to convert decimal to binary
void* decimalToBinary(void* arg) 
{
    int decimal = *(int*)arg;
    int binary[32];
    int i = 0;
    for(; decimal > 0; i++) {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
    }
    printf("Binary conversion is: ");
    for(int j = i - 1; j >= 0; j--) 
        printf("%d", binary[j]);
    printf("\n");
    pthread_exit(NULL);
}

// Function to convert binary to decimal
void* binaryToDecimal(void* arg) 
{
    int binary = *(int*)arg;
    int decimal = 0;
    int base = 1;
    int temp = binary;
    while(temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
        decimal += last_digit * base;
        base = base * 2;
    }
    printf("Decimal conversion is: %d\n", decimal);
    pthread_exit(NULL);
}

int main() 
{
    pthread_t tid[2];
    int decimal = 75;
    int binary = 101;
    pthread_create(&tid[0], NULL, decimalToBinary, &decimal);
    pthread_create(&tid[1], NULL, binaryToDecimal, &binary);
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    return 0;
}