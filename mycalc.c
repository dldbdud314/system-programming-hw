#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc>1){
		int i;
		int sum = 0;
		for(i = 1; i < argc; i++){
			sum += atoi(argv[i]);
		}
		printf("%d\n", sum);
	}
	else{
		printf("usage: %s numbers...\n", argv[0]);
	}
}
