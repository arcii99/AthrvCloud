//FormAI DATASET v1.0 Category: Arithmetic ; Style: surprised
#include<stdio.h>
int main(){
   int x, y, z, sum;
   printf("Enter three numbers: \n");
   scanf("%d %d %d", &x, &y, &z);
   sum=x+y+z; //Calculating sum

   /* Checking if any two or all 
   three numbers are equal */
   if(x==y==z){
       printf("Wow! All three numbers are equal.\n");
       printf("Sum of %d, %d and %d is %d", x, y, z, sum);
   }
   else if(x==y || y==z || x==z){
       printf("Amazing! Two numbers are equal.\n");
       if(x==y){
           printf("%d and %d are equal.\n", x, y);
           printf("Their sum twice is %d.\n", (x+y)*2);
       }
       else if(y==z){
           printf("%d and %d are equal.\n", y, z);
           printf("Their sum twice is %d.\n", (y+z)*2);
       }
       else{
           printf("%d and %d are equal.\n", x, z);
           printf("Their sum twice is %d.\n", (x+z)*2);
       }
   }
   else{
       printf("Oh My God! No numbers are equal.\n");
       printf("Their sum divided by 3 is %.2f.", (float)sum/3);
   }
   return 0;
}