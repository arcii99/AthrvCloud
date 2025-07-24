//FormAI DATASET v1.0 Category: Syntax parsing ; Style: authentic
#include<stdio.h>
#include<string.h>

int main(){

    char input[1000], token[100];
    int index=0, internal_index;

    printf("Enter a C Program: ");
    fgets(input,1000,stdin);

    printf("Parsed Tokens Are: \n");

    while(index < strlen(input)){

        if(input[index] == ' ' || input[index] == '\n'){

            index++;
            continue;
        
        }else if(input[index] == '(' || input[index] == ')' || input[index] == '{' || input[index] == '}' || input[index] == ';' || input[index] == ','){

            printf("%c\n",input[index]);
            index++;

        }else if(input[index] == '/'){

            index++;

            if(input[index] == '/'){
                
                while(input[index] != '\n')
                    index++;

            }else if(input[index] == '*'){

                internal_index = index + 1;
                index += 2;

                while(input[internal_index] != '*' || input[index] != '/'){
                    internal_index++;
                    index++;
                }

                index++;

            }else{

                printf("%c",input[index-1]);
                printf("%c\n",input[index]);
                index++;
            }

        }else if(input[index] == '#' || input[index] == '@'){

            printf("%c",input[index++]);

            while(input[index] != ' '){
                printf("%c",input[index++]);
            }

            printf("\n");

        }else{

            memset(token,0,sizeof(token));
            internal_index=0;

            while((input[index]>='a' && input[index]<='z') || (input[index]>='A' && input[index]<='Z') || (input[index]>='0' && input[index]<='9') || (input[index]=='_')){
                token[internal_index] = input[index];
                index++;
                internal_index++;
            } 

            printf("%s\n",token);

        }

    }

    return 0;
}