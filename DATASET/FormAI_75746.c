//FormAI DATASET v1.0 Category: Recursive ; Style: multiplayer
#include <stdio.h>

int findWinner(int arr[], int n) {
    if(n == 1) return arr[0]; // Base condition
    
    int i, j;
    int temp[n/2]; // Temporary array to store values after dividing the array into halves
    
    // Divide the array into two halves and find the winner of each half
    for(i=0, j=0; i<n; i+=2, j++) {
        temp[j] = (arr[i] > arr[i+1]) ? arr[i] : arr[i+1];
    }
    
    // Recursively find the winner of the temporary array
    return findWinner(temp, n/2);
}

int main() {
    int n, arr[100], i;
    printf("Enter the number of players: ");
    scanf("%d", &n);
    
    // Input the scores of all players
    printf("Enter the scores of all players: ");
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Find the winner
    int winner = findWinner(arr, n);
    printf("The winner is player %d with a score of %d.\n", winner, arr[winner-1]);
    return 0;
}