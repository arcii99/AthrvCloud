//FormAI DATASET v1.0 Category: Unit converter ; Style: decentralized
#include<stdio.h>

int main(){
    int choice;
    float value;
    printf("Enter the value to be converted: ");
    scanf("%f",&value);
    printf("\n1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Kilometers to Miles\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("%.2f Celsius = %.2f Fahrenheit",value,(value*1.8)+32);
            break;
        case 2:
            printf("%.2f Fahrenheit = %.2f Celsius",value,(value-32)/1.8);
            break;
        case 3:
            printf("%.2f Miles = %.2f Kilometers",value,value*1.60934);
            break;
        case 4:
            printf("%.2f Kilometers = %.2f Miles",value,value*0.621371);
            break;
        default:
            printf("Invalid choice!");
    }
    return 0;
}