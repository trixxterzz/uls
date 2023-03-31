#include "../inc/uls.h"

int main(int argc, char *argv[]){
    t_list *fileList = NULL;
    t_list *dirList = NULL;
    int flagCount = 1;
    int sortflag = 0;
    for (int j = 0; j < argc; j++){
        if (argv[j][0] == '-') flagCount++;
    }
    for (int i = 1; i < argc; i++){
        if (argv[i][0] == '-') continue;
        DIR *cur = opendir(argv[i]);
        if (errno == 2){
            mx_printerr("uls: ");
            mx_printerr(argv[i]);
            mx_printerr(": No such file or directory\n");
            closedir(cur);
            exit(1);
        }
        if (errno == 20){
            mx_push_front(&fileList, (void *)argv[i]);
            continue;
        }
        mx_push_front(&dirList, (void *)argv[i]);
        closedir(cur);
    }
    char *flags = mx_checkForFlags(argc, argv);
    t_list *sortedFileList = NULL;
    t_list *sortedDirList = NULL;
    if(mx_strchr(flags, 'r')){
        sortedFileList = mx_sort_list(fileList, alphaSortReverse);
        sortedDirList = mx_sort_list(dirList, alphaSortReverse);
        sortflag = 1;
    }
    else {
        sortedFileList = mx_sort_list(fileList, alphaSort);
        sortedDirList = mx_sort_list(dirList, alphaSort);
    }
    if (argc == flagCount) mx_push_front(&sortedDirList, (void *)".");
    if (mx_strchr(flags, 'R')) {
        if (argc == flagCount) {
            mx_printstr(".");
            mx_printstr(":\n");
            char *path = mx_pathfinder((const char *)sortedDirList->data, (const char *)sortedDirList->data);
            mx_withoutflags(path, flags);
            mx_printstr("\n");
            mx_flag_R(sortedDirList, 0, sortflag, flags);
            free(path);
        }
        else {
            while (sortedDirList != NULL) {
                mx_printpath((const char *)sortedDirList->data, (const char *)sortedDirList->data, 1);
                mx_printstr(":\n");
                char *path = mx_pathfinder((const char *)sortedDirList->data, (const char *)sortedDirList->data);
                mx_withoutflags(path, flags);
                mx_printstr("\n");
                mx_flag_R(sortedDirList, 1, sortflag, flags);
                free(path);
                sortedDirList = sortedDirList->next;
            }
        }
    }
    else {
        mx_flag_L(sortedFileList, flags);
        if(sortedDirList != NULL && sortedFileList != NULL) mx_printstr("\n");
        mx_flag_L(sortedDirList, flags);
    }
    free(flags);
    mx_clearDir(&sortedDirList);
    mx_clearDir(&sortedFileList);
}

