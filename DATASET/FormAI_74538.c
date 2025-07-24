//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Donald Knuth
#include <stdio.h>

void compress(char *inbuf, int inlen, char *outbuf, int *outlen) {
  int i, j;
  int lastchar, runlength;

  *outlen = 0;
  lastchar = inbuf[0];
  runlength = 1;

  for (i = 1; i < inlen; i++) {
    if (inbuf[i] == lastchar) {
      runlength++;
    } else {
      outbuf[*outlen] = lastchar;
      outbuf[*outlen + 1] = runlength;
      *outlen += 2;
      lastchar = inbuf[i];
      runlength = 1;
    }
  }

  outbuf[*outlen] = lastchar;
  outbuf[*outlen + 1] = runlength;
  *outlen += 2;
}

void decompress(char *inbuf, int inlen, char *outbuf, int *outlen) {
  int i, j;
  int charcode, runlength;

  *outlen = 0;

  for (i = 0; i < inlen; i += 2) {
    charcode = inbuf[i];
    runlength = inbuf[i + 1];
    for (j = 0; j < runlength; j++) {
      outbuf[*outlen] = charcode;
      *outlen += 1;
    }
  }
}

int main() {
  char inbuf[] = "AAABBBCCCDDDEEEE";
  char outbuf[256];
  int outlen;

  compress(inbuf, 15, outbuf, &outlen);

  printf("Compressed data: ");
  for (int i = 0; i < outlen; i++) {
    printf("%d ", outbuf[i]);
  }
  printf("\n");

  char result[256];
  int resultlen;
  decompress(outbuf, outlen, result, &resultlen);

  printf("Decompressed data: ");
  for (int i = 0; i < resultlen; i++) {
    printf("%c", result[i]);
  }
  printf("\n");

  return 0;
}