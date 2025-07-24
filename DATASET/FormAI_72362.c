//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
int main(){
    int n;
    printf("Enter the number of bytes: ");
    scanf("%d",&n);
    unsigned char* buffer = (unsigned char*)malloc(n*sizeof(char));
    printf("Enter the data: ");
    scanf("%s",buffer);
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=buffer[i];
    }
    unsigned char checksum = (unsigned char)(sum%256);
    printf("Checksum: %u\n",checksum);
    free(buffer);
    return 0;
}