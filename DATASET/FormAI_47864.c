//FormAI DATASET v1.0 Category: Binary Converter ; Style: happy
#include<stdio.h>
#include<string.h>

void toBinary(int num) {
    int binary[32];
    int index=0;
    while(num>0) {
        binary[index++]=num%2;
        num/=2;
    }
    printf("Binary equivalent is: ");
    for(int i=index-1;i>=0;i--)
        printf("%d", binary[i]);
    printf("\n");
}

int main() {
    printf("Welcome to the happy Binary Converter!\n");
    printf("Enter the number that you want to convert to binary: ");
    int num;
    scanf("%d", &num);
    printf("\nConverting to binary...\n");
    toBinary(num);
    printf("\n");
    printf("Yay! We've successfully converted %d to binary! :)\n", num);
    printf("Thank you for using our happy Binary Converter! Have a great day!\n");
    return 0;
}