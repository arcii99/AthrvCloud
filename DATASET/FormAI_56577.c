//FormAI DATASET v1.0 Category: Unit converter ; Style: cheerful
#include <stdio.h>

float convert(float num, char from, char to)
{
    if(from=='C' && to=='F')
    {
        return (num*1.8)+32;
    }
    else if(from=='F' && to=='C')
    {
        return (num-32)/1.8;
    }
    else if(from=='K' && to=='C')
    {
        return num-273.15;
    }
    else if(from=='C' && to=='K')
    {
        return num+273.15;
    }
    else if(from=='F' && to=='K')
    {
        return (num+459.67)/1.8;
    }
    else if(from=='K' && to=='F')
    {
        return (num*1.8)-459.67;
    }
    else
    {
        return num;
    }
}

int main()
{
    float num;
    char from, to;
    printf("Hello! I am a cheerful unit converter bot!\n");
    printf("Please enter a number: ");
    scanf("%f", &num);
    printf("What unit is this number in? (C, F, K) ");
    scanf("%s", &from);
    printf("What unit would you like to convert this number to? (C, F, K) ");
    scanf("%s", &to);
    float result = convert(num, from, to);
    printf("%f%c is equal to %f%c. Thank you for using our converter bot!", num, from, result, to);
    return 0;
}