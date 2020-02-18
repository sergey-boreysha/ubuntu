#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <dlfcn.h>

int (*stringStat)(const char*, size_t, int*);

bool init_lib()
{
	void *head = dlopen("./libsolution.so", RTLD_LAZY);
	if (head == NULL)
		return false;

	stringStat = (int(*)(const char*, size_t, int*))dlsym(head, "stringStat");
	if (stringStat == NULL)
		return false;
	
	return true;
}

int main()
{
	char str[] = "qwerty";
	
	int x = 10;
	int *data;
	data = &x;
	
	if(init_lib())
	{
		int res = stringStat(str,2,data);
	
		printf("%d\n",res);
		printf("%d\n",x);
	} else
		printf("Lib was not loaded\n");
	
}
