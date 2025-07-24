//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Cyberpunk
#include<stdio.h>
#include<string.h>

int main(){

    char input[100];
    int length,i,j,k;
    char output[100]={'\0'};

    printf("Enter the string that needs to be compressed: ");
    scanf("%s",input);

    length=strlen(input);

    for(i=0, j=0;i<length;){

        if(input[i] == input[i+1]){
            k=i;
            while(input[i] == input[i+1]){
                i++;
            }
            output[j++] = input[k];
            output[j++] = input[i]+1;
            i++;
        }

        else{
          output[j++] = input[i++];
        }

    }

    printf("\nCompressed String: %s\n",output);

    return 0;
}