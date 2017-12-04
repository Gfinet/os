#include <sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main(int argc, char **argv){
	pid_t pid; 
	int pere\_fils[2],fils\_pere[2], nbr1, nbr2, somme;
	if (pipe(pere\_fils) == -1 || pipe(fils\_pere) == -1){
		perror("Erreur a la creation des pipes");
		return EXIT_FAILURE;
	}
	pid = fork()
	if (pid == 0){ //Processus fils
		close(pere_fils[1]);
    	close(fils_pere[0]);
    	read(pere_fils[0], (void *)(&nbr1), sizeof(int));
	    read(pere_fils[0], (void *)(&nbr2), sizeof(int));
    	somme = nbr1 + nbr2;
    	write(fils_pere[1], (void *)(&somme), sizeof(int));
		
	}
	else if (pid !=-1){ //processus fils
		close(fils_pere[1]);    
    	close(pere_fils[0]);
   		printf("Introduisez deux nombre : ");
    	scanf("%d", &nbr1);
    	scanf("%d", &nbr2);
    	write(pere_fils[1], (void *)(&nbr1), sizeof(int));
    	write(pere_fils[1], (void *)(&nbr2), sizeof(int));
    	read(fils_pere[0], (void *)(&somme), sizeof(int));
    	printf("La somme des deux nombres est %d\n", somme);
	}
	else{
		perror("Erreur durant le fork");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
