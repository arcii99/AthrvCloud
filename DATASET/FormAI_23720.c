//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <openssl/md5.h>

int main()
{
  unsigned char *input = "This is just a test";
  unsigned char output[MD5_DIGEST_LENGTH];
  int i;

  MD5(input, strlen(input), output);

  printf("The input string is: %s\n", input);
  printf("The output hash is: ");

  for(i = 0; i < MD5_DIGEST_LENGTH; i++)
    printf("%02x", output[i]);

  printf("\n");

  return 0;
}