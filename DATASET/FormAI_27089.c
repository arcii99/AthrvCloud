//FormAI DATASET v1.0 Category: Educational ; Style: Cryptic
#include <stdio.h>

int main() {
    int n=10, s=0;
    for(int i=1;i<=n;++i) s+=i;
    
    printf("3,6,10,15,21,28,36,45,55,66, sum = %d\n", s);
    
    int arr[] = {4, 8, 15, 16, 23, 42};
    int len = sizeof(arr)/sizeof(int);
    int sum = 0;
    for(int i=0;i<len;++i) sum+=arr[i];
    
    printf("lost = %d\n", sum);
    
    int matrix[5][5] = { 
        {1, 2, 3, 4, 5}, 
        {6, 7, 8, 9, 10}, 
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int scan = 0, sumdiagonal = 0;
    for(int i=0;i<5;++i) {
        for(int j=0;j<5;++j) {
            if(i==j) sumdiagonal+=matrix[i][j];
            if((i+j)==4) scan+=matrix[i][j];
        }
    }
    
    printf("sum of diagonal is %d, and the answer is %d\n", sumdiagonal, scan);
    
    return 0;
}