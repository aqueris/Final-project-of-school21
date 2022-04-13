#include "output.h"

void menu() {
    printf(" Please choose operation");
    printf("   1  SELECT");
    printf("   2  INSERT");
    printf("   3  DELETE");
    printf("   4  UPDATE");
    printf("   5 Get all active modules");
    printf("   6 Delete module by id");
    printf("   7 Set protect for module by ib");
    printf("   8 Move by id to specified level and cell");
    printf("   9 Set protect for memory level");
}

void error() {
    printf("n/a");
    system("exit");
}