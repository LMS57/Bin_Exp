#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/sendfile.h>

int win(){
	int fd = open("./flag.txt",0);
	sendfile(1,fd,0,100);
	exit(0);
}

int main(){
	int x = 0;
	char c[10];
	printf("What is your name?\n");
	scanf("%s", c);
	if(x == 0x1337c0de)
		win();
	printf("Nice to meet you %s\n", c);

}
