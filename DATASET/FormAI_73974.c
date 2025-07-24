//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: grateful
#include <stdio.h>

int main() {
    int num, temp, i = 0;
    char hex[50];

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    temp = num;

    while(temp != 0) {
        int remainder = temp % 16;
        if(remainder < 10) {
            hex[i] = (char)(48 + remainder);
        } else {
            hex[i] = (char)(55 + remainder);
        }
        temp = temp / 16;
        i++;
    }

    printf("The hexadecimal conversion of %d is: ", num);

    for(int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }

    return 0;
}