//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: enthusiastic
#include<stdio.h>
int main(){
    printf("Welcome to the amazing world of digital watermarking!\n\n");

    //Defining variables
    char originalContent[1000], watermark[100];
    int j=0;

    //Getting user input for original content
    printf("Enter the original content: \n");
    scanf("%[^\n]s", originalContent);

    //Getting user input for watermark
    printf("\nEnter the watermark to be added: \n");
    scanf("%s", watermark);

    //Adding watermark to the original content
    for(int i=0; originalContent[i]!='\0'; i++){
        if(originalContent[i]==' '){
            originalContent[i]=watermark[j];
            j++;
            if(watermark[j]=='\0') break;
        }
    }

    //Displaying the watermarked content
    printf("\nThe watermarked content is as follows: \n");
    printf("%s\n\n", originalContent);

    return 0;
}