//FormAI DATASET v1.0 Category: Recursive ; Style: content
#include<stdio.h>

int sum(int num){
   if(num == 0)
      return num;
   else
      return num + sum(num-1);
}

int main(){
   int num = 10;
   int result = sum(num);
   printf("The sum of natural numbers from 1 to %d is %d",num,result);
   return 0;
}