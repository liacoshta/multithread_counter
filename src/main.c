/* Contador de primos
 * Autora: Lia Costa
 * RA: 159834
 * Este programa recebera um texto na entrada e contar quantos números primos 
 * existem nessa entrada.
 * Porém o objetivo é fazer um sistema operar como multi-thread, usando 
 * a instrução pthread_create ().
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <time.h>
#include <pthread.h>



#define WORKERS 3
int inicio_buffer =0;
int final_buffer =0;
int total_buffer =0;
int buffer[100];
int n_completos = 0;
int a;
pthread_mutex_t trava;
int var[100];
int *i;
int *contador;


int Verificaprimo(int num){
/*função que verifica cada primo*/
        for (int i=2; i<num; i++){
                if (num % i == 0||num==1){
                        a=0;//não é primo
                        return a;
                        }
                   }
                if(num>=2){
                        a=1;//é primo
                        }else{
                        a=0;
                        }
                return a;
        }



void* worker(void *arg) {
  int *N = (int*)(arg);
  int M = (*N);
  printf("Iniciando thread %d\n", M);
  int atuador = -1;
 // while(total_buffer == 0);

    pthread_mutex_lock(&trava);
    //incluir verificar se ja leu todo var break;
	if ((*i)>=0){
	 int c, b;
	 c = (var[(*i)]);
	 (*i)--;
	 b = Verificaprimo(c);
	 if (b) (*contador)++;
	}
    pthread_mutex_unlock(&trava);
    printf("Numero %d acessado por thread %d\n", atuador, M);
 

//   for (int j=0; j<500000; j++);
   printf("Saindo de thread %d\n", M);
  return NULL;
}



int main(int argc, char**argv) {
char lixo;
	do {
	scanf("%d",&(var[(*i)]));
	scanf("%c",&lixo);
	(*i)++;
	}while(lixo != '\n');

 pthread_t thread[3];
 int thread_args[3];
/*cria threads*/
 for(int i = 0; i<4;i++) {
  thread_args[i];
  pthread_create(&thread[i], NULL, worker, &(thread_args[i]));
//  for (int p=0;p<800000;p++);
}

/*Esperando threads terminarem*/
  for(int i = 0;i<3;i++){
  pthread_join(thread[i],NULL);
}

printf("%d", *contador);
return 0;
}
