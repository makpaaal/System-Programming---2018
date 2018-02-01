#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

int main()
{

    char str1[] = "vbnpuukndt";
    char str2[] = "omkalncftk";

    int fd, size1, size2;
    int n = 100, i = 0, j = 0;

    char filename[100];
    printf("Please, enter the filename:\n");
    scanf("%s", filename);
    strcat(filename, ".txt");

    fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if(fd == -1){
        perror("Error in open operation");
    }

    while( i < n){
        if(write(fd, str1, strlen(str1)) != 10)
            perror("Error in write operation to str1");

        if(lseek(fd, 20 + j, SEEK_SET) == -1)
            perror("Error in lseek");

        if(write(fd, str2, strlen(str2)) != 10)
            perror("Error in write operation in str2");
        i++;
        j += 31;
    }



    /*int fd_from, fd_to, length=100;
    char buf[length];
    ssize_t rr, ww;

    fd_from = open (filename, O_RDONLY);
    if(fd_from == -1){
        perror("Error in open operation");
        exit(1);
    }

    fd_to = creat ("second.txt", S_IRWXU);
    if(fd_to == -1){
        perror("Error in create operation");
        exit(1);
    }

     while((rr = read (fd_from, &buf, length)) != 0){
     if(rr == -1){
            if(errno == EINTR)
                continue;
            perror("Error in read operation");
            break;
        }
        ww = write (fd_to, &buf, rr);
        if(ww != rr)
            perror("Error in write opeartion");
    }

    close(fd_from);
    close(fd_to);*/

    return 0;
}
