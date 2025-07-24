//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARR_LEN 1000
#define MAX_OBJ_LEN 1000
#define MAX_KEY_LEN 100
#define MAX_VAL_LEN 100

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOLEAN,
    JSON_NULL
} json_type_t;

typedef union {
    char* string;
    double number;
    int boolean;
} json_value_t;

typedef struct {
    json_type_t type;
    json_value_t value;
} json_elem_t;

typedef struct {
    char* key;
    json_elem_t value;
} json_pair_t;

void parse_json(char* json_str);

int main() {
    char json_str[MAX_ARR_LEN] = "{\"name\": \"John\", \"age\": 25, \"isStudent\": true, \"subjects\": [\"Math\", \"Science\"]}";
    parse_json(json_str);
    return 0;
}

void parse_json(char *json_str) {
    json_pair_t json_obj[MAX_OBJ_LEN];
    int obj_cnt = 0;
    json_elem_t json_arr[MAX_ARR_LEN];
    int arr_cnt = 0;
    
    int cur_pos = 0;

    while(json_str[cur_pos] != '\0' && cur_pos < MAX_ARR_LEN) {
        if(json_str[cur_pos] == '{') {
            // Object start
            cur_pos++;
            while(json_str[cur_pos] != '}' && json_obj[obj_cnt].key != NULL) {
                char key[MAX_KEY_LEN] = "";
                json_elem_t value;

                // Read key
                while(json_str[cur_pos] != ':') {
                    if(json_str[cur_pos] == '"') {
                        cur_pos++;
                        while(json_str[cur_pos] != '"') {
                            char c[2] = {json_str[cur_pos], '\0'};
                            strcat(key, c);
                            cur_pos++;
                        }
                    }
                    cur_pos++;
                }
                json_obj[obj_cnt].key = key;

                // Read value
                cur_pos++;
                if(json_str[cur_pos] == '"') {
                    // String
                    char val[MAX_VAL_LEN] = "";
                    cur_pos++;
                    while(json_str[cur_pos] != '"') {
                        char c[2] = {json_str[cur_pos], '\0'};
                        strcat(val, c);
                        cur_pos++;
                    }
                    value.type = JSON_STRING;
                    value.value.string = val;
                } else if(json_str[cur_pos] >= '0' && json_str[cur_pos] <= '9') {
                    // Number
                    char val[MAX_VAL_LEN] = "";
                    int i = 0;
                    while((json_str[cur_pos] >= '0' && json_str[cur_pos] <= '9') || json_str[cur_pos] == '.') {
                        char c[2] = {json_str[cur_pos], '\0'};
                        strcat(val, c);
                        cur_pos++;
                        i++;
                    }
                    value.type = JSON_NUMBER;
                    value.value.number = atof(val);
                } else if(json_str[cur_pos] == 't' || json_str[cur_pos] == 'f') {
                    // Boolean
                    char val[MAX_VAL_LEN] = "";
                    if(json_str[cur_pos] == 't') {
                        strcat(val, "true");
                        cur_pos += 4;
                        value.type = JSON_BOOLEAN;
                        value.value.boolean = 1;
                    } else {
                        strcat(val, "false");
                        cur_pos += 5;
                        value.type = JSON_BOOLEAN;
                        value.value.boolean = 0;
                    }
                } else if(json_str[cur_pos] == '{') {
                    // Nested object
                    int nested_obj_start = cur_pos;
                    int nested_obj_end = cur_pos;
                    int nested_obj_count = 1;

                    while(nested_obj_count != 0) {
                        nested_obj_end++;
                        if(json_str[nested_obj_end] == '{')
                            nested_obj_count++;
                        else if(json_str[nested_obj_end] == '}')
                            nested_obj_count--;
                    }

                    char* nested_obj_str = malloc(nested_obj_end - nested_obj_start + 1);
                    strncpy(nested_obj_str, json_str + nested_obj_start, nested_obj_end - nested_obj_start + 1);
                    nested_obj_str[nested_obj_end - nested_obj_start] = '\0';

                    value.type = JSON_OBJECT;
                    // Recursively parse nested object
                    parse_json(nested_obj_str);
                } else if(json_str[cur_pos] == '[') {
                    // Array
                    cur_pos++;
                    while(json_str[cur_pos] != ']') {
                        if(json_str[cur_pos] == ',')
                            cur_pos++;
                        cur_pos++;
                        if(json_str[cur_pos] == '"') {
                            // String array element
                            char val[MAX_VAL_LEN] = "";
                            cur_pos++;
                            while(json_str[cur_pos] != '"') {
                                char c[2] = {json_str[cur_pos], '\0'};
                                strcat(val, c);
                                cur_pos++;
                            }
                            json_elem_t elem;
                            elem.type = JSON_STRING;
                            elem.value.string = val;
                            json_arr[arr_cnt] = elem;
                            arr_cnt++;
                        } else if(json_str[cur_pos] >= '0' && json_str[cur_pos] <= '9') {
                            // Number
                            char val[MAX_VAL_LEN] = "";
                            int i = 0;
                            while((json_str[cur_pos] >= '0' && json_str[cur_pos] <= '9') || json_str[cur_pos] == '.') {
                                char c[2] = {json_str[cur_pos], '\0'};
                                strcat(val, c);
                                cur_pos++;
                                i++;
                            }
                            json_elem_t elem;
                            elem.type = JSON_NUMBER;
                            elem.value.number = atof(val);
                            json_arr[arr_cnt] = elem;
                            arr_cnt++;
                        } else if(json_str[cur_pos] == '{') {
                            // Object
                            int nested_obj_start = cur_pos;
                            int nested_obj_end = cur_pos;
                            int nested_obj_count = 1;

                            while(nested_obj_count != 0) {
                                nested_obj_end++;
                                if(json_str[nested_obj_end] == '{')
                                    nested_obj_count++;
                                else if(json_str[nested_obj_end] == '}')
                                    nested_obj_count--;
                            }

                            char* nested_obj_str = malloc(nested_obj_end - nested_obj_start + 1);
                            strncpy(nested_obj_str, json_str + nested_obj_start, nested_obj_end - nested_obj_start + 1);
                            nested_obj_str[nested_obj_end - nested_obj_start] = '\0';

                            json_elem_t elem;
                            elem.type = JSON_OBJECT;
                            // Recursively parse nested object
                            parse_json(nested_obj_str);
                            json_arr[arr_cnt] = elem;
                            arr_cnt++;
                        } else if(json_str[cur_pos] == 't' || json_str[cur_pos] == 'f') {
                            // Boolean
                            char val[MAX_VAL_LEN] = "";
                            if(json_str[cur_pos] == 't') {
                                strcat(val, "true");
                                cur_pos += 4;
                            } else {
                                strcat(val, "false");
                                cur_pos += 5;
                            }
                            json_elem_t elem;
                            elem.type = JSON_BOOLEAN;
                            elem.value.boolean = strcmp(val, "true") == 0 ? 1 : 0;
                            json_arr[arr_cnt] = elem;
                            arr_cnt++;
                        } else if(json_str[cur_pos] == 'n') {
                            // null
                            cur_pos += 4;
                            json_elem_t elem;
                            elem.type = JSON_NULL;
                            json_arr[arr_cnt] = elem;
                            arr_cnt++;
                        }
                    }
                }

                json_pair_t pair;
                pair.key = key;
                pair.value = value;
                json_obj[obj_cnt] = pair;
                obj_cnt++;

                cur_pos++;
            }
        } else if(json_str[cur_pos] == '[') {
            // Array start
            cur_pos++;
            
            while(json_str[cur_pos] != ']' && arr_cnt < MAX_ARR_LEN) {
                if(json_str[cur_pos] == ',')
                    cur_pos++;
                cur_pos++;
                if(json_str[cur_pos] == '"') {
                    // String array element
                    char val[MAX_VAL_LEN] = "";
                    cur_pos++;
                    while(json_str[cur_pos] != '"') {
                        char c[2] = {json_str[cur_pos], '\0'};
                        strcat(val, c);
                        cur_pos++;
                    }
                    json_elem_t elem;
                    elem.type = JSON_STRING;
                    elem.value.string = val;
                    json_arr[arr_cnt] = elem;
                    arr_cnt++;
                } else if(json_str[cur_pos] >= '0' && json_str[cur_pos] <= '9') {
                    // Number
                    char val[MAX_VAL_LEN] = "";
                    int i = 0;
                    while((json_str[cur_pos] >= '0' && json_str[cur_pos] <= '9') || json_str[cur_pos] == '.') {
                        char c[2] = {json_str[cur_pos], '\0'};
                        strcat(val, c);
                        cur_pos++;
                        i++;
                    }
                    json_elem_t elem;
                    elem.type = JSON_NUMBER;
                    elem.value.number = atof(val);
                    json_arr[arr_cnt] = elem;
                    arr_cnt++;
                } else if(json_str[cur_pos] == '{') {
                    // Object
                    int nested_obj_start = cur_pos;
                    int nested_obj_end = cur_pos;
                    int nested_obj_count = 1;

                    while(nested_obj_count != 0) {
                        nested_obj_end++;
                        if(json_str[nested_obj_end] == '{')
                            nested_obj_count++;
                        else if(json_str[nested_obj_end] == '}')
                            nested_obj_count--;
                    }

                    char* nested_obj_str = malloc(nested_obj_end - nested_obj_start + 1);
                    strncpy(nested_obj_str, json_str + nested_obj_start, nested_obj_end - nested_obj_start + 1);
                    nested_obj_str[nested_obj_end - nested_obj_start] = '\0';

                    json_elem_t elem;
                    elem.type = JSON_OBJECT;
                    // Recursively parse nested object
                    parse_json(nested_obj_str);
                    json_arr[arr_cnt] = elem;
                    arr_cnt++;
                } else if(json_str[cur_pos] == 't' || json_str[cur_pos] == 'f') {
                    // Boolean
                    char val[MAX_VAL_LEN] = "";
                    if(json_str[cur_pos] == 't') {
                        strcat(val, "true");
                        cur_pos += 4;
                    } else {
                        strcat(val, "false");
                        cur_pos += 5;
                    }
                    json_elem_t elem;
                    elem.type = JSON_BOOLEAN;
                    elem.value.boolean = strcmp(val, "true") == 0 ? 1 : 0;
                    json_arr[arr_cnt] = elem;
                    arr_cnt++;
                } else if(json_str[cur_pos] == 'n') {
                    // null
                    cur_pos += 4;
                    json_elem_t elem;
                    elem.type = JSON_NULL;
                    json_arr[arr_cnt] = elem;
                    arr_cnt++;
                }
            }
        }

        cur_pos++;
    }

    printf("Parsed JSON:\n");

    for(int i = 0; i < obj_cnt; i++) {
        printf("%s: ", json_obj[i].key);

        json_elem_t elem = json_obj[i].value;
        switch(elem.type) {
            case JSON_OBJECT:
                printf("object\n");
                break;
            case JSON_ARRAY:
                printf("array\n");
                break;
            case JSON_STRING:
                printf("string - %s\n", elem.value.string);
                break;
            case JSON_NUMBER:
                printf("number - %f\n", elem.value.number);
                break;
            case JSON_BOOLEAN:
                printf("boolean - %d\n", elem.value.boolean);
                break;
            case JSON_NULL:
                printf("null\n");
                break;
        }
    }

    for(int i = 0; i < arr_cnt; i++) {
        json_elem_t elem = json_arr[i];
        switch(elem.type) {
            case JSON_OBJECT:
                printf("object\n");
                break;
            case JSON_ARRAY:
                printf("array\n");
                break;
            case JSON_STRING:
                printf("string - %s\n", elem.value.string);
                break;
            case JSON_NUMBER:
                printf("number - %f\n", elem.value.number);
                break;
            case JSON_BOOLEAN:
                printf("boolean - %d\n", elem.value.boolean);
                break;
            case JSON_NULL:
                printf("null\n");
                break;
        }
    }
}