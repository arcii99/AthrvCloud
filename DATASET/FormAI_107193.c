//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char key[16];
    char value[128];
} KeyValue;

typedef struct {
    KeyValue values[32];
    size_t size;
} Json;

int get_key_value(char* src, size_t length, KeyValue* kv) {
    char* p = strchr(src, '"');
    if (!p) {
        return -1;
    }
    src = p + 1;
    p = strchr(src, '"');
    if (!p) {
        return -1;
    }
    size_t key_size = p - src;
    if (key_size > sizeof(kv->key) - 1) {
        return -1;
    }
    memcpy(kv->key, src, key_size);
    kv->key[key_size] = '\0';

    src = p + 1;
    p = strchr(src, '"');
    if (!p) {
        return -1;
    }
    src = p + 1;
    p = strchr(src, '"');
    if (!p) {
        return -1;
    }
    size_t value_size = p - src;
    if (value_size > sizeof(kv->value) - 1) {
        return -1;
    }
    memcpy(kv->value, src, value_size);
    kv->value[value_size] = '\0';

    return key_size + value_size + 4;
}

int parse_json(char* src, size_t length, Json* json) {
    char* p = strchr(src, '{');
    if (!p) {
        return -1;
    }
    src = p + 1;
    while (*src != '}') {
        if (json->size == sizeof(json->values) / sizeof(*json->values)) {
            return -1;
        }
        int size = get_key_value(src, length - (src - src), &json->values[json->size]);
        if (size < 0) {
            return -1;
        }
        json->size++;
        src += size;
        p = strchr(src, ',');
        if (!p) {
            break;
        }
        src = p + 1;
    }
    return 0;
}

int main() {
    char src[] = "{\"name\":\"Bob\",\"age\":25,\"address\":\"123 Main St\",\"city\":\"New York\"}";
    Json json;
    memset(&json, 0, sizeof(json));
    if (parse_json(src, sizeof(src) - 1, &json) == 0) {
        for (size_t i = 0; i < json.size; i++) {
            KeyValue* kv = &json.values[i];
            printf("%s: %s\n", kv->key, kv->value);
        }
    }
    return 0;
}