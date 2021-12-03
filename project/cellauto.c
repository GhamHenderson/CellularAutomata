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
   printf("\n cells \n\n");

  // Print first generation array and assign values to both arrays.
  for(i = 0; i < rows; i++)
  {
    for(j = 0; j < cols; j++)
    {
      cells[i][j] = states[0];
      cells[0][1] = states[2];
      cells[0][8] = states[2];
      cells[8][1] = states[2];
      cells[8][8] = states[2];
      printf("%d ", cells[i][j]);
    }  
    printf("\n");
  }
  printf("\n futureCells \n\n");

  // Print and assign values to future array.
    for(i = 0; i < rows; i++)
    {
      for(j = 0; j < cols; j++)
      {
      
      futurecells[i][j] = cells[i][j];
      printf("%d ", futurecells[i][j]);
    }  
    printf("\n");
  }
  printf("\n\n\n");
 
  int counter = 1;
  unsigned int suscells = 0;
  unsigned int expcells = 0;
  unsigned int infectedcells = 0;
  unsigned int recoveredcells = 0;
  unsigned int deadcells = 0;
  
  // Check if a cell is sus
  for(i = 0; i < rows; i++)
  {
    for(j = 0; j < cols; j++)
    {
      if(cells[i][j] == states[0])
      {
        suscells++;
	
      }

      	//check if cells around sus cell are infected and if so make current cell exposed
        //Top Left Corner
       if(cells[0][0] == states[0])
       {
	  if(cells[i][j+1] == states[2])
	  {
	    futurecells[0][0] = states[1];
	  }
	  else if(cells[i+1][j] == states[2])
	  {
	    futurecells[0][0] = states[1];
	  }
	   else if(cells[i+1][j+1] == states[2])
	  {
	    futurecells[0][0] = states[1];
	  }
       }

	//Top right corner
       if(cells[0][SIZE-1] == states[0])
       {
	  if(cells[i][j-1] == states[2])
	  {
	    futurecells[0][SIZE-1] = states[1];
	  }
	  else if(cells[i+1][j-1] == states[2])
	  {
	    futurecells[0][SIZE-1] = states[1];
	  }
	   else if(cells[i+1][j] == states[2])
	  {
	    futurecells[0][SIZE-1] = states[1];
	  }
       }

	//Bottom Left Corner
       if(cells[SIZE-1][0] == states[0])
       {
	  if(cells[i-1][j] == states[2])
	  {
	    futurecells[SIZE-1][0] = states[1];
	  }
	  else if(cells[i+1][j+1] == states[2])
	  {
	     futurecells[SIZE-1][0] = states[1];
	  }
	   else if(cells[i][j+1] == states[2])
	  {
	     futurecells[SIZE-1][0] = states[1];
	  }
       }

       //Bottom Right Corner
       if(cells[SIZE-1][SIZE-1] == states[0])
       {
	  if(cells[i-1][j] == states[2])
	  {
	    futurecells[SIZE-1][SIZE-1] = states[1];
	  }
	  else if(cells[i-1][j-1] == states[2])
	  {
	     futurecells[SIZE-1][SIZE-1] = states[1];
	  }
	   else if(cells[i][j-1] == states[2])
	  {
	     futurecells[SIZE-1][SIZE-1] = states[1];
	  }
       }
    }
  }

  //check the first row
  for(i = 0; i < rows-1; i++)
  {
    for(j = 1; j < cols-1; j++)
    {
      if(cells[0][j] == states[0])
      {
	if(cells[0][j-1] == states[2])
	{
	  futurecells[0][j] = states[1];
	}
	else if(cells[1][j-1] == states[2])
	{
	  futurecells[0][j] = states[1];
	}
	else if(cells[1][j] == states[2])
	{
	  futurecells[0][j] = states[1];
	}
	else if(cells[1][j+1] == states[2])
	{
	  futurecells[0][j] = states[1];
	}
	else if(cells[0][j+1] == states[2])
	{
	  futurecells[0][j] = states[1];
	}
      } 
    }
  }

   //check the bottom row
  for(i = SIZE-1; i < rows-1; i++)
  {
    for(j = 1; j < cols-1; j++)
    {
      if(cells[SIZE-1][j] == states[0])
      {
	if(cells[SIZE-1][j-1] == states[2])
	{
	  futurecells[SIZE-1][j] = states[1];
	}
	else if(cells[SIZE-1][j+1] == states[2])
	{
	  futurecells[SIZE-1][j] = states[1];
	}
	else if(cells[SIZE-2][j] == states[2])
	{
	  futurecells[SIZE-1][j] = states[1];
	}
	else if(cells[SIZE-2][j+1] == states[2])
	{
	  futurecells[SIZE-1][j] = states[1];
	}
	else if(cells[SIZE-2][j-1] == states[2])
	{
	  futurecells[SIZE-1][j] = states[1];
	}
      } 
    }
  }

  

  
  
   // Check if a cell is exposed
  for(i = 0; i < rows; i++)
  {
    for(j = 0; j < cols; j++)
    {
      if(cells[i][j] == states[1])
      {
        expcells++;
	//check if cells around exposed cell are infected and calculate chance of infection
	//calculate chance of infection based on amount of infected neighbours and RNG between 0 and 1
      }
    }
  }

   // Check if a cell is infected
  for(i = 0; i < rows; i++)
  {
    for(j = 0; j < cols; j++)
    {
      if(cells[i][j] == states[2])
      {
        infectedcells++;
        
	//50% chance of death
	//50% chance of recovery
	//generate a random number between 0 and 1 and if greater than 0.5, make cell dead / if less than or equal to 0.5 the cell recovers and gains immunity 
      }
    }
  }

   // Check if a cell is recovered
  for(i = 0; i < rows; i++)
  {
    for(j = 0; j < cols; j++)
    {
      if(cells[i][j] == states[3])
      {
	recoveredcells++;
      }
    }
  }

   // Check if a cell is dead
  for(i = 0; i < rows; i++)
  {
    for(j = 0; j < cols; j++)
    {
      if(cells[i][j] == states[3])
      {
	deadcells++;
      }
    }
  }

  printf("\nGeneration: %d \n\n", counter);
  counter++;
  // Print first generation array and assign values to both arrays.
  for(i = 0; i < rows; i++)
  {
    for(j = 0; j < cols; j++)
    {
      printf("%d ", futurecells[i][j]);
    }  
    printf("\n");
  }
    
  printf("\nSus Cells = %d \n\n", suscells);
  printf("\nExposed Cells = %d \n\n", expcells);
  printf("\nInfected Cells = %d \n\n", infectedcells);
  printf("\nRecovered Cells = %d \n\n", recoveredcells);
  printf("\nDead Cells = %d \n\n", deadcells);
} 
