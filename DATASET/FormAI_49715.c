//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: scientific
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int choice, quantity, i, j, bill=0;
    char item_name[20][20]={"Black Coffee", "Latte", "Cappuccino", "Espresso", "Americano", "Iced Coffee", "Mocha", "Green Tea", "Black Tea", "Herbal Tea", "Hot Chocolate", "Vanilla Latte", "Caramel Macchiato", "Chai Tea Latte", "White Mocha"};
    int item_price[20]={50, 70, 80, 60, 65, 75, 85, 40, 35, 50, 90, 90, 95, 80, 100};

    printf("---------------------------\n");
    printf("Welcome to Cafe Billing System\n");
    printf("---------------------------\n\n");

    do{
        printf("Choose an item from the menu (1-15): \n");
        for(i=0; i<15; i++){
            printf("%d. %s - Rs. %d\n", i+1, item_name[i], item_price[i]);
        }
        printf("Press 16 to exit\n");

        scanf("%d", &choice);

        if(choice>=1 && choice<=15){
            printf("\nEnter quantity: ");
            scanf("%d", &quantity);

            bill += item_price[choice-1]*quantity;
            printf("%s added to cart. Quantity: %d\n", item_name[choice-1], quantity);
        }
        else if(choice==16){
            printf("\nTotal bill: Rs. %d\n", bill);
            printf("Thank you for visiting the Cafe Billing System. Have a nice day!\n");
            exit(0);
        }
        else{
            printf("\nInvalid choice. Please try again.\n\n");
        }

    }while(1);

    return 0;
}