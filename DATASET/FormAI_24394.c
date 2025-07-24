//FormAI DATASET v1.0 Category: Digital Auction System ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

struct item {
    char name[30];
    int id;
    float price;
    int sold;
};

void display(struct item it[], int n) {
    printf("\nItem id\tItem Name\tItem Price\tItem Sold");
    for(int i = 0; i < n; i++) {
        printf("\n%d\t%s\t%.2f\t%d", it[i].id, it[i].name, it[i].price, it[i].sold);
    }
}

void bid(struct item it[], int n, int id) {
    for(int i = 0; i < n; i++) {
        if(it[i].id == id) {
            float price;
            printf("\nEnter your bid for %s (Minimum bid amount: %.2f): ", it[i].name, it[i].price+10);
            scanf("%f", &price);
            if(price >= (it[i].price+10)) {
                it[i].price = price;
                printf("\nCongratulations! You are the highest bidder for %s now.", it[i].name);
            } else {
                printf("\nSorry, your bid is lower than the minimum bid amount of %.2f", it[i].price+10);
            }
        }
    }
}

int main() {
    int n = 3;
    struct item it[n];
    it[0].id = 101;
    it[0].sold = 0;
    strcpy(it[0].name, "Camera");
    it[0].price = 100.00;

    it[1].id = 102;
    it[1].sold = 0;
    strcpy(it[1].name, "Mobile");
    it[1].price = 500.00;

    it[2].id = 103;
    it[2].sold = 0;
    strcpy(it[2].name, "Television");
    it[2].price = 1000.00;

    int ch, id;
    do {
        printf("\n\n1. Display Items\n2. Bid for an Item\n3. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: display(it, n); break;
            case 2: printf("\nEnter the Item id you want to bid for: ");
                    scanf("%d", &id);
                    bid(it, n, id);
                    break;
            case 3: exit(0); break;
            default: printf("\nPlease enter the valid choice.");
        }
    } while(ch != 3);

    return 0;
}