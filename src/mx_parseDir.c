#include "../inc/uls.h"

t_list *mx_parseDir(DIR *dir, char *flags){
    struct dirent *entry;
    bool isEmpty = true;
    t_list *list = NULL;
    while((entry = readdir(dir)) != NULL){
        if(!mx_strchr(flags, 'a')){
            if ((entry->d_name[0] == '.' && !mx_strchr(flags, 'A')) || 
            ((mx_strcmp(entry->d_name, ".") == 0 || mx_strcmp(entry->d_name, "..") == 0) && mx_strchr(flags, 'A'))) continue;
        }
        mx_push_front(&list, (void *)entry->d_name);
        isEmpty = false;
    }
    if (isEmpty == true){
        return NULL;
    }
    t_list *sortedList = mx_sort_list(list, alphaSort);
    return sortedList;
}
