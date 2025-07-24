//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CUSTOMERS 100
#define MAX_MEDICINES 100

struct Medicine{
    int medId;
    char medName[50];
    int medPrice;
    int medQty;
};

struct Customer{
    int custId;
    char custName[50];
    int medId[MAX_MEDICINES];
    int medQty[MAX_MEDICINES];
    int totalMedicines;
};

struct MedicalStore{
    int medId[MAX_MEDICINES];
    char medName[50][50];
    int medPrice[MAX_MEDICINES];
    int medQty[MAX_MEDICINES];
    int totalMedicines;
};

struct MedicalStore ms;
struct Customer cust[MAX_CUSTOMERS];
int custCount = 0;

void initStore(){
    ms.medId[ms.totalMedicines] = 1;
    strcpy(ms.medName[ms.totalMedicines], "Aspirin");
    ms.medPrice[ms.totalMedicines] = 25;
    ms.medQty[ms.totalMedicines] = 50;
    ms.totalMedicines++;

    ms.medId[ms.totalMedicines] = 2;
    strcpy(ms.medName[ms.totalMedicines], "Paracetamol");
    ms.medPrice[ms.totalMedicines] = 35;
    ms.medQty[ms.totalMedicines] = 100;
    ms.totalMedicines++;
}

void displayStore(){
    printf("\n-------Medicines Available in Store-------\n");
    printf("Id\tName\t\tPrice\tQty\n");
    for(int i=0; i<ms.totalMedicines; i++){
        printf("%d\t%s\t\t%d\t%d\n", ms.medId[i], ms.medName[i], ms.medPrice[i], ms.medQty[i]);
    }
    printf("-----------------------------------------\n");
}

void addCustomer(){
    printf("Enter Customer Name: ");
    scanf("%s", cust[custCount].custName);
    cust[custCount].custId = custCount + 1;
    int medId, medQty;
    cust[custCount].totalMedicines = 0;
    printf("Enter Medicine Id and Quantity (Enter -1 to stop):\n");
    while(1){
        printf("Medicine Id: ");
        scanf("%d", &medId);
        if(medId == -1){
            break;
        }
        printf("Quantity: ");
        scanf("%d", &medQty);
        int medIndex = -1;
        for(int i=0; i<ms.totalMedicines; i++){
            if(ms.medId[i] == medId){
                medIndex = i;
                break;
            }
        }
        if(medIndex == -1){
            printf("Invalid Medicine Id!\n");
        }
        else if(ms.medQty[medIndex] < medQty){
            printf("Medicine not available in sufficient quantity!\n");
        }
        else{
            cust[custCount].medId[cust[custCount].totalMedicines] = medId;
            cust[custCount].medQty[cust[custCount].totalMedicines] = medQty;
            cust[custCount].totalMedicines++;
            ms.medQty[medIndex] -= medQty;
        }
    }
    custCount++;
    printf("Customer added successfully!\n");
}

void displayCustomers(){
    printf("\n-------Customers-------\n");
    printf("Id\tName\n");
    for(int i=0; i<custCount; i++){
        printf("%d\t%s\n", cust[i].custId, cust[i].custName);
    }
    printf("------------------------\n");
}

void searchCustomer(){
    int custId;
    printf("Enter Customer Id: ");
    scanf("%d", &custId);
    int custIndex = -1;
    for(int i=0; i<custCount; i++){
        if(cust[i].custId == custId){
            custIndex = i;
            break;
        }
    }
    if(custIndex == -1){
        printf("Invalid Customer Id!\n");
    }
    else{
        printf("\n-------Customer Info-------\n");
        printf("Name: %s\n\n", cust[custIndex].custName);
        printf("Medicine Details:\n");
        printf("Id\tName\tPrice\tQty\n");
        int totalBill = 0;
        for(int i=0; i<cust[custIndex].totalMedicines; i++){
            int medIndex = -1;
            for(int j=0; j<ms.totalMedicines; j++){
                if(ms.medId[j] == cust[custIndex].medId[i]){
                    medIndex = j;
                    break;
                }
            }
            printf("%d\t%s\t%d\t%d\n", cust[custIndex].medId[i], ms.medName[medIndex], ms.medPrice[medIndex], cust[custIndex].medQty[i]);
            totalBill += ms.medPrice[medIndex] * cust[custIndex].medQty[i];
        }
        printf("\nTotal Bill: %d\n", totalBill);
        printf("---------------------------\n");
    }
}

int main(){
    initStore();
    int ch;
    printf("\nWelcome to Medical Store Management System!\n");
    while(1){
        printf("\n1. Display Medicines Available in Store\n");
        printf("2. Add Customer\n");
        printf("3. Display Customers\n");
        printf("4. Search Customer Information\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: displayStore(); break;
            case 2: addCustomer(); break;
            case 3: displayCustomers(); break;
            case 4: searchCustomer(); break;
            case 5: printf("Thank you for using Medical Store Management System!\n"); exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}