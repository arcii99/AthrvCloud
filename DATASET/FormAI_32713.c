//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

void solve(int , char , char , char );

int main(){
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    
    solve(n, 'A', 'B', 'C');
    
    return 0;
}

void solve(int n, char start, char temp, char end){
    if(n == 1){
        printf("Move disk 1 from %c to %c\n", start, end);
        return;
    }
    solve(n-1, start, end, temp);
    printf("Move disk %d from %c to %c\n", n, start, end);
    solve(n-1, temp, start, end);
}