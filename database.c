#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

Database db_create(void){
  Database db;
  db.head=NULL;
  db.key_count=0;
  return db;
}

void free_node(Entry *node){
  free(node->key);
  free(node->value);
  free(node);
}

void db_destroy(Database *db){
  if (db==NULL){
    return;
  }
  Entry *current=db->head;
  while(current!=NULL){
    Entry *next=current->next;
    free_node(current);
    // free(current->key);
    // free(current->value);
    // free(current);
    current=next;
  }
  db->head=NULL;
  db->key_count=0;
}

Entry *create_node(const char *key,const char *value){
  Entry *node = malloc(sizeof(Entry));
  if (node==NULL){
    return NULL;
  }
  
  node->key=strdup(key);
  if((node->key)==NULL){
    free(node);
    return NULL;
  }

  node->value=strdup(value);
  if(node->value==NULL){
    free(node->key);
    free(node);
    return NULL;
  }

  node->next=NULL;
  return node;
}