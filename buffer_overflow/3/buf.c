#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/sendfile.h>
#include <time.h>

int win(){
	int fd = open("flag.txt",0);
	sendfile(1,fd,0,100);
	exit(0);
}

int main(){

	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);

	srand(time(0));
	long long check = rand();
	char buf[10];
	scanf("%s", buf);
	if (atoll(buf) == check)
		win();
	else
		printf("Correct answer was %lld\n", check);

}
