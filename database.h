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


Database *db_create(void);

void db_destroy(Database *db);

void free_node(Database);

Entry *create_node(const char *key, const char *value);

int db_set();

// int db_del(...);
Entry * find_node(Database *db,char *key);