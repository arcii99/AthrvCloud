//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char alien[50];
    int length,i;

    printf("Enter a string in alien language: ");
    scanf("%s", alien);

    length = strlen(alien);

    for(i=0;i<length;i++){
        if(alien[i] == 'A'){
            printf("Ka ");
        }
        else if(alien[i] == 'B'){
            printf("Shui ");
        }
        else if(alien[i] == 'C'){
            printf("Qua ");
        }
        else if(alien[i] == 'D'){
            printf("Twi ");
        }
        else if(alien[i] == 'E'){
            printf("Plo ");
        }
        else if(alien[i] == 'F'){
            printf("Mij ");
        }
        else if(alien[i] == 'G'){
            printf("Zoo ");
        }
        else if(alien[i] == 'H'){
            printf("Kio ");
        }
        else if(alien[i] == 'I'){
            printf("Fae ");
        }
        else if(alien[i] == 'J'){
            printf("Kla ");
        }
        else if(alien[i] == 'K'){
            printf("Lop ");
        }
        else if(alien[i] == 'L'){
            printf("Tur ");
        }
        else if(alien[i] == 'M'){
            printf("Zil ");
        }
        else if(alien[i] == 'N'){
            printf("Nim ");
        }
        else if(alien[i] == 'O'){
            printf("Ra ");
        }
        else if(alien[i] == 'P'){
            printf("Sol ");
        }
        else if(alien[i] == 'Q'){
            printf("Tu ");
        }
        else if(alien[i] == 'R'){
            printf("Sui ");
        }
        else if(alien[i] == 'S'){
            printf("Ea ");
        }
        else if(alien[i] == 'T'){
            printf("Uru ");
        }
        else if(alien[i] == 'U'){
            printf("Vai ");
        }
        else if(alien[i] == 'V'){
            printf("Tra ");
        }
        else if(alien[i] == 'W'){
            printf("Zai ");
        }
        else if(alien[i] == 'X'){
            printf("Gru ");
        }
        else if(alien[i] == 'Y'){
            printf("Dro ");
        }
        else if(alien[i] == 'Z'){
            printf("Pro ");
        }
    }
    
    return 0;
}