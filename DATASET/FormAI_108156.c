//FormAI DATASET v1.0 Category: Binary Converter ; Style: Romeo and Juliet
/* Romeo and Juliet's Binary Converter */
#include <stdio.h>

int main()
{
    int num, binaryNum[1000], i = 0;
    printf("Romeo: Oh, fair Juliet, please tell me the decimal number you need converted to binary.\n");
    scanf("%d", &num);
    printf("Juliet: Of course, my dear Romeo. The decimal number is %d.\n", num);

    while(num > 0)
    {
        binaryNum[i] = num % 2;
        num = num / 2;
        i++;
    }

    printf("Romeo: Ah, the binary number is:\n");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
    
    printf("\nJuliet: Such magnificent calculations, my beloved Romeo.\n");
    return 0;
}