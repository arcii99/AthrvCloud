//FormAI DATASET v1.0 Category: Database querying ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main(int argc, char *argv[]) {

  MYSQL *conn;
  MYSQL_RES *res;
  MYSQL_ROW row;

  char *server = "localhost";
  char *user = "root";
  char *password = "password"; /* set me first */
  char *database = "customers";

  conn = mysql_init(NULL);

  /* Connect to database */
  if (!mysql_real_connect(conn, server,
        user, password, database, 0, NULL, 0)) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    exit(1);
  }

  /* Send SQL query */
  if (mysql_query(conn, "SELECT * FROM customers")) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    exit(1);
  }

  res = mysql_store_result(conn);

  /* Print all customers in the database */
  while ((row = mysql_fetch_row(res)) != NULL) {
    printf("ID: %s\n", row[0]);
    printf("Name: %s\n", row[1]);
    printf("Email: %s\n", row[2]);
    printf("Address: %s\n", row[3]);
    printf("\n");
  }

  mysql_free_result(res);
  mysql_close(conn);

  return 0;
}