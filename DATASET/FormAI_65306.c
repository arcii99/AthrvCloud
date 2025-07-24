//FormAI DATASET v1.0 Category: File Encyptor ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(char *input, char *output){
  int i, key = 3;
  char ch;
  FILE *f_in, *f_out;
  f_in = fopen(input, "r");
  f_out = fopen(output, "w");
  while ((ch = fgetc(f_in)) != EOF){
    ch = ch + key;
    fputc(ch, f_out);
  }
  fclose(f_in);
  fclose(f_out);
}

void decrypt(char *input, char *output){
  int i, key = 3;
  char ch;
  FILE *f_in, *f_out;
  f_in = fopen(input, "r");
  f_out = fopen(output, "w");
  while ((ch = fgetc(f_in)) != EOF){
    ch = ch - key;
    fputc(ch, f_out);
  }
  fclose(f_in);
  fclose(f_out);
}

int main(){
  char input[50], output[50];
  printf("Enter the name of file to be encrypted: ");
  scanf("%s", input);
  printf("Enter the name of output file: ");
  scanf("%s", output);
  encrypt(input, output);
  printf("File Encrypted Successfully!!\n");
  printf("Enter the name of file to be decrypted: ");
  scanf("%s", input);
  printf("Enter the name of output file: ");
  scanf("%s", output);
  decrypt(input, output);
  printf("File Decrypted Successfully!!\n");
  return 0;
}