//FormAI DATASET v1.0 Category: Compression algorithms ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

char compressed_string[MAX];
char e1[MAX],e2[MAX];
int e1_size,e2_size;
int current_index=0;

//Function to append a character to the compressed string
void append_char(char c){
    compressed_string[current_index++]=c;
}

//Function to compress the input string
void compress_string(char *input_string){
    int length = strlen(input_string);
    for(int i=0;i<length;i++){
        //Check if the character is present in the first encoding list
        int present_flag=0;
        for(int j=0;j<e1_size;j++){
            if(input_string[i] == e1[j]){
                present_flag=1;
                append_char(j+'A');
                break;
            }
        }
        //If the character is not present, check the second encoding list
        if(present_flag==0){
            for(int j=0;j<e2_size;j++){
                if(input_string[i] == e2[j]){
                    present_flag=1;
                    append_char(j+'a');
                    break;
                }
            }
        }
        //If the character is still not present, add it to the second encoding list
        if(present_flag==0){
            e2[e2_size++]=input_string[i];
            append_char((e2_size-1)+'a');
        }
        //If the second encoding list is full, reset it
        if(e2_size==26){
            e2_size=0;
        }
    }
}


int main(){
    char input_string[MAX];
    printf("Enter a string to compress\n");
    fgets(input_string, MAX, stdin);
    input_string[strcspn(input_string,"\n")]='\0'; //Removing newline character from fgets output
    //Initialising the first encoding list with vowels
    e1[0]='a'; e1[1]='e'; e1[2]='i'; e1[3]='o'; e1[4]='u';
    e1_size=5;
    compress_string(input_string);
    printf("The compressed string is: %s",compressed_string);
    return 0;
}