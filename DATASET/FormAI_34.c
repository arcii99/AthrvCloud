//FormAI DATASET v1.0 Category: Database querying ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main(int argc, char **argv) {
  MYSQL *conn;
  MYSQL_RES *res;
  MYSQL_ROW row;

  char *server = "localhost";
  char *user = "root";
  char *password = "password";
  char *database = "mydb";

  conn = mysql_init(NULL);

  if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    exit(1);
  }

  if (mysql_query(conn, "SELECT * FROM employees WHERE age > 25")) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    exit(1);
  }

  res = mysql_use_result(conn);

  printf("Employees over the age of 25:\n");
  while ((row = mysql_fetch_row(res)) != NULL) {
    printf("%s %s, %d\n", row[0], row[1], atoi(row[2]));
  }

  mysql_free_result(res);
  mysql_close(conn);

  return 0;
}