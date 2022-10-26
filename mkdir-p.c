#include<stdio.h>
#include<sys/types.h>
#include <syscall.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include <fcntl.h>
#include<sys/stat.h>

int main(int argc,char *a[]){
    int check;
    if (strcmp(a[0],"/mnt/c/Users/Rishav Raj/OneDrive/Desktop/OS_Assignment1/mkdir-p.out")==0){
        check = 1;
    }
    else{
        check = 0;
    }
    int i;
    if (strcmp(a[check],"-v")==0){
        i = check+1;
    }
    else{
        i = check;
    }
    char path[100];
    getcwd(path,100);
    strcat(path,"/");
    while(a[i]!=NULL && strcmp(a[i],"NULL")!=0){
        //printf("%s\n",a[i]);
        if (strcmp(a[i],"-p")==0  || strcmp(a[i],"&t")==0){
            i++;
            continue;
        }
        strcat(path,a[i]);
        i++;
        int mk = mkdir(path,0777);
        if (strcmp(a[check],"-v")==0  && mk!=-1){
            printf("%s directory is created\n",a[i-1]);
        }
        if (mk==-1){
            printf("command failed\n");
        }
        strcat(path,"/");
    }
    return 0;
}