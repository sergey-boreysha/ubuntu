#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


int main()
{			
	char temp3[] = "";
	char buf[50] = "";

	int fd = open("/proc/self/stat", O_RDONLY);
	size_t sz = read(fd, buf, 50);
	
	int space = 0;

	int i = 0;
	for(; i<=50; i++)
	{
		if(space == 3){

			int j = 0;	
			for(; j<=50; j++)
			{
                		
				if(buf[i] == ' ')
				{
					
					temp3[j] = '\0';
					break;
				}
				
				temp3[j] = buf[i];
				i++;
			}	
		}
		
		if(buf[i] == ' ')
			space++;
	}

	printf("%d\n", atoi(temp3));
}
