#include "../inc/uls.h"

void mx_clearDir(t_list **list){
    if(list == NULL) return;
    t_list *head = *list;
    while(head != NULL){
        t_list *buff = head;
        head = head->next;
        free(buff);
    }
    *list = NULL;
    return;
}
