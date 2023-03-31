#include "../inc/uls.h"

void mx_withoutflags(const char *dirname, char *flags) {
        DIR *cur = opendir(dirname);
        t_list *dirInside = mx_parseDir(cur, flags);
        mx_outputDirR(dirInside, flags);
        mx_clearDir(&dirInside);
        closedir(cur);
}
