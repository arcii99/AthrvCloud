//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to compute the checksum of a given file
int checksum(char* file) {
  FILE *fp;
  fp = fopen(file, "rb");
  if(fp == NULL) {
    printf("File not found!\n");
    exit(1);
  }
  
  unsigned int sum = 0;
  unsigned char buffer[1024];
  size_t count;
  while((count = fread(buffer, 1, 1024, fp)) > 0) {
    for(size_t i=0; i<count; i++) {
      sum = (sum << 1) + buffer[i];
      sum += sum >> 16;
    }
  }
  
  fclose(fp);
  return sum & 0xFFFF;
}

// Function to determine if a given file is infected with a C virus
int scan(char* file) {
  int sum = checksum(file);
  if(sum == 0x1234 || sum == 0x5678) {
    return 1;
  }
  return 0;
}

int main(int argc, char* argv[]) {
  if(argc != 2) {
    printf("Usage: antivirus <file>\n");
    return 1;
  }
  
  int isInfected = scan(argv[1]);
  if(isInfected) {
    printf("Infected file found!\n");
  } else {
    printf("File is clean.\n");
  }
  
  return 0;
}