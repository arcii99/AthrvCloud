//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: expert-level
// C code for building a JSON parser
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
 
// defining structure for JSON object
typedef struct {
    char *key;
    void *value;
} json_obj;
 
// defining structure for JSON array
typedef struct {
    void **value;
    size_t len;
} json_arr;
 
// function to convert JSON array to string
char* json_arr_to_string(json_arr *arr);
 
// function to parse JSON object
json_obj* json_parse_obj(char *str) {
    json_obj *obj = malloc(sizeof(json_obj));
    int k_start = 0, v_start = 0;
    int len = strlen(str);
     
    // looking for the first key
    for (int i = 0; i < len; i++) {
        if (str[i] == '\"') {
            k_start = i + 1;
            break;
        }
    }
     
    // looking for the first value
    for (int i = k_start + 1; i < len; i++) {
        if (str[i] == ':') {
            v_start = i + 1;
            break;
        }
    }
     
    char *key = malloc(sizeof(char) * (k_start - 1));
    strncpy(key, str + 1, k_start - 2);
    key[k_start - 2] = '\0';
    obj->key = key;
     
    // parsing value
    char *value_str = malloc(sizeof(char) * (len - v_start - 2));
    strncpy(value_str, str + v_start, len - v_start - 2);
    obj->value = value_str;
     
    return obj;
}
 
// function to parse JSON array
json_arr* json_parse_arr(char *str) {
    json_arr *arr = malloc(sizeof(json_arr));
    int s_index = 0, e_index = 0;
    int len = strlen(str);
     
    // looking for start and end of elements in array
    for (int i = 0; i < len; i++) {
        if (str[i] == '[') {
            s_index = i + 1;
        } else if (str[i] == ']') {
            e_index = i;
            break;
        }
    }
     
    // counting the number of elements in array
    int count = 0;
    for (int i = s_index; i < e_index; i++) {
        if (str[i] == ',') {
            count++;
        }
    }
    count++;
     
    // creating array and parsing elements
    void **arr_val = malloc(sizeof(void *) * count);
    char *elem_str;
    for (int i = 0, j = s_index; i < count; i++, j++) {
        int elem_len = 0;
        for (int k = j; k < e_index; k++) {
            if (str[k] == ',') {
                elem_len = k - j;
                break;
            }
            if (k == e_index - 1) {
                elem_len = e_index - j;
            }
        }
        elem_str = malloc(sizeof(char) * elem_len);
        strncpy(elem_str, str + j, elem_len);
        elem_str[elem_len - 1] = '\0';
        arr_val[i] = elem_str;
        j += elem_len;
    }
     
    arr->value = arr_val;
    arr->len = count;
     
    return arr;
}
 
// function to convert JSON array to string
char* json_arr_to_string(json_arr *arr) {
    size_t len = 2;
    for (int i = 0; i < arr->len; i++) {
        len += strlen(arr->value[i]) + 2;
    }
    char *str = malloc(sizeof(char) * len);
    strcpy(str, "[");
    for (int i = 0; i < arr->len; i++) {
        strcat(str, "\"");
        strcat(str, arr->value[i]);
        strcat(str, "\"");
        if (i < arr->len - 1) {
            strcat(str, ",");
        }
    }
    strcat(str, "]");
    return str;
}
 
int main() {
    char *json_str = "{ \"name\": \"John\", \"age\": 30, \"city\": \"New York\" }";
    json_obj *obj = json_parse_obj(json_str);
    printf("Object: { \"%s\": \"%s\" }\n", obj->key, (char *) obj->value);
    free(obj->key);
    free(obj->value);
    free(obj);
     
    json_str = "[ \"apple\", \"banana\", \"cherry\" ]";
    json_arr *arr = json_parse_arr(json_str);
    char *str = json_arr_to_string(arr);
    printf("Array: %s\n", str);
    free(str);
    for (int i = 0; i < arr->len; i++) {
        free(arr->value[i]);
    }
    free(arr->value);
    free(arr);
     
    return 0;
}