//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Sherlock Holmes
//Sherlock Holmes style JSON parser

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//declaring the available JSON data types
typedef enum{
    JSON_INVALID,
    JSON_NULL,
    JSON_TRUE,
    JSON_FALSE,
    JSON_STRING,
    JSON_NUMBER,
    JSON_ARRAY,
    JSON_OBJECT
} json_type;

//JSON data structure definitions
typedef struct json_value json_value;
typedef struct json_object json_object;
typedef struct json_array json_array;
typedef struct json_member json_member;

//JSON value types and their content, kept as a union
struct json_value{
    union{
        struct{json_member* m; size_t size;} object;
        struct{json_value* e; size_t size;} array;
        struct{char* s; size_t len;} string;
        double num;
    }u;
    json_type type;
};

//JSON member consisting a key-value pair
struct json_member{
    char* k; size_t klen; //key and its length
    json_value v; //value
};

//JSON object or collection of key-value pairs
struct json_object{
    json_member* m; size_t size; //members and their count
};

//JSON array or collection of elements of any type
struct json_array{
    json_value* e; size_t size; //elements and their count
};

//Simple way to skip white spaces
static const char* json_parse_whitespace(const char* json){
    while(*json==' ' || *json=='\t' || *json=='\n' || *json=='\r')
        ++json;
    return json;
}

//Read and parse a JSON null value
static const char* json_parse_null(const char* json, json_value* value){
    if(!strncmp(json, "null", 4)){
        value->type = JSON_NULL;
        return json+4;
    }
    return NULL; //return NULL on error
}

//Read and parse a JSON boolean value
static const char* json_parse_bool(const char* json, json_value* value){
    if(!strncmp(json, "true", 4)){
        value->type = JSON_TRUE;
        return json+4;
    }
    if(!strncmp(json, "false", 5)){
        value->type = JSON_FALSE;
        return json+5;
    }
    return NULL; //return NULL on error
}

//Read and parse a JSON string value
static const char* json_parse_string(const char* json, json_value* value){
    size_t len = 0;
    const char* p = json+1; //skip initial quote
    char* s; //buffer for the parsed string
    while(*p != '\"' && *p != '\0'){
        if(*p == '\\'){ //special character
            switch(*(p+1)){
                case 'n': len++; break;
                case 't': len++; break;
                case 'r': len++; break;
                case '\"': len++; break;
                case '\\': len++; break;
                default: return NULL; //return NULL on error
            }
            p+=2;
        }
        else{ //normal character
            len++;
            p++;
        }
    }
    if(*p != '\"')  return NULL; //return NULL on error

    //allocate and copy the parsed string
    value->u.string.s = s = (char*)malloc(len+1);
    value->u.string.len = len;
    p = json+1;
    while(*p != '\"' && *p != '\0'){
        if(*p == '\\'){
            switch(*(p+1)){
                case 'n': *s++ = '\n'; break;
                case 't': *s++ = '\t'; break;
                case 'r': *s++ = '\r'; break;
                case '\"': *s++ = '\"'; break;
                case '\\': *s++ = '\\'; break;
            }
            p+=2;
        }
        else{ //normal character
            *s++ = *p++;
        }
    }
    *s = '\0';

    value->type = JSON_STRING;
    return p+1;
}

//Read and parse a JSON number value
static const char* json_parse_number(const char* json, json_value* value){
    const char* p = json;
    double n = 0.0; //the parsed number
    int sign = 1; //sign of the number
    int frac = 0; //indicates if there is a fraction part
    int expsign = 1; //sign of the exponent part
    int exp = 0; //the exponent part
    if(*p=='-') { //negative sign
        sign = -1;
        ++p;
    }
    if(*p=='0') { //zero
        ++p;
        if(*p=='.') return NULL; //must not start a fraction part
    }
    else if(*p>='1' && *p<='9'){ //positive integer part
        while(*p>='0' && *p<='9'){
            n = n * 10.0 + (*p++ - '0');
        }
    }
    else{ //unknown or invalid number
        return NULL;
    }
    if(*p=='.') { //fraction part, e.g. 1.05
        frac = 1; //signal that a fraction part was found
        ++p;
        if(*p<'0' || *p>'9') return NULL; //must have one or more digits
        while(*p>='0' && *p<='9'){
            n += (*p++ - '0') * 0.1;
        }
    }
    if(*p=='e' || *p=='E') { //exponent part, e.g. 10E6 or -0.02e-4
        ++p;
        if(*p=='+') { //positive exponent
            ++p;
        }
        else if(*p=='-') { //negative exponent
            expsign = -1;
            ++p;
        }
        if(*p<'0' || *p>'9') return NULL; //must have one or more digits
        while(*p>='0' && *p<='9'){
            exp = exp * 10 + (*p++ - '0');
        }
    }
    n = sign * n * pow(10, expsign * exp * (frac ? -1 : 0)); //calculate the final number
    value->u.num = n;
    value->type = JSON_NUMBER;
    return p;
}

//Read and parse a JSON value of any type
static const char* json_parse_value(const char* json, json_value* value){
    switch(*json){
        case 'n': return json_parse_null(json, value);
        case 't': case 'f': return json_parse_bool(json, value);
        case '\"': return json_parse_string(json, value);
        case '[': return NULL; //array parsing is not yet implemented
        case '{': return NULL; //object parsing is not yet implemented
        case '-': //negative number
        case '0': //positive number starting with zero
        case '1'...'9': //positive number starting with one
            return json_parse_number(json, value);
        default: return NULL; //unknown value type
    }
}

//Main function for the JSON parser
int main(){
    char json[10000]; //buffer for the input JSON data
    json_value value;
    printf("Enter the JSON data to parse:\n");
    fgets(json, sizeof(json), stdin); //reading the input JSON data
    json_parse_value(json_parse_whitespace(json), &value); //parsing the input JSON
    printf("The parsed value:\n");
    switch(value.type){ //print the result depending on the value type
        case JSON_NULL: printf("null\n"); break;
        case JSON_TRUE: printf("true\n"); break;
        case JSON_FALSE: printf("false\n"); break;
        case JSON_STRING: printf("%s\n", value.u.string.s); break;
        case JSON_NUMBER: printf("%G\n", value.u.num); break;
        default: printf("unknown value type\n"); break;
    }
    return 0; //exit the program
}