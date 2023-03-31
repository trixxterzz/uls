#include "../inc/uls.h"

long mx_longestSize(int arrSize, t_lflag arr[arrSize]){
    int longest = 0;
    for (int i = 0; i < arrSize; i++){
        long sizeLen = mx_sizeLen(arr[i].size);
        if (sizeLen > longest) longest = sizeLen;
    }
    return longest;
}

int mx_longestLink(int arrSize, t_lflag arr[arrSize]){
    int longest = 0;
    for (int i = 0; i < arrSize; i++){
        int sizeLen = mx_sizeLen(arr[i].links);
        if (sizeLen > longest) longest = sizeLen;
    }
    return longest;
}

