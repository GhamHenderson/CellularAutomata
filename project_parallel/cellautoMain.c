#include "functions.h"
#include <pthread.h>
#include <stdlib.h>

unsigned int suscells = 0;
unsigned int expcells = 0;
unsigned int infectedcells = 0;
unsigned int recoveredcells = 0;
unsigned int deadcells = 0;
    
int thread_count = 4;
long thread;

int main(){
  pthread_t *thread_handles;
  thread_handles = (pthread_t*)malloc(thread_count*sizeof(pthread_t));
  
  for(thread = 0; thread < thread_count; thread++){
    pthread_create(&thread_handles[thread], NULL, cellautochild, (void*)thread);    
  }

  for(thread = 0; thread < thread_count; thread++){
    pthread_join(thread_handles[thread],NULL);    
  }
  free(thread_handles);
  return 0;
}
