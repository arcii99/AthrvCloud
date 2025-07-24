//FormAI DATASET v1.0 Category: Syntax parsing ; Style: immersive
#include<stdio.h>
int main(){
  //Welcome Message
  printf("Welcome to C Syntax parser!\n");
  printf("Please input your code below\n");

  //Taking input from user
  char code[1000];
  fgets(code, 1000, stdin);

  //Removing unnecessary whitespaces
  int i=0, j=0;
  while(code[i]!='\0'){
    if(code[i]==' '){
        if(code[i+1]!=' ' && j!=0){
            code[j]=code[i];
            j++;
        }
    }else{
        code[j]=code[i];
        j++;
    }
    i++;
  }
  code[j]='\0';
  printf("Code after removing unnecessary spaces:\n%s\n", code);
  
  //Checking for opening and closing braces
  int count=0;
  for(int i=0; code[i]!='\0'; i++){
    if(code[i]=='{'){
        count++;
    }else if(code[i]=='}'){
        count--;
    }
  }
  if(count!=0){
    printf("Syntax Error: Braces not balanced\n");
    return 0;
  }
  printf("Opening and closing braces are balanced\n");

  //Checking for semicolons at the end of each statement
  for(int i=0; code[i]!='\0'; i++){
    if(code[i]==';'){
        if((code[i+1]<'a' || code[i+1]>'z') && (code[i+1]<'A' || code[i+1]>'Z')){
            printf("Syntax Error: Semicolon not at the end of statement\n");
            return 0;
        }else{
            i++;
        }
    }
  }
  printf("Semicolons are at the end of each statement\n");

  //Checking for syntax errors in conditional statements
  for(int i=0; code[i]!='\0'; i++){
    if(code[i]=='i' && code[i+1]=='f' && (code[i+2]<'a' || code[i+2]>'z') && (code[i+2]<'A' || code[i+2]>'Z')&& code[i+2]!=' '){
        i+=2;
        while(code[i]==' ') i++;
        if(code[i]!='('){
            printf("Syntax Error: If statement syntax not matched\n");
            return 0;
        }
        i++;
        while(code[i]==' ') i++;
        int bracket_count=1;
        while(bracket_count!=0){
            if(code[i]=='(') bracket_count++;
            else if(code[i]==')') bracket_count--;
            i++;
        }
        i--;
        while(code[i]==' ') i++;
        if((code[i]!='{' && (code[i+1]<'a' || code[i+1]>'z') && (code[i+1]<'A' || code[i+1]>'Z')) || (code[i]=='{' && code[i+1]!='}')){
            printf("Syntax Error: If statement syntax not matched\n");
            return 0;
        }
    }
  }
  printf("If statement syntax matched\n");

  //Checking for syntax errors in loops
  for(int i=0; code[i]!='\0'; i++){
    if(code[i]=='f'&&code[i+1]=='o'&&code[i+2]=='r'&&(code[i+3]<'a'||code[i+3]>'z')&&(code[i+3]<'A'||code[i+3]>'Z')&&code[i+3]!=' '){
        i+=3;
        while(code[i]==' ') i++;
        if(code[i]!='('){
            printf("Syntax Error: For loop syntax not matched\n");
            return 0;
        }
        i++;
        while(code[i]==' ') i++;
        if((code[i]<'a'||code[i]>'z')&&(code[i]<'A'||code[i]>'Z')){
            printf("Syntax Error: For loop syntax not matched\n");
            return 0;
        }
        while(code[i]!=';') i++;
        i++;
        while(code[i]==' '||code[i]==';') i++;
        if((code[i]<'a'||code[i]>'z')&&(code[i]<'A'||code[i]>'Z')){
            printf("Syntax Error: For loop syntax not matched\n");
            return 0;
        }
        while(code[i]!=';') i++;
        i++;
        while(code[i]==' ') i++;
        if(code[i]<'0'||code[i]>'9'){
            printf("Syntax Error: For loop syntax not matched\n");
            return 0;
        }
        while(code[i]>='0'&&code[i]<='9') i++;
        while(code[i]==' ') i++;
        if(code[i]==';') i++;
        while(code[i]==' ') i++;
        if((code[i]<'a'||code[i]>'z')&&(code[i]<'A'||code[i]>'Z')){
            printf("Syntax Error: For loop syntax not matched\n");
            return 0;
        }
        while(code[i]!=' '&&code[i]!='\n'&&code[i]!='\0') i++;
        if(code[i]!=' '){
            printf("Syntax Error: For loop syntax not matched\n");
            return 0;
        }
        while(code[i]==' ') i++;
        if(code[i]!=')'){
            printf("Syntax Error: For loop syntax not matched\n");
            return 0;
        }
        i++;
        while(code[i]==' ') i++;
        if(code[i]!='{'&&(code[i]<'a'||code[i]>'z')&&(code[i]<'A'||code[i]>'Z')){
            printf("Syntax Error: For loop syntax not matched\n");
            return 0;
        }else if(code[i]=='{'){
            i++;
            while(code[i]!='\0'){
                if(code[i]=='}') break;
                i++;
            }
            if(code[i]!='}'){
                printf("Syntax Error: For loop syntax not matched\n");
                return 0;
            }
        }
    }
  }
  printf("For loop syntax matched\n");

  //Checking for syntax errors in functions
  for(int i=0; code[i]!='\0'; i++){
    if(code[i]=='f'&&code[i+1]=='u'&&code[i+2]=='n'&&code[i+3]=='c'&&(code[i+4]<'a'||code[i+4]>'z')&&(code[i+4]<'A'||code[i+4]>'Z')&&code[i+4]!=' '){
        i+=4;
        while(code[i]==' ') i++;
        if((code[i]<'a'||code[i]>'z')&&(code[i]<'A'||code[i]>'Z')){
            printf("Syntax Error: Function syntax not matched\n");
            return 0;
        }
        while(code[i]!='('&&code[i]!='\0') i++;
        if(code[i]=='\0'){
            printf("Syntax Error: Function syntax not matched\n");
            return 0;
        }
        i++;
        while(code[i]==' ') i++;
        if((code[i]<'a'||code[i]>'z')&&(code[i]<'A'||code[i]>'Z')){
            printf("Syntax Error: Function syntax not matched\n");
            return 0;
        }
        while(code[i]!=')'&&code[i]!='\0'){
            i++;
            if(code[i]=='\0'){
                printf("Syntax Error: Function syntax not matched\n");
                return 0;
            }
        }
        i++;
        while(code[i]=='\n'||code[i]==' '){
            i++;
            if(code[i]=='\0'){
                printf("Syntax Error: Function syntax not matched\n");
                return 0;
            }
        }
        if(code[i]!='{'){
            printf("Syntax Error: Function syntax not matched\n");
            return 0;
        }
        i++;
        int brace_count=1;
        while(brace_count!=0){
            if(code[i]=='{'){
                brace_count++;
            }else if(code[i]=='}'){
                brace_count--;
            }
            i++;
        }
        while(code[i+1]=='\n'||code[i+1]==' '){
            i++;
            if(code[i]=='\0'){
                break;
            }
        }
        if(code[i+1]!='\0'){
            printf("Syntax Error: Function syntax not matched\n");
            return 0;
        }
    }
  }
  printf("Function syntax matched\n");

  //If no syntax errors are found, the program continues
  printf("Your code has passed through the syntax parser!\n");
  return 0;
}