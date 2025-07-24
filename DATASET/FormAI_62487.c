//FormAI DATASET v1.0 Category: Compression algorithms ; Style: visionary
#include<stdio.h>
#include<string.h>

void compress(char* string){
    int i=0,count=1,n=strlen(string);
    
    for(i=1;i<n;i++){
        if(string[i]==string[i-1]){
            count++;
        }
        else{
            printf("%c%d",string[i-1],count);
            count=1;
        }
    }
    printf("%c%d",string[n-1],count);
}

int main(){
    char* input="aaabbcccdd";
    printf("Before Compression: %s\n",input);
    printf("After Compression: ");
    compress(input);
    printf("\n");
    return 0;
}