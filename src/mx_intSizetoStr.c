#include "../inc/uls.h"

t_list *mx_intSizetoStr(int count, t_lflag info[count]){
    t_list *strSizes = NULL;
    for (int j = 0; j < count; j++){
        if (info[j].size > 10737418240){
            char *tenBillions = mx_itoa(info[j].size / 1073741824);
            char *toPush = mx_strjoin(tenBillions, "G");
            mx_push_back(&strSizes, (void *)toPush);
            free(tenBillions);
        }
        if (info[j].size > 1073741824){
            char *billions = mx_itoa(info[j].size / 1073741824);
            char *buff1 = mx_strjoin(billions, ",");
            free(billions);
            int hundredMillionInt = info[j].size % 1073741824;
            char *hundredMillion = mx_itoa(hundredMillionInt / 100000000);
            char *buff2 = mx_strjoin(buff1, hundredMillion);
            free(buff1);
            free(hundredMillion);
            char *toPush = mx_strjoin(buff2, "G");
            free(buff2);
            mx_push_back(&strSizes, (void *)toPush);
        }
        else if (info[j].size > 10485760){
            char *tenMillions = mx_itoa(info[j].size / 1048576);
            char *toPush = mx_strjoin(tenMillions, "M");
            mx_push_back(&strSizes, (void *)toPush);
            free(tenMillions);
        }
        else if (info[j].size > 1048576){
            char *millions = mx_itoa(info[j].size / 1048576);
            char *buff1 = mx_strjoin(millions, ",");
            free(millions);
            int hundredThousandInt = info[j].size % 1048576;
            char *hundredThousand = mx_itoa(hundredThousandInt / 102400);
            char *buff2 = mx_strjoin(buff1, hundredThousand);
            free(buff1);
            free(hundredThousand);
            char *toPush = mx_strjoin(buff2, "M");
            free(buff2);
            mx_push_back(&strSizes, (void *)toPush);
        }
        else if (info[j].size > 10240){
            char *tenThousands = mx_itoa(info[j].size / 1024);
            char *toPush = mx_strjoin(tenThousands, "K");
            mx_push_back(&strSizes, (void *)toPush);
            free(tenThousands);
        }
        else if(info[j].size > 1024){
            char *thousands = mx_itoa(info[j].size / 1024);
            char *buff1 = mx_strjoin(thousands, ",");
            free(thousands);
            int hundredsInt = info[j].size % 1024;
            char *hundreds = mx_itoa(hundredsInt / 100);
            char *buff2 = mx_strjoin(buff1, hundreds);
            free(buff1);
            free(hundreds);
            char *toPush = mx_strjoin(buff2, "K");
            free(buff2);
            mx_push_back(&strSizes, (void *)toPush);
        }
        else if(info[j].size < 1000){
            mx_push_back(&strSizes, mx_itoa(info[j].size));
        }
    }
    return strSizes;
}

