#include <stdio.h>
#include "database.h"

Database db_create(void){
  Database db;
  db.head=NULL;
  db.key_count=0;
  return db;
}

void free_node(Database *db){
  Entry *current=db->head;
  free(db->head);
  db->key_count=0;
}