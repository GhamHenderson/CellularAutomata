#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include "timer.h"
#define SIZE 10

extern int thread_count;
void *cellautochild(void* rank){
  pthread_mutex_t lock;
  long my_rank = (long) rank;
  int gens = 10;
  long long my_m = gens / thread_count;
  long long my_first_i = my_m * my_rank;
  long long my_last_i = my_first_i + my_m;
  double start, finish, elapsed;
  GET_TIME(start);
  // 0 = sus, 1 = exposed, 2 = infected,
  // 3 = recovered, 4 = dead
  int states[5] = {0,1,2,3,4};
  
  // Grid Variables
  int i,j,k;
  int rows = SIZE;
  int cols = SIZE;
  int cells[cols][rows];
  int futurecells[cols][rows];
  int counter = 1;
  float chanceOfDeath = 0.5;
  float neighbourhood = 0.0;
  float infN = 0.3;
  float deadN = 0.05;
  float recN;
  unsigned int suscells = 0;
  unsigned int expcells = 0;
  unsigned int infectedcells = 0;
  unsigned int recoveredcells = 0;
  unsigned int deadcells = 0;
  srand((unsigned int)time(NULL));
  
  //  printf("\nGeneration 1 \n\n");
  
  float randNum = ((float)rand()/(float)(RAND_MAX)) * (1 - 0);

    //int rand_i = ((float)rand()/(float)(RAND_MAX)) * (SIZE - 0);
    //int rand_j = ((float)rand()/(float)(RAND_MAX)) * (SIZE - 0);
    // // Print first generation array and assign values to both arrays.
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            cells[i][j] = states[0];

            // printf("%d ", cells[i][j]);
        }
        printf("\n");
    }

    //infect random cells to begin simulation

    cells[0][0] = states[2];
    cells[0][1] = states[2];
    cells[0][2] = states[2];
    cells[8][12] = states[2];
    cells[9][18] = states[2];
    cells[7][5] = states[2];
    cells[4][12] = states[2];



    // assign values to future array.
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            futurecells[i][j] = cells[i][j];
            //printf("%d ", futurecells[i][j]);
        }
    }


    //Create the generations
    for(k = my_first_i; k < my_last_i; k++){
        pthread_mutex_lock(&lock);
        //////////////////////////////////////////////////////////////SUSCEPTIBLE//////////////////////////////////////////////////
        // Check if a cell is sus
        for(i = 0; i < rows; i++)
        {
            for(j = 0; j < cols; j++)
            {
                if(cells[i][j] == states[0])
                {
                    suscells++;
                }
            }
        }
	pthread_mutex_unlock(&lock);

	pthread_mutex_lock(&lock);
        for(i = 0; i < rows; i++){
            for(j = 0; j < cols; j++){
                if(cells[i][j] == states[0]){
                    //Top Left Corner
                    if(cells[0][0] == states[0]){
                        if(cells[0][1] == states[2]){
                            futurecells[0][0] = states[1];
                        }

                        if(cells[1][0] == states[2]){
                            futurecells[0][0] = states[1];
                        }

                        if(cells[1][1] == states[2]){
                            futurecells[0][0] = states[1];
                        }
                    }
		    
                    //Top right corner
                    if(cells[0][SIZE-1] == states[0]){
                        if(cells[0][SIZE-2] == states[2]){
                            futurecells[0][SIZE-1] = states[1];
                        }

                        if(cells[1][SIZE-2] == states[2]){
                            futurecells[0][SIZE-1] = states[1];
                        }

                        if(cells[1][SIZE-1] == states[2]){
                            futurecells[0][SIZE-1] = states[1];
                        }
                    }

                    //Bottom Left Corner
                    if(cells[SIZE-1][0] == states[0]){
                        if(cells[SIZE-1][1] == states[2]){
                            futurecells[SIZE-1][0] = states[1];
                        }

                        if(cells[SIZE-2][1] == states[2]){
                            futurecells[SIZE-1][0] = states[1];
                        }
                        if(cells[SIZE-2][0] == states[2]){
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
	    pthread_mutex_unlock(&lock);
            //////////////////////////////////////////////////////EXPOSED//////////////////////////////////////////////////////

	    pthread_mutex_lock(&lock);
            // Check if a cell is exposed
            for(i = 0; i < rows; i++)
            {
                for(j = 0; j < cols; j++)
                {
                    if(cells[i][j] == states[1])
                    {
                        expcells++;
                    }
                    //Top Left Corner
                    if(cells[0][0] == states[1])
                    {
                        if(cells[0][1] == states[2])
                        {
                            neighbourhood+=infN;
                        }
                        else if(cells[0][1] == states[4])
                        {
                            neighbourhood+=deadN;
                        }

                        if(cells[1][0] == states[2])
                        {
                            neighbourhood+=infN;
                        }
                        else if(cells[1][0] == states[4])
                        {
                            neighbourhood+=deadN;
                        }

                        if(cells[1][1] == states[2])
                        {
                            neighbourhood+=infN;
                        }
                        else if(cells[1][1] == states[4])
                        {
                            neighbourhood+=deadN;
                        }
                    }
                    if(neighbourhood > randNum)
                    {
                        futurecells[0][0] = states[2];
                    }

                    neighbourhood = 0.0;
                    randNum = ((float)rand()/(float)(RAND_MAX)) * (1 - 0);

                    //Top right corner
                    if(cells[0][SIZE-1] == states[1]){
                        if(cells[0][SIZE-2] == states[2]){
                            neighbourhood+=infN;
                        }
                        else if(cells[0][SIZE-2] == states[4]){
                            neighbourhood+=deadN;
                        }

                        if(cells[1][SIZE-2] == states[2]){
                            neighbourhood+=infN;
                        }
                        else if(cells[1][SIZE-2] == states[4]){
                            neighbourhood+=deadN;
                        }

                        if(cells[1][SIZE-1] == states[2]){
                            neighbourhood+=infN;
                        }
                        else if(cells[1][SIZE-1] == states[4]){
                            neighbourhood+=deadN;
                        }
                    }
                    if(neighbourhood > randNum){
                        futurecells[0][SIZE-1] = states[2];
                    }
                    neighbourhood = 0.0;
                    randNum = ((float)rand()/(float)(RAND_MAX)) * (1 - 0);

                    //Bottom Left Corner
                    if(cells[SIZE-1][0] == states[1]){
                        if(cells[SIZE-1][1] == states[2]){
                            neighbourhood += infN;
                        }
                        else if(cells[SIZE-1][1] == states[4]){
                            neighbourhood+=deadN;
                        }

                        if(cells[SIZE-2][1] == states[2]){
                            neighbourhood += infN;
                        }
                        else if(cells[SIZE-2][1] == states[4]){
                            neighbourhood+=deadN;
                        }

                        if(cells[SIZE-2][0] == states[2]){
                            neighbourhood += infN;
                        }
                        else if(cells[SIZE-2][0] == states[4]){
                            neighbourhood+=deadN;
                        }
                    }
                    if(neighbourhood > randNum){
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
                        else if(cells[SIZE-1][SIZE-2] == states[4])
                        {
                            neighbourhood+=deadN;
                        }

                        if(cells[SIZE-2][SIZE-2] == states[2])
                        {
                            neighbourhood+=infN;
                        }
                        else if(cells[SIZE-2][SIZE-2] == states[4])
                        {
                            neighbourhood+=deadN;
                        }

                        if(cells[SIZE-2][SIZE-1] == states[2])
                        {
                            neighbourhood+=infN;
                        }
                        else if(cells[SIZE-2][SIZE-1] == states[4])
                        {
                            neighbourhood+=deadN;
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
                        else if(cells[0][j-1] == states[4]){
                            neighbourhood+=deadN;
                        }
                        if(cells[1][j-1] == states[2]){
                            neighbourhood+=infN;
                        }
                        else if(cells[1][j-1] == states[4]){
                            neighbourhood+=deadN;
                        }

                        if(cells[1][j] == states[2]){
                            neighbourhood+=infN;
                        }
                        else if(cells[1][j] == states[4]){
                            neighbourhood+=deadN;
                        }

                        if(cells[1][j+1] == states[2]){
                            neighbourhood+=infN;
                        }
                        else if(cells[1][j+1] == states[4]){
                            neighbourhood+=deadN;
                        }

                        if(cells[0][j+1] == states[2]){
                            neighbourhood+=infN;
                        }
                        else if(cells[0][j+1] == states[4]){
                            neighbourhood+=deadN;
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
                        else if(cells[i][j-1] == states[4]){
                            neighbourhood+=deadN;
                        }

                        if(cells[i-1][j-1] == states[2]){
                            neighbourhood+=infN;
                        }
                        else if(cells[i-1][j-1] == states[4]){
                            neighbourhood+=deadN;
                        }

                        if(cells[i-1][j] == states[2]){
                            neighbourhood+=infN;
                        }
                        else if(cells[i-1][j] == states[4]){
                            neighbourhood+=deadN;
                        }

                        if(cells[i-1][j+1] == states[2]){
                            neighbourhood+=infN;
                        }
                        else if(cells[i-1][j+1] == states[4]){
                            neighbourhood+=deadN;
                        }

                        if(cells[i][j+1] == states[2]){
                            neighbourhood+=infN;
                        }
                        else if(cells[i][j+1] == states[4]){
                            neighbourhood+=deadN;
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
                        else if(cells[i-1][0] == states[4]){
                            neighbourhood+=deadN;
                        }

                        if(cells[i+1][0] == states[2]){
                            neighbourhood+=infN;
                        }
                        else if(cells[i+1][0] == states[4]){
                            neighbourhood+=deadN;
                        }

                        if(cells[i-1][1] == states[2]){
                            neighbourhood+=infN;
                        }
                        else if(cells[i-1][1] == states[4]){
                            neighbourhood+=deadN;
                        }

                        if(cells[i][1] == states[2]){
                            neighbourhood+=infN;
                        }
                        else if(cells[i][1] == states[4]){
                            neighbourhood+=deadN;
                        }

                        if(cells[i+1][1] == states[2]){
                            neighbourhood+=infN;
                        }
                        else if(cells[i+1][1] == states[4]){
                            neighbourhood+=deadN;
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
                        else if(cells[i-1][SIZE-1] == states[4]){
                            neighbourhood+=deadN;
                        }

                        if(cells[i+1][SIZE-1] == states[2]){
                            neighbourhood+=infN;
                        }
                        else if(cells[i+1][SIZE-1] == states[4]){
                            neighbourhood+=deadN;
                        }

                        if(cells[i-1][SIZE-2] == states[2]){
                            neighbourhood+=infN;
                        }
                        else if(cells[i-1][SIZE-2] == states[4]){
                            neighbourhood+=deadN;
                        }

                        if(cells[i][SIZE-2] == states[2]){
                            neighbourhood+=infN;
                        }
                        else if(cells[i][SIZE-2] == states[4]){
                            neighbourhood+=deadN;
                        }

                        if(cells[i+1][SIZE-2] == states[2]){
                            neighbourhood+=infN;
                        }
                        else if(cells[i+1][SIZE-2] == states[4]){
                            neighbourhood+=deadN;
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
                        else if(cells[i-1][j-1] == states[4]){
                            neighbourhood+=deadN;
                        }

                        if(cells[i-1][j] == states[2]){
                            neighbourhood+=infN;
                        }
                        else if(cells[i-1][j] == states[4]){
                            neighbourhood+=deadN;
                        }

                        if(cells[i-1][j+1] == states[2]){
                            neighbourhood+=infN;
                        }
                        else if(cells[i-1][j+1] == states[4]){
                            neighbourhood+=deadN;
                        }

                        if(cells[i][j-1] == states[2]){
                            neighbourhood+=infN;
                        }
                        else if(cells[i][j-1] == states[4]){
                            neighbourhood+=deadN;
                        }

                        if(cells[i][j+1] == states[2]){
                            neighbourhood+=infN;
                        }
                        else if(cells[i][j+1] == states[4]){
                            neighbourhood+=deadN;
                        }

                        if(cells[i+1][j-1] == states[2]){
                            neighbourhood+=infN;
                        }
                        else if(cells[i+1][j-1] == states[4]){
                            neighbourhood+=deadN;
                        }

                        if(cells[i+1][j] == states[2]){
                            neighbourhood+=infN;
                        }
                        else if(cells[i+1][j] == states[4]){
                            neighbourhood+=deadN;
                        }

                        if(cells[i+1][j+1] == states[2]){
                            neighbourhood+=infN;
                        }
                        else if(cells[i+1][j+1] == states[4]){
                            neighbourhood+=deadN;
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
	    pthread_mutex_unlock(&lock);
            ////////////////////////////////////////////////////////////INFECTED///////////////////////////////////////////////////////////
	    pthread_mutex_lock(&lock);
            // Check if a cell is infected
            for(i = 0; i < rows; i++){
                for(j = 0; j < cols; j++){
                    if(cells[i][j] == states[2]){
                        infectedcells++;

                        //50% chance of death
                        //50% chance of recovery
                        if(chanceOfDeath > randNum){
                            futurecells[i][j] = states[3];
                        }
                        randNum = ((float)rand()/(float)(RAND_MAX)) * (1 - 0);

                        if(chanceOfDeath < randNum){
                            futurecells[i][j] = states[4];
                        }
                        randNum = ((float)rand()/(float)(RAND_MAX)) * (1 - 0);
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
                    if(cells[i][j] == states[4])
                    {
                        deadcells++;
                    }
                }
            }
	    pthread_mutex_unlock(&lock);
            // Print each generation and store future cells in cells array
	    pthread_mutex_lock(&lock);
            printf("\nGeneration: %d \n\n", counter);
            counter++;
            for(i = 0; i < rows; i++)
            {
                for(j = 0; j < cols; j++)
                {
                    printf("%d ", cells[i][j]);
                    cells[i][j] = futurecells[i][j];
                }
                printf("\n");
            }
	    pthread_mutex_unlock(&lock);
            //Print Results
            printf("\n(0)Sus Cells = %d ", suscells);
            printf("\n(1)Exposed Cells = %d ", expcells);
            printf("\n(2)Infected Cells = %d ", infectedcells);
            printf("\n(3)Recovered Cells = %d ", recoveredcells);
            printf("\n(4)Dead Cells = %d ", deadcells);
            printf("\n Thread ID : %ld \n",my_rank);

            //Reset variables.
            suscells=0;
            expcells=0;
            infectedcells=0;
            recoveredcells=0;
            deadcells=0;

            pthread_mutex_unlock(&lock);
        }
    }
    GET_TIME(finish);
    elapsed = finish - start;
    printf("The code to be timed took %e seconds\n", elapsed);
    printf("gen = %d", gens);
}

