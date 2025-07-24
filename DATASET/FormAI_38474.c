//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Medicine{
    int id;
    char name[30];
    float price;
    int quantity;
}medicines[100];

int numMedicines = 0;

void insertMedicine(){
    printf("Enter Medicine Details:\n");
    printf("Medicine Name: ");
    scanf("%s", medicines[numMedicines].name);
    printf("Medicine Price: ");
    scanf("%f", &medicines[numMedicines].price);
    printf("Medicine Quantity: ");
    scanf("%d", &medicines[numMedicines].quantity);
    medicines[numMedicines].id = numMedicines + 1;
    numMedicines++;
    printf("Medicine Added Successfully!\n");
}

void displayMedicine(){
    if(numMedicines == 0){
        printf("No Medicines Available!\n");
        return;
    }
    printf("Medicine Details:\n");
    printf("ID\tName\tPrice\tQuantity\n");
    for(int i = 0; i < numMedicines; i++){
        printf("%d\t%s\t%.2f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
}

void searchMedicine(){
    char name[30];
    printf("Enter Medicine Name: ");
    scanf("%s", name);
    int found = 0;
    for(int i = 0; i < numMedicines; i++){
        if(strcmp(medicines[i].name, name) == 0){
            found = 1;
            printf("Medicine Details:\n");
            printf("ID\tName\tPrice\tQuantity\n");
            printf("%d\t%s\t%.2f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
            break;
        }
    }
    if(!found){
        printf("Medicine Not Found!\n");
    }
}

void updateMedicine(){
    int id;
    printf("Enter Medicine ID: ");
    scanf("%d", &id);

    int found = 0;
    for(int i = 0; i < numMedicines; i++){
        if(medicines[i].id == id){
            printf("Current Medicine Details:\n");
            printf("ID\tName\tPrice\tQuantity\n");
            printf("%d\t%s\t%.2f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
            printf("\nEnter New Details:\n");
            printf("Medicine Name: ");
            scanf("%s", medicines[i].name);
            printf("Medicine Price: ");
            scanf("%f", &medicines[i].price);
            printf("Medicine Quantity: ");
            scanf("%d", &medicines[i].quantity);
            printf("Medicine Updated Successfully!\n");
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Medicine Not Found!\n");
    }
}

void deleteMedicine(){
    int id;
    printf("Enter Medicine ID: ");
    scanf("%d", &id);

    int found = 0;
    for(int i = 0; i < numMedicines; i++){
        if(medicines[i].id == id){
            found = 1;
            for(int j = i; j < numMedicines - 1; j++){
                medicines[j] = medicines[j + 1];
            }
            numMedicines--;
            printf("Medicine Deleted Successfully!\n");
            break;
        }
    }
    if(!found){
        printf("Medicine Not Found!\n");
    }
}

int main(){
    int choice;
    do{
        printf("1. Insert Medicine\n");
        printf("2. Display All Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: insertMedicine();
                    break;
            case 2: displayMedicine();
                    break;
            case 3: searchMedicine();
                    break;
            case 4: updateMedicine();
                    break;
            case 5: deleteMedicine();
                    break;
            case 6: printf("Exiting Program...\n");
                    break;
            default: printf("Invalid Choice!\n");
                     break;
        }
    }while(choice != 6);
    return 0;
}