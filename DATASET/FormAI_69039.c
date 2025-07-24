//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: sophisticated
#include<stdio.h>
#include<string.h>

struct menu{
    char name[20];
    int price;
}item[10] = {
                {"Coffee", 100},
                {"Tea", 70},
                {"Sandwich", 150},
                {"Burger", 200},
                {"Cold Drink", 80}
             };

int main(){
    int i, choice, quantity, total = 0;
    printf("Welcome to C Cafe Billing System!\n\n");
    printf("Menu:\n");
    for(i = 0; i < 5; i++){
        printf("%d. %s - Rs. %d\n", i+1, item[i].name, item[i].price);
    }
    printf("\n");
    while(1){
        printf("Enter the item number you want to order (1-5): ");
        scanf("%d", &choice);
        if(choice < 1 || choice > 5){
            printf("Invalid choice! Please try again.\n");
            continue;
        }
        printf("Enter the quantity you want to order: ");
        scanf("%d", &quantity);
        total += (quantity * item[choice-1].price);
        printf("%s (Quantity: %d) - Rs. %d added to the bill.\n", item[choice-1].name, quantity, quantity * item[choice-1].price);
        printf("Do you want to order anything else? (Y/N): ");
        char ch[2];
        scanf("%s", ch);
        if(strcmp(ch, "Y") != 0){
            break;
        }
    }
    printf("\nTotal amount to be paid: Rs. %d\n", total);
    printf("Thank you for visiting C Cafe! Have a nice day.\n");
    return 0;
}