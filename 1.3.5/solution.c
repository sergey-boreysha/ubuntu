#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <dlfcn.h>
#include <stdlib.h>

int (*f_name)(int);
bool init_lib(char *lname, char *fname);

int main(int argc, char **argv)
{
	
	if(init_lib(argv[1],argv[2]))
	{
		printf("%d\n",f_name(atoi(argv[3])));

	} else
		printf("Lib was not loaded\n");
}

bool init_lib(char *lname, char *fname)
{
	void *head = dlopen(lname, RTLD_LAZY);
	if (head == NULL)
		return false;

	f_name = (int(*)(int))dlsym(head, fname);
	if (f_name == NULL)
		return false;
	
	return true;
}

