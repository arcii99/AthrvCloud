//FormAI DATASET v1.0 Category: Educational ; Style: curious
#include<stdio.h>

int main(){
   printf("Welcome to the Curious C Tutorial!\n");
 
   int num1, num2, sum; //declaring variables
 
   printf("Enter your first number: "); 
   scanf("%d", &num1); //taking input from user
 
   printf("Enter your second number: ");
   scanf("%d", &num2); //taking input from user
 
   sum = num1 + num2; //calculating sum
 
   printf("\n\nThe sum of %d and %d is: %d\n", num1, num2, sum); //printing the result
 
   if(sum % 2 ==0) { //checking if the sum is even or odd
       printf("\n%d is an even number\n", sum);
   } else {
       printf("\n%d is an odd number\n", sum);
   }
 
   int i, n; // declaring variables for loops
 
   printf("\nEnter any number: ");
   scanf("%d", &n); //taking input from user for loop
 
   printf("\nThe multiplication table of %d is:\n", n); //printing results for loop
   for(i=1; i<=10; i++){
       printf("%d x %d = %d\n", n, i, n*i);
   }
 
   int a[5] = {1, 2, 3, 4, 5}; //declaring and initializing an array
 
   printf("\nPrinting the elements of the array:\n"); //printing the array elements
   for(i=0; i<5; i++){
       printf("%d ", a[i]);
   }
 
   printf("\n\nThat's it for this tutorial! Hope you learned something new!\n");
   return 0;
}