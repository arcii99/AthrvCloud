//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: mind-bending
#include <stdio.h>

int main() {
    int n, peg1[100], peg2[100], peg3[100], i;
    printf("Welcome to the Mind-Bending Tower of Hanoi Problem Solver\n");
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if(n <= 0) {
        printf("Invalid number of disks!");
        return 0;
    }
    for(i=0; i<n; i++) {
        peg1[i] = n-i;
    }
    printf("\nInitial Configuration: \n");
    printPegs(n, peg1, peg2, peg3);
    printf("\nSolution:\n");
    solve(n, peg1, peg2, peg3, 1, 3);
    printf("\nFinal Configuration: \n");
    printPegs(n, peg1, peg2, peg3);
    printf("\nCongratulations! Problem solved.");
    return 0;
}

void printPegs(int n, int peg1[], int peg2[], int peg3[]) {
    int i;
    printf("\nPeg 1: ");
    for(i=0; i<n; i++) {
        if(peg1[i] != 0) {
            printf("%d ", peg1[i]);
        }
    }
    printf("\nPeg 2: ");
    for(i=0; i<n; i++) {
        if(peg2[i] != 0) {
            printf("%d ", peg2[i]);
        }
    }
    printf("\nPeg 3: ");
    for(i=0; i<n; i++) {
        if(peg3[i] != 0) {
            printf("%d ", peg3[i]);
        }
    }
}

void solve(int n, int peg1[], int peg2[], int peg3[], int source, int target) {
    if(n == 1) {
        int sourceDisk = peg1[n-1];
        int targetDisk = getEmptySlot(peg3);
        peg3[targetDisk] = sourceDisk;
        peg1[n-1] = 0;
        printPegs(getMax(n, peg1, peg2, peg3), peg1, peg2, peg3);
    }
    else {
        solve(n-1, peg1, peg3, peg2, source, getOtherTower(source, target));
        solve(1, peg1, peg2, peg3, source, target);
        solve(n-1, peg2, peg1, peg3, getOtherTower(source, target), target);
    }
}

int getEmptySlot(int peg[]) {
    int i = 0;
    while(peg[i] != 0) {
        i++;
    }
    return i;
}

int getMax(int n, int peg1[], int peg2[], int peg3[]) {
    int max = 0, i;
    for(i=0; i<n; i++) {
        if(peg1[i] > max) {
            max = peg1[i];
        }
        if(peg2[i] > max) {
            max = peg2[i];
        }
        if(peg3[i] > max) {
            max = peg3[i];
        }
    }
    return max;
}

int getOtherTower(int source, int target) {
    if(source == 1) {
        if(target == 2) {
            return 3;
        }
        else {
            return 2;
        }
    }
    else if(source == 2) {
        if(target == 1) {
            return 3;
        }
        else {
            return 1;
        }
    }
    else {
        if(target == 1) {
            return 2;
        }
        else {
            return 1;
        }
    }
}