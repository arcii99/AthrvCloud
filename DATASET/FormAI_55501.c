//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine{
    char name[50];
    int id;
    int stock;
    float price;
};

void display(struct medicine med[],int n){

    printf("Available Medicines: \n");
    for(int i=0;i<n;i++){
        printf("\nMedicine %d\n",i+1);
        printf("\nMedicine Name: %s", med[i].name);
        printf("\nMedicine ID: %d", med[i].id);
        printf("\nAvailable Stock: %d", med[i].stock);
        printf("\nPrice per unit: %.2f", med[i].price);
        printf("\n\n");
    }
}

void lowStock(struct medicine med[],int n){

    printf("Low Stock Medicines: \n");
    for(int i=0;i<n;i++){
        if(med[i].stock<10){
            printf("\nMedicine Name: %s", med[i].name);
            printf("\nMedicine ID: %d", med[i].id);
            printf("\nAvailable Stock: %d", med[i].stock);
            printf("\nPrice per unit: %.2f", med[i].price);
            printf("\n\n");
        }
    }
}

void addMedicine(struct medicine med[],int *n){

    printf("Enter Medicine Name: ");
    scanf("%s",med[*n].name);
    printf("Enter Medicine ID: ");
    scanf("%d",&med[*n].id);
    printf("Enter Available Stock: ");
    scanf("%d",&med[*n].stock);
    printf("Enter Price per unit: ");
    scanf("%f",&med[*n].price);

    *n=*n+1;

}

void deleteMedicine(struct medicine med[],int *n,int id){

    int index=-1;
    for(int i=0;i<*n;i++){
        if(med[i].id==id){
            index=i;
            break;
        }
    }

    if(index==-1){
        printf("Medicine with ID %d not found!",id);
        return;
    }

    for(int i=index;i<*n-1;i++){
        med[i]=med[i+1];
    }

    *n=*n-1;

    printf("Medicine with ID %d deleted successfully!\n",id);

}

void updateStock(struct medicine med[],int n,int id){

    int index=-1;
    for(int i=0;i<n;i++){
        if(med[i].id==id){
            index=i;
            break;
        }
    }

    if(index==-1){
        printf("Medicine with ID %d not found!",id);
        return;
    }

    printf("Enter Quantity to Add/Subtract (-ve for subtraction): ");
    int change;
    scanf("%d",&change);

    med[index].stock+=change;

    printf("Stock Updated Successfully!\n");

}

int main(){

    int n=3;
    struct medicine med[10];

    strcpy(med[0].name,"Paracetmol");
    med[0].id=1001;
    med[0].price=12.50;
    med[0].stock=50;

    strcpy(med[1].name,"Aspirin");
    med[1].id=1002;
    med[1].price=15.00;
    med[1].stock=20;

    strcpy(med[2].name,"Ibuprofen");
    med[2].id=1003;
    med[2].price=20.00;
    med[2].stock=30;

    int choice,id;
    do{
            printf("Enter 1 to display Available Medicines\n");
            printf("Enter 2 to display Low Stock Medicines\n");
            printf("Enter 3 to add a New Medicine\n");
            printf("Enter 4 to delete a Medicine\n");
            printf("Enter 5 to update stock of a Medicine\n");
            printf("Enter 6 to Exit\n");

            printf("Enter your choice: ");
            scanf("%d",&choice);

            switch (choice) {
                case 1: display(med,n);
                    break;
                case 2: lowStock(med,n);
                    break;
                case 3: addMedicine(med,&n);
                    break;
                case 4: printf("Enter the ID of medicine to be deleted: ");
                        scanf("%d",&id);
                        deleteMedicine(med,&n,id);
                    break;
                case 5: printf("Enter the ID of medicine to update stock: ");
                        scanf("%d",&id);
                        updateStock(med,n,id);
                    break;
                case 6: printf("Exiting.");
                    break;
                default: printf("Invalid Choice! Try Again.");
            }

            printf("\n----------------------------------\n");


        }while(choice!=6);

    return 0;
}