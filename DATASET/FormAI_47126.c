//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: romantic
#include<stdio.h>

int main() {
    int data[100], checksum = 0, n;
    printf("Enter the number of data words: ");
    scanf("%d",&n);
    printf("Enter data words: ");
    for(int i=0; i<n; i++) {
        scanf("%d",&data[i]);
        checksum += data[i];
    }
    checksum = ~checksum + 1;
    printf("Checksum: %d\n",checksum);
    return 0;
}