//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: standalone
#include<stdio.h>

void towerOfHanoi(int n, char source, char destination, char auxiliary){
    if(n==1){
        printf("Moved disk %d from %c to %c\n",n,source,destination);
        return;
    }
    towerOfHanoi(n-1,source,auxiliary,destination);
    printf("Moved disk %d from %c to %c\n",n,source,destination);
    towerOfHanoi(n-1,auxiliary,destination,source);
}

int main(){
    int numberOfDisks;
    printf("Enter the number of disks: ");
    scanf("%d",&numberOfDisks);
    towerOfHanoi(numberOfDisks,'A','C','B');
    return 0;
}