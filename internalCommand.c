#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/wait.h>
#include<pthread.h>

struct argThread{
	char lspath1[100];
	char *a[3];
};

void  blue(){
	printf("\033[0;34m");
}
void reset(){
	printf("\033[0m");
}
void green(){
	printf("\033[0;32m");
}
void showdir(DIR *pointer){
	struct dirent *de;
	while((de=readdir(pointer))!=NULL){
        char copy[100];
        strcpy(copy,de->d_name);
        if (copy[0]=='.'){
           // printf("hi");
            
            continue;
        }
		printf("%s\n",de->d_name);
	}
	closedir(pointer);
	
}

void* CALLTHREAD(void *arg){
	char a[100];
	strcpy(a,arg);
	//printf("%s \n",a);
	int ret = system(a);
	if (ret==1){
		
	}
}

//////////////////////////////////////////////////

void echo(int eflag ,char *str){
	int index = 0;
	char *ans  = (char *)malloc(sizeof(char)*100);
	for (int i= 0;i<strlen(str);i++){
		if (str[i]=='"' ){
			continue;
		}
		else{
			ans[index] = str[i];
			index++;
		}
	}
	printf("%s",ans);
}


int main(){
	char *args = (char*)malloc(100*sizeof(char));
	char lsPath[100] ;
	getcwd(lsPath,100);
	char exit[] = "exit";
	char *path = (char*)malloc(100*sizeof(char));
	getcwd(path,100);
	char pathForCd[100] ;
	strcpy(pathForCd,"/home/");
	DIR *pointerToHome = opendir("/home/");
	struct dirent *df ;
	df = readdir(pointerToHome);
	//printf("%s\n",df->d_name);
	strcat(pathForCd,df->d_name);
	closedir(pointerToHome);
	while(strcmp(args,exit)!=0){

		green();
		printf("%s","RishavLaptop$~");
		green();
		printf("%s",path);
		green();
		printf("~");
		reset();
		scanf("%[^\n]%*c",args);
		char tobreak[] = " ";
        char *KeepOriginalCommand  = (char *)malloc(sizeof(char)*100);
        strcpy(KeepOriginalCommand,args);
		// char *ptr = strtok(args, tobreak);
		struct dirent *de;
		DIR *pointerTodirectory = opendir(path);
		////////////////////////////////////////////////////////////////////////////

		char tobreak1[]=" ";
		pthread_t tp;

		char ForThread[1000];
		strcpy(ForThread,KeepOriginalCommand);
		int THREADFLAG = 0;
		char *findthread  = strtok(ForThread,tobreak);
		while(findthread!=NULL){
			if (strcmp(findthread,"&t")==0 && (findthread = strtok(NULL,tobreak))==NULL){
				THREADFLAG = 1;
				break;
			}
			findthread = strtok(NULL,tobreak);
		}
		char *ptr = strtok(args, tobreak);

		////////////////////////////////////////////////////////////////////////////
		if (strcmp(ptr,"echo")==0){                       //echo , echo -n , echo -e
			int nflag = 0;
			int eflag = 0;
			ptr = strtok(NULL, tobreak);
			if (ptr==NULL){
				printf("%s","invalid command\n");
				continue;
			}
			if (strcmp(ptr,"-n")==0){
				nflag = 1;
				ptr = strtok(NULL, tobreak);
			}
			else if (strcmp(ptr,"*")==0){
				eflag = 1;
				ptr = strtok(NULL, tobreak);
				showdir(pointerTodirectory);
				continue;
			}
			if (ptr[0]!='"'){
					eflag = 0;
				}
				while(ptr!=NULL){
					echo(eflag,ptr);
					printf(" ");
					ptr = strtok(NULL,tobreak);
				}
				if (nflag !=1){
					printf("\n");	
				}
		}
		else if (strcmp(KeepOriginalCommand,"ls -a")==0 || strcmp(KeepOriginalCommand,"ls -A")==0 || strcmp(KeepOriginalCommand,"ls -A &t")==0 || strcmp(KeepOriginalCommand,"ls -a &t")==0){
			if (THREADFLAG==1){
				if (strcmp(KeepOriginalCommand,"ls -A &t")==0){
					char lsPath1[100] ;
					strcpy(lsPath1,"\"");
					strcat(lsPath1,lsPath);
					strcat(lsPath1,"/ls-aA.out");
					strcat(lsPath1,"\"");
					pthread_create(&tp,NULL,CALLTHREAD,lsPath1);
				}
				else if(strcmp(KeepOriginalCommand,"ls -a &t")==0){
					char lsPath1[100] ;
					strcpy(lsPath1,"\"");
					strcat(lsPath1,lsPath);
					strcat(lsPath1,"/ls-a.out");
					strcat(lsPath1,"\"");
					pthread_create(&tp,NULL,CALLTHREAD,lsPath1);
				}
				pthread_join(tp,NULL);
				getcwd(path,100);	
				continue;
			}
            pid_t Pid = fork();
            char lsPath1[100] ;
			strcpy(lsPath1,lsPath);
			//printf("%s",lsPath);
			if (strcmp(KeepOriginalCommand,"ls -a")==0){
				strcat(lsPath1,"/ls-a.out");
			}
			else{
				strcat(lsPath1,"/ls-aA.out");
			}
			
			if (Pid==0){
				execl(lsPath1,"ls-a.out",(char*)NULL);
			}
			wait(NULL);	
            getcwd(path,100);
		}
		else if(strcmp(KeepOriginalCommand,"ls")==0 || strcmp(KeepOriginalCommand,"ls &t")==0){
            if (THREADFLAG==1){
				char lsPath1[100] ;
				strcpy(lsPath1,"\"");
				strcat(lsPath1,lsPath);
				strcat(lsPath1,"/ls.out");
				strcat(lsPath1,"\"");
				pthread_create(&tp,NULL,CALLTHREAD,lsPath1);
				pthread_join(tp,NULL);
				getcwd(path,100);	
				continue;
			}
			pid_t Pid = fork();
            char lsPath1[100] ;
			strcpy(lsPath1,lsPath);
			strcat(lsPath1,"/ls.out");
			if (Pid==0){
				execl(lsPath1,"ls.out",(char*)NULL);
			}
			wait(NULL);	
            getcwd(path,100);	

		}
        else if (strcmp(ptr,"cat")==0){                   // cat , cat -n , cat -T
            ptr = strtok(NULL,tobreak);
            if (ptr==NULL){
                printf("BASH : INVALID COMMAND\n");
            }
			if (THREADFLAG==1){
				//struct argThread *tmp;
				char lspath1[100];
				strcpy(lspath1,"\"");
				strcat(lspath1,lsPath);
				strcat(lspath1,"/cat.out");
				strcat(lspath1,"\"");
				strcat(lspath1," ");
				int i=0;
				while(ptr!=NULL){
					if (strcmp(ptr,"&t")==0){
						ptr = strtok(NULL,tobreak);
						continue;
					}
					strcat(lspath1,ptr);
					strcat(lspath1," ");
					ptr = strtok(NULL,tobreak);
				}
				strcat(lspath1,"NULL");
				pthread_create(&tp,NULL,CALLTHREAD,lspath1);
				pthread_join(tp,NULL);
				getcwd(path,100);	
				continue;
			}
			else{
				char lsPath1[100];
				strcpy(lsPath1,lsPath);
				strcat(lsPath1,"/cat.out");
                pid_t pid = fork();
                if(pid==0){
					char *a[3];
					int i=0;
					while(ptr!=NULL){
						a[i] = ptr;
						ptr = strtok(NULL,tobreak);
						i++;
					}
					a[i] = NULL;
					//printf("%s\n",a[0]);
                    execv(lsPath1,a);
                }
                wait(NULL);
                getcwd(path,100);
			}
        }
		else if (strcmp(ptr,"rm")==0){           //rm, rm -i, rm -d
			ptr = strtok(NULL,tobreak);
			if (ptr==NULL){
				printf("BASH : INVALID COMMAND\n");
				continue;
			}
			if (THREADFLAG==1){
				char lspath1[100];
				strcpy(lspath1,"\"");
				strcat(lspath1,lsPath);
				strcat(lspath1,"/rm.out");
				strcat(lspath1,"\"");
				strcat(lspath1," ");

				// strcat(lspath1,lsPath);
				// strcat(lspath1,"/rm.out");
				// strcat(lspath1,"\"");
				int i=0;
				while(ptr!=NULL){
					if (strcmp(ptr,"&t")==0){
						ptr = strtok(NULL,tobreak);
						continue;
					}
					strcat(lspath1,ptr);
					strcat(lspath1," ");
					ptr = strtok(NULL,tobreak);
				}
				strcat(lspath1,"NULL");
				pthread_create(&tp,NULL,CALLTHREAD,lspath1);
				pthread_join(tp,NULL);
				getcwd(path,100);	
				continue;
			}
			else if (strcmp(ptr,"-d")==0){
				char lsPath1[100];
				strcpy(lsPath1,lsPath);
				strcat(lsPath1,"/rm.out"); 
				pid_t pid = fork();
				if (pid==0){
					char *a[4];
					int i =0;
					while(ptr!=NULL){
						a[i] = ptr;
						ptr = strtok(NULL,tobreak);
						i++;
					}
					a[i] = NULL;
					execv(lsPath1,a);
				}
				wait(NULL);
				getcwd(path,100);
			}
			else {
				char lsPath1[100];
				strcpy(lsPath1,lsPath);
				strcat(lsPath1,"/rm.out");
				pid_t pid = fork();
				if (pid==0){
					char *a[3];
					int i =0;
					while(ptr!=NULL){
						a[i] = ptr;
						ptr = strtok(NULL,tobreak);
						i++;
					}
					a[i] = NULL;
					execv(lsPath1,a);
				}
				wait(NULL);
				getcwd(path,100);
			}
		}
		else if (strcmp(ptr,"mkdir")==0){           // mkdir ,mkdir -v , mkdir -p
			ptr = strtok(NULL,tobreak);
			if (ptr==NULL){
				printf("missing arguement to mkdir\n");
				continue;
			}
			else if (strcmp(ptr,"-p")==0){
				if (THREADFLAG==1){
					
					char lspath1[100];
					strcpy(lspath1,"\"");
					strcat(lspath1,lsPath);
					strcat(lspath1,"/mkdir-p.out");
					strcat(lspath1,"\"");
					strcat(lspath1," ");


					char new [100];
					strcpy(new,"");
					int j  = 0;
					//printf("%s\n",ptr);
					while(ptr!=NULL){
						//printf("%s\n",ptr);
						ptr = strtok(NULL,tobreak);
						if (strcmp(ptr,"&t")==0){
							ptr = strtok(NULL,tobreak);
							continue;
						}
						strcat(new,ptr);
						
						j ++;
					}
					if (j>=2){
						
						printf("Invalid command\n");
						continue;
					}

					char *ptr1 = strtok(new,"/");

					


					int i=0;
					while(ptr1!=NULL){
						strcat(lspath1,ptr1);
						strcat(lspath1," ");
						ptr1 = strtok(NULL,"/");
					}




					strcat(lspath1,"NULL");
					pthread_create(&tp,NULL,CALLTHREAD,lspath1);
					pthread_join(tp,NULL);
					getcwd(path,100);	
					continue;
				}
				ptr = strtok(NULL,"/");
				char lspath1[100];
				strcpy(lspath1,lsPath);
				strcat(lspath1,"/mkdir-p.out");
				pid_t pid  = fork();
				if (pid ==0){
					char *a[4];
					int i =0;
					while(ptr!=NULL){
						a[i] = ptr;
						ptr = strtok(NULL,"/");
						i++;
					}
					a[i]  = NULL;
					execv(lspath1,a);
				}
				wait(NULL);
				getcwd(path,100);
			}
			else{
				if (THREADFLAG==1){
					char lspath1[100];
					strcpy(lspath1,"\"");
					strcat(lspath1,lsPath);
					strcat(lspath1,"/mkdir.out");
					strcat(lspath1,"\"");
					strcat(lspath1," ");


					char new [100];
					strcpy(new,"");
					//printf("%s\n",ptr);
					while(ptr!=NULL){
						//printf("%s\n",ptr);
						
						if (strcmp(ptr,"&t")==0){
							ptr = strtok(NULL,tobreak);
							continue;
						}
						strcat(new,ptr);
						strcat(new," ");
						ptr = strtok(NULL,tobreak);
						
					}

					char *ptr1 = strtok(new," ");

					


					int i=0;
					while(ptr1!=NULL){
						strcat(lspath1,ptr1);
						strcat(lspath1," ");
						ptr1 = strtok(NULL," ");
					}
					strcat(lspath1,"NULL");
					pthread_create(&tp,NULL,CALLTHREAD,lspath1);
					pthread_join(tp,NULL);
					getcwd(path,100);	
					continue;
				}
				char lspath1[100];
				strcpy(lspath1,lsPath);
				strcat(lspath1,"/mkdir.out");
				pid_t pid = fork();
				if (pid==0){
					char *a[4];
					int i =0;
					while(ptr!=NULL){
						a[i] = ptr;
						ptr = strtok(NULL,tobreak);
						i++;
					}
					a[i] = NULL;
					execv(lspath1,a);
				}
				wait(NULL);
				getcwd(path,100);
			}
			
			
		}
		else if (strcmp(ptr,"date")==0){
			ptr = strtok(NULL,tobreak);
			//pid_t Pid = fork();
			pid_t Pid ;
            char lsPath1[100] ;
			strcpy(lsPath1,lsPath);
			if  (ptr==NULL || strcmp(ptr,"&t")==0){
				if (THREADFLAG==1){
					char lsPath1[100] ;
					strcpy(lsPath1,"\"");
					strcat(lsPath1,lsPath);
					strcat(lsPath1,"/date.out");
					strcat(lsPath1,"\"");
					pthread_create(&tp,NULL,CALLTHREAD,lsPath1);
					pthread_join(tp,NULL);
					getcwd(path,100);	
					continue;
				}
				Pid = fork();
				if (Pid==0){
					strcat(lsPath1,"/date.out");
					execl(lsPath1,"date.out",(char*)NULL);
				}
				wait(NULL);
			}
			else if (strcmp(ptr,"-R")==0){
				//strcat(lsPath1,"/date-R.out");
				if (THREADFLAG==1){
					char lsPath1[100] ;
					strcpy(lsPath1,"\"");
					strcat(lsPath1,lsPath);
					strcat(lsPath1,"/date-R.out");
					strcat(lsPath1,"\"");
					pthread_create(&tp,NULL,CALLTHREAD,lsPath1);
					pthread_join(tp,NULL);
					getcwd(path,100);	
					continue;
				}
				Pid = fork();
				if (Pid==0){
					strcat(lsPath1,"/date-R.out");
					execl(lsPath1,"date.out",(char*)NULL);
				}
				wait(NULL);
			}
			else if (strcmp(ptr,"-I")==0){
				//strcat(lsPath1,"/date-I.out");
				if (THREADFLAG==1){
					char lsPath1[100] ;
					strcpy(lsPath1,"\"");
					strcat(lsPath1,lsPath);
					strcat(lsPath1,"/date-I.out");
					strcat(lsPath1,"\"");
					pthread_create(&tp,NULL,CALLTHREAD,lsPath1);
					pthread_join(tp,NULL);
					getcwd(path,100);	
					continue;
				}
				Pid = fork();
				if (Pid==0){
					strcat(lsPath1,"/date-I.out");
					execl(lsPath1,"date.out",(char*)NULL);
				}
				wait(NULL);
			}
			// if (Pid==0){
			// 	execl(lsPath1,"date.out",(char*)NULL);
			// }
			//wait(NULL);	
            getcwd(path,100);
		}
		else if (strcmp(ptr,"cd")==0){
			// ptr = strtok(NULL,"./");
			// ptr = strtok(NULL,"\\");
			ptr = strtok(NULL, tobreak);
			if (ptr==NULL){
				chdir(pathForCd);
				char n[100];
				getcwd(n,100);
				path = n;
				pointerTodirectory = opendir(path);
			}
			else if(strcmp(ptr,"..")==0){
				chdir("..");
				char n[100];
				getcwd(n,100);
				path = n;
				pointerTodirectory = opendir(path);
			}
			else{
				// ptr = strtok(ptr,"\\");
				// if (chdir(ptr)!=0){
				// 	perror("BASH");
				// }
				// else{
				// 	char s[100];
				// 	getcwd(s,100);
				// 	path = s;
				// 	pointerTodirectory = opendir(path);
				// }
				ptr = strtok(ptr,"\\");
				while(ptr!=NULL){
					if (chdir(ptr)!=0){
						perror("BASH");
					}
					else{
						char s[100];
						getcwd(s,100);
						path = s;
						pointerTodirectory = opendir(path);
					}
					ptr = strtok(NULL,tobreak);
				}
				

				
			}
		}
		else if (strcmp(ptr,"pwd")==0){
			ptr = strtok(NULL,tobreak);
			if (ptr==NULL){
				char s[50];
				printf("%s\n",getcwd(s,100));
			}
			else if (strcmp(ptr,"-P")==0){
				char s[50];
				printf("%s\n",getcwd(s,100));
			}
			else if (strcmp(ptr,"-a")==0){
				ptr = strtok(NULL,tobreak1);
				char a[100];
				strcpy(a,"stat");
				strcat(a," ");
				strcat(a,ptr);
				int ret = system(a);
				if (ret==-1){
					printf("no file detected\n");
				}
			}
			else{
				printf("Invalid command\n");
			}
			
		}
        else{
			if (strcmp(KeepOriginalCommand,"exit")!=0){
				printf("BASH : COMMAND NOT FOUND\n");
			}
        }
	}
}