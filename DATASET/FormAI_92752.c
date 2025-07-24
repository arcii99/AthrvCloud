//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: secure
#include <stdio.h>
#include <stdint.h>

/* Calculate CRC32 checksum. */
uint32_t crc32(const uint8_t *buf, size_t size)
{
  uint32_t crc = 0xffffffff;
  while (size--)
  {
    crc ^= *buf++;
    for (size_t j = 0; j < 8; ++j)
      crc = (crc >> 1) ^ (0xedb88320 & (-(int32_t)(crc & 1)));
  }
  return ~crc;
}

int main()
{
  printf("Enter a message to calculate CRC32 checksum: ");

  /* Read user input message. */
  char message[1000];
  fgets(message, sizeof(message), stdin);

  /* Remove newline character from message. */
  size_t len = strlen(message);
  if (len > 0 && message[len-1] == '\n')
    message[len-1] = '\0';

  /* Calculate checksum. */
  uint32_t checksum = crc32((uint8_t *)message, len);

  /* Print checksum. */
  printf("Checksum: 0x%08x\n", checksum);

  return 0;
}