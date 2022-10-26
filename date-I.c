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

        printf("%d-",1900+tmp->tm_year);
        printf("%d-",tmp->tm_mon+1);
        printf("%d\n",tmp->tm_mday);
    }
    
    return 0;
}