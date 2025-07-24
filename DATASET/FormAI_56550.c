//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct json_node {
   char *key;
   enum {OBJ, ARRAY, STRING, INTEGER, FLOAT, BOOL, NIL} type;
   union {
      struct json_node **nodes;
      char *string_val;
      int integer_val;
      float float_val;
      int bool_val;
   } value;
} json_node;

json_node *parse_json(const char *json);

static size_t SkipWhitespace(const char *str, size_t index) {
  while (index < strlen(str) && isspace(str[index])) ++index;
  return index;
}

static size_t ParseJsonString(const char *str, size_t index, char **out_str) {
   size_t len = 0; ++index;  // skip opening quote
   while (str[index+len] != '\"') {
      if (str[index + len] == '\\') len++;  // skip past backslash
      len++;
   }
   *out_str = malloc(len + 1);
   memcpy(*out_str, &str[index], len);
   (*out_str)[len] = '\0';  // null terminate new string
   return index + len + 1;  // include closing quote
}

json_node *parse_json(const char *json) {
   size_t index = SkipWhitespace(json, 0);
   json_node *node = malloc(sizeof(json_node));
   node->key = NULL;
   if (json[index] == '\"') {  // parse string
      node->type = STRING;
      index = ParseJsonString(json, index, &node->value.string_val);
   } else if (isdigit(json[index]) || json[index] == '-') {  // parse number
      char *end;
      if (strchr(json, '.') || strchr(json, 'e') || strchr(json, 'E')) {
         node->type = FLOAT;
         node->value.float_val = strtof(&json[index], &end);
      } else {
         node->type = INTEGER;
         node->value.integer_val = strtol(&json[index], &end, 10);
      }
      index = end - json;
   } else if (json[index] == '[') {  // parse array
      node->type = ARRAY;
      index = SkipWhitespace(json, index+1);
      node->value.nodes = malloc(sizeof(json_node*) * 8);  // start with allocation of 8 array members
      size_t node_count = 0;
      while (json[index] != ']') {
         node->value.nodes[node_count++] = parse_json(&json[index]);
         index = SkipWhitespace(json, index + 1);
         if (json[index] == ',') ++index;  // skip past comma
         else if (json[index] != ']') { printf("Invalid array format."); exit(1); }
         if (node_count % 8 == 0) {  // realloc some more space for every 8 nodes.
            node->value.nodes = realloc(node->value.nodes, sizeof(json_node*) * (node_count + 8));
         }
      }
      node->value.nodes = realloc(node->value.nodes, sizeof(json_node*) * node_count);
   } else if (json[index] == '{') {  // parse object
      node->type = OBJ;
      index = SkipWhitespace(json, index+1);
      node->value.nodes = malloc(sizeof(json_node*) * 8);  // start with allocation of 8 node members
      size_t node_count = 0;
      while (json[index] != '}') {
         node->value.nodes[node_count] = malloc(sizeof(json_node));
         node->value.nodes[node_count]->key = NULL;
         while (json[index] != '\"') ++index;  // find opening key quote
         index = ParseJsonString(json, index, &node->value.nodes[node_count]->key);
         index = SkipWhitespace(json, index);
         if (json[index++] != ':') { printf("Invalid object format."); exit(1); }
         node->value.nodes[node_count]->type = NIL;
         index = SkipWhitespace(json, index);
         node->value.nodes[node_count]->value.nodes = malloc(sizeof(json_node*) * 8);  // start with allocation of 8 node members
         if (json[index] == '{' || json[index] == '[') {  // value is another object or array
            node->value.nodes[node_count]->value.nodes[0] = parse_json(&json[index]);
            node->value.nodes[node_count]->type = (json[index] == '{') ? OBJ : ARRAY;
         } else if (json[index] == '\"') {  // value is a string
            node->value.nodes[node_count]->type = STRING;
            index = ParseJsonString(json, index, &node->value.nodes[node_count]->value.string_val);
         } else if (isdigit(json[index]) || json[index] == '-') {  // value is a number
            char *end;
            if (strchr(json, '.') || strchr(json, 'e') || strchr(json, 'E')) {
               node->value.nodes[node_count]->type = FLOAT;
               node->value.nodes[node_count]->value.float_val = strtof(&json[index], &end);
            } else {
               node->value.nodes[node_count]->type = INTEGER;
               node->value.nodes[node_count]->value.integer_val = strtol(&json[index], &end, 10);
            }
            index = end - json;
         } else if (!strncmp(&json[index], "true", 4)) {  // value is a true bool
            node->value.nodes[node_count]->type = BOOL;
            node->value.nodes[node_count]->value.bool_val = 1;
            index += 4;
         } else if (!strncmp(&json[index], "false", 5)) {  // value is a false bool
            node->value.nodes[node_count]->type = BOOL;
            node->value.nodes[node_count]->value.bool_val = 0;
            index += 5;
         } else if (!strncmp(&json[index], "null", 4)) {  // value is a null value
            index += 4;
         } else { printf("Invalid object format."); exit(1); }
         ++node_count;
         index = SkipWhitespace(json, index);
         if (json[index] == ',') ++index;  // skip past comma
         else if (json[index] != '}') { printf("Invalid object format."); exit(1); }
         if (node_count % 8 == 0) {  // realloc some more space for every 8 nodes.
            node->value.nodes = realloc(node->value.nodes, sizeof(json_node*) * (node_count + 8));
         }
      }
      node->value.nodes = realloc(node->value.nodes, sizeof(json_node*) * node_count);
   } else {
      printf("Invalid JSON format.");
      exit(1);
   }
   return node;
}

int main() {
   const char *json = "{\"name\": \"John Doe\", \"age\": 36, \"gender\": \"male\", \"children\": [\"Jane\", \"Janice\"], \"address\": {\"street\": \"123 Main St.\", \"city\": \"Anywhere\", \"state\": \"NY\"}, \"pet\": null}";
   json_node *root = parse_json(json);
   printf("Name: %s\n", root->value.nodes[0]->value.string_val);
   printf("Age: %d\n", root->value.nodes[1]->value.integer_val);
   printf("Gender: %s\n", root->value.nodes[2]->value.string_val);
   printf("Children: %s, %s\n", root->value.nodes[3]->value.nodes[0]->value.string_val, root->value.nodes[3]->value.nodes[1]->value.string_val);
   printf("Street: %s\n", root->value.nodes[4]->value.nodes[0]->value.string_val);
   printf("City: %s\n", root->value.nodes[4]->value.nodes[1]->value.string_val);
   printf("State: %s\n", root->value.nodes[4]->value.nodes[2]->value.string_val);
   printf("Pet: %s\n", (root->value.nodes[5]->type == NIL) ? "none" : "unknown");
   return 0;
}