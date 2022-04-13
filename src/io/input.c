#include "input.h"
#include "output.h"

int choosen_option(int *flag) {
    int inputed_flag = 0;
    char check_end;
    if (scanf("%d%c", flag, &check_end) != 2 && check_end != '\n') {
        inputed_flag = 0;
        error();
    } 
    if (1 >= *flag && *flag <= 9) {
        inputed_flag = *flag;
    }
    if (*flag >= 9) {
        inputed_flag = 0;
    }
    return inputed_flag;
}

int select_id(int *id) {
    int selected_id;
    char check_end;
    if (scanf("%d%c", id, &check_end) != 2 && check_end != '\n') {
        error();
    } else {
        selected_id = *id;
    }
    printf("%d", *id);
    return selected_id;
}