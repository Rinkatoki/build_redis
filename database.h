typedef struct entry Entry;

typedef struct database
{
    Entry *head ;
    size_t key_count;
}Database;

typedef struct entry
{
    char *key;
    char *value;
    Entry *next;
}Entry;

int db_set(...);

int db_del(...);
