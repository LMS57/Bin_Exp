#include <stdio.h>
#include <stdlib.h>

int main(){
	char buf[100];
	setvbuf(stdin,0,2,0);
	setvbuf(stdout,0,2,0);
	puts("Good Luck!");
	read(0,buf,500);
	__printf_chk(1,buf);
	
}
