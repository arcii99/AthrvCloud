//FormAI DATASET v1.0 Category: Banking Record System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

struct BankRecord {
    char name[50];
    int age;
    float balance;
};

int main() {
    int n;
    printf("Enter the number of customers: ");
    scanf("%d", &n);
    
    struct BankRecord *bank = (struct BankRecord*)malloc(n*sizeof(struct BankRecord));
    
    for(int i=0; i<n; i++) {
        printf("\n-------Customer %d-------\n", i+1);
        printf("Enter name: ");
        scanf("%s", bank[i].name);
        printf("Enter age: ");
        scanf("%d", &bank[i].age);
        printf("Enter balance: ");
        scanf("%f", &bank[i].balance);
    }
    
    printf("\n-------Bank Records-------\n");
    for(int i=0; i<n; i++) {
        printf("Name: %s\n", bank[i].name);
        printf("Age: %d\n", bank[i].age);
        printf("Balance: $%.2f\n\n", bank[i].balance);
    }
    
    free(bank);
    
    return 0;
}