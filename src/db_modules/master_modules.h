#ifndef MASTER_MODULES_H
#define MASTER_MODULES_H

#include "../libs/libs.h"

typedef struct {
    int id;
    char name[30];
    int memory_level;
    int cell_number;
    int delete_flag;
    } module;

module get_record(FILE *database, int id);
int database_size(FILE *database);
int record_count(FILE *database);

#endif