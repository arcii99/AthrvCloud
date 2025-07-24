//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARS 256

typedef struct {
    char key[MAX_CHARS];
    char value[MAX_CHARS];
} KVPair;

typedef struct {
    KVPair *pairs;
    size_t count;
} JSONObject;

char *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("fopen");
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    long len = ftell(file);
    rewind(file);
    char *content = (char *) malloc(len + 1);
    if (!content) {
        fclose(file);
        perror("malloc");
        return NULL;
    }
    size_t read_len = fread(content, 1, len, file);
    if (read_len < len) {
        fclose(file); 
        free(content);
        perror("fread");
        return NULL;
    }
    content[len] = '\0';
    fclose(file);
    return content;
}

int skip_whitespace(const char *json, int start) {
    while (isspace(json[start])) {
        start++;
    }
    return start;
}

int find_next_unescaped(const char *json, char target, int start) {
    while (json[start] && json[start] != target) {
        if (json[start] == '\\' && json[start + 1]) {
            start += 2;
        } else {
            start++;
        }
    }
    return json[start] == target ? start : -1;
}

KVPair parse_kvpair(const char *json, int start) {
    KVPair pair;
    start = skip_whitespace(json, start);
    int end_key = find_next_unescaped(json, ':', start);
    strncpy(pair.key, json+start, end_key-start);
    pair.key[end_key-start] = '\0';
    start = end_key + 1;
    int end_value = find_next_unescaped(json, ',', start);
    if (end_value == -1) {
        end_value = strlen(json) - 1;
    }
    strncpy(pair.value, json+start, end_value-start);
    pair.value[end_value-start] = '\0';
    return pair;
}

JSONObject parse_json(const char *json) {
    JSONObject object = {NULL, 0};
    int pos = skip_whitespace(json, 0);
    if (json[pos] != '{') {
        fprintf(stderr, "Expected '{' at start of JSON object\n");
        return object;
    }
    pos++;
    while (json[pos] && json[pos] != '}') {
        KVPair pair = parse_kvpair(json, pos);
        pos = skip_whitespace(json, pos);
        object.pairs = (KVPair *) realloc(object.pairs, (++object.count) * sizeof(KVPair));
        object.pairs[object.count - 1] = pair;
        if (json[pos] == ',') {
            pos++;
        }
    }
    if (json[pos] != '}') {
        fprintf(stderr, "Expected '}' at end of JSON object\n");
    }        
    return object;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: json_parser filename\n");
        return 1;
    }
    char *content = read_file(argv[1]);
    if (!content) {
        return 1;
    }
    JSONObject object = parse_json(content);
    printf("{\n");
    for (int i=0; i<object.count; i++) {
        printf("  \"%s\": \"%s\"", object.pairs[i].key, object.pairs[i].value);
        if (i != object.count - 1) {
            printf(",");
        }
        printf("\n");
    }
    printf("}\n");
    free(content);
    free(object.pairs);
    return 0;
}