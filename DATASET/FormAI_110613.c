//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: active
#include<stdio.h>
#include<string.h>

//function to translate C Cat Language to English Language
void translateCcatToEnglish(char cCatCode[]){
    int i, length;

    length = strlen(cCatCode);

    for(i=0;i<length;){

        //check for start of sentence
        if(cCatCode[i]=='P'){
            i++;
            //check for middle of sentence
            while(cCatCode[i]==' '){
                i++;
                if(cCatCode[i]=='P'){
                    printf("If ");
                    i++;
                }
                else if(cCatCode[i]=='~'){
                    printf("Break;");
                    i++;
                }
                else if(cCatCode[i]=='X'){
                    printf("Else ");
                    i++;
                }
            }
            //check for end of sentence
            if(cCatCode[i]=='M'){
                printf("{");
                i++;
            }
        }

        //check for data types
        else if(cCatCode[i]=='I'){
            printf("int ");
            i++;
            if(cCatCode[i]=='M'){
                printf(";\n");
                i++;
            }
            else{
                //check for variable name
                while(cCatCode[i]!='M'){
                    printf("%c", cCatCode[i]);
                    i++;
                }
                printf(";");
                i++;
            }
        }
        else if(cCatCode[i]=='D'){
            printf("double ");
            i++;
            if(cCatCode[i]=='M'){
                printf(";\n");
                i++;
            }
            else{
                while(cCatCode[i]!='M'){
                    printf("%c", cCatCode[i]);
                    i++;
                }
                printf(";");
                i++;
            }
        }
        else if(cCatCode[i]=='C'){
            printf("char ");
            i++;
            if(cCatCode[i]=='M'){
                printf(";\n");
                i++;
            }
            else{
                while(cCatCode[i]!='M'){
                    printf("%c", cCatCode[i]);
                    i++;
                }
                printf(";");
                i++;
            }
        }

        //check for conditional statements
        else if(cCatCode[i]=='G'){
            printf("if(");
            i++;
            while(cCatCode[i]!='M'){
                printf("%c", cCatCode[i]);
                i++;
            }
            printf("){");
            i++;
        }
        else if(cCatCode[i]=='W'){
            printf("while(");
            i++;
            while(cCatCode[i]!='M'){
                printf("%c", cCatCode[i]);
                i++;
            }
            printf("){");
            i++;
        }

        //check for mathematical operators
        else if(cCatCode[i]=='A'){
            printf("+");
            i++;
        }
        else if(cCatCode[i]=='S'){
            printf("-");
            i++;
        }
        else if(cCatCode[i]=='M'){
            printf("*");
            i++;
        }
        else if(cCatCode[i]=='D'){
            printf("/");
            i++;
        }
        else if(cCatCode[i]=='%'){
            printf("%%");
            i++;
        }
    }
}

int main(){
    char cCatCode[] = "P ~ W(I < 10) M A I M I M X P I M I M M";

    printf("\nC Cat Code: %s\n\n", cCatCode);

    printf("Translated Code: ");

    translateCcatToEnglish(cCatCode);

    printf("}");

    return 0;
}