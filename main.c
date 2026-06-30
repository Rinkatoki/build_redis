#include <stdio.h>
#include "database.h"

int main(void){
    Database db=db_create();
    int a=db_set(&db,"1","a");
    int b=db_set(&db,"2","b");
    char * value=db_get(&db,"2");
    if(value!=NULL){
        printf("%s\n",value);
    }
    else{
        printf("invalid element");
    }
    int c=db_exists(&db,"2");
    printf("key found %d\n",c);
    printf("Keys: %zu\n",db_count(&db));
    printf("elements\n");
    db_print(&db);
    db_destroy(&db);
    return 0;
}