//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: genious
#include<stdio.h>
int main()
{
  int num_items, i, item_id[50], qty[50];
  float price[50], total = 0.0, tax, service_charge, grand_total;

  printf("Welcome to Cafe Billing System\n");

  printf("Enter the number of items you want to purchase: ");
  scanf("%d", &num_items);

  printf("\nEnter the details of each item:\n");

  for(i=0; i<num_items; i++)
  {
    printf("\nItem ID: ");
    scanf("%d", &item_id[i]);

    printf("\nQuantity: ");
    scanf("%d", &qty[i]);

    printf("\nPrice: ");
    scanf("%f", &price[i]);

    total += price[i]*qty[i];
  }

  printf("\nTotal amount: %.2f\n", total);

  tax = total*0.1;
  printf("Tax (10 percent): %.2f\n", tax);

  service_charge = total*0.05;
  printf("Service Charge (5 percent): %.2f\n", service_charge);
  
  grand_total = total + tax + service_charge;
  printf("Grand Total: %.2f\n", grand_total);

  printf("\nThanks for shopping with us! Have a good day!\n");

  return 0;
}