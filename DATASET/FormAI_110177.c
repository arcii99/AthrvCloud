//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    srand(time(NULL)); //Initializing the random seed

    int option;
    printf("Welcome! I am the automated Fortune Teller. \n");
    printf("Choose an option to know your fortune for today:\n");
    printf("1. Career\n2. Love\n3. Health\n4. Family\n5. Money\n");
    scanf("%d", &option);

    switch(option){

        case 1:
            printf("Your hard work and sincerity will pay off soon. Keep going!\n");
            break;

        case 2:
            printf("Love is in the air. You have already met the one who completes you. Trust your intuition and take the leap of faith!\n");
            break;

        case 3:
            printf("Your health is your wealth. Make sure to take care of yourself, eat healthy and exercise. A healthy mind and body will lead to a prosperous life.\n");
            break;

        case 4:
            printf("Your family is your support system. Cherish and value their presence in your life. Spend quality time with them and create memorable moments together.\n");
            break;

        case 5:
            printf("A good financial opportunity is on its way. Stay focused and keep your eyes and ears open for new opportunities. Your hard work will soon lead to financial stability and success.\n");
            break;

        default:
            printf("Oops! Looks like you entered an invalid option. Please choose an option between 1-5.\n");
    }

    return 0;
}