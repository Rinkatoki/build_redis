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

void db_destroy(Database *db);

void free_node(Entry * node);

Entry *create_node(const char *key, const char *value);

int db_set(Database *db,const char *key,const char * value);

char * db_get(Database *db ,char*key);

int db_exists(Database *db,char *key);

size_t db_count(Database * db);

void db_print(Database *db);

// int db_del(...);
// Entry * find_node(Database *db,char *key);