#include "../inc/uls.h"

char *mx_checkForFlags(int size, char *arr[]){
    int len = 0;
    bool h = false;
    bool r = false;
    bool t = false;
    bool a = false;
    bool A = false;
    bool u = false;
    bool l = false;
    bool R = false;
    bool S = false;
    bool flag1 = false;
    if (isatty(STDOUT_FILENO) == 0) flag1 = true;
    for (int i = 1; i < size; i++){
        if (arr[i][0] != '-') continue;
        for(int j = 0; j < 8; j++){
            char *buff = arr[i];
            if(mx_strchr(buff, 'h')) h = true;
            if(mx_strchr(buff, 'r')) r = true;
            if(mx_strchr(buff, 't')) t = true;
            if(mx_strchr(buff, 'a')) a = true;
            if(mx_strchr(buff, 'A')) A = true;
            if(mx_strchr(buff, 'u')) u = true;
            if(mx_strchr(buff, 'l')) l = true;
            if(mx_strchr(buff, 'R')) R = true;
            if(mx_strchr(buff, 'S')) S = true;
            if(mx_strchr(buff, '1')) flag1 = true;
        }
    }
    if (h == true) len++;
    if (r == true) len++;
    if (t == true) len++;
    if (a == true) len++;
    if (A == true) len++;
    if (u == true) len++;
    if (l == true) len++;
    if (R == true) len++;
    if (S == true) len++;
    if (flag1 == true) len++;
    char *flags = mx_strnew(len);
    char *buff = flags;
    if (h == true){
        *flags = 'h';
        flags++;
    }
    if (r == true){
        *flags = 'r';
        flags++;
    }
    if (t == true){
        *flags = 't';
        flags++;
    }
    if (a == true){
        *flags = 'a';
        flags++;
    }
    if (A == true){
        *flags = 'A';
        flags++;
    }
    if (u == true){
        *flags = 'u';
        flags++;
    }
    if (l == true){
        *flags = 'l';
        flags++;
    }
    if (R == true){
        *flags = 'R';
        flags++;
    }
    if (S == true){
        *flags = 'S';
        flags++;
    }
    if (flag1 == true){
        *flags = '1';
        flags++;
    }
    return buff;
}

