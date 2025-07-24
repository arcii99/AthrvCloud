//FormAI DATASET v1.0 Category: Unit converter ; Style: puzzling
#include<stdio.h>

int main()
{
    char choice;
    float value;
    printf("Welcome to the puzzling C unit converter program\n");
    printf("Enter the value you want to convert: ");
    scanf("%f",&value);
    printf("Enter the unit of the value: (I) Inches, (M) Meters, (L) Lightyears, (S) Seconds: ");
    scanf(" %c",&choice);

    switch(choice)
    {
        case 'I':
            printf("The value in inches is %f\n",value);
            printf("The value in feet is %f\n",value*12);
            printf("The value in yards is %f\n",value/36);
            printf("The value in miles is %f\n",value/63360);
            break;

        case 'M':
            printf("The value in meters is %f\n",value);
            printf("The value in kilometers is %f\n",value/1000);
            printf("The value in centimeters is %f\n",value*100);
            printf("The value in millimeters is %f\n",value*1000);
            break;

        case 'L':
            printf("The value in lightyears is %f\n",value);
            printf("The value in parsecs is %f\n",value*3.26156);
            printf("The value in astronomical units is %f\n",value*63241.077);
            printf("The value in kilometers is %f\n",(value*9.461*10E12));
            break;

        case 'S':
            printf("The value in seconds is %f\n",value);
            printf("The value in minutes is %f\n",value/60);
            printf("The value in hours is %f\n",value/3600);
            printf("The value in days is %f\n",value/86400);
            break;

        default:
            printf("Invalid choice. Please select I, M, L, or S.\n");
    }

    return 0;
}