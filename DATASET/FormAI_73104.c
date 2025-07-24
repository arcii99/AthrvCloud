//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: random
#include <stdio.h>

// Function to move the disks from source rod to destination rod
void towerOfHanoi(int num_disks, char source_rod, char dest_rod, char aux_rod) {
    if (num_disks == 1) {
        printf("\nMove disk 1 from rod %c to rod %c", source_rod, dest_rod);
        return;
    }
    towerOfHanoi(num_disks - 1, source_rod, aux_rod, dest_rod);
    printf("\nMove disk %d from rod %c to rod %c", num_disks, source_rod, dest_rod);
    towerOfHanoi(num_disks - 1, aux_rod, dest_rod, source_rod);
}

// Function to show how the tower of Hanoi problem can be creatively used to sort an array
void hanoiSort(int arr[], int num_disks, char source_rod, char dest_rod, char aux_rod) {
    if (num_disks == 1) {
        arr[0] = source_rod;    // store the source rod value in the array as it will be the smallest
        return;
    }
    hanoiSort(arr, num_disks - 1, source_rod, aux_rod, dest_rod);
    arr[num_disks - 1] = source_rod;    // store the source rod value in the array
    hanoiSort(arr, num_disks - 1, aux_rod, dest_rod, source_rod);
}

int main() {
    int num_disks = 2;
    char source_rod = 'A';
    char dest_rod = 'C';
    char aux_rod = 'B';
    int arr[num_disks];
    
    // Solve the Tower of Hanoi problem and display the moves
    printf("Solving the Tower of Hanoi problem with %d disks:\n\n", num_disks);
    towerOfHanoi(num_disks, source_rod, dest_rod, aux_rod);
    
    // Use the tower of Hanoi problem to sort the array
    printf("\n\nSorting an array with the Tower of Hanoi:\n\n");
    hanoiSort(arr, num_disks, source_rod, dest_rod, aux_rod);
    printf("Sorted array: ");
    for (int i = 0; i < num_disks; i++) {
        printf("%c ", arr[i]);
    }
    return 0;
}