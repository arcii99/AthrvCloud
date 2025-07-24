//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Medicine {
   int id;
   char name[50];
   int quantity;
   float price;
};

struct Medicine med[500];
int count=0;

void addItem(int id, char* name, int quantity, float price) {
    med[count].id = id;
    strcpy(med[count].name, name);
    med[count].quantity = quantity;
    med[count].price = price;
    count++;
}

void display() {
    if(count==0) {
        printf("\n No items are there in the stock\n");
        return;
    }
    printf("\nID\tName\tQuantity\tPrice\n");
    for(int i=0;i<count;i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", med[i].id, med[i].name, med[i].quantity, med[i].price);
    }
}

void deleteItem(int id) {
    for(int i=0;i<count;i++) {
        if(med[i].id==id) {
            for(int j=i;j<count-1;j++) {
                med[j]=med[j+1];
            }
            count--;
            printf("\nItem Deleted Successfully!!\n");
            return;
        }
    }
    printf("\nItem not found!\n");
}

void updateItem(int id) {
    int choice;
    for(int i=0;i<count;i++) {
        if(med[i].id==id) {
            printf("Which one do you want to update?\n");
            printf("\n1. Name");
            printf("\n2. Quantity");
            printf("\n3. Price");
            printf("\nEnter your choice: ");
            scanf("%d",&choice);
            switch(choice) {
                case 1: char name[50];
                        printf("\nEnter the new name: ");
                        scanf("%s",&name);
                        strcpy(med[i].name, name);
                        printf("\nName updated successfully!!\n");
                        break;
                        
                case 2: int quantity;
                        printf("\nEnter the new quantity: ");
                        scanf("%d",&quantity);
                        med[i].quantity = quantity;
                        printf("\nQuantity updated successfully!!\n");
                        break;
                        
                case 3: float price;
                        printf("\nEnter the new price: ");
                        scanf("%f", &price);
                        med[i].price = price;
                        printf("\nPrice updated successfully!!\n");
                        break;
            }
            return;
        }
    }
    printf("\nItem not found!!\n");
}

void searchItem(int id) {
    for(int i=0;i<count;i++) {
        if(med[i].id==id) {
            printf("\nID\tName\tQuantity\tPrice\n");
            printf("%d\t%s\t%d\t\t%.2f\n", med[i].id, med[i].name, med[i].quantity, med[i].price);
            return;
        }
    }
    printf("\nItem not found!!\n");
}

int main() {
    int choice, id, quantity;
    char name[50];
    float price;
    
    while(1) {
        printf("Choose an option:\n");
        printf("\n1. Add an Item");
        printf("\n2. Display all Items");
        printf("\n3. Delete an Item");
        printf("\n4. Update an Item");
        printf("\n5. Search an Item");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice) {
            case 1: printf("\nEnter the ID of the medicine: ");
                    scanf("%d", &id);
                    printf("\nEnter the name of the medicine: ");
                    scanf("%s", &name);
                    printf("\nEnter the quantity of the medicine: ");
                    scanf("%d", &quantity);
                    printf("\nEnter the price of the medicine: ");
                    scanf("%f", &price);
                    addItem(id, name, quantity, price);
                    printf("\nItem added successfully!!\n");
                    break;
            
            case 2: display();
                    break;
                    
            case 3: printf("\nEnter the ID of the medicine to be deleted: ");
                    scanf("%d", &id);
                    deleteItem(id);
                    break;
                    
            case 4: printf("\nEnter the ID of the medicine to be updated: ");
                    scanf("%d", &id);
                    updateItem(id);
                    break;
                    
            case 5: printf("\nEnter the ID of the medicine to be searched: ");
                    scanf("%d", &id);
                    searchItem(id);
                    break;
                    
            case 6: printf("\nExiting from the program!!\n");
                    exit(0);
                    break;
                    
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}