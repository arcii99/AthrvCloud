//FormAI DATASET v1.0 Category: Temperature monitor ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>

int main(){
    float temperature;
    int options;
    do
    {
    printf("\n\nWelcome to our Temperature Monitoring System\n");
    printf("1.Enter temperature\n");
    printf("2.View last entered temperature\n");
    printf("3.Exit\n\n");
    printf("Enter your option: ");

    scanf("%d",&options);

    switch(options){

        case 1:
            printf("\nPlease enter the current temperature: ");
            scanf("%f",&temperature);
            printf("\nTemperature entered: %f",temperature);
            break;

         case 2:
            printf("\nLast entered temperature is: %f",temperature);
            break;

        case 3:
            printf("\nExiting the program...\n");
            exit(0);
            break;

        default:
            printf("\nInvalid option. Please try again.\n");
     }
    }while(1); // loop infinitely
    return 0;
}