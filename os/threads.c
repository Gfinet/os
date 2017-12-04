#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>

void* maFonction(void* data);
int main(int argc, char **argv){
	int i;
	pthread_t thread;
	pthread_create(&thread, NULL, maFonction, NULL);// Permet d'exécuter le fonction maFonction en parallèle
	//  pthread_create(pthread_t* thrad, pthread_attr_t* attr, void*(*start_routne)(void*),void* arg)
	for(i=0 ; i<100 ; i++)
        printf("1");
   // Attend la fin du thread créé
   pthread_join(thread, NULL);
   return EXIT_SUCCESS;
}
void* maFonction(void* data)
{
    int i;
    for(i=0 ; i<100 ; i++)
        printf("2");
    return NULL;
}

// compiler avec"gcc nomSource.c -lpthread -o nomExecutable"
