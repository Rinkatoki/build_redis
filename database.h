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


Database db_create(void);

void free_node(Database);

int db_set(...);

int db_del(...);
