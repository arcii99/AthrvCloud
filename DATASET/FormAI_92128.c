//FormAI DATASET v1.0 Category: Recursive ; Style: medieval
#include <stdio.h>

int fact(int n){
   if(n == 0) //if n is 0, return 1 as the factor is 1
      return 1;
   else //else recursive calls the function with n-1
      return n * fact(n-1);
}

int main(){
   int num;
   printf("Greetings, my liege! I am a recursive factor calculator in thy service.\n");
   printf("Pray tell me, what number dost thou want the factor of? ");
   scanf("%d", &num);
   printf("Thee shalt have thy factor anon, my liege!\n");
   printf("%d! = %d", num, fact(num));
   return 0;
}