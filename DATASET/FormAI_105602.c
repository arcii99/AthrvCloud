//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a structure for item in warehouse */
struct warehouseItem
{
    int id;
    char name[30];
    float price;
    int quantityOnHand;
};

/* Define a structure for warehouse and items */
struct warehouse
{
    struct warehouseItem items[50];
    int numItems;
};

/* Function to add item to the warehouse */
void addItem(struct warehouse* wh)
{
    // Get the details of item from user
    int id;
    printf("Enter item id: ");
    scanf("%d", &id);
    
    char name[30];
    printf("Enter item name: ");
    scanf("%s", name);
    
    float price;
    printf("Enter item price: ");
    scanf("%f", &price);
    
    int quantity;
    printf("Enter item quantity: ");
    scanf("%d", &quantity);
    
    // Create a new item with the details
    struct warehouseItem newItem;
    newItem.id = id;
    strcpy(newItem.name, name);
    newItem.price = price;
    newItem.quantityOnHand = quantity;
    
    // Add the new item to the warehouse
    wh->items[wh->numItems++] = newItem;

    printf("Item added successfully!\n");
}

/* Function to delete an item from the warehouse */
void deleteItem(struct warehouse* wh, int id)
{
    // Find the item with the given id
    int index = -1;
    for(int i=0; i<wh->numItems; i++)
    {
        if(wh->items[i].id == id)
        {
            index = i;
            break;
        }
    }
    
    if(index == -1)
    {
        printf("Item with id %d not found!\n", id);
        return;
    }
    
    // Remove the item at the index
    for(int i=index; i<wh->numItems-1; i++)
    {
        wh->items[i] = wh->items[i+1];
    }
    wh->numItems--;

    printf("Item with id %d deleted successfully!\n", id);
}

/* Function to display all items in the warehouse */
void displayItems(struct warehouse wh)
{
    printf("All items in the warehouse:\n");
    printf("Item ID\tItem Name\tPrice\tQuantity\n");
    for(int i=0; i<wh.numItems; i++)
    {
        printf("%d\t%s\t\t%.2f\t%d\n", wh.items[i].id, wh.items[i].name,
               wh.items[i].price, wh.items[i].quantityOnHand);
    }
}

int main()
{
    // Initialize the warehouse with some items
    struct warehouse wh;
    wh.numItems = 2;
    wh.items[0].id = 1;
    strcpy(wh.items[0].name, "Mouse");
    wh.items[0].price = 10.50;
    wh.items[0].quantityOnHand = 100;
    wh.items[1].id = 2;
    strcpy(wh.items[1].name, "Keyboard");
    wh.items[1].price = 20.00;
    wh.items[1].quantityOnHand = 50;
    
    // Display menu to user
    int choice;
    do
    {
        printf("\nWarehouse Management System\n");
        printf("1. Add an item\n");
        printf("2. Delete an item\n");
        printf("3. Display all items\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                addItem(&wh);
                break;
            case 2:
                {
                    int id;
                    printf("Enter item id to be deleted: ");
                    scanf("%d", &id);
                    deleteItem(&wh, id);
                }
                break;
            case 3:
                displayItems(wh);
                break;
            case 4:
                printf("Quitting...\n");
                break;
            default:
                printf("Invalid choice! Choose again.\n");
        }
    } while(choice != 4);
    
    return 0;
}