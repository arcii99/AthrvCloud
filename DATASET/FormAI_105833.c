//FormAI DATASET v1.0 Category: Pattern printing ; Style: active
#include<stdio.h>
int main() {
    int n;
    printf("Enter the number of rows (minimum 3): ");
    scanf("%d", &n);
    if(n < 3) {
        printf("Number of rows should be minimum 3\n");
        return 0;
    }
    int mid = (n+1)/2 - 1;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i==0 || i==n-1) {
                if(j!=mid) {
                    printf("*");
                }
                else {
                    printf(" ");
                }
            } 
            else if(j==mid) {
                printf("*");
            }
            else if(j == mid-i || j == mid+i) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}