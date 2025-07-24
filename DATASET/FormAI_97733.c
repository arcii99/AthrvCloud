//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int randomNumber()
{
    return rand()%256; // generates a random number between 0 - 255
}

void randomHexadecimal()
{
    int i;
    char hexa[17] = "0123456789abcdef"; // possible hexadecimal characters
    printf("Your random hexadecimal value is: ");
    for(i = 0; i < 2; i++)
    {
        printf("%c", hexa[randomNumber()>>4]); // print the first 4 bits
        printf("%c", hexa[randomNumber()]); // print the last 4 bits
    }
    printf("\n");
}

void convertToHexadecimal(int num)
{
    char hexa[17] = "0123456789abcdef"; // possible hexadecimal characters
    char result[3];
    result[0] = hexa[num>>4]; // get the first 4 bits
    result[1] = hexa[num&0x0f]; // get the last 4 bits
    result[2] = '\0';
    printf("%s", result);
}

int main()
{
    int num;
    printf("Enter an integer value: ");
    scanf("%d", &num);
    printf("The hexadecimal value of your integer is: ");
    convertToHexadecimal(num);
    printf("\n");
    printf("Let's generate a random hexadecimal value too! \n");
    srand(time(NULL)); // set the seed for random number generator
    randomHexadecimal();
    return 0;
}