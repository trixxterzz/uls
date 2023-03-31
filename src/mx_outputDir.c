#include "../inc/uls.h"

void mx_outputDir(int count, t_lflag info[count], char *flags){
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
    if (mx_strchr(flags, '1')){
        for (int i = 0; i < count; i++){
            mx_printstr(info[i].name);
            mx_printstr("\n");
        }
        return;
    }
    int longest[8];
    int longestStep = 0;
    if (count / 8 > 0){
        int currLongest = 0;
        int step = 0;
        int k = 0;
        for (int i = 0; i < 8; i++){
            for (int j = 0 + step; j < (count / 8 + 1) + step; j++){
                if(j > count - 1) break;
                if (mx_strlen(info[j].name) > currLongest) currLongest = mx_strlen(info[j].name);
            }
            longest[k] = currLongest;
            step += (count / 8 + 1);
            k++;
            currLongest = 0;
        }
    }
    for (int i = 0; i < (count / 8 + 1); i++){
        for (int j = i; j < count; j += (count / 8 + 1)){
            mx_printstr(info[j].name);
            mx_printstr("  ");
            if (count / 8 > 0 && mx_strlen(info[j].name) < longest[longestStep]){
                for(int f = 0; f < (longest[longestStep] - mx_strlen(info[j].name)); f++){
                    mx_printstr(" ");
                }
                
            }
            longestStep++;
        }
        mx_printstr("\n");
        longestStep = 0;
    }
}



