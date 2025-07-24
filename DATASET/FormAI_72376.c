//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

#define MAX_MSG_LEN 1000
#define MAX_KEY_LEN 32
#define NUM_ROUNDS 16

void round_function(uint32_t *left, uint32_t *right, uint32_t key);

int main() {
  char message[MAX_MSG_LEN];
  char key[MAX_KEY_LEN];
  
  printf("Enter message (max length %d): ", MAX_MSG_LEN-1);
  fgets(message, MAX_MSG_LEN, stdin);
  
  printf("Enter key (max length %d): ", MAX_KEY_LEN-1);
  fgets(key, MAX_KEY_LEN, stdin);
  
  // Remove newlines
  message[strcspn(message, "\n")] = 0;
  key[strcspn(key, "\n")] = 0;
  
  // Pad key with zeros if necessary
  int key_len = strlen(key);
  if (key_len < MAX_KEY_LEN) {
    memset(key + key_len, 0, MAX_KEY_LEN - key_len);
  }
  
  int msg_len = strlen(message);
  
  // Pad message with zeros if necessary
  if (msg_len % 8 != 0) {
    memset(message + msg_len, 0, 8 - (msg_len % 8));
    msg_len += 8 - (msg_len % 8);
  }
  
  // Break message into 64-bit blocks
  uint64_t *msg_blocks = (uint64_t *) message;
  int num_blocks = msg_len / 8;
  
  // Break key into 32-bit words
  uint32_t *key_words = (uint32_t *) key;
  
  // Generate round keys
  uint32_t round_keys[NUM_ROUNDS];
  for (int i = 0; i < NUM_ROUNDS; i++) {
    round_keys[i] = key_words[i % 2];
  }
  
  // Encrypt each block
  for (int i = 0; i < num_blocks; i++) {
    uint32_t left = msg_blocks[i] >> 32;
    uint32_t right = msg_blocks[i] & 0xffffffff;
    
    for (int j = 0; j < NUM_ROUNDS; j++) {
      round_function(&left, &right, round_keys[j]);
    }
    
    msg_blocks[i] = ((uint64_t) left << 32) | (uint64_t) right;
  }
  
  // Print encrypted message
  printf("Encrypted message: ");
  for (int i = 0; i < num_blocks; i++) {
    printf("%016llx", msg_blocks[i]);
  }
  printf("\n");
  
  return 0;
}

void round_function(uint32_t *left, uint32_t *right, uint32_t key) {
  uint32_t temp = *left;
  *left = *right ^ (key * (*left + 1));
  *right = temp;
}