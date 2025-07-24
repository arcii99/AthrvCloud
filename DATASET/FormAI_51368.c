//FormAI DATASET v1.0 Category: Database querying ; Style: satisfied
//This program demonstrates how to query data from a student database using C language

#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main() {
    MYSQL *con = mysql_init(NULL);
    
    //Connect to the database
    if(con == NULL) {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }

    if(mysql_real_connect(con, "localhost", "user", "password", "students_db", 0, NULL, 0) == NULL) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    
    //Select data from the students table
    if(mysql_query(con, "SELECT * FROM students")) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }

    MYSQL_RES *result = mysql_store_result(con);
    if(result == NULL) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }

    //Fetch and output data
    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;
    while((row = mysql_fetch_row(result))) {
        for(int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
    mysql_close(con);
    return 0;
}