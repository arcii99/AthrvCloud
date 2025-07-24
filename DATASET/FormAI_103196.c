//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: intelligent
#include<stdio.h>
#include<string.h>
#include<ctype.h>

// Structure for storing menu items
struct MenuItem{
    int itemCode;
    char itemName[20];
    int quantity;
    float price;
};

// Function to display menu and get user's choice
int getMenuChoice(){
    int choice;
    printf("Welcome to our Cafe!\n");
    printf("1. Add new item to menu\n");
    printf("2. Update menu item\n");
    printf("3. Delete menu item\n");
    printf("4. Display menu\n");
    printf("5. Generate bill\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    return choice;
}

// Function to get new menu item details from user
void getNewMenuItem(struct MenuItem* item){
    int code;
    char name[20];
    float price;
    printf("Enter new item details:\n");
    printf("Item code: ");
    scanf("%d",&code);
    printf("Item name: ");
    scanf("%s",name);
    printf("Item price: ");
    scanf("%f",&price);
    item->itemCode = code;
    strcpy(item->itemName,name);
    item->quantity = 0;
    item->price = price;
}

// Function to update menu item details
void updateMenuItem(struct MenuItem* item){
    int choice;
    float price;
    printf("Enter new details for item %d:\n",item->itemCode);
    printf("1. Item name\n");
    printf("2. Item price\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter new item name: ");
            scanf("%s",item->itemName);
            break;
        case 2:
            printf("Enter new item price: ");
            scanf("%f",&price);
            item->price = price;
            break;
        default:
            printf("Invalid choice\n");
    }
}

// Function to delete menu item
void deleteMenuItem(struct MenuItem* item){
    item->itemCode = -1;
    strcpy(item->itemName,"");
    item->quantity = 0;
    item->price = 0;
}

// Function to display menu
void displayMenu(struct MenuItem* menu, int size){
    printf("-------Menu-------\n");
    printf("Code\tName\tPrice\n");
    for(int i=0;i<size;++i){
        if(menu[i].itemCode!=-1){
            printf("%d\t%s\t%.2f\n",menu[i].itemCode,menu[i].itemName,menu[i].price);
        }
    }
}

// Function to get order details from user
void getOrder(struct MenuItem* menu, int size, struct MenuItem* order, int* total){
    int code, qty, index=-1;
    char more[5];
    *total = 0;
    do{
        printf("Enter item code and quantity (separated by space): ");
        scanf("%d %d",&code,&qty);
        for(int i=0;i<size;++i){
            if(menu[i].itemCode==code && menu[i].quantity>=qty){
                index = i;
                break;
            }
        }
        if(index!=-1){
            order[code-1].itemCode = code;
            strcpy(order[code-1].itemName,menu[index].itemName);
            order[code-1].quantity += qty;
            order[code-1].price = menu[index].price;
            menu[index].quantity -= qty;
            *total += order[code-1].price * order[code-1].quantity;
            printf("Do you want to add more items? (yes/no): ");
            scanf("%s",more);
        }
        else{
            printf("Invalid input/cannot meet the requested quantity. Try again.\n");
        }
    }while(strcmp(more,"no")!=0);
}

// Function to print bill
void printBill(struct MenuItem* order, int size, int total){
    printf("-------Bill-------\n");
    printf("Code\tName\tQty\tPrice\n");
    for(int i=0;i<size;++i){
        if(order[i].quantity>0){
            printf("%d\t%s\t%d\t%.2f\n",order[i].itemCode,order[i].itemName,order[i].quantity,order[i].price*order[i].quantity);
        }
    }
    printf("Total: %.2f\n",(float)total);
}

int main(){
    int choice,total=0;
    struct MenuItem menu[20];
    struct MenuItem order[20];
    for(int i=0;i<20;++i){
        menu[i].itemCode = -1;
        strcpy(menu[i].itemName,"");
        menu[i].quantity = 0;
        menu[i].price = 0;
        order[i].itemCode = -1;
        strcpy(order[i].itemName,"");
        order[i].quantity = 0;
        order[i].price = 0;
    }
    int menuSize=0;
    do{
        choice = getMenuChoice();
        switch(choice){
            case 1:
                getNewMenuItem(&menu[menuSize]);
                ++menuSize;
                break;
            case 2:
                printf("Enter item code to update: ");
                scanf("%d",&choice);
                for(int i=0;i<menuSize;++i){
                    if(menu[i].itemCode==choice){
                        updateMenuItem(&menu[i]);
                        break;
                    }
                }
                break;
            case 3:
                printf("Enter item code to delete: ");
                scanf("%d",&choice);
                for(int i=0;i<menuSize;++i){
                    if(menu[i].itemCode==choice){
                        deleteMenuItem(&menu[i]);
                        break;
                    }
                }
                break;
            case 4:
                displayMenu(menu,menuSize);
                break;
            case 5:
                getOrder(menu,menuSize,order,&total);
                printBill(order,menuSize,total);
                break;
            case 6:
                printf("Thank you for visiting our Cafe!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }while(choice!=6);
    return 0;
}