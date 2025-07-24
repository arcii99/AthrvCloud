//FormAI DATASET v1.0 Category: Database querying ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

int main(int argc, char **argv) {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char *server = "localhost";
    char *user = "root";
    char *password = "password";
    char *database = "mydatabase";

    // Configurable variables
    char *query = "SELECT * FROM users WHERE age > ?";
    int param = 25;

    conn = mysql_init(NULL);

    if(mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        mysql_query(conn, "SET NAMES utf8");
        mysql_query(conn, "SET CHARACTER SET utf8");

        // Query with parameter binding
        MYSQL_STMT *statement;
        statement = mysql_stmt_init(conn);
        if(!statement) {
            fprintf(stderr, "mysql_stmt_init(), out of memory \n");
            return -1;
        }

        if(mysql_stmt_prepare(statement, query, strlen(query))) {
            fprintf(stderr, "mysql_stmt_prepare(), SELECT failed\n");
            fprintf(stderr, "error %s\n", mysql_stmt_error(statement));
            return -1;
        }

        // Bind a parameter for the statement
        MYSQL_BIND paramBind;
        memset(&paramBind, 0, sizeof(paramBind));
        paramBind.buffer_type = MYSQL_TYPE_LONG;
        paramBind.buffer = &param;
        paramBind.is_unsigned = 0;
        paramBind.length = 0;

        // Bind the parameter to the statement
        if(mysql_stmt_bind_param(statement, &paramBind)) {
            fprintf(stderr, "mysql_stmt_bind_parameter(), failed\n");
            return -1;
        }

        if(mysql_stmt_execute(statement)) {
            fprintf(stderr, "mysql_stmt_execute(), failed\n");
            fprintf(stderr, "error %s\n", mysql_stmt_error(statement));
            return -1;
        }

        // Store result
        res = mysql_stmt_result_metadata(statement);
        int num_fields = mysql_num_fields(res);

        // Fetch rows
        while(!mysql_stmt_fetch(statement)) {
            for(int i = 0; i < num_fields; i++) {
                row = mysql_fetch_row(res);
                if(row[i] != NULL) {
                    printf("%s ", row[i]);
                } else {
                    printf("NULL ");
                }
            }
            printf("\n");
        }

        // Free resources
        mysql_free_result(res);
        mysql_stmt_close(statement);

        mysql_close(conn);

        return 0;
    } else {
        fprintf(stderr, "Connection failed\n");
        if(conn) {
            mysql_close(conn);
        }
        return -1;
    }

}