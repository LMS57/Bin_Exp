#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char *chunks[10];
int chunk_counter = 0;

void print_menu(){
	printf("What would you like to do?\n1. Create a chunk\n2. Edit a chunk\n3. Delete a chunk\n4. Print a chunk\n> ");
}

void edit(int index, int size){
	if(index == -1){
		printf("What index would you like to save to?\n> ");
		scanf("%d", &index);
		if(index > 9)
			return;
	}
	printf("What data would you like to put there?\n> ");
	char *ptr = chunks[index];
	if (size == 0)
	{
		printf("How much data?\n> ");
		scanf("%d", &size);
	}
	read(0,ptr,size);
}

void create(){
	if(chunk_counter > 9){
		return;
	}
	printf("What index would you like to save to?\n> ");
	unsigned int index;
	scanf("%d", &index);
	if(index > 9)
		return;
	printf("What size would you like to allocate?\n> ");
	unsigned long long size;
	scanf("%lld", &size);
	chunks[index] = malloc(size);

	edit(index,size);
}

void delete(){
	printf("What index would you like to delete?\n> ");

	unsigned int index;
	scanf("%d", &index);
	if(index > 9 || !chunks[index])
		return;

	free(chunks[index]);
	chunks[index] = 0;

}

int main(){
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stdin, 0, 2, 0);

	puts("All these programs always keep track of the size of a buffer, but why? The size is already stored right before the chunk everytime something is malloc'd. We can just use that!");

	int choice = 0;
	while(1){
		print_menu();
		scanf("%d", &choice);

		switch(choice){
			case 1:
				create();
				break;
			case 2:
				edit(-1,0);
				break;
			case 3:
				delete();
				break;
			case 4:
				//print();
				break;
			default:
				break;
		}
	}


}
