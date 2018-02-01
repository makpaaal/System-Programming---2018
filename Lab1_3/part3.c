#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd, ww;
    char inp[100], tee[3], a[2], filename[100];

    printf("Please, enter your command in this form: sometext tee -a filename\n");
    scanf("%s %s %s %s", inp, tee, a, filename);

    fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if(fd == -1){
        perror("Error in open operation");
        exit(1);
    }

    ww = write(fd, inp, strlen(inp));
    if(ww == -1){
        perror("Error in write operation");
    }

    close(fd);
    return 0;
}
