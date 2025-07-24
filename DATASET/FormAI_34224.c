//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: genious
#include<stdio.h>

int main(){

 int n=8; //number of coins
 int coins[]={1,5,10,25,50,100,200,500}; //list of coins
 int amount=500; //total amount to make

 int i, j;
 int selected[n];

 for(i = 0; i < n; i++) {
   selected[i] = 0; //initially set all coins as not selected
 }

 i = n - 1;

 while(amount > 0) {
   if(coins[i] <= amount) { //if the current coin can be used for change
     amount -= coins[i]; //subtract the coin value from the remaining amount
     selected[i]++; //increment the selected coin count
   } else {
     i--; //try the next coin
   }
 }

 printf("Coins used to make the amount of %d:\n", amount);
 for(j = 0; j < n; j++){
   if(selected[j] > 0) {
     printf("%d: %d\n", coins[j], selected[j]); //output the number of each coin used
   }
 }

 return 0;
}