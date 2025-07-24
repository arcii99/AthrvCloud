//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: recursive
#include <stdio.h>
#include <string.h>

void translate(char *word, int pos);

int main(){
    char word[50];

    printf("Enter a word in C Alien Language: ");
    fgets(word, 50, stdin);
    
    // removes newline character at the end of the input
    word[strcspn(word, "\n")] = 0;

    printf("Translated word: ");
    translate(word, 0);
    printf("\n");

    return 0;
}

void translate(char *word, int pos){
    char c = word[pos];

    if(c == '\0'){
        return;
    }

    if(c == 'C'){
        printf("K");
    }
    else if(c == 'c'){
        printf("k");
    }
    else if(c == 'A'){
        printf("Z");
    }
    else if(c == 'a'){
        printf("z");
    }
    else if(c == 'E'){
        printf("F");
    }
    else if(c == 'e'){
        printf("f");
    }
    else if(c == 'G'){
        printf("H");
    }
    else if(c == 'g'){
        printf("h");
    }
    else if(c == 'I'){
        printf("L");
    }
    else if(c == 'i'){
        printf("l");
    }
    else if(c == 'O'){
        printf("P");
    }
    else if(c == 'o'){
        printf("p");
    }
    else if(c == 'U'){
        printf("W");
    }
    else if(c == 'u'){
        printf("w");
    }
    else if(c == 'Y'){
        printf("X");
    }
    else if(c == 'y'){
        printf("x");
    }
    else{
        printf("%c", c);
    }

    translate(word, pos+1);
}