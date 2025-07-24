//FormAI DATASET v1.0 Category: Game ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10
int main(){
    int a[MAX],b[MAX],c[MAX];
    srand(time(NULL));
    printf("Enter values for array A:\n");
    for(int i=0;i<MAX;i++){
        scanf("%d",&a[i]);
    }
    printf("\nArray B is:\n");
    for(int i=0;i<MAX;i++){
        b[i] = rand()%20+1;
        printf("%d ",b[i]);
    }
    printf("\n\nPerforming element-wise multiplication of A and B...\n");
    for(int i=0;i<MAX;i++){
        c[i] = a[i] * b[i];
        printf("%d ",c[i]);
    }
    return 0;
}