//FormAI DATASET v1.0 Category: Compression algorithms ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

void compress(char *input, char *output){
    int count = 0, i = 0, j = 0;
    char current;
    while(input[i] != '\0'){
        current = input[i];
        while(input[i] == current){
            count++;
            i++;
        }
        output[j++] = current;
        output[j++] = count+'0';
        count = 0;
    }
    output[j] = '\0';
}

int main(){
    char input[MAX], output[MAX];
    printf("Enter the string: \n");
    fgets(input, MAX, stdin);
    compress(input, output);
    printf("Compressed string: %s\n", output);
    return 0;
}