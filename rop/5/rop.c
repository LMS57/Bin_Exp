#include <stdio.h>
#include <stdlib.h>

int main(){
	char buf[100];
	setvbuf(stdin,0,2,0);
	read(0,buf, 200);
}
