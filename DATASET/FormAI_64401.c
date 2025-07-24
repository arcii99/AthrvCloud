//FormAI DATASET v1.0 Category: Product Inventory System ; Style: intelligent
#include<stdio.h>
#include<string.h>

struct product{
    int id;
    char name[50];
    float price;
    int quantity;
}p[100];

int n=0;

void add_product(){
    printf("\n\nEnter product details: ");
    printf("\nID: ");
    scanf("%d",&p[n].id);
    printf("Name: ");
    scanf("%s",p[n].name);
    printf("Price: ");
    scanf("%f",&p[n].price);
    printf("Quantity: ");
    scanf("%d",&p[n].quantity);
    n++;
}

void display_all(){
    printf("\n\nDisplaying all products:\n");
    printf("ID\tName\tPrice\tQuantity\n");
    for(int i=0;i<n;i++){
        printf("%d\t%s\t%.2f\t%d\n",p[i].id,p[i].name,p[i].price,p[i].quantity);
    }
}

void search_product(){
    int id;
    printf("\n\nEnter product ID to search: ");
    scanf("%d",&id);
    for(int i=0;i<n;i++){
        if(p[i].id==id){
            printf("Product details:\n");
            printf("ID: %d\n",p[i].id);
            printf("Name: %s\n",p[i].name);
            printf("Price: %.2f\n",p[i].price);
            printf("Quantity: %d\n",p[i].quantity);
            return;
        }
    }
    printf("Product not found!\n");
}

void update_product(){
    int id;
    printf("\n\nEnter product ID to update: ");
    scanf("%d",&id);
    for(int i=0;i<n;i++){
        if(p[i].id==id){
            printf("Enter new details: ");
            printf("\nName: ");
            scanf("%s",p[i].name);
            printf("Price: ");
            scanf("%f",&p[i].price);
            printf("Quantity: ");
            scanf("%d",&p[i].quantity);
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

void delete_product(){
    int id;
    printf("\n\nEnter product ID to delete: ");
    scanf("%d",&id);
    for(int i=0;i<n;i++){
        if(p[i].id==id){
            for(int j=i;j<n-1;j++){
                p[j]=p[j+1];
            }
            n--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

int main(){
    int choice;
    do{
        printf("\n\nPRODUCT INVENTORY SYSTEM");
        printf("\n\n1. Add new product");
        printf("\n2. Display all products");
        printf("\n3. Search a product");
        printf("\n4. Update a product");
        printf("\n5. Delete a product");
        printf("\n6. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: add_product();
                    break;
            case 2: display_all();
                    break;
            case 3: search_product();
                    break;
            case 4: update_product();
                    break;
            case 5: delete_product();
                    break;
            case 6: printf("\nThank you for using product inventory system!\n");
                    break;
            default: printf("\nInvalid choice!\n");
                     break;
        }
    }while(choice!=6);
    return 0;
}