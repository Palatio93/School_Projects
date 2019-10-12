#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int money = 100;
void flip_coin(int, int);
void Cho_Han(int, int);
void High_Card(int);
void Roulette(int);

int main(void){ // Games
  int Guess = 0, Bet = 0, Player_Choice = 0, Game_of_choice = 1, keep_playing_casino = 0, keep_playing_game = 1;
  printf("\033[1;36m"); // Color
  printf("You wanna play in the casino?\n 1 for Yes \t Any key for No\n");
  scanf("%d", &Player_Choice);
  if (Player_Choice == 1){
    do {
      printf("What would you like to play?\n 1. Flip a coin \n 2. Cho Han\n 3. High Card\n 4. Roulette\n");
      scanf("%d", &Game_of_choice);
      printf("\033[0m");
      switch (Game_of_choice) {
        case 1: // Flip Coin
          do {
            printf("Heads is 1 and Tails is 2.\n");
            printf("Place your bet please.\n");
            scanf("%d", &Bet);
            printf("Give me your guess please.\n");
            scanf("%d", &Guess);
            flip_coin(Guess, Bet);
            printf("\nYou want to stay in this game?\n 1 for Yes \t Any key for No\n");
            scanf("%d", &keep_playing_game);
          } while(keep_playing_game == 1);
        break;
        case 2: // Cho Han
          do {
            printf("Sum odd is 1\t Sum even is 2\n");
            printf("Place your bet please.\n");
            scanf("%d", &Bet);
            printf("Give me your guess please.\n");
            scanf("%d", &Guess);
            Cho_Han(Guess, Bet);
            printf("\nYou want to stay in this game?\n 1 for Yes \t Any key for No\n");
            scanf("%d", &keep_playing_game);
          } while(keep_playing_game == 1);
        break;
        case 3: //  High Card
          do {
            printf("Game is pick a random card with values between 1 and 13 from the deck.\n");
            printf("Place your bet please.\n");
            scanf("%d", &Bet);
            High_Card(Bet);
            printf("\nYou want to stay in this game?\n 1 for Yes \t Any key for No\n");
            scanf("%d", &keep_playing_game);
          } while(keep_playing_game == 1);
        break;
        case 4: // Roulette
          printf("Welcome to Roulette\n");
            do {
            printf("Place your bet please.\n");
            scanf("%d", &Bet);
            Roulette(Bet);
            printf("\nYou want to stay in this game?\n 1 for Yes \t Any key for No\n");
            scanf("%d", &keep_playing_game);
          } while(keep_playing_game == 1);
        break;
      }
      printf("\033[1;36m"); // Color
      printf("\nYou want to stay in the casino?\n 1 for Yes \t Any key for No\n");
      scanf("%d", &keep_playing_casino);
    } while (keep_playing_casino == 1);
  } else
      printf("\033[1;36m"); // Color
      printf("\nHave a nice day.\n");
  if (keep_playing_casino != 1){
    system("clear");
    printf("\033[1;36m"); // Color
    printf("Thank you for playing, see you next time.\n");
  }
  return 0;
}


// Creating Flip Coin game
void flip_coin(int guess, int bet) {
  srand(time(NULL));
  if (bet <= money && bet > 0) { // Check if bet is valid
    int result = rand()%2+1; // Heads will be 1, Tails will be 2
    if (guess >= 1 && guess <= 2){
      if (guess == 1)
        printf("\nYou're rolling for Heads.\n");
      else
        printf("\nYou're rolling for Tails.\n");
      if (result == 1)
        printf("The coin fell on Heads.\n");
      else
        printf("The coin fell on Tails.\n");
      if ((guess == 1 && result == 1) || (guess == 2 && result == 2)){
        money += bet;
        printf("\033[1;32m");
        printf("You won.\n Your new balance is %d.\n", money);
        printf("\033[0m");
      } else{
        money -= bet;
        printf("You lost.\n Your new balance is %d.\n", money);
      }
    } else
      printf("\nNot a valid guess.\n");
  } else
    printf("\nBet not valid.\n");
}

// Creating Cho Han game
void Cho_Han(int guess, int bet) { // Sum even is 2, sum odd is 1
  srand(time(NULL));
  if (bet <= money && bet > 0) { //Check if bet is valid
    int Dice1 = rand()%6+1, Dice2 = rand()%6+1;
    if (guess >= 1 && guess <= 2){
      if (guess == 1)
        printf("\nYou're going for sum odd.\n");
      else
        printf("\nYou're going for sum even.\n");
      if ((Dice1 + Dice2) % 2 == 0)
        printf("The sum is even.\n");
      else
        printf("The sum is odd.\n");
      if (((Dice1 + Dice2) % 2 == 0 && (guess == 2)) || ((Dice1 + Dice2) % 2 != 0 && (guess == 1))) {
        printf("\033[1;32m"); //Color
        printf("You won!.\n");
        money += bet;
        printf("New balance is: %d\n", money);
        printf("\033[0m");
      } else {
        printf("You lost.\n");
        money -= bet;
        printf("New balances is: %d\n", money);
      }
    } else
      printf("\nNot a valid guess.\n");
  } else
    printf("\nBet not valid.\n");
}

//Creating High Card game
void High_Card(int bet) {
  if (money > 0) { // Checking if player has money to play
      if (bet <= money && bet > 0) { // Checking if bet is valid
          srand(time(NULL));
          int Result = rand()%13+1;  // House pick
          int Player_Result = rand()%13+1;   //Player pick
          printf("\nYou picked %d.\n", Player_Result);
          printf("\nHouse picked %d.\n", Result);
          if (Player_Result > Result) {    // Player wins
              printf("\033[1;32m"); //Color
              printf("You won!\n");
              money += bet;
              printf("New balance is %d.\n", money);
              printf("\033[0m");
          } else if (Player_Result < Result) { // Player loses
              printf("You lost.\n");
              money -= bet;
              printf("New balance is %d.\n", money);
          } else {
              printf("\033[0;32m");
              printf("\nThat's a tie!\n");
              printf("New balance is %d.\n", money);
              printf("\033[0m");
          }
      } else
          printf("\nYou don't have enough money to play.\n");
  } else
      printf("\nYou don't have enough money to play.\n");
}

// Creating Roulette game
void Roulette(int bet) {
  int Player_guess = 0, roulette_guess_type = 0;
  int column1[12] = {1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34};
  int column2[12] = {2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 35};
  int column3[12] = {3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36};
  printf("  First column \t Second Column \t Third column\n");
  for (int i=0; i<12; i++) {
    printf("\t%d\t\t %d\t\t %d\n", column1[i], column2[i], column3[i]);
  }
  printf("You're betting for:\n 1. A number\n 2. Even\n 3. Odd\n 4. First column\n 5. Second column\n 6. Third column\n");
  scanf("%d", &roulette_guess_type);
  srand(time(NULL));
  int Result = rand()%37;
  switch (roulette_guess_type) {
    case 1:
      printf("What number between 0 and 36 you wanna bet?\n");
      scanf("%d", &Player_guess);
      printf("Ball fall in %d.\n", Result);
      if (Player_guess == Result){
        printf("You won.\n");
        money += (bet * 36);  // Pays 36 to 1
        printf("New balance is %d.\n", money);
      } else {
        printf("You lost.\n");
        money -= bet;
        printf("New balance is %d.\n", money);
      }
    break;
    case 2:
      printf("Ball fall in %d.\n", Result);
      if (Result % 2 == 0){
        printf("You won.\n");
        money += (bet * 2); // Pays 2 to 1
        printf("New balance is %d.\n", money);
      } else {
        printf("You lost.\n");
        money -= bet;
        printf("New balance is %d.\n", money);
      }
    break;
    case 3:
      printf("Ball fall in %d.\n", Result);
      if (Result % 2 != 0){
        printf("You won.\n");
        money += (bet * 2); // Pays 2 to 1
        printf("New balance is %d.\n", money);
      } else {
        printf("You lost.\n");
        money -= bet;
        printf("New balance is %d.\n", money);
      }
    break;
    case 4:
      printf("Ball fall in %d.\n", Result);
      for(int i = 0; i<=12; i++){
        if (Result == column1[i]){
          printf("You won.\n");
          money += (bet * 3); // Pays 3 to 1
          printf("New balance is %d.\n", money);
        }
      }
      printf("You lost.\n");
      money -= bet;
      printf("New balance is %d.\n", money);
    break;
    case 5:
      printf("Ball fall in %d.\n", Result);
      for(int i = 0; i<=12; i++){
        if(Result == column2[i]){
          printf("You won.\n");
          money += (bet * 3); // Pays 3 to 1
          printf("New balance is %d.\n", money);
        }
      }
      printf("You lost.\n");
      money -= bet;
      printf("New balance is %d.\n", money);
    break;
    case 6:
      printf("Ball fall in %d.\n", Result);
      for(int i = 0; i<=12; i++){
        if(Result == column3[i]){
          printf("You won.\n");
          money += (bet * 3); // Pays 3 to 1
          printf("New balance is %d.\n", money);
        }
      }
      printf("You lost.\n");
      money -= bet;
      printf("New balance is %d.\n", money);
    break;
  }
}
