//FormAI DATASET v1.0 Category: Database querying ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QUERY_LENGTH 1000
#define MAX_TABLES 5
#define MAX_COLUMNS 20
#define MAX_DATA_LENGTH 50
#define MAX_CONDITIONS 5

typedef struct column {
    char name[MAX_DATA_LENGTH];
    char type[MAX_DATA_LENGTH];
} Column;

typedef struct table {
    char name[MAX_DATA_LENGTH];
    int num_columns;
    Column columns[MAX_COLUMNS];
} Table;

typedef struct condition {
    char column[MAX_DATA_LENGTH];
    char value[MAX_DATA_LENGTH];
} Condition;

void print_results(char **results, int num_rows);
void execute_query(char *query, Table *tables, int num_tables);
bool is_valid_query(char *query, Table *tables, int num_tables);
bool has_valid_tables(char *query, Table *tables, int num_tables);
bool has_valid_columns(char *query, Table *tables, int num_tables);
bool has_valid_conditions(char *query, Table *tables, int num_tables);
bool is_valid_column(char *column, Table *table);
bool is_valid_condition(char *condition, Table *table);

int main() {
    Table tables[MAX_TABLES] = {
        {
            .name = "customers",
            .num_columns = 3,
            .columns = {
                {.name = "id", .type = "int"},
                {.name = "name", .type = "string"},
                {.name = "age", .type = "int"}
            }
        },
        {
            .name = "orders",
            .num_columns = 4,
            .columns = {
                {.name = "id", .type = "int"},
                {.name = "customer_id", .type = "int"},
                {.name = "product", .type = "string"},
                {.name = "quantity", .type = "int"}
            }
        }
    };
    int num_tables = 2;

    char query[MAX_QUERY_LENGTH] = "SELECT id, name FROM customers WHERE age > 25";
    execute_query(query, tables, num_tables);

    return 0;
}

void print_results(char **results, int num_rows) {
    for (int i = 0; i < num_rows; i++) {
        printf("%s\n", results[i]);
    }
}

void execute_query(char *query, Table *tables, int num_tables) {
    if (!is_valid_query(query, tables, num_tables)) {
        printf("Invalid query.\n");
        return;
    }

    char *table_name = strtok(query, " ");
    if (strcmp(table_name, "SELECT") != 0) {
        printf("Invalid query.\n");
        return;
    }

    int num_columns = 0;
    char **columns = malloc(MAX_COLUMNS * sizeof(char *));
    char *column = strtok(NULL, " ");
    while (strcmp(column, "FROM") != 0) {
        if (is_valid_column(column, tables)) {
            columns[num_columns] = column;
            num_columns++;
        }
        column = strtok(NULL, " ");
    }

    char *table = strtok(NULL, " ");

    int num_conditions = 0;
    Condition conditions[MAX_CONDITIONS];
    char *condition = strtok(NULL, " ");
    while (condition != NULL) {
        if (*condition == 'W' && *(condition + 1) == 'H' && *(condition + 2) == 'E' && *(condition + 3) == 'R' && *(condition + 4) == 'E') {
            char *column = strtok(condition + 6, "=");
            char *value = strtok(NULL, " ");
            if (is_valid_condition(column, tables)) {
                strcpy(conditions[num_conditions].column, column);
                strcpy(conditions[num_conditions].value, value);
                num_conditions++;
            }
        }
        condition = strtok(NULL, " ");
    }

    int num_rows = 0;
    char **results = malloc(MAX_DATA_LENGTH * sizeof(char *));
    for (int i = 0; i < MAX_DATA_LENGTH; i++) {
        results[i] = malloc(MAX_COLUMNS * MAX_DATA_LENGTH * sizeof(char));
    }

    for (int i = 0; i < num_tables; i++) {
        if (strcmp(tables[i].name, table) == 0) {
            for (int j = 0; j < tables[i].num_columns; j++) {
                printf("%s ", tables[i].columns[j].name);
            }
            printf("\n");

            for (int j = 0; j < tables[i].num_columns; j++) {
                printf("%s ", tables[i].columns[j].type);
            }
            printf("\n");

            for (int j = 0; j < num_columns; j++) {
                printf("%s ", columns[j]);
            }
            printf("\n");

            for (int j = 0; j < num_conditions; j++) {
                printf("%s %s \n", conditions[j].column, conditions[j].value);
            }

            // code to query the database and populate the results array goes here

            num_rows = 1;
            strcpy(results[0], "1 john");

            break;
        }
    }

    print_results(results, num_rows);
}

bool is_valid_query(char *query, Table *tables, int num_tables) {
    return has_valid_tables(query, tables, num_tables) && has_valid_columns(query, tables, num_tables) && has_valid_conditions(query, tables, num_tables);
}

bool has_valid_tables(char *query, Table *tables, int num_tables) {
    char *table = strtok(query, " ");
    while (table != NULL) {
        for (int i = 0; i < num_tables; i++) {
            if (strcmp(table, tables[i].name) == 0) {
                return true;
            }
        }
        table = strtok(NULL, " ");
    }

    return false;
}

bool has_valid_columns(char *query, Table *tables, int num_tables) {
    char *column = strtok(query, " ");
    while (column != NULL) {
        if (is_valid_column(column, tables)) {
            return true;
        }
        column = strtok(NULL, " ");
    }

    return false;
}

bool has_valid_conditions(char *query, Table *tables, int num_tables) {
    char *condition = strtok(query, " ");
    while (condition != NULL) {
        if (*condition == 'W' && *(condition + 1) == 'H' && *(condition + 2) == 'E' && *(condition + 3) == 'R' && *(condition + 4) == 'E') {
            char *column = strtok(condition + 6, "=");
            char *value = strtok(NULL, " ");
            if (is_valid_condition(column, tables)) {
                return true;
            }
        }
        condition = strtok(NULL, " ");
    }

    return false;
}

bool is_valid_column(char *column, Table *tables) {
    for (int i = 0; i < MAX_TABLES; i++) {
        for (int j = 0; j < tables[i].num_columns; j++) {
            if (strcmp(column, tables[i].columns[j].name) == 0) {
                return true;
            }
        }
    }

    return false;
}

bool is_valid_condition(char *condition, Table *tables) {
    char column[MAX_DATA_LENGTH], value[MAX_DATA_LENGTH];
    strcpy(column, strtok(condition, "="));
    strcpy(value, strtok(NULL, "="));

    if (!is_valid_column(column, tables)) {
        return false;
    }

    Column col;
    for (int i = 0; i < MAX_TABLES; i++) {
        for (int j = 0; j < tables[i].num_columns; j++) {
            if (strcmp(column, tables[i].columns[j].name) == 0) {
                col = tables[i].columns[j];
                break;
            }
        }
    }

    if (strcmp(col.type, "int") == 0) {
        for (int i = 0; i < strlen(value); i++) {
            if (value[i] < '0' || value[i] > '9') {
                return false;
            }
        }
    }

    return true;
}