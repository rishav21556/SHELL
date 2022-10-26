#include <stdio.h>
#include <stdlib.h>
#include <syscall.h>
#include <unistd.h>
#include <fcntl.h>  
int main()
{
    // open("test_file.txt", O_RDONLY);
    // Create this file before hand with some content
   int fd = syscall(SYS_open, "test_file.txt", O_RDONLY);
   char my_value;
   //read(fd, &my_value,1);
   int bytes_read = syscall(SYS_read, fd, &my_value, 1) ;
   if (bytes_read)
   {
       printf("my value %c", my_value);
       int write_fd = syscall(SYS_open, "new_testfile.txt", O_CREAT | O_RDWR);
       //write(write_fd, &my_value, 1);
       int status_code = syscall(SYS_write, write_fd, &my_value, 1);
       if (status_code == -1 )
       {
           perror("Failed to open new testfile\n");
       }
   }
   syscall(SYS_write, STDOUT_FILENO, &my_value, 1);
   printf("\n");


   

   return 0;
}
