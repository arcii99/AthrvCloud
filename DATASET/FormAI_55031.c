//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: artistic
// Tower of Hanoi problem using recursive approach
// with artistic style

#include <stdio.h>
#include <stdlib.h>

void hanoiTower(int, char, char, char);

int main() {

    int n;

    printf("\n\n--- Tower of Hanoi Artistic Style ---\n\n");

    // take the number of discs
    printf("Enter the number of discs: ");
    scanf("%d", &n);

    system("clear"); //clear the screen 

    printf("\n");

    hanoiTower(n, 'A', 'B', 'C'); // call the recursive function

    printf("\n\n--- End of Program ---\n\n");

    return 0;
}

// recursive function to solve the tower of hanoi problem
void hanoiTower(int n, char source, char auxiliary, char destination) { 

    if(n == 1) {
        printf("\033[0;31m>> Move Disc 1 from Tower %c to Tower %c\033[0m\n", source, destination);
        return;
    }

    hanoiTower(n - 1, source, destination, auxiliary);

    printf("\033[0;32m>> Move Disc %d from Tower %c to Tower %c\033[0m\n", n, source, destination);

    hanoiTower(n - 1, auxiliary, source, destination);
}