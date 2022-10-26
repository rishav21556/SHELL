#include<stdio.h>
#include<sys/types.h>
#include <syscall.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include <fcntl.h>  
//https://man7.org/linux/man-pages/man2/open.2.html
int main(int argc,char *a[3]){
    // printf("%s\n",a[]);
    //printf("hi\n");

    int check ;
    if (strcmp(a[0],"/mnt/c/Users/Rishav Raj/OneDrive/Desktop/OS_Assignment1/cat.out")==0){
        check = 1;
    }
    else {
        check = 0;
    }

    if (strcmp(a[check],"-n")==0){

        char path[100];
        getcwd(path,100);
        strcat(path,"/");
        strcat(path,a[check+1]);
        //printf("%s\n",path);

        int fd = open(path,O_RDONLY);            //fd-> file descriptor entry
        if (fd>0){
            char *buffer = (char *)calloc(10000,sizeof(char));
            int readr  = read(fd,buffer,10000);
            buffer[readr] = '\0';
            if (readr>=0){
                int count = 1;
                int i = 0;
                printf("%d ",count);
                while(buffer[i]!='\0'){
                    if (buffer[i]=='\n'){
                        count++;
                        printf("\n");
                        printf("%d ",count);
                        i++;
                    }
                    else{
                        printf("%c",buffer[i]);
                        i++;
                    }
                }
                printf("\n");
                //printf("%s\n",buffer);                  
            }
        }
        else{
            printf("BASH: no such file\n");
        }

    }
    else if (strcmp(a[check],"-T")==0){
        char path[100];
        getcwd(path,100);
        strcat(path,"/");
        strcat(path,a[check+1]);
        //printf("%s\n",path);

        int fd = open(path,O_RDONLY);            //fd-> file descriptor entry
        if (fd>0){
            char *buffer = (char *)calloc(10000,sizeof(char));
            int readr  = read(fd,buffer,10000);
            buffer[readr] = '\0';
            if (readr>=0){
                int i = 0;
                while(buffer[i]!='\0'){
                    if (buffer[i]=='\t'){
                        printf("^I");
                        i++;
                    }
                    else{
                        printf("%c",buffer[i]);
                        i++;
                    }
                }
                printf("\n");
                //printf("%s\n",buffer);                  
            }
        }
        else{
            printf("BASH: no such file\n");
        }

    }
    else{
        char path[100];
        getcwd(path,100);
        strcat(path,"/");
        strcat(path,a[check]);
        //printf("%s\n",path);

        int fd = open(path,O_RDONLY);            //fd-> file descriptor entry
        if (fd>0){
            char *buffer = (char *)calloc(10000,sizeof(char));
            int readr  = read(fd,buffer,10000);
            buffer[readr] = '\0';
            if (readr>=0){
                printf("%s\n",buffer);                  
            }
        }
        else {
            printf("BASH: no such file\n");
        }
    }
}