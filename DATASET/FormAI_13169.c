//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: imaginative
#include<stdio.h>

int main(){

    int data[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}; // Initializing data array
    int i, j, count_one, count_zero, checksum;

    printf("\n-------------------------------------\n");
    printf("         CHECKSUM CALCULATOR         ");
    printf("\n-------------------------------------\n");
    printf("Original data: ");

    //Printing the original data
    for(i=0;i<16;i++){
        printf("%d ", data[i]);
    }

    //Performing checksum calculation
    for(i=0;i<16;i++){
        count_one=0;
        for(j =0;j<8;j++){
            if(data[i] & (1 << j)) count_one++; //Counting ones in binary representation of data
        }
        if(count_one % 2 == 0) data[i] = ~data[i]; //Inverting data if number of ones is even
    }

    //Calculating checksum
    checksum=0;
    for(i=0;i<16;i++){
        count_one=0;
        for(j =0;j<8;j++){
            if(data[i] & (1 << j)) count_one++; //Counting ones in binary representation of data
        }
        if(count_one % 2 == 0) checksum+=1;     //Incrementing checksum if number of ones is even
    }

    //Printing checksum and modified data
    printf("\nModified data: ");
    for(i=0;i<16;i++){
        printf("%d ", data[i]);
    }
    printf("\nCalculated checksum: %d\n",checksum);

    return 0;
}