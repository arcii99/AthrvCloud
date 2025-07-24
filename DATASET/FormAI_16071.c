//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: retro
#include <stdio.h>
#include <string.h>

// Function to translate from C Cat language
void cat_to_c(char* input) {
  char output[200] = ""; 
  int len = strlen(input);
  for(int i = 0; i < len; i++) {
    if(input[i] == 'm') {
      strcat(output, "int ");
    }
    else if(input[i] == 'p') {
      strcat(output, "printf(\"%d\\n\", ");
    }
    else if(input[i] == 'c') {
      strcat(output, "char ");
    }
    else if(input[i] == 'd') {
      strcat(output, "double ");
    }
    else if(input[i] == 'f') {
      strcat(output, "float ");
    }
    else if(input[i] == 's') {
      strcat(output, "scanf(\"%d\", ");
    }
    else if(input[i] == 'l') {
      strcat(output, "long ");
    }
    else {
      strcat(output, " ");
      strncat(output, &input[i], 1);
    }
  }
  printf("%s\n", output);
}

int main() {
  char code[200] = "mhelloworldp";
  cat_to_c(code); // Output: int helloworld printf("%d\n", );
  
  char code_2[200] = "cmy_name[20]s";
  cat_to_c(code_2); // Output: char my_name[20] scanf("%d", );
  
  char code_3[200] = "dresultf";
  cat_to_c(code_3); // Output: double result float
  
  char code_4[200] = "lcounteri";
  cat_to_c(code_4); // Output: long counter int
  
  return 0;
}