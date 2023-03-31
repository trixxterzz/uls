#include "../inc/uls.h"

void mx_clearStruct(int size, t_lflag info[size]){
    for(int i = 0; i < size; i++){
            free(info[i].date);
            free(info[i].group);
            free(info[i].name);
            free(info[i].permissions);
            free(info[i].user);
    }
    free(info);
}

void mx_clearStructR(int size, t_lflag info[size]){
    for(int i = 0; i < size; i++){
            //free(info[i].date);
            //free(info[i].group);
            free(info[i].name);
            //free(info[i].permissions);
            //free(info[i].user);
    }
    free(info);
}

