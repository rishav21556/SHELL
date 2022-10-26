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
        //printf("%s",asctime(tmp));

        if (tmp->tm_wday==0){printf("Sun, ");}
        else if (tmp->tm_wday==1){printf("Mon, ");}
        else if (tmp->tm_wday==2){printf("Tue, ");}
        else if (tmp->tm_wday==3){printf("Wed, ");}
        else if (tmp->tm_wday==4){printf("Thur, ");}
        else if (tmp->tm_wday==5){printf("Fri, ");}
        else if (tmp->tm_wday==6){printf("Sat, ");}


        printf("%d ",tmp->tm_mday);


        if (tmp->tm_wday==0){printf("Jan ");}
        else if (tmp->tm_mon==1){printf("Feb ");}
        else if (tmp->tm_mon==2){printf("Mar ");}
        else if (tmp->tm_mon==3){printf("Apr ");}
        else if (tmp->tm_mon==4){printf("May ");}
        else if (tmp->tm_mon==5){printf("Jun ");}
        else if (tmp->tm_mon==6){printf("Jul ");}
        else if (tmp->tm_mon==7){printf("Aug ");}
        else if (tmp->tm_mon==8){printf("Sep ");}
        else if (tmp->tm_mon==9){printf("Oct ");}
        else if (tmp->tm_mon==10){printf("No, ");}
        else if (tmp->tm_mon==11){printf("De, ");}

        printf("%d ",1900+tmp->tm_year);
        printf("%d:",tmp->tm_hour);
        printf("%d:",tmp->tm_min);
        printf("%d ",tmp->tm_min);
        printf("+0530");

        printf("\n");
    }
    
    return 0;
}