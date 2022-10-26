#include<stdio.h>
#include<sys/types.h>
#include <syscall.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include <fcntl.h>
#include<time.h>



int main(char *arg[],char *argv[]){
    time_t times = time(NULL);
    struct tm *tmp;
    tmp = localtime(&times);



    if (tmp==NULL){
        printf("Request denied.");
    }
    else{
        // printf("    tm_sec   = %d\n", tmp->tm_sec);
        // printf("    tm_min   = %d\n", tmp->tm_min);
        // printf("    tm_hour  = %d\n", tmp->tm_hour);
        // printf("    tm_mday  = %d\n", tmp->tm_mday);
        // printf("    tm_mon   = %d\n", tmp->tm_mon);
        // printf("    tm_year  = %d\n", tmp->tm_year);
        // printf("    tm_wday  = %d\n", tmp->tm_wday);
        // printf("    tm_yday  = %d\n", tmp->tm_yday);
        // printf("    tm_isdst = %d\n", tmp->tm_isdst);
        // printf("%d ",tmp->tm_wday);
        // printf("%d ",tmp->tm_mday);
        printf("%s",asctime(tmp));
    }
    
    return 0;
}