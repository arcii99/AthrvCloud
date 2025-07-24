//FormAI DATASET v1.0 Category: Stock market tracker ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stock{
    char company[20];
    float price;
};

int main(){
    int n;
    printf("Enter the number of companies to track: ");
    scanf("%d", &n);

    struct stock s[n];

    for(int i=0; i<n; i++){
        printf("Enter the name of company %d: ", i+1);
        scanf("%s", &s[i].company);
        printf("Enter the current price of %s: ", s[i].company);
        scanf("%f", &s[i].price);
    }

    printf("\n\nSTOCK PRICES\n");
    printf("------------\n");

    for(int i=0; i<n; i++){
        printf("%s - $%.2f\n", s[i].company, s[i].price);
    }

    return 0;
}