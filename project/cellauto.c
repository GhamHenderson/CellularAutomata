#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define SIZE 10
int main(){
  
  // 0 = sus, 1 = exposed, 2 = infected,
  // 3 = recovered, 4 = dead
  int states[5] = {0,1,2,3,4};
    
  // Grid Variables
  int i,j;
  int rows = SIZE;
  int cols = SIZE;
  int cells[cols][rows];
  int futurecells[cols][rows];

  printf("\nGeneration 1 \n\n");

  // Print first generation array and assign values to both arrays.
  for(i = 0; i < rows; i++){
    for(j = 0; j < cols; j++){
      cells[i][j] = states[0];
      cells[4][7] = states[2];
      printf("%d ", cells[i][j]);
    }  
  printf("\n");
  }
  printf("\nGeneration 2\n\n");

  // Print and assign values to future array.
    for(i = 0; i < rows; i++){
    for(j = 0; j < cols; j++){
      
      futurecells[i][j] = states[0];
      futurecells[4][7] = states[2];
      printf("%d ", futurecells[i][j]);
    }  
    printf("\n");
  }
  printf("\n\n\n");
 
  int counter = 0;
  unsigned int suscells = 0;
  
  // Check if a cell is sus
  for(i = 0; i < rows; i++)
  {
    for(j = 0; j < cols; j++)
    {
      if(cells[i][j] == states[0])
	{
        suscells++;
	//check if cells around sus cell are infected and if so how many, and make current cell exposed

      }
    }
  }

  //calculate chance of infection based on amount of infected neighbours and RNG between 0 and 1
    
  printf("\n\nSus Cells = %d \n\n", suscells);
} 
