#include "../inc/uls.h"

int mx_longestStrSize(t_list *list){
    int longest = 0;
    t_list *head = list;
    while (head != NULL){
        if (longest < mx_strlen((const char *)head->data)) longest = mx_strlen((const char *)head->data);
        head = head->next;
    }
    return longest;
}

