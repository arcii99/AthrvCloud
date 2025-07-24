//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: sophisticated
/* C Checksum Calculator Example Program */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to calculate checksum
unsigned char checksum_calculation(unsigned char *data, int len){
    unsigned int sum = 0;
    int i = 0;

    // perform 16-bit sum on each word in the data
    while(len > 1){
        sum += *(unsigned int*) data++;
        len -= 2;
    }

    // if there is a leftover byte, add it to the sum
    if(len){
        sum += *(unsigned char*) data;
    }

    // add carry bits to the sum
    while(sum >> 16){
        sum = (sum & 0xFFFF) + (sum >> 16);
    }

    // return the one's complement of the sum
    return (unsigned char)~sum;
}

int main(){
    unsigned char *data = (unsigned char*)malloc(sizeof(unsigned char)*1024);
    memset(data,0x00,sizeof(unsigned char)*1024);

    int len = 0;
    printf("\nEnter the data for which checksum is to be calculated:\n");
    scanf("%s",(char*)data);
    len = strlen((char*)data);

    unsigned char chksum = checksum_calculation(data,len);
    printf("\nChecksum value is: 0x%02X\n",chksum);

    free(data);
    return 0;
}