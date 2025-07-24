//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: detailed
#include<stdio.h>
#include<string.h>

int main(){
    char input[100];
    printf("Please enter the message you wish to translate to Alien Language: ");
    scanf("%s", input);

    for(int i=0; i<strlen(input); i++){
        if(input[i] == 'a'){
            printf("<");
        }else if(input[i] == 'b'){
            printf("*");
        }else if(input[i] == 'c'){
            printf("}");
        }else if(input[i] == 'd'){
            printf(":");
        }else if(input[i] == 'e'){
            printf("+");
        }else if(input[i] == 'f'){
            printf("=");
        }else if(input[i] == 'g'){
            printf(">");
        }else if(input[i] == 'h'){
            printf("[");
        }else if(input[i] == 'i'){
            printf("@");
        }else if(input[i] == 'j'){
            printf("#");
        }else if(input[i] == 'k'){
            printf("]");
        }else if(input[i] == 'l'){
            printf("$");
        }else if(input[i] == 'm'){
            printf("'");
        }else if(input[i] == 'n'){
            printf("&");
        }else if(input[i] == 'o'){
            printf("(");
        }else if(input[i] == 'p'){
            printf("/");
        }else if(input[i] == 'q'){
            printf("\\");
        }else if(input[i] == 'r'){
            printf(",");
        }else if(input[i] == 's'){
            printf(".");
        }else if(input[i] == 't'){
            printf(";");
        }else if(input[i] == 'u'){
            printf("?");
        }else if(input[i] == 'v'){
            printf("!");
        }else if(input[i] == 'w'){
            printf("%");
        }else if(input[i] == 'x'){
            printf("*");
        }else if(input[i] == 'y'){
            printf("`");
        }else if(input[i] == 'z'){
            printf("^");
        }else{
            printf("%c", input[i]);
        }
    }
    printf("\n");

    return 0;
}