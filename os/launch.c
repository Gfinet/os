#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(int argc, char *argv[])
	{
	pid_t pid; char **argu; int status, i;
	pid = fork();
	if (pid == 0){
		argu[0] = "/bin/ls";
		argu[1] = "-f";
		argu[2] = NULL;	
		execv("/bin/ls",argu);
		WIFEXITED(status);
		WEXITSTATUS(status);}
	else if(pid != -1){
		pid_t fils = waitpid(pid, &status, 0);		
		printf("lol");
		}
	else {
		perror("Erreur durant le fork");
		return EXIT_FAILURE;
		}
	return EXIT_SUCCESS;
	
	}
