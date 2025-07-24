//FormAI DATASET v1.0 Category: Database querying ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
#define SERVER "localhost"
#define USER "root"
#define PASSWORD "password"
#define DATABASE "university"

static char *host = SERVER;
static char *user = USER;
static char *pass = PASSWORD;
static char *dbname = DATABASE;

unsigned int port = 3306;
static char *unix_socket = NULL;
unsigned int flag = 0;

MYSQL *conn;
MYSQL_RES *res;
MYSQL_ROW row;

int main() {
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, host, user, pass, dbname, port, unix_socket, flag)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }
    char *query = "SELECT student_name, course_name, grade FROM students NATURAL JOIN courses";
    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }
    res = mysql_use_result(conn);
    printf("Student Name\tCourse Name\tGrade\n");
    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("%s\t\t%s\t\t%s\n", row[0], row[1], row[2]);
    }
    mysql_free_result(res);
    mysql_close(conn);
    return 0;
}