
//Compile: gcc fundamentals.c -o fundamentals -z relro -z now -fstack-protector
#include <stdio.h>
#include <stdlib.h>


int main(){
	char flag[100];
	char guess[100];
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	printf("What is your guess?\n");
	int fd = open("./flag.txt",0);
	read(fd,flag,100);
	read(0,guess,100);
	if(strncmp(guess,flag,strlen(flag))){
		printf("Your guessed wrong with ");
		printf(guess);
		puts("");
	}
	else{
		puts("Wow you actually guessed it");
	}
}
