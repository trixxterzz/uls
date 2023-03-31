#include "../inc/uls.h"

void mx_outputDirR(t_list *list, char *flags){
    t_list *head = list;
    t_list *buff = NULL;
    int longest[8];
    int longestStep = 0;
    int count = mx_list_size(list);
    if (mx_strchr(flags, '1')){
        buff = list;
        while (buff != NULL){
            mx_printstr((const char *)buff->data);
            mx_printstr("\n");
            buff = buff->next;
        }
        return;
    }
    if (count / 8 > 0){
        int currLongest = 0;
        int step = 0;
        int k = 0;
        for (int i = 0; i < 8; i++){
            buff = list;
            for (int j = 0; j < step; j++){
                buff = buff->next;
            }
            for(int j = 0; j < (count / 8 + 1); j++){
                if(buff == NULL) break;
                if (mx_strlen((const char *)buff->data) > currLongest) currLongest = mx_strlen((const char *)buff->data);
                buff = buff->next;
            }
            longest[k] = currLongest;
            k++;
            step += count / 8;
            currLongest = 0;
        }
    }
    for (int i = 0; i < (count / 8 + 1); i++){
        head = list;
        for (int j = 0; j < i; j++){
            head = head->next;
        }
        for (int j = 0; j < count; j+= (count / 8 + 1)){
            mx_printstr((const char *)head->data);
            mx_printstr("  ");
            if (count / 8 > 0 && mx_strlen((const char *)head->data) < longest[longestStep]){
                for(int f = 0; f < (longest[longestStep] - mx_strlen((const char *)head->data)); f++){
                    mx_printstr(" ");
                }
                
            }
            longestStep++;
            for (int f = 0; f < (count / 8 + 1); f++) if (head->next != NULL) head = head->next;
        }
        mx_printstr("\n");
        longestStep = 0;
    }
    while(buff != NULL){
        mx_printstr((const char *)buff->data);
        if(buff->next != NULL) mx_printstr(" ");
        buff = buff->next;
    }
    mx_printstr("\n");
}
