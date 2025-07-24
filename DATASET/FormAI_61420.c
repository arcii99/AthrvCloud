//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct product{
    char name[20];
    float price;
    int quantity;
};

int main(){
    int n = 5;
    struct product store[n];
    memset(&store, 0, sizeof(store));
    int ch;
    while(1){
        printf("\n\nWarehouse Management System\n");
        printf("1. Add to inventory\n2. Check inventory\n3. Show Revenue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("Enter Name: ");
                char name[20];
                scanf("%s",name);
                printf("Enter Price: ");
                float price;
                scanf("%f", &price);
                printf("Enter Quantity: ");
                int quantity;
                scanf("%d", &quantity);
                int found = 0, i;
                for(i=0;i<n;i++){
                    if(strcmp(store[i].name, name) == 0){
                        found = 1;
                        store[i].quantity += quantity;
                        break;
                    }
                }
                if(!found){
                    for(i=0;i<n;i++){
                        if(store[i].quantity == 0){
                            strcpy(store[i].name, name);
                            store[i].price = price;
                            store[i].quantity = quantity;
                            break;
                        }
                    }
                }
                printf("%d %s added to inventory successfully!\n",quantity,name);
                break;
            }
            case 2:{
                int i;
                printf("\nProducts in inventory:\n");
                float revenue = 0.0;
                for(i=0;i<n;i++){
                    if(store[i].quantity != 0){
                        printf("%s\t$%.2f\t%d\n", store[i].name, store[i].price, store[i].quantity);
                        revenue += (store[i].price * store[i].quantity);
                    }
                }
                printf("\nTotal Revenue: $%.2f\n", revenue);
                break;
            }
            case 3:{
                int i;
                float revenue = 0.0;
                for(i=0;i<n;i++){
                    if(store[i].quantity != 0){
                        revenue += (store[i].price * store[i].quantity);
                    }
                }
                printf("Total Revenue: $%.2f\n", revenue);
                break;
            }
            case 4:{
                printf("Exiting...\n");
                exit(0);
                break;
            }
            default:{
                printf("Invalid Choice! Please Try Again.\n");
                break;
            }
        }
    }
    return 0;
}