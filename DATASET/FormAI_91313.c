//FormAI DATASET v1.0 Category: Data mining ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
  char secret_data[] = "CmZzExWYuCpY,HmZxGgXwCqZy";
  int key = 5;
  int len = strlen(secret_data);

  char* plain_data = (char*)malloc(sizeof(char)*len);

  for(int i=0;i<len;i++){
    if(i%2==0)
      plain_data[i] = secret_data[i]+key;
    else
      plain_data[i] = secret_data[i]-key;
  }

  printf("The encrypted data: %s\n",secret_data);
  printf("The decrypted data: %s\n",plain_data);

  FILE* fp;
  fp = fopen("encrypted_data.txt","w");
  fputs(secret_data,fp);
  fclose(fp);

  fp = fopen("decrypted_data.txt","w");
  fputs(plain_data,fp);
  fclose(fp);

  free(plain_data);

  return 0;
}