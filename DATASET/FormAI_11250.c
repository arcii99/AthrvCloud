//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int option, stock = 0, purchase = 0;

    printf("Welcome to Dr. Strange's Medical Store, where we have medicines for all your sorrows!\n");

    do
    {
        printf("\nEnter your choice:\n1. View stock\n2. Add purchase\n3. Exit\n>> ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\nWe currently have %d medicines in stock. You better hurry before Doctor's monsters eat them all up!\n", stock);
                break;

            case 2:
                printf("\nHow many medicines do you want to purchase? ");
                scanf("%d", &purchase);
                if(purchase < 1)
                {
                    printf("\nDoctor Strange says 'I'm sorry, but you can't purchase negative or zero medicines. Try again.'\n");
                }
                else if(purchase > 20)
                {
                    printf("\nDoctor Strange says 'I'm sorry, but our store policy doesn't allow purchases of over 20 medicines at a time. Try again.'\n");
                }
                else
                {
                    stock += purchase;
                    printf("\nYou have successfully purchased %d medicines, now we have a total of %d medicines in stock. Doctor Strange thanks you for your business!\n", purchase, stock);
                }
                break;

            case 3:
                printf("\nThank you for shopping at Dr. Strange's Medical Store! Have a magical day! *poof*\n");
                break;

            default:
                printf("\nDoctor Strange says 'I'm sorry, I don't understand what you want. Please try a valid option.'\n");
        }
    }while(option != 3);

    return 0;
}