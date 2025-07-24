//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: puzzling
#include<stdio.h>
#include<string.h>

//function to translate Alien language to English
void translate(char message[]){
    int length = strlen(message);
    int i=0;
    while(i<length){
        if(message[i]=='0'){
            printf("a");
        }
        else if(message[i]=='1'){
            printf("b");
        }
        else if(message[i]=='2'){
            printf("c");
        }
        else if(message[i]=='3'){
            printf("d");
        }
        else if(message[i]=='4'){
            printf("e");
        }
        else if(message[i]=='5'){
            printf("f");
        }
        else if(message[i]=='6'){
            printf("g");
        }
        else if(message[i]=='7'){
            printf("h");
        }
        else if(message[i]=='8'){
            printf("i");
        }
        else if(message[i]=='9'){
            printf("j");
        }
        else if(message[i]=='a'){
            printf("0");
        }
        else if(message[i]=='b'){
            printf("1");
        }
        else if(message[i]=='c'){
            printf("2");
        }
        else if(message[i]=='d'){
            printf("3");
        }
        else if(message[i]=='e'){
            printf("4");
        }
        else if(message[i]=='f'){
            printf("5");
        }
        else if(message[i]=='g'){
            printf("6");
        }
        else if(message[i]=='h'){
            printf("7");
        }
        else if(message[i]=='i'){
            printf("8");
        }
        else if(message[i]=='j'){
            printf("9");
        }
        else{
            //if an invalid character is found
            printf("x");
        }
        i++;
    }
}

int main(){
    //sample input
    char message[] = "7328f5";
    printf("Original Message: %s\n", message);
    printf("Translated Message: ");
    translate(message);
    printf("\n");
    return 0;
}