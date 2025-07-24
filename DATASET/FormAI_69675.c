//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: random
#include <stdio.h>
#include <string.h>

int main(){
    char input[100];
    int len;
    printf("Enter the string to scan for viruses: ");
    scanf("%s",input);
    len = strlen(input);
    int i;
    int result = 0;
    for(i = 0; i < len; i++){
        if(input[i] == 'v' && input[i+1] == 'i' && input[i+2] == 'r' && input[i+3] == 'u' && input[i+4] == 's'){
            result = 1;
        }
    }
    if(result == 1){
        printf("Warning: Virus detected in input!\n");
    }
    else{
        printf("No viruses detected in input. Proceed with caution.\n");
    }
    return 0;
}