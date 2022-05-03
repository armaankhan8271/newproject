#include <stdio.h>
#include <unistd.h>

int main(){
	pid_t pid;
	pid=fork();
	if(pid==0){
		printf("\nI  am child %u\n",getpid());
	}
	else{
		wait()
		printf("\n I am parent %u\n",getpid());
	}
	return 0;

}
