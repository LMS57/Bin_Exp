#include <stdio.h>
#include <stdlib.h>

int main(){
	char buf[72];
	read(0,buf, 220);
	setvbuf(stdin,0,2,0);
}
