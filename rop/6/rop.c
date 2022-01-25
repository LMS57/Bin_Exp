#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "seccomp-bpf.h"



void seccomp(){
	struct sock_filter filter[] = {
    ALLOW_SYSCALL(read),
    ALLOW_SYSCALL(write),
    ALLOW_SYSCALL(close),
    ALLOW_SYSCALL(open),
    ALLOW_SYSCALL(exit),
    ALLOW_SYSCALL(exit_group),
    ALLOW_SYSCALL(mprotect),
	KILL_PROCESS
	};

	struct sock_fprog prog = {
		.len = (unsigned short)(sizeof(filter)/sizeof(filter[0])),
		.filter = filter,
	};

	if (prctl(PR_SET_NO_NEW_PRIVS, 1, 0, 0, 0)) {
		perror("prctl(NO_NEW_PRIVS)");
		goto failed;
	}
	if (prctl(PR_SET_SECCOMP, SECCOMP_MODE_FILTER, &prog)) {
		perror("prctl(SECCOMP)");
		goto failed;
	}
		return;

failed:
	if (errno == EINVAL)
		fprintf(stderr, "SECCOMP_FILTER is not available. :(\n");
	return;
}

void setup(){
	setvbuf(stdout,0,2,0);
	setvbuf(stdin,0,2,0);
	seccomp();
}

int main(){
	setup();
	char buf[130];
	puts("Good Luck!");
	read(0,buf,200);
	__printf_chk(1,buf);
	
}
