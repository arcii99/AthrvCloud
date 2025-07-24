//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize random seed
    srand(time(NULL));
    
    // Declare variables
    int date, month, year, lucky_num, fortune;
    
    // Prompt user for birth date
    printf("Hello! I am the Automated Fortune Teller. Please enter your birthdate (dd mm yyyy): ");
    scanf("%d %d %d", &date, &month, &year);
    
    // Calculate lucky number
    lucky_num = (date * month) % 10;
    
    // Generate random fortune
    fortune = rand() % 5;
    
    // Output fortune
    switch(fortune)
    {
        case 0:
            printf("Your lucky number is %d. You will have a successful career.\n", lucky_num);
            break;
        case 1:
            printf("Your lucky number is %d. You will meet someone special today.\n", lucky_num);
            break;
        case 2:
            printf("Your lucky number is %d. You will receive unexpected financial gain.\n", lucky_num);
            break;
        case 3:
            printf("Your lucky number is %d. You will face a challenging situation, but it will lead to growth.\n", lucky_num);
            break;
        case 4:
            printf("Your lucky number is %d. You will have a long and healthy life.\n", lucky_num);
            break;
    }
    
    return 0;
}