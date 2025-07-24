//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct JSON_Object JSON_Object;
typedef struct JSON_Array JSON_Array;

struct JSON_Object {
  char *key;
  char *value;
};

struct JSON_Array {
  JSON_Object *objects;
  int size;
};

void parse_object(JSON_Object *obj, char *str);
void parse_array(JSON_Array *arr, char *str);

int main() {
  char str[] = "{ \"name\": \"John\", \"age\": 30, \"city\": \"New York\", \"hobbies\": [\"reading\", \"sports\", \"gaming\"] }";
  
  JSON_Object obj[4];
  JSON_Array arr;

  parse_object(obj, str);
  parse_array(&arr, str);

  printf("Object:\n");

  for(int i = 0; i < 4; i++) {
    printf("Key: %s\n", obj[i].key);
    printf("Value: %s\n", obj[i].value);
  }

  printf("Array:\n");

  for(int i = 0; i < arr.size; i++) {
    printf("%d: Key: %s\n", i, arr.objects[i].key);
    printf("%d: Value: %s\n", i, arr.objects[i].value);
  }

  return 0;
}

void parse_object(JSON_Object *obj, char *str) {
  char *token;
  const char delim[] = "{},:\"";
  token = strtok(str, delim);
  int count = 0;

  while(token != NULL) {
    if(strcmp(token, "name") == 0 || strcmp(token, "age") == 0 ||
      strcmp(token, "city") == 0) {
        obj[count].key = token;
        token = strtok(NULL, delim);
        obj[count].value = token;
        token = strtok(NULL, delim);
        count++;
    } else {
      token = strtok(NULL, delim);
    }
  }
}

void parse_array(JSON_Array *arr, char *str) {
  char *token;
  const char delim[] = "{},:\"";
  token = strtok(str, delim);
  int count = 0;

  while(token != NULL) {
    if(strcmp(token, "hobbies") == 0) {
      arr->objects = (JSON_Object*)malloc(sizeof(JSON_Object) * 2);
      token = strtok(NULL, delim);
      int i = 0;
      while(token != NULL && strcmp(token, "]") != 0) {
        arr->objects[i].key = "";
        arr->objects[i].value = token;
        token = strtok(NULL, delim);
        if(strcmp(token, ",") == 0) {
          token = strtok(NULL, delim);
        }
        i++;
      }
      arr->size = i;
      break;
    } else {
      token = strtok(NULL, delim);
    }
  }
}