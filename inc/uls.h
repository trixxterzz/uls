#pragma once

#include "../libmx/inc/libmx.h"
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/xattr.h>
#include <sys/acl.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

typedef struct s_lflag {
    char* permissions;
    int links;
    char* user;
    char* group;
    long size;
    char* date;
    char* name;
}               t_lflag;

bool alphaSort(void *s1, void *s2);
bool alphaSortReverse(void *s1, void *s2);
bool alphaSortReverse(void *s1, void *s2);
t_list *mx_parseDir(DIR *dir, char *flags);
void mx_outputDir(int count, t_lflag info[count], char *flags);
void mx_clearDir(t_list **list);
void mx_flag_L(t_list *list, char *flags);
void mx_flag_R(t_list *dirname, int printflag, int sortflag, char *flags);
char* mx_permissions(mode_t mode, const char *path);
void mx_sort_struct(int size, t_lflag info[size]);
char *mx_toLower(char *arg);
long mx_longestSize(int arrSize, t_lflag arr[arrSize]);
int mx_sizeLen(long size);
char *mx_pathfinder(const char *name, const char *filename);
void mx_outputFlagL(int count, long total, t_lflag info[count], char *flags);
void mx_clearStruct(int size, t_lflag info[size]);
char *mx_checkForFlags(int size, char *arr[]);
void mx_sort_structReverse(t_lflag *info, int size);
int *mx_longestName(int count, t_lflag info[count]);
int mx_longestStrSize(t_list *list);
t_list *mx_intSizetoStr(int count, t_lflag info[count]);
void mx_clearSizeList(t_list **list);
int mx_printpath(const char *name, const char *filename, int printflag);
void mx_withoutflags(const char *dirname, char *flags);
void mx_outputDirR(t_list *list, char *flags);
void mx_sort_structBySize(t_lflag *info, int count);
void mx_sort_structBySizeReverse(t_lflag *info, int count);
void mx_clearStructR(int size, t_lflag info[size]);
int mx_longestDate(int count, t_lflag info[count]);
int mx_longestLink(int arrSize, t_lflag arr[arrSize]);
void mx_printLong(long n);

