//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>

struct item{
char name[20];
float price;
int quantity;
};

int main(){
    int n,i;
    float sum=0;
    printf("Welcome to C Cafe Billing System\n");
    printf("Enter the number of items: ");
    scanf("%d",&n);
    struct item items[n];
    printf("Enter item details:\n");
    for(i=0;i<n;i++){
        printf("Item %d name: ",i+1);
        scanf("%s",items[i].name);
        printf("Item %d price: ",i+1);
        scanf("%f",&items[i].price);
        printf("Item %d quantity: ",i+1);
        scanf("%d",&items[i].quantity);
        sum+=items[i].price*items[i].quantity;
    }
    printf("\n\nYour Bill\n");
    printf("-------------------------------------------------\n");
    printf("Name\t\tPrice\t\tQty\t\tTotal\n");
    printf("-------------------------------------------------\n");
    for(i=0;i<n;i++){
        printf("%s\t\t%.2f\t\t%d\t\t%.2f\n",items[i].name,items[i].price,items[i].quantity,items[i].price*items[i].quantity);
    }
    printf("-------------------------------------------------\n");
    printf("\t\t\t\tTotal: %.2f\n",sum);
    printf("-------------------------------------------------\n");
    printf("\nThank you for visiting C Cafe!\n");
    return 0;
}