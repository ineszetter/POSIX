#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define TAM_ALMACEN 10

sem_t vacias;
sem_t llenas;


typedef struct registro
{
	int cajas[TAM_ALMACEN];
	int frente;
	int posterior;
}Buffer;

Buffer B;

/*/
En esta parte buffer seria el tipo de variable y registro es el identificador
entonces para acceder a las caracteristicas de bufer podemos utilizar el 
operador unario de desreferencia * o el operador punto .
Ejemplo: Buffer.frente[lugar];
De esta manera podemos acceder al contenido del espacio de memoria o al espacio mismo
con cualquiera de los operadores. 
Ejemplo: prinft("%d",B.frente);
Ejemplo: printf("%d",b->frente);
/*/


void ini_cola(Buffer *B)
{
	B -> frente = 0;
	B -> posterior = 0;
}

void encola(Buffer *B, int elem)
{
	B->cajas[B->posterior]=elem;
	B->posterior = (B->posterior+1)%TAM_ALMACEN;
/*/
Aqui lo que hacemos el localizar el puntero en el ultimo elemento de la pila
y despues incrementarlo para repetir la operacion.
Finalmente con el modulo verificamos que no se haya sobrepasado el tamaño del almacen,
esto lo hace de maner que cada vez que se alcance el valor maximo (10) es entonces que se
retorna al valor inicial (0) y vuelve a incrementar, como un autolaso.
/*/
}

int desencola(Buffer *B)
{
int dato;
	dato = B -> cajas[B->frente];
	B -> frente = (B -> frente +1)%TAM_ALMACEN;
return dato;
}



void productor(){
	int caja = 1;
	int t;
	while(1){
		sem_wait(&vacias);
		printf("\n He producido la caja No. %d", caja);
		encola(&B,caja);
		caja++;
		t = (rand()%2);
		sleep(t);
		sem_wait(&llenas);
		}
}



void consumidor(){
	int caja;
	int t;
	while(1){
		sem_wait(&llenas);
		caja = desencola(&B);
		printf("\n Retire la caja No. %d", caja);
		t = (rand()%3);
		sleep(t);
		sem_wait(&vacias);
		}
}




int main(){
pthread_t H_productor, H_consumidor;
/*/
En esta ocasión estamos utilizando la metafora del gato y el raton,
el gato es el consumidor y el raton es el productor. El objetivo es
encontrar el equilibrio que permita que la cantidad de producciones
y consumidores sea equivalente de manera exponencial.
/*/

/*/
Los semaforos son como contadores, aunque entre sus caracteristicas
cuentan con ciertos estados de actividad que detienen o retornan el flujo
de operaciones del programa. (Init, wait, post)
/*/

sem_init(&vacias,0,TAM_ALMACEN);
sem_init(&llenas,0,TAM_ALMACEN);

ini_cola(&B);
//Inicializamos la cola

pthread_create(&H_productor, NULL, (void *)&productor, NULL);
pthread_create(&H_consumidor, NULL, (void *)&consumidor, NULL);
pthread_join(H_productor, NULL);
pthread_join(H_consumidor, NULL);
}
