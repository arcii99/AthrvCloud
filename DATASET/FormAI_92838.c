//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine
{
    int id;
    char name[50];
    double price;
    int quantity;
}med[100];

int count = 0;

int main()
{
    int choice = 0;
    int id;
    char name[50];
    double price;
    int quantity;
    int i;
    
    while(choice != 6)
    {
        printf("\n-------------------\n");
        printf("1. Add Medicine\n");
        printf("2. Search Medicine\n");
        printf("3. Edit Medicine Details\n");
        printf("4. Delete Medicine\n");
        printf("5. Display All Medicines\n");
        printf("6. Exit\n");
        printf("-------------------\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("\nEnter ID: ");
                scanf("%d", &id);
                printf("\nEnter Name: ");
                scanf("%s", name);
                printf("\nEnter Price: ");
                scanf("%lf", &price);
                printf("\nEnter Quantity: ");
                scanf("%d", &quantity);
                addMedicine(id, name, price, quantity);
                break;
            
            case 2:
                printf("\nEnter ID: ");
                scanf("%d", &id);
                searchMedicine(id);
                break;
                
            case 3:
                printf("\nEnter ID: ");
                scanf("%d", &id);
                editMedicine(id);
                break;
                
            case 4:
                printf("\nEnter ID: ");
                scanf("%d", &id);
                deleteMedicine(id);
                break;
                
            case 5:
                displayAllMedicines();
                break;
                
            case 6:
                printf("\nExiting...\n");
                break;
            
            default:
                printf("\nInvalid Choice. Please Select Again.\n");
        }
    }
    
    return 0;
}

void addMedicine(int id, char name[], double price, int quantity)
{
    med[count].id = id;
    strcpy(med[count].name, name);
    med[count].price = price;
    med[count].quantity = quantity;
    count++;
    printf("\nMedicine Added Successfully!\n");
}

void searchMedicine(int id)
{
    int i, flag = 0;
    for(i = 0; i < count; i++)
    {
        if(med[i].id == id)
        {
            printf("\nID: %d\n", med[i].id);
            printf("Name: %s\n", med[i].name);
            printf("Price: %.2lf\n", med[i].price);
            printf("Quantity: %d\n", med[i].quantity);
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("\nMedicine Not Found!\n");
    }
}

void editMedicine(int id)
{
    int i, flag = 0;
    for(i = 0; i < count; i++)
    {
        if(med[i].id == id)
        {
            printf("\nID: %d", med[i].id);
            printf("\nName: %s", med[i].name);
            printf("\nPrice: %lf", med[i].price);
            printf("\nQuantity: %d", med[i].quantity);
            printf("\nEnter New Details:\n");
            printf("\nName: ");
            scanf("%s", med[i].name);
            printf("\nPrice: ");
            scanf("%lf", &med[i].price);
            printf("\nQuantity: ");
            scanf("%d", &med[i].quantity);
            flag = 1;
            printf("\nMedicine Details Updated Successfully!\n");
            break;
        }
    }
    if(flag == 0)
    {
        printf("\nMedicine Not Found!\n");
    }
}

void deleteMedicine(int id)
{
    int i, flag = 0;
    for(i = 0; i < count; i++)
    {
        if(med[i].id == id)
        {
            for(int j = i; j < count-1; j++)
            {
                med[j] = med[j+1];
            }
            count--;
            flag = 1;
            printf("\nMedicine Deleted Successfully!\n");
            break;
        }
    }
    if(flag == 0)
    {
        printf("\nMedicine Not Found!\n");
    }
}

void displayAllMedicines()
{
    if(count == 0)
    {
        printf("\nNo Medicines Found!\n");
        return;
    }
    printf("\nID\tName\t\tPrice\t\tQuantity\n");
    for(int i = 0; i < count; i++)
    {
        printf("%d\t%s\t\t%.2lf\t\t%d\n", med[i].id, med[i].name, med[i].price, med[i].quantity);
    }
}