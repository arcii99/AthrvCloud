//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* hex_to_bin(char* hex_digit){
    switch(*hex_digit){
        case '0':
            return "0000";
        case '1':
            return "0001";
        case '2':
            return "0010";
        case '3':
            return "0011";
        case '4':
            return "0100";
        case '5':
            return "0101";
        case '6':
            return "0110";
        case '7':
            return "0111";
        case '8':
            return "1000";
        case '9':
            return "1001";
        case 'A':
        case 'a':
            return "1010";
        case 'B':
        case 'b':
            return "1011";
        case 'C':
        case 'c':
            return "1100";
        case 'D':
        case 'd':
            return "1101";
        case 'E':
        case 'e':
            return "1110";
        case 'F':
        case 'f':
            return "1111";
        default:
            return "Invalid input";
    }
}

char* bin_to_hex(char* bin_digit){
    if(strlen(bin_digit) != 4){
        return "Invalid input";
    }
    if(!strcmp(bin_digit, "0000")){
        return "0";
    }
    if(!strcmp(bin_digit, "0001")){
        return "1";
    }
    if(!strcmp(bin_digit, "0010")){
        return "2";
    }
    if(!strcmp(bin_digit, "0011")){
        return "3";
    }
    if(!strcmp(bin_digit, "0100")){
        return "4";
    }
    if(!strcmp(bin_digit, "0101")){
        return "5";
    }
    if(!strcmp(bin_digit, "0110")){
        return "6";
    }
    if(!strcmp(bin_digit, "0111")){
        return "7";
    }
    if(!strcmp(bin_digit, "1000")){
        return "8";
    }
    if(!strcmp(bin_digit, "1001")){
        return "9";
    }
    if(!strcmp(bin_digit, "1010")){
        return "A";
    }
    if(!strcmp(bin_digit, "1011")){
        return "B";
    }
    if(!strcmp(bin_digit, "1100")){
        return "C";
    }
    if(!strcmp(bin_digit, "1101")){
        return "D";
    }
    if(!strcmp(bin_digit, "1110")){
        return "E";
    }
    if(!strcmp(bin_digit, "1111")){
        return "F";
    }
    return "Invalid input";
}

void convert_to_hex(){
    char hex[16];
    printf("\nEnter a hexadecimal number: ");
    scanf("%s", hex);
    printf("The binary equivalent is: ");
    for(int i=0; i<strlen(hex); i++){
        printf("%s", hex_to_bin(&hex[i]));
    }
    printf("\nThe hex equivalent is: %s\n", hex);
}

void convert_to_bin(){
    char bin[65];
    printf("\nEnter a binary number: ");
    scanf("%s", bin);
    if(strlen(bin) % 4 != 0){
        int padding = 4 - (strlen(bin) % 4);
        char padded_bin[65];
        for(int i=0; i<padding; i++){
            padded_bin[i] = '0';
        }
        strcat(padded_bin, bin);
        printf("The padded binary equivalent is: %s\n", padded_bin);
        strcpy(bin, padded_bin);
    }
    printf("The hex equivalent is: ");
    for(int i=0; i<strlen(bin); i+=4){
        char bin_digit[5];
        memcpy(bin_digit, &bin[i], 4);
        bin_digit[4] = '\0';
        printf("%s", bin_to_hex(bin_digit));
    }
    printf("\nThe binary equivalent is: %s\n", bin);
}

int main(){
    while(1){
        printf("\nSelect an option:\n");
        printf("1. Convert hexadecimal to binary and hex.\n");
        printf("2. Convert binary to hexadecimal and binary.\n");
        printf("3. Exit.\n");
        printf("Enter option number: ");
        int option;
        scanf("%d", &option);
        switch(option){
            case 1:
                convert_to_hex();
                break;
            case 2:
                convert_to_bin();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid option number.\n");
        }
    }
    return 0;
}