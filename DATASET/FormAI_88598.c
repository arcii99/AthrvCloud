//FormAI DATASET v1.0 Category: System boot optimizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char boot_opt[100];     // declare character array to store boot optimizer 
    char art[3][100] = {"  _____           _    _   _     _        ", 
                        " |   __|___ _____|_| _|_|_|___| |_ ___ ",
                        " |__   |   |     | || . | |   |  _|_ -|" };  // declare ASCII art characters
    printf("\n\t\t\tBoot Optimizer\n\n");
    printf("Enter boot optimizer: ");
    gets(boot_opt);     // get user input for boot optimizer

    system("cls");  // clear screen

    printf("\n\n");

    for(int i=0; i<3; i++){
        for(int j=0; j<strlen(art[i]); j++){
            if(art[i][j] == '_')
                printf("%s", boot_opt);   // replacing ASCII art '_' with user input boot optimizer
            else
                printf("%c", art[i][j]);  // print ASCII art character 
        }
        printf("\n");
    }

    printf("\n\nBoot Optimizer successfully applied.\n\n");

    return 0;
}