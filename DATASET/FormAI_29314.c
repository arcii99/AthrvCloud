//FormAI DATASET v1.0 Category: Encryption ; Style: active
#include <stdio.h>

int main() {
  char str[100];
  int key, i;

  printf("Enter a string to encrypt: ");
  fgets(str, 100, stdin);

  printf("Enter key to encrypt the string: ");
  scanf("%d", &key);

  printf("Encrypted string: ");

  for(i=0; str[i]!='\0'; i++) {
    if(str[i] >= 'a' && str[i] <= 'z') {
      str[i] = ((str[i] - 'a' + key) % 26) + 'a';
    } else if(str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = ((str[i] - 'A' + key) % 26) + 'A';
    }
    printf("%c", str[i]);
  }

  return 0;
}