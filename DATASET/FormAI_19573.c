//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Cryptic
#include<stdio.h>
int main(){
    const int N=10;
    int arr[N], k, i;
    for(i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    k=N;
    int cnt=0, ans[N], j;
    while(k>0){
        int idx;
        int mx=-1;
        for(i=0;i<N;i++){
            if(arr[i]>mx){
                mx=arr[i];
                idx=i;
            }
        }
        k-=mx;
        if(k<0) break;
        ans[cnt++]=mx;
        for(j=0;j<N;j++){
            if(j!=idx){
                arr[j]-=mx;
            }
        }
    }
    printf("Selected values:");
    for(i=0;i<cnt;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}