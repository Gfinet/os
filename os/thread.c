#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* maFonction(void* data);
int main() {
	int i;
   pthread_t thread;// On crée un thread
   pthread_create(&thread, NULL, maFonction, NULL);// Permet d'exécuter le fonction maFonction en parallèle
   for(i=0 ; i<100 ; i++){
        printf("1");}
   // Attend la fin du thread créé
   pthread_join(thread, NULL);

   return EXIT_SUCCESS;
}
void* maFonction(void* data)
{
    int i;
    for(i=0 ; i<100 ; i++){
        printf("2");}
    return NULL;
}
