//FormAI DATASET v1.0 Category: Database querying ; Style: futuristic
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <mysql/mysql.h>  

int main()  
{  
    MYSQL *conn;  
    MYSQL_RES *res;  
    MYSQL_ROW row;  

    char *server = "localhost";  
    char *user = "root";  
    char *password = "password"; /* set me first */  
    char *database = "mydatabase";  

    conn = mysql_init(NULL);  

    /* Connect to database */  
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {  
        fprintf(stderr, "%s\n", mysql_error(conn));  
        exit(1);  
    }  

    /* Execute SQL query */  
    if (mysql_query(conn, "SELECT * FROM products WHERE price < 1000")) {  
        fprintf(stderr, "%s\n", mysql_error(conn));  
        exit(1);  
    }  

    res = mysql_use_result(conn);  

    /* Output table headers */  
    printf("Product ID\tProduct Name\tProduct Price\n");  

    /* Output rows from query */  
    while ((row = mysql_fetch_row(res)) != NULL) {  
        printf("%s\t\t%s\t\t%s\n", row[0], row[1], row[2]);  
    }  

    /* Free result set */  
    mysql_free_result(res);  

    /* Close connection */  
    mysql_close(conn);  

    return 0;  
}