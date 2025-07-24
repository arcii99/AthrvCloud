//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: sophisticated
#include<stdio.h>
int move(int n, char source, char destination, char intermediate) {
    if (n == 1) {
        printf("\n Move disk 1 from %c to %c", source, destination);
        return 1;
    } else {
        move(n - 1, source, intermediate, destination);
        printf("\n Move disk %d from %c to %c", n, source, destination);
        move(n - 1, intermediate, destination, source);
        return 0;
    }
}
int main() {
    int n;
    char source = 'A', destination = 'C', intermediate = 'B';
    printf("Enter number of disks: ");
    scanf("%d", &n);

    move(n, source, destination, intermediate);
    return 0;
}