#include <semaphore.h>
#include <stdio.h>
#define true 1
#define false 0


sem_t mutex;
mutex = sem_open ("/mutex", O_CREAT, 0644, 1);
int main()
{
  sem_init(mutex,0,1);
 if(sem_wait(mutex)==0)
   {
     //si el valor del semaforo es negativo queda en espera con sem_wait
    printf("Realizando operacion critica..");
    //para cambiar el estado del semaforo se utiliza sem_post
    sem_post(mutex);
   }
if(sem_wait(mutex)==1)
{
printf("Ejecucion terminada...\n");
}
return 0;
}
