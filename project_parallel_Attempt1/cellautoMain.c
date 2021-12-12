

#include "functions.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>


long long suscells = 0;
long long expcells = 0;
long long infectedcells = 0;
long long recoveredcells = 0;
long long deadcells = 0;
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
  
  printf("--- From Main ---");
  printf("\n(0)Sus Cells = %lld ", suscells);
  printf("\n(1)Exposed Cells = %lld ", expcells);
  printf("\n(2)Infected Cells = %lld ", infectedcells);
  printf("\n(3)Recovered Cells = %lld ", recoveredcells);
  printf("\n(4)Dead Cells = %lld \n", deadcells);  
  return 0;
}
