#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


void print_process_parents(int pid);
int get_parent_pid(int pid); 

int main(int cnt, const char **cmd)
{
	if(cnt!=2)
        {
                printf("\nPlease call\n\t%s process_name\n", cmd[0]);
                return 1;
        }

	print_process_parents(atoi(cmd[1]));
}


void print_process_parents(int pid){
	
	int current = pid;
	while (current != 1) {
		
		printf("%d\n",current);
		current = get_parent_pid(current);
		getchar();
	}
	
	printf("%d (init) \n",current);
}

int get_parent_pid(int pid){

	char path[50] = "/proc/";
	char temp[50] = "";
	char temp2[] = "/stat";
	char temp3[] = "";
	char buf[20] = "";
	size_t sz = 0;

	sprintf(temp, "%d", pid);
	strcat(path, temp);
	strcat(path, temp2);
	printf("Path = %s\n", path);
	
	int fd = open(path, O_RDONLY);
        perror("fd");
       	printf("fd=%d\n", fd);
       	
	sz = read(fd, buf, 50);
        printf("sz=%ld\n", sz);
	printf("buf=%s\n", buf);
	
	int space = 0;

	for(int i=0; i<=50; i++){

		if(space == 3){

			printf("Position finded!\n");	
			
			for(int j=0; j<=20; j++){
                		
				if(buf[i] == ' '){
					
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

	printf("Parents = %s\n", temp3);

	return atoi(temp3);
}
