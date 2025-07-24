//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: calm
#include<stdio.h>
#include<string.h>

struct item {
   char itemName[50];
   int itemQuantity;
   float itemPrice;
};

struct order {
   struct item orderedItem;
   int orderedQuantity;
   float totalPrice;
};

int main() {
   int i,d;
   float total=0,temp;
   char choice='Y', cnf;
   struct order orderList[100];
   int itemCount=0;
   
   struct item menuList[7] = { {"Tea          \t",0,20.0}, {"Coffee       \t",0,30.0}, {"Sandwich     \t",0,50.0}, 
                              {"Burger       \t",0,70.0}, {"Pasta        \t",0,80.0}, {"Pizza        \t",0,100.0}, {"French Fries\t",0,40.0}
                            };

   printf("Welcome to Cafe bill calculator!\n");
   while (choice=='Y') {
      
      printf("Select the item you want to order:\n");
      for (i=0;i<7;i++) {
         printf("%d. %s %0.2f\n",i+1, menuList[i].itemName,menuList[i].itemPrice);
      }
      printf("Enter Item number: ");
      scanf("%d",&d);
      while(d<1||d>7){
         printf("Invalid input!\n");
         for (i=0;i<7;i++) {
            printf("%d. %s %0.2f\n",i+1, menuList[i].itemName,menuList[i].itemPrice);
         }
         printf("Enter Item number: ");
         scanf("%d",&d);
      }
      
      printf("Enter Quantity: ");
      scanf("%d",&menuList[d-1].itemQuantity);
      while(menuList[d-1].itemQuantity<1 || menuList[d-1].itemQuantity>20){
         printf("Invalid input!\n");
         printf("Enter Quantity: ");
         scanf("%d",&menuList[d-1].itemQuantity);   
      }
         
      printf("Add more items? (Y/N): ");
      scanf(" %c",&choice);
   }
   printf("Do you confirm the order? (Y/N): ");
   scanf(" %c",&cnf);
   if(cnf=='Y'){
      printf("\n\n==Order Confirmend==\n");
      printf("\t\tQuantity    Price    \tTotal \n");
      for (i=0;i<7;i++) {
         if(menuList[i].itemQuantity>0){
            temp=menuList[i].itemQuantity*menuList[i].itemPrice;
            printf("%s\t%3d\t%0.2f\t%0.2f\n", menuList[i].itemName, menuList[i].itemQuantity, menuList[i].itemPrice,temp);
            orderList[itemCount].orderedItem=menuList[i];
            orderList[itemCount].orderedQuantity=menuList[i].itemQuantity;
            orderList[itemCount].totalPrice=temp;
            itemCount++;
            total+=temp;
         }
      }
      if(total>0){
         printf("Grand Total: %0.2f",total);
      }
      else{
         printf("No items found in the order!");
      }
   }
   else{
      printf("Order cancelled!");
   }
   return 0;
}