//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: interoperable
#include<stdio.h>

void towerOfHanoi(int n, char src, char dest, char aux) {  
    if(n==1) {  
        printf("\n Move disk 1 from rod %c to rod %c", src, dest);  
        return;  
    }  
    towerOfHanoi(n-1, src, aux, dest);  
    printf("\n Move disk %d from rod %c to rod %c", n, src, dest);  
    towerOfHanoi(n-1, aux, dest, src);    
}  

int main() {  
    int n; 
    printf("Enter the number of disks: ");
    scanf("%d", &n); 
    towerOfHanoi(n, 'A', 'C', 'B');
    printf("\n");  
    return 0;  
}