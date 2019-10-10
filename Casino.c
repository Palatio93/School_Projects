#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int money = 100;
void flip_coin(int, int);
void Cho_Han(int, int);
void High_Card(int);

int main(){ // Games
  int Guess = 0, Bet = 0;
  printf("Let's play a game.\n");
//  printf("Heads is 1 and Tails is 2.\n");
//  printf("Sum odd is 1\t Sum even is 2\n");
  printf("Game is pick a random card with values between 1 and 13.\n");
  printf("Place your bet please.\n");
  scanf("%d", &Bet);
  printf("Give me your guess please.\n");
  scanf("%d", &Guess);
  //flip_coin(Guess, Bet);
  //Cho_Han(Guess, Bet);
  High_Card(Bet);
  return 0;
}
// Creating Flip Coin game
void flip_coin(int guess, int bet) {
  srand(time(NULL));
  if (bet <= money && bet > 0) { // Check if bet is valid
    int result = rand()%2+1; // Heads will be 1, Tails will be 2
    if (guess >= 1 && guess <= 2){
      if (guess == 1)
        printf("You're rolling for Heads.\n");
      else
        printf("You're rolling for Tails.\n");
      if (result == 1)
        printf("The coin fell on Heads.\n");
      else
        printf("The coin fell on Tails.\n");
      if ((guess == 1 && result == 1) || (guess == 2 && result == 2)){
        money += bet;
        printf("You won.\n Your new balance is %d.\n", money);
      } else{
        money -= bet;
        printf("You lost.\n Your new balance is %d.\n", money);
      }
    } else
      printf("Not a valid guess.\n");
  } else
    printf("Bet not valid.\n");
}

// Creating Cho Han game
void Cho_Han(int guess, int bet) { // Sum even is 2, sum odd is 1
  srand(time(NULL));
  if (bet <= money && bet > 0) { //Check if bet is valid
    int Dice1 = rand()%6+1, Dice2 = rand()%6+1;
    if (guess >= 1 && guess <= 2){
      if (guess == 1)
        printf("You're going for sum odd.\n");
      else
        printf("You're going for sum even.\n");
      if ((Dice1 + Dice2) % 2 == 0)
        printf("The sum is even.\n");
      else
        printf("The sum is odd.\n");
      if (((Dice1 + Dice2) % 2 == 0 && (guess == 2)) || ((Dice1 + Dice2) % 2 != 0 && (guess == 1))) {
        printf("You won!.\n");
        money += bet;
        printf("New balance is: %d\n", money);
      } else {
        printf("You lost.\n");
        money -= bet;
        printf("New balances is: %d\n", money);
      }
    } else
      printf("Not a valid guess.\n");
  } else
    printf("Bet not valid.\n");
}

//Creating High Card game
void High_Card(int bet) {
  if (money > 0) { // Checking if player has money to play
      if (bet <= money && bet > 0) { // Checking if bet is valid
          srand(time(NULL));
          int Result = rand()%13+1;  // House pick
          int Player_Result = rand()%13+1;   //Player pick
          printf("You picked %d.\n", Player_Result);
          printf("House picked %d.\n", Result);
          if (Player_Result > Result) {    // Player wins
              printf("You won!\n");
              money += bet;
              printf("New balance is %d.\n", money);
          } else if (Player_Result < Result) { // Player loses
              printf("You lost.\n");
              money -= bet;
              printf("New balance is %d.\n", money);
          } else {
              printf("That's a tie!");
              printf("New balance is %d.\n", money);
          }
      } else
          printf("You don't have enough money to play.\n");
  } else
      printf("You don't have enough money to play.\n");
}
