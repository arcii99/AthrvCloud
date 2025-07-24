//FormAI DATASET v1.0 Category: Product Inventory System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[50];
    int id;
    float price;
    int quantity;
};

int main() {
    int option, i, j, count=0;
    struct product products[50];
    
    do {
        printf("\n");
        printf("-------------Menu--------------\n");
        printf("1. Add a product\n");
        printf("2. Display all products\n");
        printf("3. Search a product\n");
        printf("4. Edit a product\n");
        printf("5. Delete a product\n");
        printf("6. Exit\n");
        printf("\n\tEnter an option: ");
        scanf("%d", &option);
        
        switch(option) {
            
            case 1: //Add a product
                printf("Enter the product name: ");
                scanf("%s", &products[count].name);
                printf("Enter the price of the product: ");
                scanf("%f", &products[count].price);
                printf("Enter the quantity of the product: ");
                scanf("%d", &products[count].quantity);
                products[count].id = count+1;
                count++;
                printf("\nProduct added successfully!\n");
                break;
            
            case 2: //Display all products
                if(count == 0) {
                    printf("\nNo products found!\n");
                }
                else {
                    printf("\nAll products:\n");
                    printf("ID\tName\t\tPrice\tQuantity\n");
                    for(i=0; i<count; i++) {
                        printf("%d\t%-10s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
                    }
                }
                break;
            
            case 3: //Search a product
                if(count==0) {
                    printf("\nNo products found!\n");
                }
                else {
                    char search[50];
                    int found=0;
                    printf("\nEnter the product name to search: ");
                    scanf("%s", &search);
                    for(i=0; i<count; i++) {
                        if(strcmp(search, products[i].name) == 0) {
                            printf("\nProduct found!\n");
                            printf("ID\tName\t\tPrice\tQuantity\n");
                            printf("%d\t%-10s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
                            found = 1;
                            break;
                        }
                    }
                    if(found==0) {
                        printf("\nProduct not found!\n");
                    }
                }
                break;
            
            case 4: //Edit a product
                if(count==0) {
                    printf("\nNo products found!\n");
                }
                else {
                    int editId, editOption, editQuantity;
                    printf("\nEnter the product ID to edit: ");
                    scanf("%d", &editId);
                    for(i=0; i<count; i++) {
                        if(editId==products[i].id) {
                            printf("\nWhich attribute do you want to edit?\n");
                            printf("1. Name\n");
                            printf("2. Price\n");
                            printf("3. Quantity\n");
                            printf("\n\tEnter an option: ");
                            scanf("%d", &editOption);
                            switch(editOption) {
                                case 1:
                                    printf("Enter the new name: ");
                                    scanf("%s", &products[i].name);
                                    printf("\nProduct name updated successfully!\n");
                                    break;
                                case 2:
                                    printf("Enter the new price: ");
                                    scanf("%f", &products[i].price);
                                    printf("\nProduct price updated successfully!\n");
                                    break;
                                case 3:
                                    printf("Enter the new quantity: ");
                                    scanf("%d", &editQuantity);
                                    products[i].quantity = editQuantity;
                                    printf("\nProduct quantity updated successfully!\n");
                                    break;
                                default:
                                    printf("\nInvalid option!\n");
                            }
                            break;
                        }
                    }
                    if(i==count) {
                        printf("\nProduct ID not found!\n");
                    }
                }
                break;
            
            case 5: //Delete a product
                if(count==0) {
                    printf("\nNo products found!\n");
                }
                else {
                    int deleteId, deleteIndex;
                    printf("\nEnter the product ID to delete: ");
                    scanf("%d", &deleteId);
                    for(i=0; i<count; i++) {
                        if(deleteId==products[i].id) {
                            printf("\nProduct deleted successfully!\n");
                            deleteIndex = i;
                            for(j=deleteIndex; j<count-1; j++) {
                                products[j] = products[j+1];
                            }
                            count--;
                            break;
                        }
                    }
                    if(i==count) {
                        printf("\nProduct ID not found!\n");
                    }
                }
                break;
            
            case 6: //Exit
                printf("\nExiting the program. Thank you!\n");
                break;
            
            default: //Invalid option
                printf("\nInvalid option!\n");
                break;
        }
        
    } while(option!=6);
    
    return 0;
}