#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

void *factorail (void *arg);

sem_t sem[12];
int f=1;
pthread_t tid[11];

int main (){

	// for (int i = 1; i < 21; i++){
	// 	f=f*i;
	// }

	for (int i = 2; i <= 11; i++) {
		sem_init ( &sem[i], 0,0);
	}
	sem_init(&sem[1],0,1);
	for (int i = 1; i<11; i++){
		pthread_create(&tid[i], NULL, factorail, (void *) i);
	}

	return 0;
}

void *factorail (void *arg){
	int id = (int) arg;
	sem_wait (&sem[id]);
	f = f * (id+20);
	printf("Thread %i was executed. The output is %i \n", id, f);
	sem_post(&sem[id+1]);
}
