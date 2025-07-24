//FormAI DATASET v1.0 Category: Text processing ; Style: active
#include<stdio.h>
#include<string.h>

int main(){
    char input_string[100],output_string[100];
    int i,j,str_len;

    printf("Enter a string:\n");
    fgets(input_string,sizeof(input_string),stdin); // Input

    str_len=strlen(input_string)-1; // Length of input string

    for(i=0,j=0;i<str_len;i++){ // loop over string
        if(input_string[i]!=' '){ // Check for spaces
            output_string[j++]=input_string[i]; // Append to output string
        }
    }
    output_string[j]='\0'; // Null terminate
    printf("Output String: %s\n",output_string); // Print output

    return 0;
}