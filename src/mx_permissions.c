#include "../inc/uls.h"

char *mx_permissions(mode_t mode, const char *path) {
    char *permission = mx_strnew(11);
    struct stat st;
    if (stat(path, &st) != -1) {
    permission[0] = *((S_ISDIR(mode)) ? "d" : "-");
    permission[1] = *((mode & S_IRUSR) ? "r" : "-");
    permission[2] = *((mode & S_IWUSR) ? "w" : "-");
    permission[3] = *((mode & S_IXUSR) ? "x" : "-");
    permission[4] = *((mode & S_IRGRP) ? "r" : "-");
    permission[5] = *((mode & S_IWGRP) ? "w" : "-");
    permission[6] = *((mode & S_IXGRP) ? "x" : "-");
    permission[7] = *((mode & S_IROTH) ? "r" : "-");
    permission[8] = *((mode & S_IWOTH) ? "w" : "-");
    permission[9] = *((mode & S_IXOTH) ? "x" : "-");
    }
    if (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0) {
        permission[10] = '@';
    } 
    else if (acl_get_file(path, ACL_TYPE_EXTENDED) != NULL) {
            permission[10] = '+';
    } 
    else {
        permission[10] = '\0';
    }
    return permission;
}


