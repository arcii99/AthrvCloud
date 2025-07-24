//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Alan Touring
#include<stdio.h>

int main(){
    char unit;
    float temp, convertedTemp;
    printf("Temperature Conversion Tool\n");
    printf("Enter the temperature value: ");
    scanf("%f",&temp);
    fflush(stdin);
    printf("Enter the temperature unit (C/F): ");
    scanf("%c",&unit);

    if(unit == 'F' || unit == 'f'){
        convertedTemp = (temp - 32)*(5.0/9.0);
        printf("%.2f%sF is equal to %.2f%sC\n",temp,"\370",convertedTemp,"\370C");
    }
    else if(unit == 'C' || unit == 'c'){
        convertedTemp = (temp*(9.0/5.0)) + 32;
        printf("%.2f%sC is equal to %.2f%sF\n",temp,"\370",convertedTemp,"\370F");
    }
    else{
        printf("Invalid temperature unit! Please enter C/F\n");
    }   
    return 0;
}