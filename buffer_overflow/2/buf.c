#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(){

	int a = open("/etc/passwd",0);
	int b = open("flag.txt", 0);
	char c[50];
	char *d = malloc(500);

	printf("I learned from my last mistakes and won't let you overflow like last time, this time I'm only going to read from /etc/password, first let me clear the buffer\n");
	scanf("%500s", d);
	strncpy(c,d,strlen(d));
	printf("You had %s there\n", c);
	read(a, c, 50);
	printf("Here is /etc/passwd: %s", c);
}
