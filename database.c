#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

Database *db_create(void){
  Database *db;
  db->head=NULL;
  db->key_count=0;
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

static Entry * find_node(Database *db,const char *key){
  Entry *current=db->head;
  while(current!=NULL){
    if (strcmp(current->key,key)==0){
      return current;
    }
    current=current->next;
  }
  return NULL;
}

int db_set(Database *db,const char * key,const char *value){
  if (db==NULL || key==NULL || value==NULL){
    return 0;
  }
  Entry *current=find_node(db,key);
  if(current!=NULL){
    char * temp=strdup(value);
    if(temp==NULL){
      return 0;
    }
    free(current->value);
    current->value=temp;
    return 1;
  }
  Entry *node =create_node(key,value);
  if(node==NULL){
    return 0;
  }
  node->next=db->head;
  db->head=node;
  db->key_count+=1;
  return 1;
}