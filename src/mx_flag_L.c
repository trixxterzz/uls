#include "../inc/uls.h"

void mx_flag_L(t_list *list, char *flags) {
    if (list == NULL) return;
    t_list *head = list;
    DIR *dir;
    struct dirent *d;
    struct stat file_stat;
    struct passwd *pwd = NULL;
    struct group *grp = NULL;
    dir = opendir((const char *)head->data);
    bool isFileList = false;
    if (errno == 20){
        isFileList = true;
    }
    else {
        closedir(dir);
    }
    if (isFileList){
        int count = 0;
        t_lflag *info = (t_lflag*) malloc(sizeof(t_lflag) * mx_list_size(list));
        while (head != NULL){
            info[count].name = mx_strnew(mx_strlen((const char *)head->data));
            mx_strcpy(info[count].name, (char *)(const char *)head->data);
            char *result = mx_pathfinder((const char *)head->data, (const char *)head->data);
            if (stat(result, &file_stat) == 0) {
                char *path = mx_pathfinder((const char *)head->data, (const char *)head->data);
                info[count].permissions = mx_permissions(file_stat.st_mode, path);
                free(path);
                info[count].links = (int)file_stat.st_nlink;
                if ((pwd = getpwuid(file_stat.st_uid)) != NULL) {
                info[count].user = mx_strnew(mx_strlen(pwd->pw_name));
                    mx_strcpy(info[count].user, pwd->pw_name);
                }
                if ((grp = getgrgid(file_stat.st_gid)) != NULL) {
                    info[count].group = (char *) mx_strnew(mx_strlen(grp->gr_name));
                    mx_strcpy(info[count].group, grp->gr_name);
                }
                info[count].size = (int)file_stat.st_size;
                char *raw = mx_strnew(mx_strlen(ctime(&file_stat.st_mtime)));
                mx_strncpy(raw, ctime(&file_stat.st_mtime), mx_strlen(ctime(&file_stat.st_mtime)));
                char *date_parsed;
                if (time(NULL) - file_stat.st_mtime > 15724800) {
                    date_parsed = mx_strnew(13);
                    mx_memcpy(date_parsed, raw + 4, 7);
                    mx_memcpy(date_parsed + 7, raw + 20, 5);
                }
                else {
                    char *bufferidze = mx_strndup(raw + 4, 13);
                    date_parsed = mx_strnew(mx_strlen(bufferidze));
                    mx_strncpy(date_parsed, bufferidze, mx_strlen(bufferidze));
                    free(bufferidze);
                }
                info[count].date = mx_strnew(mx_strlen(date_parsed));
                mx_strncpy(info[count].date, date_parsed, mx_strlen(date_parsed) - 1);
                free(raw);
                free(date_parsed);
                count++;
            }
            free(result);
            head = head->next;
        }
        if (mx_strchr(flags, 'l')){
            mx_outputFlagL(count, 0, info, flags);
        }
        else {
            mx_outputDir(count, info, flags);
        }
        mx_clearStruct(count, info);
    }
    else {
        while (head != NULL){
            dir = opendir((const char *)head->data);
            long total = 0;
            int count = 0;
            while ((d = readdir(dir)) != NULL) {
                if(!mx_strchr(flags, 'a')){
                    if ((d->d_name[0] == '.' && !mx_strchr(flags, 'A')) || ((mx_strcmp(d->d_name, ".") == 0 || mx_strcmp(d->d_name, "..") == 0) && mx_strchr(flags, 'A'))) {
                    continue;
                    }
                    else {
                        count++;
                    }
                }
                else {
                    count++;
                }
            }
            t_lflag *info = (t_lflag*) malloc(sizeof(t_lflag) * count);
            closedir(dir);
            int i = 0;
            dir = opendir((const char *)head->data);
            while ((d = readdir(dir)) != NULL) {
                if(!mx_strchr(flags, 'a')){
                    if((d->d_name[0] == '.' && !mx_strchr(flags, 'A')) || ((mx_strcmp(d->d_name, ".") == 0 || mx_strcmp(d->d_name, "..") == 0) && mx_strchr(flags, 'A'))){
                        continue;
                    }
                    else {
                        info[i].name = mx_strnew(mx_strlen(d->d_name));
                        mx_strcpy(info[i].name, d->d_name);
                    }
                }
                else {
                    info[i].name = mx_strnew(mx_strlen(d->d_name));
                    mx_strcpy(info[i].name, d->d_name);
                }
                char *result = mx_pathfinder((const char *)head->data, d->d_name);
                if (stat(result, &file_stat) == 0) {
                    total += (long)file_stat.st_blocks;
                    char *path = mx_pathfinder((const char *)head->data, d->d_name);
                    info[i].permissions = mx_permissions(file_stat.st_mode, path);
                    free(path);
                    info[i].links = (int)file_stat.st_nlink;
                    if ((pwd = getpwuid(file_stat.st_uid)) != NULL) {
                        info[i].user = mx_strnew(mx_strlen(pwd->pw_name));
                        mx_strcpy(info[i].user, pwd->pw_name);
                    }
                    if ((grp = getgrgid(file_stat.st_gid)) != NULL) {
                        info[i].group = (char *) mx_strnew(mx_strlen(grp->gr_name));
                        mx_strcpy(info[i].group, grp->gr_name);
                    }
                    info[i].size = (long)file_stat.st_size;
                    char *raw = mx_strnew(mx_strlen(ctime(&file_stat.st_mtime)));
                    mx_strncpy(raw, ctime(&file_stat.st_mtime), mx_strlen(ctime(&file_stat.st_mtime)));
                    char *date_parsed;
                    if (time(NULL) - file_stat.st_mtime > 15724800) {
                        date_parsed = mx_strnew(13);
                        mx_memcpy(date_parsed, raw + 4, 7);
                        mx_memcpy(date_parsed + 7, raw + 20, 5);
                    }
                    else {
                        char *bufferidze = mx_strndup(raw + 4, 13);
                        date_parsed = mx_strnew(mx_strlen(bufferidze));
                        mx_strncpy(date_parsed, bufferidze, mx_strlen(bufferidze));
                        free(bufferidze);
                    }
                    info[i].date = mx_strnew(mx_strlen(date_parsed));
                    mx_strncpy(info[i].date, date_parsed, mx_strlen(date_parsed) - 1);
                    free(raw);
                    free(date_parsed);
                }
                free(result);
                i++;
            }
            closedir(dir);
            if (mx_list_size(list) > 1){
                mx_printstr((const char *)head->data);
                mx_printstr(":\n");
            }
            if (mx_strchr(flags, 'l')){
                mx_outputFlagL(count, total, info, flags);
            }
            else {
                mx_outputDir(count, info, flags);
            }
            if(head->next != NULL) mx_printstr("\n");
            head = head->next;
            mx_clearStruct(count, info);
        }
    }
}

