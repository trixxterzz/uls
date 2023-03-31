#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)){
    if (lst == NULL || cmp == NULL) return lst;
    bool isSorted = true;
    while(isSorted){
        isSorted = false;
        for(t_list *cur = lst; cur->next != NULL; cur = cur->next){
            t_list *tmp = cur;
            t_list *nxt = tmp->next;
            if(cmp(cur->data, nxt->data)){
                void *tmp_data = tmp->data;
                tmp->data = nxt->data;
                nxt->data = tmp_data;
                isSorted = true;
            }
        }
    }
    return lst;
}

