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
  printf("Quieres jugar en el casino?\n 1. Sí \t Cualquier tecla No\n");
  scanf("%d", &Player_Choice);
  printf("Tu saldo inicial es %d\n", money);
  if (Player_Choice == 1){
    do {
      printf("Que quieres jugar?\n 1. Volado \n 2. Cho Han\n 3. Carta Alta\n 4. Ruleta\n");
      scanf("%d", &Game_of_choice);
      printf("\033[0m");
      switch (Game_of_choice) {
        case 1: // Flip Coin
          do {
            printf("Coloca tu apuesta por favor.\n");
            scanf("%d", &Bet);
            printf("Aguila es 1 y Sol es 2.\n");
            printf("Aguila o sol?.\n");
            scanf("%d", &Guess);
            flip_coin(Guess, Bet);
            printf("\nQuieres seguir jugando?\n 1. Sí \t Cualquier tecla No\n");
            scanf("%d", &keep_playing_game);
            if (money == 0)
              printf("Te has quedado sin dinero.\n");
          } while(keep_playing_game == 1 && money > 0);
        break;
        case 2: // Cho Han
          do {
            printf("Coloca tu apuesta por favor.\n");
            scanf("%d", &Bet);
            printf("Suma impar es 1\t Suma par es 2\n");
            printf("Par o impar?\n");
            scanf("%d", &Guess);
            Cho_Han(Guess, Bet);
            printf("\nQuieres seguir jugando?\n 1. Sí \t Cualquier tecla No\n");
            scanf("%d", &keep_playing_game);
            if (money == 0)
              printf("Te has quedado sin dinero.\n");
          } while(keep_playing_game == 1 && money > 0);
        break;
        case 3: //  High Card
          do {
            printf("El juego es quien saca la carta mas alta, entre 1 y 13.\n");
            printf("Coloca tu apuesta por favor.\n");
            scanf("%d", &Bet);
            High_Card(Bet);
            printf("\nQuieres seguir jugando?\n 1. Sí \t Cualquier tecla No\n");
            scanf("%d", &keep_playing_game);
            if (money == 0)
              printf("Te has quedado sin dinero.\n");
          } while(keep_playing_game == 1 && money > 0);
        break;
        case 4: // Roulette
          printf("Bienvenido a la ruleta.\n");
            do {
            printf("Coloca tu apuesta por favor.\n");
            scanf("%d", &Bet);
            Roulette(Bet);
            printf("\nQuieres seguir jugando?\n 1. Sí \t Cualquier tecla No\n");
            scanf("%d", &keep_playing_game);
            if (money == 0)
              printf("Te has quedado sin dinero.\n");
          } while(keep_playing_game == 1 && money > 0);
        break;
      }
      printf("\033[1;36m"); // Color
      printf("\nQuieres seguir jugando en el casino?\n 1. Sí \t Cualquier tecla No\n");
      scanf("%d", &keep_playing_casino);
      if (money == 0)
        printf("Te has quedado sin dinero.\n");
    } while (keep_playing_casino == 1 && money > 0);
    } else
        printf("\033[1;36m"); // Color
        printf("\nQue tengas buen dia.\n");
    if (keep_playing_casino != 1){
      system("clear");
      printf("\033[1;36m"); // Color
      printf("Gracias por jugar, hasta la proxima.\n");
    }
  return 0;
}


// Creating Flip Coin game
void flip_coin(int guess, int bet) {
  srand(time(NULL));
  if (money > 0) {
    if (bet <= money && bet > 0) { // Check if bet is valid
      int result = rand()%2+1; // Aguila es 1, Sol es 2
      if (guess >= 1 && guess <= 2){
        if (guess == 1)
          printf("\nApuestas por aguila.\n");
        else
          printf("\nApuestas por sol.\n");
        if (result == 1)
          printf("Cayó aguila.\n");
        else
          printf("Cayó sol.\n");
        if ((guess == 1 && result == 1) || (guess == 2 && result == 2)){
          money += bet;
          printf("\033[1;32m");
          printf("Ganaste.\n Tu saldo es de  %d.\n", money);
          printf("\033[0m");
        } else{
          money -= bet;
          printf("Perdiste.\n Tu saldo es de %d.\n", money);
        }
      } else
        printf("\nEso no es valido.\n");
    } else
      printf("\nApuesta no valida..\n");
  } else
      printf("No tienes suficiente saldo.\n");
}

// Creating Cho Han game
void Cho_Han(int guess, int bet) { // Sum even is 2, sum odd is 1
  srand(time(NULL));
  if (money > 0) {
    if (bet <= money && bet > 0) { //Check if bet is valid
      int Dice1 = rand()%6+1, Dice2 = rand()%6+1;
      if (guess >= 1 && guess <= 2){
        if (guess == 1)
          printf("\nVas por suma impar.\n");
        else
          printf("\nVas por suma par.\n");
        printf("Los dados salieron %d y %d\n", Dice1, Dice2);
        if ((Dice1 + Dice2) % 2 == 0)
          printf("La suma es par.\n");
        else
          printf("La suma es impar.\n");
        if (((Dice1 + Dice2) % 2 == 0 && (guess == 2)) || ((Dice1 + Dice2) % 2 != 0 && (guess == 1))) {
          printf("\033[1;32m"); //Color
          printf("Ganaste!.\n");
          money += bet;
          printf("Tu nuevo saldo es de %d\n", money);
          printf("\033[0m");
        } else {
          printf("Perdiste.\n");
          money -= bet;
          printf("Tu nuevo saldo es de %d\n", money);
        }
      } else
        printf("\nEso no es valido.\n");
    } else
      printf("\nApuesta no valida.\n");
  } else
      printf("No tienes suficiente saldo.\n");
}


//Creating High Card game
void High_Card(int bet) {
  if (money > 0) { // Checking if player has money to play
      if (bet <= money && bet > 0) { // Checking if bet is valid
          srand(time(NULL));
          int Result = rand()%13+1;  // House pick
          int Player_Result = rand()%13+1;   //Player pick
          printf("\nSacaste %d.\n", Player_Result);
          printf("\nLa casa sacó %d.\n", Result);
          if (Player_Result > Result) {    // Player wins
              printf("\033[1;32m"); //Color
              printf("Ganaste!\n");
              money += bet;
              printf("Tu nuevo saldo es de %d.\n", money);
              printf("\033[0m");
          } else if (Player_Result < Result) { // Player loses
              printf("Perdiste.\n");
              money -= bet;
              printf("Tu nuevo saldo es de %d.\n", money);
          } else {
              printf("\033[0;32m");
              printf("\nEs un empate\n");
              printf("Tu nuevo saldo es de %d.\n", money);
              printf("\033[0m");
          }
      } else
          printf("\nApuesta no válida.\n");
  } else
      printf("\nSaldo insuficiente.\n");
}

// Creating Roulette game
void Roulette(int bet) {
  int Player_guess = 0, roulette_guess_type = 0;
  int column1[12] = {1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34};
  int column2[12] = {2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 35};
  int column3[12] = {3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36};
  printf("  Primera columna \t Segunda Columna \t Tercera columna\n");
  if (money > 0) { // Checking if player has money to play
      if (bet <= money && bet > 0) { // Checking if bet is valid
        for (int i=0; i<12; i++) {
          printf("\t%d\t\t %d\t\t %d\n", column1[i], column2[i], column3[i]);
        }
        printf("Por cual caso apuestas?\n 1. Un número\n 2. Par\n 3. Impar\n 4. Primera columna\n 5. Segunda columna\n 6. Tercera columna\n");
        scanf("%d", &roulette_guess_type);
        srand(time(NULL));
        int Result = rand()%37;
        switch (roulette_guess_type) {
          case 1:
            printf("Elige un número entre 0 y 36\n");
            scanf("%d", &Player_guess);
            printf("La bola cayó en %d.\n", Result);
            if (Player_guess == Result){
              printf("Ganaste.\n");
              money += (bet * 36);  // Pays 36 to 1
              printf("Tu nuevo saldo es de %d.\n", money);
              printf("\033[0m");
            } else {
              printf("Perdiste.\n");
              money -= bet;
              printf("Tu nuevo saldo es de %d.\n", money);
            }
          break;
          case 2:
            printf("La bola cayó en %d.\n", Result);
            if (Result % 2 == 0){
              printf("\033[1;32m"); //Color
              printf("Ganaste.\n");
              money += (bet * 2); // Pays 2 to 1
              printf("Tu nuevo saldo es de %d.\n", money);
              printf("\033[0m");
            } else {
              printf("Perdiste.\n");
              money -= bet;
              printf("Tu nuevo saldo es de %d.\n", money);
            }
          break;
          case 3:
            printf("La bola cayó en %d.\n", Result);
            if (Result % 2 != 0){
              printf("\033[1;32m"); //Color
              printf("Ganaste.\n");
              money += (bet * 2); // Pays 2 to 1
              printf("Tu nuevo saldo es de %d.\n", money);
              printf("\033[0m");
            } else {
              printf("Perdiste.\n");
              money -= bet;
              printf("Tu nuevo saldo es de %d.\n", money);
            }
          break;
          case 4:
            printf("La bola cayó en %d.\n", Result);
            for(int i = 0; i<=12; i++){
              if (Result == column1[i]){
                printf("\033[1;32m"); //Color
                printf("Ganaste.\n");
                money += (bet * 3); // Pays 3 to 1
                printf("Tu nuevo saldo es de %d.\n", money);
                printf("\033[0m");
              }
            }
            printf("Perdiste.\n");
            money -= bet;
            printf("Tu nuevo saldo es de %d.\n", money);
          break;
          case 5:
            printf("La bola cayó en %d.\n", Result);
            for(int i = 0; i<=12; i++){
              if(Result == column2[i]){
                printf("\033[1;32m"); //Color
                printf("Ganaste.\n");
                money += (bet * 3); // Pays 3 to 1
                printf("Tu nuevo saldo es de %d.\n", money);
                printf("\033[0m");
              }
            }
            printf("Perdiste.\n");
            money -= bet;
            printf("Tu nuevo saldo es de %d.\n", money);
          break;
          case 6:
            printf("La bola cayó en %d.\n", Result);
            for(int i = 0; i<=12; i++){
              if(Result == column3[i]){
                printf("\033[1;32m"); //Color
                printf("Ganaste.\n");
                money += (bet * 3); // Pays 3 to 1
                printf("Tu nuevo saldo es de %d.\n", money);
                printf("\033[0m");
              }
            }
            printf("Perdiste.\n");
            money -= bet;
            printf("Tu nuevo saldo es de %d.\n", money);
          break;
        }
    } else
        printf("\nApuesta no válida.\n");
  } else
  printf("\nSaldo insuficiente.\n");
}
