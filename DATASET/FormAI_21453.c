//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: satisfied
#include<stdio.h>

void main(){
   int n, w, i, j, capacity;
   float total_profit, profit_per_unit, weight_per_unit;

   printf("Enter the number of items: ");
   scanf("%d", &n);

   int weights[n], profits[n];
   float profit_density[n], temp;

   for(i = 0; i < n; i++){
       printf("\n\nItem %d -",i+1);
       printf("\nEnter the weight: ");
       scanf("%d", &weights[i]);
       printf("Enter the profit: ");
       scanf("%d", &profits[i]);

       profit_density[i] = (float)profits[i]/(float)weights[i];
   }

   printf("\nEnter the capacity of the knapsack: ");
   scanf("%d", &capacity);

   //Sorting the items based on their profit density
   for(i=0;i<n;i++){
     for(j=i+1;j<n;j++){
        if(profit_density[i]<profit_density[j]){
            temp = profit_density[j];
            profit_density[j] = profit_density[i];
            profit_density[i] = temp;

            temp = weights[j];
            weights[j] = weights[i];
            weights[i] = temp;

            temp = profits[j];
            profits[j] = profits[i];
            profits[i] = temp;
        }
     }
   }

   i=0; //i will work as index of current element
   w=0; //w will work as index of current wieght
   total_profit=0;

   while (w < capacity && i<n)
   {
       if(weights[i] + w <= capacity){
           w += weights[i];
           total_profit += profits[i];
           i++;
       }
       else{
           int balance = capacity - w;
           profit_per_unit = (float)profits[i] / (float)weights[i];
           weight_per_unit = (float)weights[i] / (float)profits[i];
           total_profit = total_profit + (balance * profit_per_unit);
           w = capacity;
       }
   }

   printf("\n\nTotal profit: Rs.%.2f", total_profit);

   return 0;
}