//FormAI DATASET v1.0 Category: Encryption ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
  char data;
  struct Node * next;
}node;

void encrypt(node * head, char * key){
  int length = strlen(key);
  int i, j;
  for(i = 0; i < length; i++){
    for(j = i+1; j < length; j++){
      if(key[i] > key[j]){
        char temp = key[i];
        key[i] = key[j];
        key[j] = temp;
      }
    }
  }
  node * current = head;
  int k = 0;
  while(current != NULL){
    current->data = current->data ^ key[k % length];
    current = current->next;
    k++;
  }
}

void decrypt(node * head, char * key){
  int length = strlen(key);
  int i, j;
  for(i = 0; i < length; i++){
    for(j = i+1; j < length; j++){
      if(key[i] > key[j]){
        char temp = key[i];
        key[i] = key[j];
        key[j] = temp;
      }
    }
  }
  node * current = head;
  int k = 0;
  while(current != NULL){
    current->data = current->data ^ key[k % length];
    current = current->next;
    k++;
  }
}

int main(){
  char message[] = "this is a secret message"; //message to encrypt
  char key[] = "encryption"; //encryption key
  int length = strlen(message);

  node * head = NULL;
  node * tail = NULL;

  int i;
  for(i = 0; i < length; i++){
    node * temp = malloc(sizeof(node));
    temp->data = message[i];
    temp->next = NULL;
    if(head == NULL){
      head = temp;
      tail = temp;
    }
    else{
      tail->next = temp;
      tail = tail->next;
    }
  }

  encrypt(head, key);

  printf("Encrypted message: ");
  node * current = head;
  while(current != NULL){
    printf("%c", current->data);
    current = current->next;
  }

  printf("\n");

  decrypt(head, key);

  printf("Decrypted message: ");
  current = head;
  while(current != NULL){
    printf("%c", current->data);
    current = current->next;
  }

  printf("\n");

  return 0;
}