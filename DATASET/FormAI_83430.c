//FormAI DATASET v1.0 Category: Binary Converter ; Style: happy
#include<stdio.h>

int main() {
    printf("Welcome to the Happy Binary Converter Program! Let's convert some numbers to binary!\n");

    int num, binary[100], i = 0;

    printf("Enter the number you want to convert to binary: ");
    scanf("%d", &num);

    while(num > 0) {
        binary[i] = num % 2;
        num = num / 2;
        i++;
    }

    printf("The binary number for your given input is: \n");

    for(int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }

    printf("\nHooray, we have successfully converted the number to binary! Happy Converting!\n");

    return 0;
}