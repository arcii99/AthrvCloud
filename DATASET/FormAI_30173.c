//FormAI DATASET v1.0 Category: Database querying ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

#define SERVER "localhost"
#define DATABASE "example_db"
#define USER "root"
#define PASSWORD "password"

int main(void)
{
    MYSQL *conn;
    MYSQL_RES *result;
    MYSQL_ROW row;
    
    conn = mysql_init(NULL);
    
    if (!mysql_real_connect(conn, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0)) {
        fprintf(stderr, "Error connecting to database: %s\n", mysql_error(conn));
        exit(1);
    }
    
    printf("Successfully connected to database!\n");
    
    if (mysql_query(conn, "SELECT * FROM users WHERE age > 30")) {
        fprintf(stderr, "Error querying database: %s\n", mysql_error(conn));
        exit(1);
    }
    
    result = mysql_use_result(conn);
    
    printf("Users aged over 30:\n");
    
    while ((row = mysql_fetch_row(result)) != NULL) {
        printf("%s %s, age %s, email: %s\n", row[0], row[1], row[2], row[3]);
    }
    
    mysql_free_result(result);
    mysql_close(conn);
    
    printf("Database connection closed.\n");
    
    return 0;
}