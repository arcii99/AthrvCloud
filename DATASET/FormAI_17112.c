//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: light-weight
#include <stdio.h>
#include <string.h>

void translate(char* word){
    int n = strlen(word);
    for(int i=0; i<n; i++){
        if(word[i] == 'a'){
            printf("l");
        }
        else if(word[i] == 'b'){
            printf("s");
        }
        else if(word[i] == 'c'){
            printf("j");
        }
        else if(word[i] == 'd'){
            printf("q");
        }
        else if(word[i] == 'e'){
            printf("t");
        }
        else if(word[i] == 'f'){
            printf("e");
        }
        else if(word[i] == 'g'){
            printf("m");
        }
        else if(word[i] == 'h'){
            printf("f");
        }
        else if(word[i] == 'i'){
            printf("n");
        }
        else if(word[i] == 'j'){
            printf("p");
        }
        else if(word[i] == 'k'){
            printf("o");
        }
        else if(word[i] == 'l'){
            printf("y");
        }
        else if(word[i] == 'm'){
            printf("x");
        }
        else if(word[i] == 'n'){
            printf("z");
        }
        else if(word[i] == 'o'){
            printf("k");
        }
        else if(word[i] == 'p'){
            printf("b");
        }
        else if(word[i] == 'q'){
            printf("d");
        }
        else if(word[i] == 'r'){
            printf("v");
        }
        else if(word[i] == 's'){
            printf("w");
        }
        else if(word[i] == 't'){
            printf("r");
        }
        else if(word[i] == 'u'){
            printf("g");
        }
        else if(word[i] == 'v'){
            printf("u");
        }
        else if(word[i] == 'w'){
            printf("a");
        }
        else if(word[i] == 'x'){
            printf("c");
        }
        else if(word[i] == 'y'){
            printf("i");
        }
        else if(word[i] == 'z'){
            printf("h");
        }
        else{
            printf("%c", word[i]);
        }
    }
}

int main(){
    char word[50];
    printf("Enter a word in Alien Language: ");
    scanf("%[^\n]", word);
    printf("Translate to English: ");
    translate(word);
    printf("\n");

    return 0;
}