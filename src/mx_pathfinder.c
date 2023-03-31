#include "../inc/uls.h"

char *mx_pathfinder(const char *name, const char *filename) {
        if(mx_strcmp(name, filename) == 0){
            char *result = mx_strnew(mx_strlen((char *)name) + 3);
            mx_memset(result, 0, mx_strlen(result));
            mx_strcat(result, ".");
            mx_strcat(result, name);
            return result;
        }
        char *result = mx_strnew(mx_strlen((char*) name) + mx_strlen((char*)filename) + 3);
        mx_memset(result, 0, mx_strlen(result));
        if(name[0] != '/'){
            mx_strcat(result, ".");
            mx_strcat(result, "/");
            mx_strcat(result, name);
        }
        mx_strcat(result, "/");
        mx_strcat(result, filename);
        return result;
}
