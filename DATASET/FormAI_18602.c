//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 50

struct medicine{
    char name[50];
    int qty;
    float price;
};

struct store{
    char name[100];
    struct medicine meds[MAX_MEDICINES];
};

int main(){
    int choice, qty, index;
    float price;
    char name[50], store_name[100];
    struct store stores[10];

    // initialization
    for(int i=0;i<10;i++){
        sprintf(stores[i].name, "Store %d", i+1);
        for(int j=0;j<MAX_MEDICINES;j++){
            strcpy(stores[i].meds[j].name, "");
            stores[i].meds[j].qty = 0;
            stores[i].meds[j].price = 0;
        }
    }

    // menu
    do{
        printf("\n\nWelcome to Medical Store Management System\n\n");
        printf("1. Add medicine\n");
        printf("2. Remove medicine\n");
        printf("3. Buy medicine\n");
        printf("4. Check stock\n");
        printf("5. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter store name : ");
                scanf("%s", store_name);
                printf("Enter medicine name : ");
                scanf("%s", name);
                printf("Enter medicine quantity : ");
                scanf("%d", &qty);
                printf("Enter medicine price : ");
                scanf("%f", &price);

                for(int i=0;i<10;i++){
                    if(strcmp(stores[i].name, store_name) == 0){
                        // add medicine to store
                        index = -1;
                        for(int j=0;j<MAX_MEDICINES;j++){
                            if(strcmp(stores[i].meds[j].name, "") == 0){
                                index = j;
                                break;
                            }
                        }
                        if(index == -1){
                            printf("Store is full. Cannot add medicine.\n");
                            break;
                        }
                        strcpy(stores[i].meds[index].name, name);
                        stores[i].meds[index].qty = qty;
                        stores[i].meds[index].price = price;
                        printf("Medicine added successfully.\n");
                        break;
                    }
                }
                break;

            case 2:
                printf("Enter store name : ");
                scanf("%s", store_name);
                printf("Enter medicine name : ");
                scanf("%s", name);

                for(int i=0;i<10;i++){
                    if(strcmp(stores[i].name, store_name) == 0){
                        // remove medicine from store
                        index = -1;
                        for(int j=0;j<MAX_MEDICINES;j++){
                            if(strcmp(stores[i].meds[j].name, name) == 0){
                                index = j;
                                break;
                            }
                        }
                        if(index == -1){
                            printf("Medicine not found.\n");
                            break;
                        }
                        strcpy(stores[i].meds[index].name, "");
                        stores[i].meds[index].qty = 0;
                        stores[i].meds[index].price = 0;
                        printf("Medicine removed successfully.\n");
                        break;
                    }
                }
                break;

            case 3:
                printf("Enter store name : ");
                scanf("%s", store_name);
                printf("Enter medicine name : ");
                scanf("%s", name);
                printf("Enter medicine quantity : ");
                scanf("%d", &qty);

                for(int i=0;i<10;i++){
                    if(strcmp(stores[i].name, store_name) == 0){
                        // buy medicine from store
                        index = -1;
                        for(int j=0;j<MAX_MEDICINES;j++){
                            if(strcmp(stores[i].meds[j].name, name) == 0){
                                index = j;
                                break;
                            }
                        }
                        if(index == -1){
                            printf("Medicine not found.\n");
                            break;
                        }
                        if(stores[i].meds[index].qty < qty){
                            printf("Insufficient stock.\n");
                            break;
                        }
                        stores[i].meds[index].qty -= qty;
                        printf("Medicine bought successfully.\n");
                        break;
                    }
                }
                break;

            case 4:
                printf("Enter store name : ");
                scanf("%s", store_name);
                for(int i=0;i<10;i++){
                    if(strcmp(stores[i].name, store_name) == 0){
                        // print stock of store
                        printf("\n%-20s %-20s %-20s %-20s\n", "Index", "Medicine Name", "Quantity", "Price");
                        for(int j=0;j<MAX_MEDICINES;j++){
                            if(strcmp(stores[i].meds[j].name, "") != 0){
                                printf("%-20d %-20s %-20d %-20.2f\n", j+1, stores[i].meds[j].name, stores[i].meds[j].qty, stores[i].meds[j].price);
                            }
                        }
                        break;
                    }
                }
                break;

            case 5:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }while(choice != 5);

    return 0;
}