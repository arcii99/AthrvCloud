//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: genious
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    printf("\nChecksum: ");
    for(i=0;i<n;i++){
        int sum = 0;
        int num = arr[i];
        while(num != 0){
            sum += num%10;
            num /= 10;
        }
        int checksum = 0;
        while(sum != 0){
            checksum += sum%10;
            sum /= 10;
        }
        printf("%d ", checksum);
    }
    return 0;
}