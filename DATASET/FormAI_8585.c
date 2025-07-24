//FormAI DATASET v1.0 Category: Memory management ; Style: Cryptic
//Undecipherable Memory Management Program
#include<stdio.h>
#include<stdlib.h>

int main(){
    int* ptrArr[10];
    int i,j,sum=0;
    for(i=0;i<10;i++){
        ptrArr[i]=(int*)malloc(i*10*sizeof(int));
        if(ptrArr[i]==NULL){
            printf("Memory allocation failed!");
            exit(0);
        }
    }
    printf("Enter the elements of each array:\n");
    for(i=0;i<10;i++){
        printf("Array %d:\n",i+1);
        for(j=0;j<i*10;j++){
            scanf("%d",(ptrArr[i]+j));
        }
    }
    printf("\nEntered Values:\n");
    for(i=0;i<10;i++){
        printf("Array %d : ",i+1);
        for(j=0;j<i*10;j++){
            printf("%d ",*(ptrArr[i]+j));
            sum+=*(ptrArr[i]+j);
        }
        printf("\n");
    }
    printf("\nTotal Sum: %d",sum);
    for(i=0;i<10;i++)
        free(ptrArr[i]);
    return 0;
}