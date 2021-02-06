#include "uls.h"

void mx_arguments_parse(t_uls **uls, t_flags *flag, char **argv, int argc) {
    int count = 1;
    (*uls)->flags = NULL;
    (*uls)->all_files = NULL;
    (*uls)->dirs = NULL;
    (*uls)->files = NULL;
    (*uls)->flag_l = false;

   
    mx_parse_flags(uls, argv, argc, &count);

    if (argc > 1 && (*uls)->flags != NULL) {
        mx_flags_manager(*uls, flag);
    }
   
    if (flag->l == true)
        (*uls)->flag_l = true;
    mx_parse_files_and_dirs(uls, argv, argc, count);
}
