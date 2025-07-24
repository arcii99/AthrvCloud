//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: retro
#include <stdio.h>  
#include <stdlib.h>  
  
struct Checksum {  
   int data[20];  
   int total;  
};  
  
int main() {  
   struct Checksum C = {{5,7,2,4,9,1,1,0,3,6,8,0,2,1,1,9,4,2,5,7}, 0};  
   int i;  
  
   for (i = 0; i < 20; ++i) {  
      C.total += C.data[i];  
   }  
  
   printf("Data values: ");  
   for (i = 0; i < 20; ++i) {  
      printf("%d ", C.data[i]);  
   }  
   printf("\nTotal: %d", C.total);  
  
   return 0;  
}