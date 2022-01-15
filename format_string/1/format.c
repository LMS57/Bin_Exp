#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sendfile.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

void win(){
	int fd = open("./flag.txt", 0);
	sendfile(1,fd,0,100);
	return;
}

int main(){
	srand(time(0));
	setvbuf(stdin,0,2,0);
	setvbuf(stdout,0,2,0);
	int guess = rand();
	int *guess_loc = &guess;
	char buf[10];
	printf("What is your guess?\n");
	read(0, buf, 10);
	printf("Your guess needs to be %d at %p\nYou Guessed: ", guess, guess_loc);
	printf(buf);
	if(atoi(buf) == guess)
		win();
	else
		puts("Incorrect");
	
}
