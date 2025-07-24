//FormAI DATASET v1.0 Category: Searching algorithm ; Style: surprised
#include<stdio.h>

int main(){
    int arr[50], size, search, i, flag=0;
    
    printf("Wow! I am going to demonstrate a unique C Searching Algorithm. ");
    printf("Please enter the number of elements in the array (Max 50): ");
    scanf("%d",&size);
    printf("Amazing! Please enter %d integers :",size);
    
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    
    printf("Unbelievable! Enter the integer you want to search: ");
    scanf("%d",&search);
    
    for(i=0;i<size;i++){
        if(arr[i]==search){
            flag=1;
            break;
        }
    }
    
    if(flag==1){
        printf("Oh my god! The integer %d is found at position %d",search,i+1);
    }
    else{
        printf("Oops! The integer %d is not found in the array.",search);
    }
    return 0;
}