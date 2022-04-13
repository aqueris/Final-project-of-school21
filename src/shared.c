#include "./db_modules/master_modules.h"
#include "./io/input.h"
#include "./io/output.h"

module get_struct(FILE *db, int index);
int db_size(FILE *db);
int db_records_count(FILE *db);

int main() {
    FILE *db = NULL;
    char * path_to_file = "../materials/master_modules.db";
    db = fopen(path_to_file, "r");
    int size = db_records_count(db);

    for(int i = 0; i < size; i++) {
        get_struct(db, i);
    }

    get_struct(db, 69);
    get_record_by_id();

    return 0;
}

module get_struct(FILE *db, int index)
{
    int offset = index * sizeof(module);
    fseek(db, offset, SEEK_SET);

    module new;
    fread(&new, sizeof(module), 1, db);

    rewind(db);
    printf("%d %-10s %d %d %d\n",
    new.id, new.name, new.memory_level,
    new.cell_number, new.delete_flag);
    return new;
}

int db_size(FILE *db)
{
    int size = 0;
    fseek(db, 0, SEEK_END);    
    size = ftell(db);          
    rewind(db);                
    return size;
}

int db_records_count(FILE *db)
{
    return db_size(db) / sizeof(module);
}


//select

//insert

//update

//delete

//move module by id to specified memory level and cell

//set protection for module*

//set protection for memory*

//get all active modules

//chose table

//show table