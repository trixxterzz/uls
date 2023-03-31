#include "../inc/uls.h"

char *mx_toLower(char *arg){
    for(int i = 0; i < mx_strlen(arg); i++){
        if(arg[i] > 64 && arg[i] < 91) arg[i] += 32;
    }
    return arg;
}

bool alphaSort(void *s1, void *s2){
    char *arg1 = mx_strnew(mx_strlen((const char *)s1));
    char *arg2 = mx_strnew(mx_strlen((const char *)s2));
    arg1 = mx_strcpy(arg1, (char *)s1);
    arg2 = mx_strcpy(arg2, (char *)s2);
    if(mx_strcmp(mx_toLower(arg1), mx_toLower(arg2)) > 0){
        free(arg1);
        free(arg2);
        return true;
    }
    free(arg1);
    free(arg2);
    return false;
}

bool alphaSortReverse(void *s1, void *s2){
    char *arg1 = mx_strnew(mx_strlen((const char *)s1));
    char *arg2 = mx_strnew(mx_strlen((const char *)s2));
    arg1 = mx_strcpy(arg1, (char *)s1);
    arg2 = mx_strcpy(arg2, (char *)s2);
    if(mx_strcmp(mx_toLower(arg1), mx_toLower(arg2)) > 0){
        free(arg1);
        free(arg2);
        return false;
    }
    free(arg1);
    free(arg2);
    return true;
}

