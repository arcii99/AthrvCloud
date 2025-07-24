//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: secure
#include <stdio.h>

void move(char from, char to) {
    printf("Moving from %c to %c\n", from, to);
}

void TowerOfHanoi(int n, char source, char auxiliary, char destination) {
    if(n == 1) {
        move(source, destination);
    }
    else {
        TowerOfHanoi(n-1, source, destination, auxiliary);
        move(source, destination);
        TowerOfHanoi(n-1, auxiliary, source, destination);
    }
}

int main() {
    int n = 3;
    char source = 'A', auxiliary = 'B', destination = 'C';
    printf("The sequence of moves involved in the Tower of Hanoi problem with %d disks is:\n", n);
    TowerOfHanoi(n, source, auxiliary, destination);
    return 0;
}