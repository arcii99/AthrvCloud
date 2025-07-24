//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Sherlock Holmes
#include<stdio.h>
 
void solve(int n, char start, char end, char mid) {
 
    if(n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", start, end);
    } else {
        solve(n-1, start, mid, end);
        printf("Move disk %d from rod %c to rod %c\n", n, start, end);
        solve(n-1, mid, end, start);
    }
 
}
 
int main () {
 
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    solve(n, 'A', 'C', 'B');
    return 0;
}