#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	if(argc > 1){
		int i;
		for(i = 1; i < argc; i++){
			unlink(argv[i]);
		}
	}
	else{
		printf("usage: %s files...", argv[0]);
	}
}
