#include "../inc/uls.h"

int mx_longestDate(int count, t_lflag info[count]){
    int longest = 0;
    for (int i = 0; i < count; i++){
        if(mx_strlen(info[i].date) > longest) longest = mx_strlen(info[i].date);
    }
    return longest;
}

