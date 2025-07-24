//FormAI DATASET v1.0 Category: Product Inventory System ; Style: irregular
#include <stdio.h>
#include <string.h>

/*Define a structure to represent a product*/
typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

/*Function to display the menu options*/
void display_menu() {
    printf("\n1. Add product\n");
    printf("2. Remove product\n");
    printf("3. Update product price\n");
    printf("4. Update product quantity\n");
    printf("5. Display product inventory\n");
    printf("6. Exit\n");
    printf("Please enter your choice: ");
}

int main() {
    static int id = 1;  /*Variable to keep track of product id*/
    int choice;
    char confirm;
    Product inventory[10];  /*Array to store the products*/

    do {
        /*Display the menu*/
        display_menu();

        /*Get user choice*/
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                /*Add a new product*/
                if (id > 10) {
                    printf("\nError: Maximum number of products reached!");
                    break;
                }
                printf("\nEnter product name: ");
                scanf("%s", inventory[id - 1].name);
                printf("Enter product price: ");
                scanf("%f", &inventory[id - 1].price);
                printf("Enter product quantity: ");
                scanf("%d", &inventory[id - 1].quantity);
                inventory[id - 1].id = id;
                printf("\nProduct added successfully!\n");
                id++;
                break;

            case 2:
                /*Remove a product*/
                int remove_id;
                printf("\nEnter the id of the product you want to remove: ");
                scanf("%d", &remove_id);
                printf("Are you sure you want to remove product %d? (y/n)\n", remove_id);
                scanf(" %c", &confirm);
                if (confirm == 'y' || confirm == 'Y') {
                    /*Shift the elements of the array*/
                    for (int i = remove_id - 1; i < id - 1; i++) {
                        strcpy(inventory[i].name, inventory[i + 1].name);
                        inventory[i].price = inventory[i + 1].price;
                        inventory[i].quantity = inventory[i + 1].quantity;
                    }
                    id--;  /*Decrease the id count*/
                    printf("\nProduct removed successfully!\n");
                }
                break;

            case 3:
                /*Update product price*/
                int update_id;
                float new_price;
                printf("\nEnter the id of the product you want to update: ");
                scanf("%d", &update_id);
                printf("Enter the updated price for product %d: ", update_id);
                scanf("%f", &new_price);
                inventory[update_id - 1].price = new_price;
                printf("\nProduct price updated successfully!\n");
                break;

            case 4:
                /*Update product quantity*/
                int update_qty;
                printf("\nEnter the id of the product you want to update: ");
                scanf("%d", &update_id);
                printf("Enter the updated quantity for product %d: ", update_id);
                scanf("%d", &update_qty);
                inventory[update_id - 1].quantity = update_qty;
                printf("\nProduct quantity updated successfully!\n");
                break;

            case 5:
                /*Display product inventory*/
                printf("\nProduct Inventory\n");
                printf("-----------------\n");
                printf("ID\tProduct Name\tPrice\tQuantity\n");
                for (int i = 0; i < id - 1; i++) {
                    printf("%d\t%s\t$%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
                }
                break;

            case 6:
                /*Exit the program*/
                printf("\nThank you for using this program!\n");
                break;

            default:
                /*Invalid input*/
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}