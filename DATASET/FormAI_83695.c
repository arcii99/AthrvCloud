//FormAI DATASET v1.0 Category: Binary Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

void binary(int num){
    int binary_num[20], i = 0;
    while(num > 0){
        binary_num[i] = num%2;
        num = num/2;
        i++;
    }
    for(int j = i-1; j>=0; j--){
        printf("%d", binary_num[j]);
    }
}

int main(int argc, char **argv){
    if(argc != 2){
        printf("Usage: ./binary_converter <integer>\n");
        return 0;
    }
    int num = atoi(argv[1]);
    if(num < 0){
        printf("Negative integers are not allowed!\n");
        return 0;
    }
    printf("The binary representation of %d is: ", num);
    binary(num);
    printf("\n");
    return 0;
}