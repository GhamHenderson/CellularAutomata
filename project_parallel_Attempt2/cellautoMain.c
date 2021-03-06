/*
 Graham Henderson B00130193,James Moore B00129782, Eduard Iacob B00125295, Alan Johnson B00090030,
 */

#include "functions.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

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
  printf("\n(0)Sus Cells = %d ", suscells);
  printf("\n(1)Exposed Cells = %d ", expcells);
  printf("\n(2)Infected Cells = %d ", infectedcells);
  printf("\n(3)Recovered Cells = %d ", recoveredcells);
  printf("\n(4)Dead Cells = %d ", deadcells);
  
  return 0;
}
