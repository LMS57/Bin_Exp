#include<stdio.h>

//gcc source.c -nostartfiles -Wl,--entry=_start -fomit-frame-pointer -nopie
//
char *a = "/bin/sh\x00";

int _start(){
	//asm("sub 0x100, %rsp");
	asm("push %rsp");
	asm("pop %rsi");
	asm("push $0");
	asm("push $0");
	asm("pop %rdi");
	asm("pop %rax");
	asm("mov $0x800, %edx");
	asm("syscall");
	asm("ret");
}

