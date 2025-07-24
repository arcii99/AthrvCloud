//FormAI DATASET v1.0 Category: File Encyptor ; Style: minimalist
#include<stdio.h>
#include<string.h>

#define MAX 10000

void encrypt(char * fileName, int key);

int main(int argc, char * argv[]) {
  if(argc<3) {
    printf("Usage: ./encrypt <filename> <encryption key>\n");
    return 1;
  }
  
  char fileName[MAX];
  strncpy(fileName, argv[1], MAX);
  int key = atoi(argv[2]);
  
  encrypt(fileName, key);
  
  printf("The file has been successfully encrypted!\n");
  
  return 0;
}

void encrypt(char * fileName, int key) {
  FILE * fpIn = fopen(fileName, "rb");
  FILE * fpOut = fopen(strcat(fileName, ".enc"), "wb");
  
  if(fpIn==NULL || fpOut==NULL) {
    printf("Error: Unable to open file!\n");
    return;
  }
  
  int ch;
  while((ch=getc(fpIn))!=EOF) {
    ch = ch + key;
    putc(ch, fpOut);
  }
  
  fclose(fpIn);
  fclose(fpOut);
}