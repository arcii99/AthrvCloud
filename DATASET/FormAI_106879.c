//FormAI DATASET v1.0 Category: Unit converter ; Style: high level of detail
#include<stdio.h>

int main(){
    int choice;
    float temp;

    printf("Please select an option:\n1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    if(choice == 1){
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temp);
        float fahrenheit = ((temp * 9) / 5) + 32;
        printf("%.2f Celsius is equal to %.2f Fahrenheit.", temp, fahrenheit);
    }
    else if(choice == 2){
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temp);
        float celsius = (temp - 32) * 5/9;
        printf("%.2f Fahrenheit is equal to %.2f Celsius.", temp, celsius);
    }
    else{
        printf("Invalid choice!");
    }

    return 0;
}