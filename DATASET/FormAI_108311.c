//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: interoperable
#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 100

int check_hex(char hex){
    if((hex >= '0' && hex <= '9') || (hex >= 'A' && hex <= 'F') || (hex >= 'a' && hex <= 'f')){
        return 1;
    }
    else{
        return 0;
    }
}

int convert_hex(char hex){
    if(hex >= '0' && hex <= '9'){
        return hex - '0';
    }
    else if(hex >= 'A' && hex <= 'F'){
        return hex - 'A' + 10;
    }
    else if(hex >= 'a' && hex <= 'f'){
        return hex - 'a' + 10;
    }
    else{
        return -1;
    }
}

int main(){
    char hex[MAX_LENGTH];
    printf("Enter a hexadecimal number: ");
    fgets(hex, MAX_LENGTH, stdin);
    int decimal = 0;
    int i = 0;
    while(hex[i] != '\0' && hex[i] != '\n'){
        if(check_hex(hex[i])){
            decimal = decimal * 16 + convert_hex(hex[i]);
        }
        else{
            printf("Invalid character '%c' in input\n", hex[i]);
            return 1;
        }
        i++;
    }
    printf("The decimal equivalent of the hexadecimal number %s is %d\n", hex, decimal);
    return 0;
}