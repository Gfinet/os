#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	pid_t pid = fork();
	if ( pid == 0) // Si le processus est le fils, 
		printf("processus fils (PID = %d, PID du père = %d)\n",getpid(), getppid());
		
	else if(pid != -1) // Si le processus est le père
		printf("Processus père (PID = %d, PID du fils = %d)\n", getpid(), pid);
		
	else {
		perror("Erreur durant le fork");
		return EXIT_FAILURE;
		}
return EXIT_SUCCESS;
}
