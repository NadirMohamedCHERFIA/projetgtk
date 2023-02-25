#ifndef __DIRECTORY_H__
#define __DIRECTORY_H__
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
extern int errno;
int create_new_folder(char *username){
const char path[255];
g_print("TEST");
g_print("%s",username);
// printf("CHERFIA CREATING ...");
strcpy(path,"Data/");
strcat(path,username);
g_print("%s",path);
    if(mkdir(path,0777)==-1){
        perror("ERROR");
        return 1;
    }
    return 0;
}


#endif