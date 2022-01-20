#include <stdio.h>
#include <stdlib.h>



int main(){
	char buf[100];
	void *leak = &main;
	setvbuf(stdin,0,2,0);
	setvbuf(stdout,0,2,0);
	write(1,"Enjoy a Leak!\n", 14);
	write(1, &leak, 8);
	read(0,buf, 200);
}
