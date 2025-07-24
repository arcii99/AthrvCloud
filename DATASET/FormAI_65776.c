//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert(unsigned int input)
{
    char result[32] = "";
    int index = 0;

    // loop through input and convert each digit to hex
    while(input > 0)
    {
        int remainder = input % 16;

        // check if remainder is 10-15 and convert to letter
        if(remainder == 10)
            result[index] = 'A';
        else if(remainder == 11)
            result[index] = 'B';
        else if(remainder == 12)
            result[index] = 'C';
        else if(remainder == 13)
            result[index] = 'D';
        else if(remainder == 14)
            result[index] = 'E';
        else if(remainder == 15)
            result[index] = 'F';
        else
            result[index] = remainder + '0';

        // shift input to remove converted digit
        input /= 16;
        index++;
    }

    // output result in reverse order
    printf("Hexadecimal: ");
    for(int i=index-1; i>=0; i--)
        printf("%c", result[i]);

    printf("\n");
}

int main()
{
    char inputStr[20];
    printf("Enter decimal number: ");
    fgets(inputStr, sizeof(inputStr), stdin);

    // convert input to unsigned int
    unsigned int input = atoi(inputStr);

    // call conversion function
    convert(input);

    return 0;
}