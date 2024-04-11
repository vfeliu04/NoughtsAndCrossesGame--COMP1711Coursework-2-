
#include <stdio.h>

#include "game.h"
#include "playGame.h"
#include "endGame.h"

/*
 * Controls the game logic from start to end
 */

void playGame( Game *game ) {
  // Initializing variables
  char symbols[2] = { 'X','O' };
  int player = 0;
  int won = 0;

  // New game starting
  printf("New game starting\n");
  showGame( game );


  // Your game should be controlled by an outer loop
  // Each pass through the loop is one completed move by a player
  // Loop while won is equal to zero
  while(won == 0){
    // Request a move from the next player and check it is valid (an unused square within the board)
    printf("Player %c: Enter your move as row column values:\n",symbols[player]); // use this to request the player move
    
    // If the move is valid 
    if(makeMove(game ,symbols[player]) == 1){
      // Update the board
      showGame( game );

      // After each valid move you can test for win or draw using functions you implement in endGame.c
      // If when the function winGame called returns 1 then the current player has won and teh variable won is set to 1
      if(winGame(game, symbols[player]) == 1){
        printf("Player %c has won\n",symbols[player]); // use to announce a winner - game is over
        won = 1;
      }
      // If when the function drawGame called returns 1 then the the match has ended in a draw and the variable won is set to 1
      else if(drawGame(game) == 1){
        printf("Match is drawn\n"); // use to announce a draw - game is over
        won = 1;
      }

      // Switch between the players
      if(player == 0){
        player = 1;
      }
      else{
        player = 0;
      }
    }
    else{
      // If the move is invalid you should repeat the request for the current player
      printf("Move rejected. Please try again\n"); // use this message if move cannot be made. You must repeat the request for a move
    }
  }
  return;
}

/*
 * Display the game board - do not adjust the formatting
 */

void showGame( Game *game ) {

  printf("\n");
  printf("      0  1  2\n");
  printf("\n");
  printf(" 0    %c  %c  %c\n",game->board[0][0],game->board[0][1],game->board[0][2]);
  printf(" 1    %c  %c  %c\n",game->board[1][0],game->board[1][1],game->board[1][2]);
  printf(" 2    %c  %c  %c\n",game->board[2][0],game->board[2][1],game->board[2][2]);
  printf("\n");

  return;
}

/*
 * Read in the players chosen location
 * Check that the input is a valid empty square
 * If valid then update the board (return 1)
 * If invalid reject the move (return 0)
 */

int makeMove( Game *game, char symbol ) {
  // Initialize variables to represent rows and column
  int row;
  int col;
  
  

  // Read the players move from the keyboard, expected as two integers coordinates as shown on the board 
  scanf("%i %i", &row, &col);

  // Test that the chosen location is a valid empty space and within range of the board
  if((row < game->boardSize) && (col < game->boardSize) && (game->board[row][col] == '.')){
    game->board[row][col] = symbol; // Set the current location in the board to the player symbol
    return 1; // move accepted
  }
  else{
    return 0; // move rejected
  } 
}

