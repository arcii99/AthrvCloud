//FormAI DATASET v1.0 Category: Pattern printing ; Style: mathematical
#include <stdio.h>

int main() {
   int n = 15; //number of rows to print
   int i, j, k, l;
   
   for(i=1; i<=n/2; i++) {  //first half of the pattern
       for(j=1; j<=i; j++) {
           printf("%d", j);
       }
       
       for(k=n/2; k>=i; k--) {
           printf("  ");
       }
       
       for(l=i; l>0; l--) {
           printf("%d", l);
       }
       printf("\n");
   }
   
   for(i=n/2+1; i<=n; i++) {  //second half of the pattern
       for(j=1; j<=n-i+1; j++) {
           printf("%d", j);
       }
       
       for(k=n/2; k<i; k++) {
           printf("  ");
       }
       
       for(l=n-i+1; l>0; l--) {
           printf("%d", l);
       }
       printf("\n");
   }
   
   return 0;
}