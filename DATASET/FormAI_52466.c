//FormAI DATASET v1.0 Category: Database querying ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUERY_LENGTH 100
#define MAX_COLUMNS 10
#define MAX_COLUMN_NAME_LENGTH 20
#define MAX_ROWS 100

struct Column {
    char name[MAX_COLUMN_NAME_LENGTH];
    int data[MAX_ROWS];
};

struct Table {
    struct Column columns[MAX_COLUMNS];
    int current_rows;
};

// Initializes the table with empty columns
void initializeTable(struct Table *table, int num_columns, char column_names[][MAX_COLUMN_NAME_LENGTH]) {
    int i, j;
    for (i = 0; i < num_columns; i++) {
        strcpy(table->columns[i].name, column_names[i]);
        for (j = 0; j < MAX_ROWS; j++) {
            table->columns[i].data[j] = 0;
        }
    }
    table->current_rows = 0;
}

// Adds a row to the table
void addRow(struct Table *table, int num_columns, int row_data[]) {
    int i;
    for (i = 0; i < num_columns; i++) {
        table->columns[i].data[table->current_rows] = row_data[i];
    }
    table->current_rows++;
}

// Executes a query on the table and prints the results
void executeQuery(struct Table *table, char query[]) {
    int column_index = -1;
    char column_name[MAX_COLUMN_NAME_LENGTH];
    int i, j;

    // Find the column to query
    for (i = 0; i < strlen(query); i++) {
        if (query[i] == ' ') {
            break;
        }
        column_name[i] = query[i];
    }
    column_name[i] = '\0';

    for (i = 0; i < MAX_COLUMNS; i++) {
        if (strcmp(table->columns[i].name, column_name) == 0) {
            column_index = i;
            break;
        }
    }

    if (column_index == -1) {
        printf("Column not found!");
        return;
    }

    // Execute the query
    int query_value;
    int num_results = 0;
    char query_operator;
    sscanf(&query[i], "%c %d", &query_operator, &query_value);

    printf("%s\n", table->columns[column_index].name);
    printf("--------------------\n");

    for (i = 0; i < table->current_rows; i++) {
        if (query_operator == '>') {
            if (table->columns[column_index].data[i] > query_value) {
                printf("%d\n", table->columns[column_index].data[i]);
                num_results++;
            }
        } else if (query_operator == '<') {
            if (table->columns[column_index].data[i] < query_value) {
                printf("%d\n", table->columns[column_index].data[i]);
                num_results++;
            }
        } else if (query_operator == '=') {
            if (table->columns[column_index].data[i] == query_value) {
                printf("%d\n", table->columns[column_index].data[i]);
                num_results++;
            }
        } else {
            printf("Invalid operator!\n");
            break;
        }
    }

    printf("--------------------\n");
    printf("%d results found.\n", num_results);
}

int main() {
    int num_columns = 3;
    char column_names[][MAX_COLUMN_NAME_LENGTH] = {"ID", "Name", "Age"};
    struct Table table;
    initializeTable(&table, num_columns, column_names);

    int row_data[] = {1, "John", 25};
    addRow(&table, num_columns, row_data);

    int row_data2[] = {2, "Jane", 30};
    addRow(&table, num_columns, row_data2);

    int row_data3[] = {3, "Bob", 20};
    addRow(&table, num_columns, row_data3);

    char query[MAX_QUERY_LENGTH] = "Age > 25";
    executeQuery(&table, query);

    return 0;
}