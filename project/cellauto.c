#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
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
  int counter = 1;
  float neighbourhood = 0.0;
  float infN = 0.3;
  unsigned int suscells = 0;
  unsigned int expcells = 0;
  unsigned int infectedcells = 0;
  unsigned int recoveredcells = 0;
  unsigned int deadcells = 0;
  srand((unsigned int)time(NULL));
  printf("\nGeneration 1 \n\n");

  float randNum = ((float)rand()/(float)(RAND_MAX)) * (1 - 0);

  // Print first generation array and assign values to both arrays.
  for(i = 0; i < rows; i++)
  {
    for(j = 0; j < cols; j++)
    {
      cells[i][j] = states[0];
      cells[0][1] = states[1];
      cells[0][5] = states[1];
      cells[1][0] = states[1];
      cells[1][1] = states[2];
      cells[8][4] = states[2];
      cells[8][8] = states[2];
      cells[8][9] = states[1];
      cells[5][5] = states[2];
      cells[5][4] = states[1];
      printf("%d ", cells[i][j]); 
    }
    printf("\n");
  }
   
  // assign values to future array.
    for(i = 0; i < rows; i++)
    {
      for(j = 0; j < cols; j++)
      {      
	futurecells[i][j] = cells[i][j];
	//printf("%d ", futurecells[i][j]);
     }  
    
  }

 
  //////////////////////////////////////////////////////////////SUSCEPTIBLE//////////////////////////////////////////////////
  //Check if a cell is sus
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
	  if(cells[0][1] == states[2])
	  {
	    futurecells[0][0] = states[1];
	  }

	  if(cells[1][0] == states[2])
	  {
	    futurecells[0][0] = states[1];
	  }

	  if(cells[1][1] == states[2])
	  {
	    futurecells[0][0] = states[1];
	  }
       }

	//Top right corner
       if(cells[0][SIZE-1] == states[0])
       {
	  if(cells[0][SIZE-2] == states[2])
	  {
	    futurecells[0][SIZE-1] = states[1];
	  }

	  if(cells[1][SIZE-2] == states[2])
	  {
	    futurecells[0][SIZE-1] = states[1];	   
	  }

	  if(cells[1][SIZE-1] == states[2])
	  {
	    futurecells[0][SIZE-1] = states[1];	    
	  }
       }

	//Bottom Left Corner
       if(cells[SIZE-1][0] == states[0])
       {
	  if(cells[SIZE-1][1] == states[2])
	  {
	    futurecells[SIZE-1][0] = states[1];
	    
	  }

	  if(cells[SIZE-2][1] == states[2])
	  {
	     futurecells[SIZE-1][0] = states[1];
	    
	  }
	  if(cells[SIZE-2][0] == states[2])
	  {
	     futurecells[SIZE-1][0] = states[1];
	    
	  }
       }

       //Bottom Right Corner
       if(cells[SIZE-1][SIZE-1] == states[0])
       {
	  if(cells[SIZE-1][SIZE-2] == states[2])
	  {
	    futurecells[SIZE-1][SIZE-1] = states[1];	    
	  }
	  
	  if(cells[SIZE-2][SIZE-2] == states[2])
	  {
	     futurecells[SIZE-1][SIZE-1] = states[1];
	  }
	  
	  if(cells[SIZE-2][SIZE-1] == states[2])
	  {
	     futurecells[SIZE-1][SIZE-1] = states[1];
	    
	  }
       }
    }
  }

  //check the first row
  for(i = 0; i < rows; i++)
  {
    for(j = 1; j < cols-1; j++)
    {
      if(cells[0][j] == states[0])
      {
	if(cells[0][j-1] == states[2])
	{
	  futurecells[0][j] = states[1];
	}

	if(cells[1][j-1] == states[2])
	{
	  futurecells[0][j] = states[1];
	}
	
	if(cells[1][j] == states[2])
	{
	  futurecells[0][j] = states[1];
	}

	if(cells[1][j+1] == states[2])
	{
	  futurecells[0][j] = states[1];
	}

	if(cells[0][j+1] == states[2])
	{
	  futurecells[0][j] = states[1];
	}
      } 
    }
  }

   //check the bottom row
  for(i = SIZE-1; i < rows; i++)
  {
    for(j = 1; j < cols-1; j++)
    {
      if(cells[SIZE-1][j] == states[0])
      {
	if(cells[i][j-1] == states[2])
	{
	  futurecells[i][j] = states[1];
	}

	if(cells[i-1][j-1] == states[2])
	{
	  futurecells[i][j] = states[1];
	}

	if(cells[i-1][j] == states[2])
	{
	  futurecells[i][j] = states[1];
	}

	if(cells[i-1][j+1] == states[2])
	{
	  futurecells[i][j] = states[1];
	}

	if(cells[i][j+1] == states[2])
	{
	  futurecells[i][j] = states[1];
	}
      } 
    }
  }

  // check the left column
   for(i = 1; i < rows-1; i++){
     for(j = 0; j < 1; j++){
       if(cells[i][0] == states[0]){
	 
  	if(cells[i-1][0] == states[2]){
  	  futurecells[i][0] = states[1];
 	}

	if(cells[i+1][0] == states[2])
  	{
  	  futurecells[i][0] = states[1];
  	}

	if(cells[i-1][1] == states[2])
  	{
  	  futurecells[i][0] = states[1];
  	}

	if(cells[i][1] == states[2])
  	{
  	  futurecells[i][0] = states[1];
  	}

	if(cells[i+1][1] == states[2])
 	{
  	  futurecells[i][0] = states[1];
  	}	
       } 
     }
  }

   // check the right column
   for(i = 1; i < rows-1; i++){
     for(j = 0; j < cols-1; j++){
       if(cells[i][SIZE-1] == states[0]){
  	if(cells[i-1][SIZE-1] == states[2]){
  	  futurecells[i][SIZE-1] = states[1];
 	}

	if(cells[i+1][SIZE-1] == states[2])
  	{
  	  futurecells[i][SIZE-1] = states[1];
  	}

	if(cells[i-1][SIZE-2] == states[2])
  	{
  	  futurecells[i][SIZE-1] = states[1];
  	}

	if(cells[i][SIZE-2] == states[2])
  	{
  	  futurecells[i][SIZE-1] = states[1];
  	}

	if(cells[i+1][SIZE-2] == states[2])
 	{
  	  futurecells[i][SIZE-1] = states[1];
  	}
       } 
     }
  }

   // Check all other cells that are not border cells.
  for(i = 1; i < rows-1; i++)
  {
    for(j = 1; j < cols-1; j++)
      {
	if(cells[i][j] == states[0]){
	  if(cells[i-1][j-1] == states[2]){
	    futurecells[i][j] = states[1];
	  }
	  if(cells[i-1][j] == states[2]){
	    futurecells[i][j] = states[1];
	  }
	  if(cells[i-1][j+1] == states[2]){
	    futurecells[i][j] = states[1];
	  }
	  if(cells[i][j-1] == states[2]){
	    futurecells[i][j] = states[1];
	  }
	  if(cells[i][j+1] == states[2]){
	    futurecells[i][j] = states[1];
	  }
	  if(cells[i+1][j-1] == states[2]){
	    futurecells[i][j] = states[1];
	  }
	  if(cells[i+1][j] == states[2]){
	    futurecells[i][j] = states[1];
	  }
	  if(cells[i+1][j+1] == states[2]){
	    futurecells[i][j] = states[1];
	  }
	}
     }
  }

   //////////////////////////////////////////////////////EXPOSED//////////////////////////////////////////////////////

   
   // Check if a cell is exposed
  for(i = 0; i < rows; i++)
  {
    for(j = 0; j < cols; j++)
    {
      if(cells[i][j] == states[1])
      {
	expcells++;
	
       //Top Left Corner
       if(cells[0][0] == states[1])
       {
	  if(cells[0][1] == states[2])
	  {
	    neighbourhood+=infN;
	  }

	  if(cells[1][0] == states[2])
	  {
	    neighbourhood+=infN;
	  }

	  if(cells[1][1] == states[2])
	  {
	    neighbourhood+=infN;
	  }
       }
      if(neighbourhood > randNum)
      {
	futurecells[0][0] = states[2];
      }
      neighbourhood = 0.0;
      randNum = ((float)rand()/(float)(RAND_MAX)) * (1 - 0);

      //Top right corner
      if(cells[0][SIZE-1] == states[1])
      {
	  if(cells[0][SIZE-2] == states[2])
	  {
	    neighbourhood+=infN;
	  }

	  if(cells[1][SIZE-2] == states[2])
	  {
	    neighbourhood+=infN;
	  }

	  if(cells[1][SIZE-1] == states[2])
	  {
	    neighbourhood+=infN;
	  }
      }
      if(neighbourhood > randNum)
      {
	futurecells[0][SIZE-1] = states[2];
      }
      neighbourhood = 0.0;
      randNum = ((float)rand()/(float)(RAND_MAX)) * (1 - 0);
      
      //Bottom Left Corner
      if(cells[SIZE-1][0] == states[1])
      {
        if(cells[SIZE-1][1] == states[2])
	{
	  neighbourhood += infN;
        }

	if(cells[SIZE-2][1] == states[2])
        {
          neighbourhood += infN; 
        }

	if(cells[SIZE-2][0] == states[2])
        {
          neighbourhood += infN;
        }
      }
      if(neighbourhood > randNum)
      {
	futurecells[SIZE-1][0] = states[2];
      }
      neighbourhood = 0.0;
      randNum = ((float)rand()/(float)(RAND_MAX)) * (1 - 0);

      //Bottom Right Corner
      if(cells[SIZE-1][SIZE-1] == states[1])
      {
        if(cells[SIZE-1][SIZE-2] == states[2])
        {
          neighbourhood+=infN;	    
        }

	if(cells[SIZE-2][SIZE-2] == states[2])
	{
          neighbourhood+=infN;
        }

	if(cells[SIZE-2][SIZE-1] == states[2])
        {
          neighbourhood+=infN;
        }
      }
      if(neighbourhood > randNum)
      {
	futurecells[SIZE-1][SIZE-1] = states[2];
      }
      neighbourhood = 0.0;
      randNum = ((float)rand()/(float)(RAND_MAX)) * (1 - 0);
    }
  }

   //check the first row
  for(i = 0; i < 1; i++){
    for(j = 1; j < cols-1; j++){
      if(cells[0][j] == states[1]){
	if(cells[0][j-1] == states[2]){
	  neighbourhood+=infN;
	}
	if(cells[1][j-1] == states[2]){
	  neighbourhood+=infN;
	}

	if(cells[1][j] == states[2]){
	  neighbourhood+=infN;
	}

	if(cells[1][j+1] == states[2]){
	  neighbourhood+=infN;
	}

	if(cells[0][j+1] == states[2]){
	  neighbourhood+=infN;
	}
	
	//printf("\nneigh: %.2f, rand: %.2f  ", neighbourhood, randNum);
	
	if(neighbourhood > randNum){
	  futurecells[i][j] = states[2];
	}
	neighbourhood = 0.0;
	randNum = ((float)rand()/(float)(RAND_MAX)) * (1 - 0);
      }
    }
  }
    
   //check the bottom row
  for(i = SIZE-1; i < rows; i++){
    for(j = 1; j < cols-1; j++){
      if(cells[SIZE-1][j] == states[1]){
	if(cells[i][j-1] == states[2]){
	  neighbourhood+=infN;
	}

	if(cells[i-1][j-1] == states[2]){
	  neighbourhood+=infN;
	}

	if(cells[i-1][j] == states[2]){
	  neighbourhood+=infN;
	}

	if(cells[i-1][j+1] == states[2]){
	  neighbourhood+=infN;
	}

	if(cells[i][j+1] == states[2]){
	  neighbourhood+=infN;
	}
		
	//printf("\nneigh: %.2f, rand: %.2f  ", neighbourhood, randNum);
	
	if(neighbourhood > randNum){
	  futurecells[i][j] = states[2];
	}
	neighbourhood = 0.0;
	randNum = ((float)rand()/(float)(RAND_MAX)) * (1 - 0);
      }
    }
  }

   // check the left column
   for(i = 1; i < rows; i++){
     for(j = 0; j < 1; j++){
       if(cells[i][0] == states[1]){	 
  	if(cells[i-1][0] == states[2]){
  	  neighbourhood+=infN;
 	}
	
	if(cells[i+1][0] == states[2]){
  	  neighbourhood+=infN;
  	}

	if(cells[i-1][1] == states[2]){
  	  neighbourhood+=infN;
  	}

	if(cells[i][1] == states[2]){
  	  neighbourhood+=infN;
  	}

	if(cells[i+1][1] == states[2]){
  	  neighbourhood+=infN;
  	}

	// printf("\nneigh: %.2f, rand: %.2f  ", neighbourhood, randNum);
	
	 if(neighbourhood > randNum){
	   futurecells[i][j] = states[2];
	 }
	 neighbourhood = 0.0;
	 randNum = ((float)rand()/(float)(RAND_MAX)) * (1 - 0);
       } 
     }
  }

   // check the right column
   for(i = 1; i < rows-1; i++){
     for(j = SIZE-1; j < cols; j++){
       if(cells[i][SIZE-1] == states[1]){
  	if(cells[i-1][SIZE-1] == states[2]){
  	  neighbourhood+=infN;
 	}

	if(cells[i+1][SIZE-1] == states[2]){
  	  neighbourhood+=infN;
  	}

	if(cells[i-1][SIZE-2] == states[2]){
  	  neighbourhood+=infN;
  	}

	if(cells[i][SIZE-2] == states[2]){
  	  neighbourhood+=infN;
  	}

	if(cells[i+1][SIZE-2] == states[2]){
  	  neighbourhood+=infN;
  	}

	// printf("\nneigh: %.2f, rand: %.2f  ", neighbourhood, randNum);
	
	 if(neighbourhood > randNum){
	   futurecells[i][j] = states[2];
	 }
	 neighbourhood = 0.0;
	 randNum = ((float)rand()/(float)(RAND_MAX)) * (1 - 0);
       } 
     }
  }

    // Check all other cells that are not border cells.
   for(i = 1; i < rows-1; i++){
     for(j = 1; j < cols-1; j++){
       if(cells[i][j] == states[1]){
	   if(cells[i-1][j-1] == states[2]){
	     neighbourhood+=infN;
	   }
	   if(cells[i-1][j] == states[2]){
	     neighbourhood+=infN;
	   }
	   if(cells[i-1][j+1] == states[2]){
	     neighbourhood+=infN;
	   }
	   if(cells[i][j-1] == states[2]){
	     neighbourhood+=infN;
	   }
	   if(cells[i][j+1] == states[2]){
	     neighbourhood+=infN;
	   }
	   if(cells[i+1][j-1] == states[2]){
	     neighbourhood+=infN;
	   }
	   if(cells[i+1][j] == states[2]){
	     neighbourhood+=infN;
	   }
	   if(cells[i+1][j+1] == states[2]){
	     neighbourhood+=infN;
	   }

	   printf("\nneigh: %.2f, rand: %.2f  ", neighbourhood, randNum);
	
	   if(neighbourhood > randNum){
	     futurecells[i][j] = states[2];
	   }
	   neighbourhood = 0.0;
	   randNum = ((float)rand()/(float)(RAND_MAX)) * (1 - 0);
	 }
     }
   }
////////////////////////////////////////////////////////////INFECTED///////////////////////////////////////////////////////////
    
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
  
  // Print each generation and store futurecells in cells array
  counter++;
  printf("\nGeneration: %d \n\n", counter);
  for(i = 0; i < rows; i++)
  {
    for(j = 0; j < cols; j++)
    {
      cells[i][j] = futurecells[i][j];
      printf("%d ", cells[i][j]);
    }  
    printf("\n");
  }
    
  printf("\nSus Cells = %d ", suscells);
  printf("\nExposed Cells = %d ", expcells);
  printf("\nInfected Cells = %d ", infectedcells);
  printf("\nRecovered Cells = %d ", recoveredcells);
  printf("\nDead Cells = %d \n", deadcells);
  }
}
