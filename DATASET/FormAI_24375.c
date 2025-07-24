//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function to print a character to ASCII art
void print_char(char c){
    switch(c){
        case 'a':
            printf("      /\\      \n");
            printf("     /  \\     \n");
            printf("    /    \\    \n");
            printf("   /------\\   \n");
            printf("  /        \\  \n");
            printf("            \n");
            break;
        case 'b':
            printf("  _____  \n");
            printf(" |     \\ \n");
            printf(" |------\\ \n");
            printf(" |      | \n");
            printf(" |_____/ \n");
            break;
        case 'c':
            printf("  _______  \n");
            printf(" /       \\ \n");
            printf("/         \\\n");
            printf("\\         /\n");
            printf(" \\_______/ \n");
            break;
        case 'd':
            printf("  _____   \n");
            printf(" |     \\  \n");
            printf(" |      \\ \n");
            printf(" |      | \n");
            printf(" |_____/  \n");
            break;
        case 'e':
            printf("  ______  \n");
            printf(" /  ____| \n");
            printf("|  |___  \n");
            printf("|  ____| \n");
            printf("\\|_____| \n");
            break;
        default:
            printf("   _____   \n");
            printf("  /     \\  \n");
            printf(" |  STOP | \n");
            printf("  \\_____/\n");
            break;
    }
}

int main(){
    char string[100];
    printf("Enter a string: ");
    fgets(string, 100, stdin); //fgets() to read a string with spaces
    
    printf("\n\n");
    
    int length = strlen(string);
    for(int i = 0; i < length; i++){
        if(string[i] == ' '){
            printf("\n\n\n\n\n");
            continue;
        }
        print_char(string[i]);
        printf("\n\n\n");
    }
    
    return 0;
}