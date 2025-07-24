//FormAI DATASET v1.0 Category: Binary Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char binary[32];
    int decimal, tempDecimal, index = 0;
    printf("Enter a Decimal Number: ");
    scanf("%d", &decimal);
    tempDecimal = decimal;

    while(tempDecimal != 0)  //Converting Decimal to Binary
    {
        binary[index] = tempDecimal % 2 + '0';
        tempDecimal = tempDecimal / 2;
        index++;
    }
    binary[index] = '\0';   //End of Binary
    
    for(int i = index - 1; i >= 0; i--)    //Reversing 
    {
        printf("%c", binary[i]);
    }
    printf("\n");

    return 0;
}