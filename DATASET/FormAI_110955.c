//FormAI DATASET v1.0 Category: Pattern printing ; Style: protected
#include <stdio.h> 
  
void printpattern(int n){ 
    int i, j, k=0; 
    for (i=0;i<n;i++){ 
        for (j=0;j<=k;j++) 
            printf("* "); 
        k++; 
        printf("\n"); 
    } 
} 
  
int main(){ 
    int n = 5; 
    printpattern(n); 
    return 0; 
}