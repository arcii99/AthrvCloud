//FormAI DATASET v1.0 Category: Color Code Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char c_code[10];
    printf("Enter a C Color Code: ");
    scanf("%s", c_code);
    
    if (strlen(c_code) != 4 && strlen(c_code) != 7) {
        printf("Invalid Color Code!\n");
        exit(0);
    }
    
    char hex_code[10] = "#";
    char temp[3];
    
    for(int i=1; i<=3; i++){
        if(strlen(c_code) == 4){
            temp[0] = c_code[i];
            temp[1] = c_code[i];
        }else{
            temp[0] = c_code[i*2 - 2];
            temp[1] = c_code[i*2 - 1];
        }

        if(temp[0] >= 'a' && temp[0] <= 'f'){
            temp[0] = temp[0] - 'a' + 'A';
        }

        if(temp[1] >= 'a' && temp[1] <= 'f'){
            temp[1] = temp[1] - 'a' + 'A';
        }
        
        strcat(hex_code, temp);
    }

    printf("Hex Code: %s\n", hex_code);

    return 0;
}