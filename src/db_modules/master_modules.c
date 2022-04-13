#include "master_modules.h"
#include "../io/output.h"
#include "../io/input.h"

const char * path_to_database = "../materials/master_modules.db";

void get_record_by_id() {
    FILE *database = NULL;
    if((database = fopen(path_to_database, "r")) == NULL) {
        error();
    } else {
        database = fopen(path_to_database, "r");
        int *module_id = 0;
        int choosen_id = select_id(module_id);
        get_record(database, 5);
        system("exit");
    }
}

void get_all_records() {

}

module get_record(FILE *database, int id) {
    int offset = id * sizeof(module);
    fseek(database, offset, SEEK_SET);

    module new;
    fread(&new, sizeof(module), 1, database);

    rewind(database);
    printf("%d %-10s %d %d %d\n",
    new.id, new.name, new.memory_level,
    new.cell_number, new.delete_flag);
    return new;
}

int database_size(FILE *database)
{
    int size = 0;
    fseek(database, 0, SEEK_END);    
    size = ftell(database);          
    rewind(database);                
    return size;
}

int records_count(FILE *database)
{
    return database_size(database) / sizeof(module);
}