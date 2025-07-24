//FormAI DATASET v1.0 Category: Stock market tracker ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

struct stock{
    char name[20];
    float current_price;
    float previous_price;
    float percent_change;
};

typedef struct stock Stock;

int main()
{
    int n,i;
    float total_change=0;
    printf("Enter the number of stocks: ");
    scanf("%d",&n);
    Stock *arr=(Stock*) malloc(n * sizeof(Stock));
    for(i=0;i<n;i++){
        printf("\nEnter the name of stock %d: ",i+1);
        scanf("%s",&arr[i].name);
        printf("\nEnter the current price of stock %d: ",i+1);
        scanf("%f",&arr[i].current_price);
        printf("\nEnter the previous price of stock %d: ",i+1);
        scanf("%f",&arr[i].previous_price);
        arr[i].percent_change=((arr[i].current_price-arr[i].previous_price)/arr[i].previous_price)*100;
        total_change+=arr[i].percent_change;
    }
    printf("\n\n------------------------------- STOCK MARKET REPORT -------------------------------\n\n");
    printf("NAME\tCURRENT PRICE\tPREVIOUS PRICE\tPERCENT CHANGE\n");
    for(i=0;i<n;i++)
        printf("%s\t%f\t%f\t%f%%\n",arr[i].name,arr[i].current_price,arr[i].previous_price,arr[i].percent_change);
    printf("\nTotal Market Change: %.2f%%",total_change);

    return 0;
}