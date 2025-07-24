//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct {
    int delivery_id;
    char recipient[50];
    Item items[10];
    int item_count;
} Delivery;

Delivery create_delivery(char recipient[50], Item items[10], int item_count) {
    Delivery delivery;
    delivery.delivery_id = rand() % 1000;
    strcpy(delivery.recipient, recipient);
    for(int i=0; i<item_count; i++) {
        delivery.items[i] = items[i];
    }
    delivery.item_count = item_count;
    return delivery;
}

int main() {
    srand(time(NULL));

    Item items[10];
    items[0] = (Item){1, "Broken clock", 5, 2.99};
    items[1] = (Item){2, "Empty bottle", 10, 0.99};
    items[2] = (Item){3, "Random key", 8, 3.5};
    items[3] = (Item){4, "Left sock", 12, 1.99};
    items[4] = (Item){5, "Plastic fork", 20, 0.2};
    items[5] = (Item){6, "Paper clip", 30, 0.5};
    items[6] = (Item){7, "Bent spoon", 5, 0.99};
    items[7] = (Item){8, "Used pen", 3, 1.5};
    items[8] = (Item){9, "Slightly cracked plate", 6, 2.99};
    items[9] = (Item){10, "Torn shirt", 2, 4.99};

    Delivery deliveries[10];
    deliveries[0] = create_delivery("John", &items[0], 2);
    deliveries[1] = create_delivery("Jane", &items[4], 3);
    deliveries[2] = create_delivery("Bob", &items[7], 1);
    deliveries[3] = create_delivery("Lisa", &items[2], 4);
    deliveries[4] = create_delivery("Peter", &items[5], 2);

    printf("Welcome to the Surrealist Warehouse Management System!\n");

    int input;
    do {
        printf("\nWhat do you want to do?\n");
        printf("1. View existing deliveries\n");
        printf("2. Add a new delivery\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &input);

        switch(input) {
            case 1:
                printf("\nExisting Deliveries:\n\n");
                for(int i=0; i<5; i++) {
                    Delivery delivery = deliveries[i];
                    printf("Delivery ID: %d\n", delivery.delivery_id);
                    printf("Recipient: %s\n", delivery.recipient);
                    printf("Items: \n");
                    for(int j=0; j<delivery.item_count; j++) {
                        printf("  - %s (Quantity: %d, Price: $%.2f)\n", delivery.items[j].name, delivery.items[j].quantity, delivery.items[j].price);
                    }
                }
                break;
            case 2:
                printf("\nAdding new delivery...\n\n");
                char recipient[50];
                printf("Enter recipient name: ");
                scanf("%s", recipient);

                Item delivery_items[10];
                int item_count;
                printf("\nAdding items to delivery...\n\n");
                do {
                    printf("Enter item ID (0 to exit): ");
                    int item_id;
                    scanf("%d", &item_id);
                    if(item_id == 0) {
                        break;
                    }
                    else {
                        printf("Enter item quantity: ");
                        int item_quantity;
                        scanf("%d", &item_quantity);
                        for(int i=0; i<10; i++) {
                            if(items[i].id == item_id) {
                                Item item = items[i];
                                item.quantity = item_quantity;
                                delivery_items[item_count] = item;
                                item_count++;
                                printf("Added item '%s' to delivery\n", item.name);
                                break;
                            }
                            else if(i == 9) {
                                printf("Item not found\n");
                                break;
                            }
                        }
                    }
                } while (item_count < 10);

                Delivery new_delivery = create_delivery(recipient, delivery_items, item_count);
                deliveries[5] = new_delivery;
                printf("New delivery successfully added!\n");
                break;
            case 3:
                printf("\nThank you for using our Surrealist Warehouse Management System!\n");
                break;
            default:
                printf("\nInvalid input\n");
                break;
        }
    } while (input != 3);

    return 0;
}