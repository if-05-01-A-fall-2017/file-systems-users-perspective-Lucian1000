/*Kepplinger Raphael 07.03.2018*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h> 
#include <fcntl.h>

void checkError(int n){
		if(n == -1){
			printf("Error\n");
			exit(1);
		}
}

int main(int argc, char* argv[]) {

	int src_fd, dst_fd;
	int check;
    unsigned char buffer[4096];
    char * srcPath, dstPath;

    if (argc != 3) {
        printf("Wrong arguments.\n");
        exit(1);
    }

    srcPath = argv[1];
    dstPath = argv[2];

    src_fd = open(srcPath, O_RDONLY);
	checkError(src_fd);
    dst_fd = open(dstPath, O_CREAT | O_WRONLY);
	checkError(dst_fd);

    while (1) {
        check = read(src_fd, buffer, 4096);
        checkError(check);
        n = checkError;
        if (n == 0) 
			break;
        checkError = write(dst_fd, buffer, n);
        checkError(check);
    }

    close(src_fd);
    close(dst_fd);
	
	return 0;
}
