//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: careful
#include<stdio.h>

int main(){
    char c[100];
    int i;
    printf("Enter C code in English words:\n");
    fgets(c, 100, stdin);
    for(i=0; c[i]!='\0'; i++){
        if(c[i]=='H' && c[i+1]=='e' && c[i+2]=='l' && c[i+3]=='l' && c[i+4]=='o'){
            printf("printf(\"Hello World\");\n");
            i+=4;
        }
        else if(c[i]=='d' && c[i+1]=='e' && c[i+2]=='c' && c[i+3]=='l' && c[i+4]=='a' && c[i+5]=='r' && c[i+6]=='e' && c[i+7]==' '){
            printf("int ");
            i+=7;
            while(c[i]!='\n'){
                printf("%c", c[i]);
                i++;
            }
            printf(";\n");
        }
        else if(c[i]=='w' && c[i+1]=='h' && c[i+2]=='i' && c[i+3]=='l' && c[i+4]=='e' && c[i+5]==' '){
            printf("while(");
            i+=5;
            while(c[i]!='\n'){
                printf("%c", c[i]);
                i++;
            }
            printf("){\n");
        }
        else if(c[i]=='i' && c[i+1]=='f' && c[i+2]==' '){
            printf("if(");
            i+=2;
            while(c[i]!='\n'){
                printf("%c", c[i]);
                i++;
            }
            printf("){\n");
        }
        else if(c[i]=='f' && c[i+1]=='o' && c[i+2]=='r' && c[i+3]==' '){
            printf("for(");
            i+=3;
            while(c[i]!='\n'){
                printf("%c", c[i]);
                i++;
            }
            printf("){\n");
        }
        else if(c[i]=='e' && c[i+1]=='l' && c[i+2]=='s' && c[i+3]=='e'){
            printf("else{\n");
            i+=3;
        }
        else if(c[i]=='s' && c[i+1]=='w' && c[i+2]=='i' && c[i+3]=='t' && c[i+4]=='c' && c[i+5]=='h' && c[i+6]==' '){
            printf("switch(");
            i+=6;
            while(c[i]!='\n'){
                printf("%c", c[i]);
                i++;
            }
            printf("){\n");
        }
        else if(c[i]=='c' && c[i+1]=='a' && c[i+2]=='s' && c[i+3]=='e' && c[i+4]==' '){
            printf("case ");
            i+=4;
            while(c[i]!='\n'){
                printf("%c", c[i]);
                i++;
            }
            printf(":\n");
        }
        else if(c[i]=='d' && c[i+1]=='e' && c[i+2]=='f' && c[i+3]=='a' && c[i+4]=='u' && c[i+5]=='l' && c[i+6]=='t' && c[i+7]==':'){
            printf("default:\n");
            i+=7;
        }
        else if(c[i]=='b' && c[i+1]=='r' && c[i+2]=='e' && c[i+3]=='a' && c[i+4]=='k' && c[i+5]==';'){
            printf("break;\n");
            i+=5;
        }
        else if(c[i]=='c' && c[i+1]=='o' && c[i+2]=='n' && c[i+3]=='t' && c[i+4]=='i' && c[i+5]=='n' && c[i+6]=='u' && c[i+7]=='e' && c[i+8]==';'){
            printf("continue;\n");
            i+=8;
        }
        else if(c[i]=='r' && c[i+1]=='e' && c[i+2]=='t' && c[i+3]=='u' && c[i+4]=='r' && c[i+5]=='n' && c[i+6]==' '){
            printf("return ");
            i+=6;
            while(c[i]!='\n'){
                printf("%c", c[i]);
                i++;
            }
            printf(";\n");
        }
        else if(c[i]=='+' || c[i]=='-' || c[i]=='*' || c[i]=='/' || c[i]=='%' || c[i]=='=' || c[i]=='>' || c[i]=='<' || c[i]=='!' || c[i]=='&' || c[i]=='|' || c[i]=='^' || c[i]=='~' || c[i]=='?' || c[i]==':' || c[i]=='(' || c[i]==')' || c[i]=='{' || c[i]=='}' || c[i]==',' || c[i]==';'){
            printf("%c", c[i]);
        }
    }
    return 0;
}