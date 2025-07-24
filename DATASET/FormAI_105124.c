//FormAI DATASET v1.0 Category: Database querying ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main() {
  MYSQL *conn;
  MYSQL_RES *res;
  MYSQL_ROW row;
  char *server = "localhost";
  char *user = "username";
  char *password = "password";
  char *database = "databasename";
  conn = mysql_init(NULL);

  if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
    printf("Error: %s\n", mysql_error(conn));
    exit(1);
  }

  if (mysql_query(conn, "SELECT * FROM users")) {
    printf("Error: %s\n", mysql_error(conn));
    exit(1);
  }

  res = mysql_store_result(conn);

  while ((row = mysql_fetch_row(res)) != NULL) {
    printf("ID: %s, Name: %s, Age: %s\n", row[0], row[1], row[2]);
  }

  mysql_free_result(res);
  mysql_close(conn);

  return 0;
}