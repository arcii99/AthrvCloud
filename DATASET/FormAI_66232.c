//FormAI DATASET v1.0 Category: Stock market tracker ; Style: multivariable
#include<stdio.h>

struct stock {
     char company_name[50];
     float current_price;
     float previous_price;
 } s[5];
 
 int main() {
     int i;
     
     //Enter data
     for(i=0; i<5; i++) {
         printf("\nEnter company name: ");
         scanf("%s", s[i].company_name);
         printf("Enter current price: ");
         scanf("%f", &s[i].current_price);
         printf("Enter previous price: ");
         scanf("%f", &s[i].previous_price);
     }
     
     //Display data
     printf("\n\nCOMPANY NAME\t\tCURRENT PRICE\t\tPREVIOUS PRICE\n");
     for(i=0; i<5; i++) {
         printf("%s\t\t\t%.2f\t\t\t%.2f\n", s[i].company_name, s[i].current_price, s[i].previous_price);
     }
     
     //Calculate and display price change
     float price_change;
     printf("\n\nCOMPANY NAME\t\tPRICE CHANGE\n");
     for(i=0; i<5; i++) {
         price_change = ((s[i].current_price - s[i].previous_price)/s[i].previous_price)*100.0;
         printf("%s\t\t\t%.2f%%\n", s[i].company_name, price_change);
     }
     
     return 0;
 }