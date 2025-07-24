//FormAI DATASET v1.0 Category: File handling ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    FILE *fp; //declaring the file pointer
    char ch, password[20], fname[20]="secrets.txt"; //declaring variables
    
    printf("Enter secret password: ");
    scanf("%s", password);
    
    fp = fopen(fname, "rb"); //opening file in read binary mode
    
    if(fp == NULL){ //checking if file exists and can be opened
        printf("Sorry, the secrets file cannot be accessed.\n");
        exit(1); //exiting program if file cannot be accessed
    }
    else{
        printf("\nAccess granted. Decrypting secrets...\n\n");
    }

    //Decryption algorithm
    int i = 0, len = strlen(password);
    while(!feof(fp)){
        ch = fgetc(fp);

        if(ch != EOF){
            ch -= password[i] % len;
            i++;
            if(i == len){
                i = 0;
            }
        }
        printf("%c", ch); //print decrypted character
    }

    fclose(fp); //closing file
    printf("\n\nSecrets decrypted successfully. Enjoy!\n");
    return 0; //end of program
}