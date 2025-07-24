//FormAI DATASET v1.0 Category: Pattern printing ; Style: calm
#include <stdio.h>

int main() {
   int i, j, k, n;
   
   printf("Enter the number of rows: ");
   scanf("%d", &n);
   
   for(i=1;i<=n;i++) {
       for(j=1;j<=n-i;j++) {
           printf(" ");
       }
       for(k=1;k<=2*i-1;k++) {
           if(k%2==0) {
               printf(" ");
           } else {
               printf("*");
           }
       }
       printf("\n");
   }
   
   for(i=n-1;i>=1;i--) {
       for(j=1;j<=n-i;j++) {
           printf(" ");
       }
       for(k=1;k<=2*i-1;k++) {
           if(k%2==0) {
               printf(" ");
           } else {
               printf("*");
           }
       }
       printf("\n");
   }
   
   return 0;
}