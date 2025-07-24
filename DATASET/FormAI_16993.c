//FormAI DATASET v1.0 Category: Database querying ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <postgresql/libpq-fe.h>

int main() {
  PGconn *conn = PQconnectdb("dbname=mydb user=myuser password=mypassword");

  if (PQstatus(conn) != CONNECTION_OK) {
    fprintf(stderr, "Connection to database failed: %s", PQerrorMessage(conn));
    PQfinish(conn);
    return 1;
  }

  // Execute a SELECT statement to retrieve data
  PGresult *res = PQexec(conn, "SELECT name, age FROM users WHERE age > 30");

  if (PQresultStatus(res) != PGRES_TUPLES_OK) {
    fprintf(stderr, "Query failed: %s", PQerrorMessage(conn));
    PQclear(res);
    PQfinish(conn);
    return 1;
  }

  // Print the results to the console
  int num_rows = PQntuples(res);
  int num_fields = PQnfields(res);

  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_fields; j++) {
      printf("%s\t", PQgetvalue(res, i, j));
    }
    printf("\n");
  }

  PQclear(res);
  PQfinish(conn);
  return 0;
}