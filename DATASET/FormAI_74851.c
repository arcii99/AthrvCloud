//FormAI DATASET v1.0 Category: Syntax parsing ; Style: decentralized
#include<stdio.h>
#include<string.h>

void program_header(){

     printf("***************************************\n");
     printf("*****  C Syntax Parsing Example ******\n");
     printf("***************************************\n");

}

void check_variable_declaration(char* line){

   char* variable_type;
   char* variable_name;
   char* remaining_line;
   char* token;

   variable_type = strtok(line, " ");
   variable_name = strtok(NULL, " ");
   remaining_line = strtok(NULL, " ");

   while(remaining_line != NULL){

       token = strtok(NULL, " ");
       
       if(strcmp(token, ";") == 0){
     
          printf("Variable Declaration -> Type: %s Name: %s\n", variable_type, variable_name);   
          break;
       }
   
       if(strcmp(token, ",") == 0){
          variable_name = strtok(NULL, " ");
        }
   }
}

void check_function_declaration(char* line){

    char* function_type;
    char* function_name;
    char* remaining_line;
    char* token;

    function_type = strtok(line, " ");
    function_name = strtok(NULL, " ");
    remaining_line = strtok(NULL, "(");

    printf("Function Declaration -> Return Type: %s Name: %s\n", function_type, function_name);

    token = strtok(NULL, ")");

    while(token != NULL){

        if(strcmp(token, "void") == 0) break;
        
        if(strcmp(token, ",") == 0){
            token = strtok(NULL, " ");
        }

        printf("Function Declaration -> Parameter: %s\n", token);
        
        token = strtok(NULL, ")");
    }
}

int main(){

    program_header();

    char line1[100] = "int x, y, z;";
    char line2[100] = "char* string_processing(char* str, int len);";
    char line3[100] = "float float_processing(float x, float y, int z);";

    check_variable_declaration(line1);
    check_function_declaration(line2);
    check_function_declaration(line3);

    return 0;
}