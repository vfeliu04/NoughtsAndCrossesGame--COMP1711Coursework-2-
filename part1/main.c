
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "initGame.h"
#include "playGame.h"


/*
 * main function: program entry point
 */

int main( int argc, char *argv[] ) {

  Game *game; // pointer for the game structure

  // Setting the pointer to the function initGame
  game = initGame(3, 3);
  
  // play a full game
  playGame(game);

  free(game); // free heap memory that was used

  return 0;
}

