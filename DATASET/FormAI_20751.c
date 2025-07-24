//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

void tower_of_hanoi(int n, char source, char auxiliary, char destination) {
    if(n==1) {
        printf("Move disk %d from %c to %c\n", n, source, destination);
        return;
    }
    tower_of_hanoi(n-1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    tower_of_hanoi(n-1, auxiliary, source, destination);
}

int main() {
    int n;
    char source='A', auxiliary='B', destination='C';
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("The steps to solve the Tower of Hanoi problem are: \n");
    tower_of_hanoi(n, source, auxiliary, destination);
    return 0;
}