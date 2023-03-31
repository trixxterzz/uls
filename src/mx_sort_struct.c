#include "../inc/uls.h"

void mx_sort_struct(int size, t_lflag info[size]) {
    t_lflag temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (mx_strcmp(info[j].name, info[j + 1].name) > 0) {
                temp = info[j];
                info[j] = info[j + 1];
                info[j + 1] = temp;
            }
        }
    }
}

void mx_sort_structReverse(t_lflag *info, int size) {
    t_lflag temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (mx_strcmp(info[j].name, info[j + 1].name) < 0) {
                temp = info[j];
                info[j] = info[j + 1];
                info[j + 1] = temp;
            }
        }
    }
}

void mx_sort_structBySize(t_lflag *info, int count) {
    t_lflag temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (info[j].size < info[j + 1].size) {
                temp = info[j];
                info[j] = info[j + 1];
                info[j + 1] = temp;
            }
        }
    }
}

void mx_sort_structBySizeReverse(t_lflag *info, int count) {
    t_lflag temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (info[j].size > info[j + 1].size) {
                temp = info[j];
                info[j] = info[j + 1];
                info[j + 1] = temp;
            }
        }
    }
}

