//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: lively
#include <stdio.h>
#include <string.h>

void translate(char *input){
    int i;
    for(i=0;i<strlen(input);i++){
        switch(input[i]){
            case 'k':
                printf("Zorg ");
                break;
            case 'p':
                printf("Mik ");
                break;
            case 't':
                printf("Pak ");
                break;
            case 'q':
                printf("Xen ");
                break;
            case 'd':
                printf("Lar ");
                break;
            case 'b':
                printf("Gor ");
                break;
            case 'r':
                printf("Sip ");
                break;
            case 'z':
                printf("Wok ");
                break;
            case 'c':
                printf("Jik ");
                break;
            case 'f':
                printf("Mop ");
                break;
            default:
                printf("Invalid character found");
        }
    }
}

int main(){
    char input[100];
    printf("Enter the message in Alien Language: ");
    fgets(input, sizeof(input), stdin);
    printf("The translated message is: ");
    translate(input);
    printf("\n");
    return 0;
}