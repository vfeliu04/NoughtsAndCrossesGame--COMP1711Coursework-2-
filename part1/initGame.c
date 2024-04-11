
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "initGame.h"

/*
 * Intialise game data for a new game
 */

Game *initGame( int boardSize, int winLength ) {

  Game *game;

  // for incorrect boardSize or winLength you should return a NULL pointer
  if(boardSize != 3 || winLength > boardSize){
    printf("Incorrect parameter values for board size or win length. Exiting\n");
  }
  
  
  // Allocate the Game data structure
  game =(Game *)malloc(sizeof(Game));
  // Initialise the Game data structure values 
  game->boardSize = boardSize;
  game->winLength = winLength;
  

  // board values should be set to '.' (unused location)
  // Loop through the board and set all values to '.'
  for(int i = 0; i < boardSize; i++){
    for(int j = 0; j < (boardSize + 1); j++){
      game->board[i][j] = '.';
    }
  }
  
  return game;
}


