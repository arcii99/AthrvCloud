//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: complete
#include<stdio.h>

int main(){
    int data[100],checksum=0,size;
    printf("Enter the size of data: "); //getting size of data
    scanf("%d",&size);

    printf("Enter the data: "); //getting the data
    for(int i=0;i<size;i++){
        scanf("%d",&data[i]);
    }

    for(int i=0;i<size;i++){ //calculating the checksum using XOR operation
        checksum ^= data[i];
    }

    printf("Checksum: %d\n",checksum);

    return 0;
}