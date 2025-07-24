//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: surprised
#include<stdio.h>
#include<string.h>

int main(){

    printf("\n Hey, welcome to my C Checksum Calculator! \n");

    char input[100];
    printf("\nEnter the text to generate its checksum value: ");
    scanf("%s",input);

    int sum=0, len=strlen(input);

    for(int i=0;i<len;i++){
        sum+=input[i];
    }

    printf("\nChecksum of the input is %d\n", sum%256);

    printf("\n Thanks for using my program, hope you liked it :) \n");

    return 0;
}