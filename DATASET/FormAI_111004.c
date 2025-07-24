//FormAI DATASET v1.0 Category: Memory management ; Style: bold
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("\n\t***MEMORY MANAGEMENT SYSTEM***\n");
    printf("\n\n1. Enter the size of memory to be allocated: ");
    int size;
    scanf("%d",&size);
    int *p=(int *)malloc(size*sizeof(int));
    if(p==NULL){
        printf("\nMEMORY IS FULL!!! DELETING MEMORY.\n");
        free(p);
        exit(0);
    }
    else{
        printf("\n%d bytes of memory is allocated.\n",size*sizeof(int));
        printf("\nEnter the elements to be added: \n");
        for(int i=0;i<size;i++)
            scanf("%d",(p+i));
    }
    printf("\nMEMORY ALLOCATION IS SUCCESSFUL.\n");
    printf("\nMEMORY DETAILS:\n");
    printf("\tMemory Located at: %p\n",p);
    printf("\tMemory Size: %d Bytes\n",size*sizeof(int));
    printf("\tMemory Content: ");
    for(int i=0;i<size;i++)
        printf("%d ",*(p+i));
    printf("\n\nDo you want to delete the memory?(1/0) : ");
    int c;
    scanf("%d", &c);
    if(c==1){
        free(p);
        printf("\n***MEMORY HAS BEEN DELETED SUCCESSFULLY.***\n");
        printf("\nMEMORY DETAILS AFTER DELETED:\n");
        printf("\tMemory Located at: %p\n",p);
        printf("\tMemory Content: ");
        for(int i=0;i<size;i++)
            printf("%d ",*(p+i));
        printf("\n");
    }
    else
        printf("\nMEMORY DELETION HAS BEEN CANCELLED BY THE USER.\n");
    return 0;
}