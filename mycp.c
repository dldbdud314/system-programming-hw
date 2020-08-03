#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	if(argc!=3){
		fprintf(stderr, "usage: %s file1 file2", argv[0]);
		exit(-1);
	}
	else{
		int fd1, fd2;
		ssize_t nread;
		char buffer[1024];

		fd1 = open(argv[1], O_RDONLY);
		if((fd2=open(argv[2], O_WRONLY|O_CREAT|O_EXCL))==-1)
			fprintf(stderr, "파일 %s가 이미 존재합니다.", argv[2]);
		else{
			while((nread=read(fd1, buffer, 1024))>0){
				if(write(fd2, buffer, nread)<nread)
					break;
			}
		}
		close(fd1);
		close(fd2);
	}
}
