#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>

void _showdir(DIR *pointer){
	struct dirent *de;
	while((de=readdir(pointer))!=NULL){
		printf("%s\n",de->d_name);
	}
	closedir(pointer);
	
}


void main(char *arg[],char *argv[]){
	//printf("hi");
	
    char *path = (char*)malloc(100*sizeof(char));
    //printf("%s",getcwd(path,100));
    getcwd(path,100);
    DIR *pointerTodirectory = opendir(path);
    _showdir(pointerTodirectory);	
}