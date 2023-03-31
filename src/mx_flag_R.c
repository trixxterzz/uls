#include "../inc/uls.h"

void mx_flag_R(t_list *dirname, int printflag, int sortflag, char  *flags) {
    t_list* directories = NULL;
    t_list* sortedDirectories = NULL;
    DIR *dir = opendir((const char *)dirname->data);
    struct dirent *d;
    while ((d = readdir(dir)) != NULL) {
        if ((d->d_name[0] == '.' && !mx_strchr(flags, 'A')) || 
        ((mx_strcmp(d->d_name, ".") == 0 || mx_strcmp(d->d_name, "..") == 0) && mx_strchr(flags, 'A'))){
            continue;
        }
        DIR *curDir = opendir(d->d_name);
        if (curDir == NULL) {
            continue;
        }
        else {
            mx_printpath((const char *)dirname->data, d->d_name, printflag);
            mx_printstr(":\n");
            char *path = mx_pathfinder((const char *)dirname->data, d->d_name);
            mx_withoutflags(path, flags);
            mx_printstr("\n");
            mx_push_front(&directories, (void*)d->d_name);
            free(path);
        }
        closedir(curDir);
    }
    if (sortflag == 0) {
        sortedDirectories = mx_sort_list(directories, alphaSort);
    }
    else {
        sortedDirectories = mx_sort_list(directories, alphaSortReverse);
    }
    while(sortedDirectories != NULL) {
        mx_flag_R(sortedDirectories, printflag, sortflag, flags);
        sortedDirectories = sortedDirectories->next;
    } 
    closedir(dir);
    mx_clearDir(&sortedDirectories);
    mx_clearDir(&directories);                
}


