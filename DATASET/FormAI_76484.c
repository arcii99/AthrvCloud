//FormAI DATASET v1.0 Category: Syntax parsing ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct variable {
    char name[30];
    char type[10];
};

struct function {
    char name[30];
    char return_type[10];
    struct variable parameters[10];
    int num_params;
};

struct program {
    char name[30];
    struct variable globals[20];
    int num_globals;
    struct function functions[10];
    int num_functions;
};

void parse_variable(char* input, struct variable* var) {
    char* token = strtok(input, " ");
    int index = 0;
    while (token != NULL) {
        if (index == 0) {
            strcpy(var->type, token);
        } else {
            strcpy(var->name, token);
        }
        token = strtok(NULL, " ");
        index++;
    }
}

void parse_function(char* input, struct function* func) {
    char* token = strtok(input, " ");
    int index = 0;
    while (token != NULL) {
        if (index == 0) {
            strcpy(func->return_type, token);
        } else if (index == 1) {
            strcpy(func->name, token);
        } else {
            parse_variable(token, &(func->parameters[func->num_params]));
            func->num_params++;
        }
        token = strtok(NULL, " ");
        index++;
    }
}

void parse_program(char* input, struct program* prog) {
    char* token = strtok(input, "\n");
    int index = 0;
    while (token != NULL) {
        if (index == 0) {
            strcpy(prog->name, token);
        } else if (index == 1) {
            parse_variable(token, &(prog->globals[prog->num_globals]));
            prog->num_globals++;
        } else {
            parse_function(token, &(prog->functions[prog->num_functions]));
            prog->num_functions++;
        }
        token = strtok(NULL, "\n");
        index++;
    }
}

int main() {
    char input[500] = "ProgramName\nint variable1\nchar variable2\nint functionName int param1 char param2\nchar functionName2 int param1\n";
    struct program prog;
    prog.num_globals = 0;
    prog.num_functions = 0;
    parse_program(input, &prog);
    printf("Program Name: %s\n", prog.name);
    printf("Global Variables:\n");
    for (int i = 0; i < prog.num_globals; i++) {
        printf("\t%s %s\n", prog.globals[i].type, prog.globals[i].name);
    }
    printf("Functions:\n");
    for (int i = 0; i < prog.num_functions; i++) {
        printf("\t%s %s(", prog.functions[i].return_type, prog.functions[i].name);
        for (int j = 0; j < prog.functions[i].num_params; j++) {
            printf("%s %s", prog.functions[i].parameters[j].type, prog.functions[i].parameters[j].name);
            if (j != prog.functions[i].num_params - 1) {
                printf(", ");
            }
        }
        printf(")\n");
    }
    return 0;
}