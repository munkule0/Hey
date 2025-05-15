#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int fd1, fd2;
    fd1 = open("foo.txt", O_RDONLY);
    close(fd1);
    fd2 = open("baz.txt", O_RDONLY);
    printf("fd2 = %d\n", fd2);
    exit(0);
}

