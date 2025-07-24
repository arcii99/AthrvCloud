//FormAI DATASET v1.0 Category: Binary Converter ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(int num)
{
    char code[10];
    int i = 0, j;
    while (num > 0) {
        if (num % 2 == 0)
            code[i] = 'a' + rand() % 26;
        else
            code[i] = 'A' + rand() % 26;
        num /= 2;
        i++;
    }
    printf("Encrypted code : ");
    for (j = 0; j < i; j++)
        printf("%c", code[j]);
    printf("\n");
}

void decrypt(char code[])
{
    int num = 0, i;
    for (i = strlen(code) - 1; i >= 0; i--) {
        if (code[i] >= 'a' && code[i] <= 'z')
            num += 0;
        else if (code[i] >= 'A' && code[i] <= 'Z')
            num += 1;
        num *= 2;
    }
    num /= 2;
    printf("Decrypted number : %d\n", num);
}

int main()
{
    int num;
    char code[10];
    printf("Enter a decimal number : ");
    scanf("%d", &num);
    encrypt(num);
    printf("\nEnter an encrypted code : ");
    scanf("%s", code);
    decrypt(code);
    return 0;
}