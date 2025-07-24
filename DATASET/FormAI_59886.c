//FormAI DATASET v1.0 Category: Searching algorithm ; Style: grateful
#include<stdio.h>
int main(){
    int a[10],i,x,low,mid,high,n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements in ascending order:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the element to be searched: ");
    scanf("%d",&x);
    low=0,high=n-1,mid=(low+high)/2;
    while(low<=high && a[mid]!=x){
        if(x<a[mid])
            high=mid-1;
        else
            low=mid+1;
        mid=(low+high)/2;
    }
    if(a[mid]==x)
        printf("%d found at position %d\n",x,mid+1);
    else
        printf("%d not found\n",x);
    return 0;
}