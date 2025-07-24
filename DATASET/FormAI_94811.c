//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_OBJ 100

typedef enum {
    JSON_OBJ, JSON_ARR, JSON_STR, JSON_NUM, JSON_BOOL, JSON_NULL
} json_type_t;

typedef struct {
    json_type_t type;
    union {
        char *str_val;
        double num_val;
        int bool_val;
        void *child;
    };
    char *key;
} json_t;

/* Parses the given JSON string */
json_t *parse_json(char *json_str){
    int i, len = strlen(json_str);
    json_t *ret = malloc(sizeof(json_t) * MAX_JSON_OBJ);

    int st_ptr[MAX_JSON_OBJ], arr_stack[MAX_JSON_OBJ], obj_stack[MAX_JSON_OBJ], ptr_cnt = 0, arr_cnt = 0, obj_cnt = 0, key_flag = 0, negate_flag = 0;
    char temp_str[MAX_JSON_OBJ];

    memset(st_ptr, 0, sizeof(int) * MAX_JSON_OBJ);
    memset(arr_stack, 0, sizeof(int) * MAX_JSON_OBJ);
    memset(obj_stack, 0, sizeof(int) * MAX_JSON_OBJ);

    /* Parse the JSON string character-by-character */
    for(i = 0; i < len; i++){
        switch(json_str[i]){
            case '\"':
                if(key_flag) {
                    /* Key ends */
                    key_flag = 0;
                } else {
                    /* String begins */
                    key_flag = 1;
                    ret[ptr_cnt].str_val = malloc(sizeof(char) * MAX_JSON_OBJ);
                    st_ptr[ptr_cnt] = 1;
                    ptr_cnt++;
                }
                break;
            case ':' :
                if(key_flag) {
                    /* Key ends, value begins */
                    key_flag = 0;
                    st_ptr[ptr_cnt-1] = 2;
                }
                break;
            case ',':
                if(key_flag) {
                    /* String is incomplete */
                    strcat(ret[ptr_cnt-1].str_val, temp_str);
                    memset(temp_str, 0, sizeof(char) * MAX_JSON_OBJ);
                } else {
                    /* Value of the element ends */
                    st_ptr[ptr_cnt-1]--;
                    if(st_ptr[ptr_cnt-1] == 0){
                        /* Parent element ends, return to parent */
                        ptr_cnt--;
                    }
                }
                break;
            case '[':
                /* Array begins */
                arr_stack[arr_cnt++] = ptr_cnt;
                ret[ptr_cnt].type = JSON_ARR;
                ret[ptr_cnt].child = malloc(sizeof(json_t) * MAX_JSON_OBJ);
                ptr_cnt++;
                break;
            case ']':
                /* Array ends */
                ptr_cnt--;
                if(ptr_cnt == arr_stack[arr_cnt-1]){
                    arr_cnt--;
                }
                break;
            case '{':
                /* Object begins */
                obj_stack[obj_cnt++] = ptr_cnt;
                ret[ptr_cnt].type = JSON_OBJ;
                ptr_cnt++;
                break;
            case '}':
                /* Object ends */
                ptr_cnt--;
                if(ptr_cnt == obj_stack[obj_cnt-1]){
                    obj_cnt--;
                }
                break;
            case ' ':
            case '\n':
            case '\t':
                /* Ignore whitespaces */
                break;
            case 't':
                /* Boolean true */
                ret[ptr_cnt].bool_val = 1;
                ret[ptr_cnt].type = JSON_BOOL;
                st_ptr[ptr_cnt] = 2;
                ptr_cnt++;
                i += 3;
                break;
            case 'f':
                /* Boolean false */
                ret[ptr_cnt].bool_val = 0;
                ret[ptr_cnt].type = JSON_BOOL;
                st_ptr[ptr_cnt] = 2;
                ptr_cnt++;
                i += 4;
                break;
            case 'n':
                /* Null */
                ret[ptr_cnt].type = JSON_NULL;
                st_ptr[ptr_cnt] = 2;
                ptr_cnt++;
                i += 3;
                break;
            case '-':
                /* Negative sign for number */
                negate_flag = 1;
                break;
            default:
                /* String or number */
                strcat(temp_str, &json_str[i]);
                if(!key_flag) {
                    /* Not a key, determine number type */
                    int has_decimal = 0, iter = i;
                    while(json_str[iter] != ',' && json_str[iter] != ']' && json_str[iter] != '}'){
                        if(json_str[iter] == '.'){
                            has_decimal = 1;
                        }
                        iter++;
                    }
                    if(has_decimal){
                        ret[ptr_cnt].num_val = strtof(temp_str, NULL);
                    } else {
                        ret[ptr_cnt].num_val = strtol(temp_str, NULL, 10);
                    }
                    if(negate_flag){
                        ret[ptr_cnt].num_val *= -1;
                    }
                    ret[ptr_cnt].type = JSON_NUM;
                }
                break;
        }
    }
    return ret;
}

/* Prints the given JSON object recursively */
void print_json(json_t *json_obj, int indent){
    int i, j, is_arr = 0;

    for(i = 0; i < indent; i++) printf("  ");

    switch(json_obj->type){
        case JSON_OBJ:
            printf("{\n");
            indent++;

            for(i = 0; json_obj[i].type != 0; i++){
                for(j = 0; j < indent; j++) printf("  ");
                printf("\"%s\": ", json_obj[i].key);
                print_json(json_obj[i].child, indent);
                if(json_obj[i+1].type != 0) {
                    printf(",\n");
                }
            }

            indent--;
            printf("\n");
            for(i = 0; i < indent; i++) printf("  ");
            printf("}");
            break;
        case JSON_ARR:
            printf("[\n");
            indent++;
            is_arr = 1;

            for(i = 0; json_obj[i].type != 0; i++){
                print_json(&json_obj[i], indent);
                if(json_obj[i+1].type != 0) {
                    printf(",\n");
                }
            }

            indent--;
            printf("\n");
            for(i = 0; i < indent; i++) printf("  ");
            printf("]");
            break;
        case JSON_STR:
            printf("\"%s\"", json_obj->str_val);
            break;
        case JSON_NUM:
            printf("%.2f", json_obj->num_val);
            break;
        case JSON_BOOL:
            printf("%s", json_obj->bool_val ? "true" : "false");
            break;
        case JSON_NULL:
            printf("null");
            break;
    }

    if(!is_arr){
        printf("\n");
    }
}

int main(){
    char json_str[MAX_JSON_OBJ] = "{\n  \"name\": \"John Doe\",\n  \"age\": 25,\n  \"is_student\": true,\n  \"subjects\": [\n    {\n      \"name\": \"Math\",\n      \"marks\": 90\n    },\n    {\n      \"name\": \"Science\",\n      \"marks\": 80\n    }\n  ],\n  \"address\": {\n    \"street\": \"123 Main St\",\n    \"city\": \"San Francisco\",\n    \"state\": \"CA\",\n    \"country\": \"USA\"\n  }\n}";

    /* Parse JSON string and print the parsed object */
    json_t *parsed_json = parse_json(json_str);
    print_json(parsed_json, 0);

    return 0;
}