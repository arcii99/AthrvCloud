//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: systematic
#include <stdio.h>
#include <string.h>

void translate(char* word){
    int len = strlen(word);
    char translated_word[len+1];

    for(int i=0; i<len; i++){
        if(word[i] == 'a'){
            translated_word[i] = 'z';
        }
        else if(word[i] == 'b'){
            translated_word[i] = 'y';
        }
        else if(word[i] == 'c'){
            translated_word[i] = 'x';
        }
        else if(word[i] == 'd'){
            translated_word[i] = 'w';
        }
        else if(word[i] == 'e'){
            translated_word[i] = 'v';
        }
        else if(word[i] == 'f'){
            translated_word[i] = 'u';
        }
        else if(word[i] == 'g'){
            translated_word[i] = 't';
        }
        else if(word[i] == 'h'){
            translated_word[i] = 's';
        }
        else if(word[i] == 'i'){
            translated_word[i] = 'r';
        }
        else if(word[i] == 'j'){
            translated_word[i] = 'q';
        } 
        else if(word[i] == 'k'){
            translated_word[i] = 'p';
        }
        else if(word[i] == 'l'){
            translated_word[i] = 'o';
        }
        else if(word[i] == 'm'){
            translated_word[i] = 'n';
        }
        else if(word[i] == 'n'){
            translated_word[i] = 'm';
        }
        else if(word[i] == 'o'){
            translated_word[i] = 'l';
        }
        else if(word[i] == 'p'){
            translated_word[i] = 'k';
        }
        else if(word[i] == 'q'){
            translated_word[i] = 'j';
        }
        else if(word[i] == 'r'){
            translated_word[i] = 'i';
        }
        else if(word[i] == 's'){
            translated_word[i] = 'h';
        }
        else if(word[i] == 't'){
            translated_word[i] = 'g';
        }
        else if(word[i] == 'u'){
            translated_word[i] = 'f';
        }
        else if(word[i] == 'v'){
            translated_word[i] = 'e';
        }
        else if(word[i] == 'w'){
            translated_word[i] = 'd';
        }
        else if(word[i] == 'x'){
            translated_word[i] = 'c';
        }
        else if(word[i] == 'y'){
            translated_word[i] = 'b';
        }
        else if(word[i] == 'z'){
            translated_word[i] = 'a';
        } 
        else if(word[i] == ' '){
            translated_word[i] = ' ';
        }
    }
    translated_word[len] = '\0';

    printf("The word %s in Alien language is: %s\n", word, translated_word);
}

int main(){
    char word[50];

    printf("Enter a word in Alien Language: ");
    scanf("%[^\n]s", word);
    getchar();

    translate(word);

    return 0;
}