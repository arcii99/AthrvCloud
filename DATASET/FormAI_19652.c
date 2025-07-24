//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: energetic
#include<stdio.h>

int main(){
    int data[1000];
    int i, n, checksum=0;
    printf("*** Welcome to the Checksum Calculator! ***\n");
    printf("Enter the number of data values: ");
    scanf("%d", &n);
    printf("Enter the data values (space-separated): ");
    for(i=0;i<n;i++){
        scanf("%d", &data[i]);
        checksum = (checksum + data[i])%255;
    }
    printf("Checksum: %d\n", checksum);

    return 0;
}