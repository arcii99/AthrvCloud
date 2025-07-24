//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: complete
#include <stdio.h>

int main() {
    int n, checksum = 0;
    printf("Enter number of integers: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) {
        printf("Enter integer %d: ", i+1);
        scanf("%d", &arr[i]);
        checksum += arr[i];
    }
    printf("Checksum: %d\n", checksum);
    printf("Complement checksum: %d\n", ~(checksum));
    return 0;
}