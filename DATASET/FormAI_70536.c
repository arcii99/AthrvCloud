//FormAI DATASET v1.0 Category: Binary Converter ; Style: light-weight
#include<stdio.h>

void toBinary(int num);

int main() {
    int num;
    printf("Enter a number to convert to binary: ");
    scanf("%d", &num);
    printf("Binary representation of %d is: ", num);
    toBinary(num);
    return 0;
}

void toBinary(int num){
    if (num != 0) {
        toBinary(num / 2);
        printf("%d", num % 2);
    }
}