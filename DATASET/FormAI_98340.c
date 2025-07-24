//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

int num_moves = 0;

void moveTower(int n, char src, char dest, char aux){
    if(n == 1){
        num_moves++;
        printf("\nMove disk 1 from %c to %c", src, dest);
        return;
    }
    
    moveTower(n-1, src, aux, dest);
    num_moves++;
    printf("\nMove disk %d from %c to %c", n, src, dest);
    moveTower(n-1, aux, dest, src);
}

int main(){
    int n;
    char src = 'A', dest = 'C', aux = 'B';
    
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    moveTower(n, src, dest, aux);
    
    printf("\nTotal number of moves: %d", num_moves);
    
    return 0;
}