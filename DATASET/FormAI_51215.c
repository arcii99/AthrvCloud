//FormAI DATASET v1.0 Category: Database querying ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main(int argc, char **argv) {

    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char *server = "localhost";
    char *user = "username";
    char *password = "password";
    char *database ="medieval";
    
    conn = mysql_init(NULL);
    
    if(!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    mysql_query(conn, "SELECT name, title, age FROM knights WHERE age > 30 AND title LIKE '%Sir%'");
    
    res = mysql_use_result(conn);
    
    printf("The following knights meet your criteria:\n");
    while((row = mysql_fetch_row(res)) != NULL) {
        printf("%s, %s, %s\n", row[0], row[1], row[2]);
    }
    
    mysql_free_result(res);
    mysql_close(conn);
    
    return 0;
}