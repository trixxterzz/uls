#include "../inc/uls.h"

int mx_printpath(const char *name, const char *filename, int printflag) {
        if(mx_strcmp(name, ".") == 0){
            char *result = mx_strnew(mx_strlen((char *)filename) + 2);
            mx_memset(result, 0, mx_strlen(result));
            mx_strcat(result, ".");
            mx_strcat(result, "/");
            mx_strcat(result, filename);
            mx_printstr(result);
            free(result);
            return 0;
        }
        else {
            if (printflag == 1) {
                if (mx_strcmp(name, filename) != 0) {
                    char *result = mx_strnew(mx_strlen((char*) name) + mx_strlen((char*)filename) + 1);
                    mx_memset(result, 0, mx_strlen(result));
                    mx_strcat(result, name);
                    mx_strcat(result, "/");
                    mx_strcat(result, filename);
                    mx_printstr(result);
                    return 0;
                }
                else {
                    char *result = mx_strnew(mx_strlen((char*)filename));
                    mx_strcat(result, filename);
                    mx_printstr(result);
                    free(result);
                    return 1;
                }
            }
            else {
                char *result = mx_strnew(mx_strlen((char*) name) + mx_strlen((char*)filename) + 3);
                mx_memset(result, 0, mx_strlen(result));
                mx_strcat(result, ".");
                mx_strcat(result, "/");
                mx_strcat(result, name);
                mx_strcat(result, "/");
                mx_strcat(result, filename);
                mx_printstr(result);
                free(result);
                return 0;
            }
        }
}

