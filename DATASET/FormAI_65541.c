//FormAI DATASET v1.0 Category: Binary Converter ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

void* decimal_to_binary(void *arg) {
    int decimal_num = *((int*)arg);
    int binary_array[32];
    int i = 0;
    while(decimal_num > 0) {
        binary_array[i] = decimal_num % 2;
        decimal_num = decimal_num / 2;
        i++;
    }
    printf("Binary Equivalent: ");
    for(int j = i-1; j >= 0; j--) {
        printf("%d", binary_array[j]);
    }
    printf("\n");
    return NULL;
}

void* binary_to_decimal(void *arg) {
    long long binary_num = *((long long*)arg);
    int decimal_num = 0;
    int base = 1;
    while(binary_num > 0) {
        int last_digit = binary_num % 10;
        binary_num = binary_num / 10;
        decimal_num += last_digit * base;
        base *= 2;
    }
    printf("Decimal Equivalent: %d\n", decimal_num);
    return NULL;
}

int main() {
    int decimal_num;
    long long binary_num;
    pthread_t tid1, tid2;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);
    pthread_create(&tid1, NULL, decimal_to_binary, &decimal_num);
    pthread_join(tid1, NULL);
    printf("Enter a binary number: ");
    scanf("%lld", &binary_num);
    pthread_create(&tid2, NULL, binary_to_decimal, &binary_num);
    pthread_join(tid2, NULL);
    return 0;
}