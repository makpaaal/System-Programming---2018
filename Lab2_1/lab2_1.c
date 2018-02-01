#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>


int main()
{
    int sizes[] = {1,1024,1130};
    char from[100], to[100];
    ssize_t rr, ww;

    printf("Please, enter the filenames:\n");
    scanf("%s" "%s", from, to);
    if(strcmp(from, to) == 0){
        printf("Sorry, file cannot be copied over itself!\n");
    }

    int i;
    for(i=0; i<3; i++){
        double time = 0;
        int fd_from, fd_to, length = sizes[i];
        char buf[length];

        time_t t;
        t= clock();

    fd_from = open (from, O_RDONLY);
        if(fd_from == -1){
        perror("Error in open operation");
        exit(1);
    }

    fd_to = creat (to, S_IRWXU);
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
            perror("Error in write operation");
    }

    close(fd_from);
    close(fd_to);


    time = clock() - t;

    printf("Buffer size:");
    printf("%d",sizes[i]);
    printf("    time:");
    printf("%f",time);
    printf("\n");

    }


    return 0;
}

