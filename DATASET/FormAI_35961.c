//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: unmistakable
#include <stdio.h>
void tower(int n, char source, char dest, char temp){
    if(n == 1){
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    }
    tower(n-1, source, temp, dest);
    printf("Move disk %d from %c to %c\n", n, source, dest);
    tower(n-1, temp, dest, source);
}
int main(){
    int n;
    printf("Enter the number of disks:");
    scanf("%d", &n);
    tower(n, 'A', 'C', 'B');
    return 0;
}