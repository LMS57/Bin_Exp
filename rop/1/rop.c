#include <stdio.h>
#include <stdlib.h>

int main(){
	char buf[100];
	setvbuf(stdin,0,0,0);
	setvbuf(stdout,0,0,0);
	puts("Good Luck!");
	gets(buf);
	
}
