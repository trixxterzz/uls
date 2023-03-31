#include "../inc/uls.h"

void mx_outputFlagL(int count, long total, t_lflag info[count], char *flags){
    if (mx_strchr(flags, 'S') && mx_strchr(flags, 'r')){
        mx_sort_structBySizeReverse(info, count);
    }
    else if(mx_strchr(flags, 'S')){
        mx_sort_structBySize(info, count);
    }
    else if (mx_strchr(flags, 'r')){
        mx_sort_structReverse(info, count);
    }
    else {
        mx_sort_struct(count, info);
    }
    if(total != 0){
        mx_printstr("total ");
        mx_printLong(total);
        mx_printstr("\n");
    }
    t_list *strSizes = NULL;
    int longestStrSize = 0;
    if(mx_strchr(flags, 'h')){
        strSizes = mx_intSizetoStr(count, info);
        longestStrSize = mx_longestStrSize(strSizes);
    }
    t_list *buff = strSizes;
    int longest = mx_longestSize(count, info);
    int longestDate = mx_longestDate(count, info);
    int longestLink = mx_longestLink(count, info);
    for (int i = 0; i < count; i++) {
        mx_printstr(info[i].permissions);
        mx_printstr(" ");
        int raznitsaLink = longestLink - mx_sizeLen(info[i].links);
        for (int j = 0; j < raznitsaLink; j++){
            mx_printstr(" ");
        }
        mx_printint(info[i].links);
        mx_printstr(" ");
        mx_printstr(info[i].user);
        mx_printstr(" ");
        mx_printstr(info[i].group);
        mx_printstr(" ");
        if (mx_strchr(flags, 'h')){
            int raznitsa = longestStrSize - mx_strlen((const char *)buff->data);
            for (int j = 0; j < raznitsa; j++){
                mx_printstr(" ");
            }
            mx_printstr((const char *)buff->data);
            buff = buff->next;
        }
        else {
            int raznitsa = longest - mx_sizeLen(info[i].size);
            for (int j = 0; j < raznitsa; j++){
                mx_printstr(" ");
            }
            mx_printLong(info[i].size);
        }
        mx_printstr(" ");
        int raznitsaDate = longestDate - mx_strlen(info[i].date);
        for (int j = 0; j < raznitsaDate; j++){
            mx_printstr(" ");
        }
        mx_printstr(info[i].date);
        mx_printstr(" ");
        mx_printstr(info[i].name);
        mx_printstr("\n");
    }
    mx_clearSizeList(&strSizes);
}

