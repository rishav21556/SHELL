#include<stdio.h>
#include<sys/types.h>
#include <syscall.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include <fcntl.h>

int main(int argc,char *a[3]){
    int check ;
    if (strcmp(a[0],"/mnt/c/Users/Rishav Raj/OneDrive/Desktop/OS_Assignment1/rm.out")==0){
        check = 1;
    }
    else{
            check = 0;
    }
    if ((a[check+1]!=NULL) && (strcmp(a[check],"-d")==0 || strcmp(a[check+1],"-d")==0)){
        int i;
        if (strcmp(a[check+1],"-d")==0 && strcmp(a[check],"-i")==0){
            if (check==1){
                i = 3;
            }
            else{
                i = 2;
            }
            
        }
        else if (strcmp(a[check],"-d")==0 && strcmp(a[check+1],"-d")==0){
            printf("BASH : INVALID COMMAND\n");
            return 0;
        }
        else if (strcmp(a[check],"-d")==0){
            if (check==1){
                i = 2;
            }
            else{
                i = 1;
            }
            
        }
        
        while(a[i]!=NULL && strcmp(a[i],"NULL")!=0){
            if (strcmp(a[0],"-i")==0){
                char ans[10];
                printf("do you want to delete %s (y|else): ",a[i]);
                scanf("%s",ans);
                if (strcmp(ans,"y")!=0){
                    i++;
                    continue;
                }
            }
            char path[100];
            getcwd(path,100);
            strcat(path,"/");
            strcat(path,a[i]);
            i++;
            //DIR *pointerToDirectory = opendir(path);
            DIR *pointerTOdirectory = opendir(path);
            if (pointerTOdirectory==NULL){
                printf("cannot remove %s : is not a directory\n",a[i-1]);
            }
            else{
                struct dirent *de;
                int count = 0;
                while((de=readdir(pointerTOdirectory))!=NULL){
                    char copy[100];
                    strcpy(copy,de->d_name);
                    count++;
                }
                if (count>2){
                    printf("cannot remove %s : is not an empty directory\n",a[i-1]);
                }
                else{
                    int status = remove(path);
                    if(status==-1){
                        perror("BASH");
                    }
                }
            }
        }
        if (a[1]==NULL  && strcmp(a[i],"NULL")!=0){
            printf("rm: missing operand\n");
        }
    }
    else{
        int i;
        if (check ==1){
            if (strcmp(a[1],"-i")==0){
                i = 2;
            }
            else{
                i = 1;
            }
        }
        else {
            if (strcmp(a[0],"-i")==0){
                i = 1;
            }
            else{
                i = 0;
            }
        }
        while(a[i]!=NULL  && strcmp(a[i],"NULL")!=0){
            if (strcmp(a[check],"-i")==0){
                char ans[10];
                printf("do you want to delete %s (y|else): ",a[i]);
                scanf("%s",ans);
                if (strcmp(ans,"y")!=0){
                    i++;
                    continue;
                }
            }
            char path[100];
            getcwd(path,100);
            strcat(path,"/");
            strcat(path,a[i]);
            i++;
            DIR *pointerTOdirectory = opendir(path);
            if (pointerTOdirectory==NULL){
                int status = remove(path);
                if(status==-1){
                    perror("BASH");
                }
            }
            else{
                printf("cannot remove %s : is a directory\n",a[i-1]);
            }
        }
    }
    return 0;
}