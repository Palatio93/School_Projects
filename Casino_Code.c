#include <stdio.h>
#include <time.h> // Libreria para rand
#include <stdlib.h>
#define RED "\033[1;31m"
#define RESET "\033[0m"

int money = 100; // Inicia el juego con 100 monedas
void flip_coin(float, float); // Prototipo para volado
void Cho_Han(float, float);   // Prototipo para Cho_Han
void High_Card(float);      // Prototipo para carta Alta
void Roulette(float);       // Prototipo para ruleta europea

int main(void){ // Inician los juegos
  float Guess = 0, Player_Choice = 0, Game_of_choice = 1, keep_playing_casino = 0, keep_playing_game = 1;
  float Bet = 0;
  system("COLOR");
  printf("\t\t\t\tAtento aviso\n\t\t\tPor favor solo ingresar numeros.\n");
  printf("\nQuieres jugar en el casino?\nIngresa 1 para Si, cualquier numero para No\n"); // Pide si quiere jugar
  scanf("%f", &Player_Choice);  // Lee el valor del usuario
  if (Player_Choice == 1){  // Revisa que el usuario sí quiere jugar
    do {
      printf("\nTu saldo es %d\n", money);  // Indica el saldo del usuario
      printf("\nIngresa el numero del juego que quieres jugar.\n 1. Volado \n 2. Cho Han\n 3. Carta Alta\n 4. Ruleta Europea\n"); // Pide por el juego que quiere iniciar
      scanf("%f", &Game_of_choice); // Lee la eleccion de juego
      switch ((int)Game_of_choice) { // Inicia el selector de juegos
        case 1: // Volado
          do {
            printf("--------------------------------------------------\n"); // Linea para separar
            printf("Juega Volado\n");
            printf("Coloca tu apuesta por favor.\n"); // Pide por la apuesta
            scanf("%f", &Bet);  // Lee la apuesta
            printf("\nAguila es 1 y Sol es 2.\n");  // Da las instrucciones para el juego
            printf("Aguila o sol?\n");
            scanf("%f", &Guess);  // Lee la decision de apuesta
            flip_coin(Guess, Bet);  // Inicia el juego de volado
            printf("\nQuieres seguir jugando volado?\nIngresa 1 para Si, cualquier numero para No\n"); // Pregunta si quiere seguir jugando el usuario
            scanf("%f", &keep_playing_game);  // Lee el valor para seguir jugando
            if (money == 0 && keep_playing_game == 1) // Revisa si aun tiene saldo el usuario
              printf("\nTe has quedado sin dinero.\n");
          } while(keep_playing_game == 1 && money > 0); // Condicion para seguir jugando
        break;
        case 2: // Cho Han
          do {
            printf("--------------------------------------------------\n"); // Linea para separar
            printf("Cho Han es un juego donde se tiran dos dados, y se apuesta por la suma de ambos dados, ya sea par o impar.\n"); // Explica el juego
            printf("Coloca tu apuesta por favor.\n"); // Pide la apuesta al usuario
            scanf("%f", &Bet);
            printf("\nSuma impar es 1\nSuma par es 2\n"); // Indica como ingresar la decision
            printf("Par o impar?\n"); // Pide la decision de apuesta al usuario
            scanf("%f", &Guess);
            Cho_Han(Guess, Bet);  // Inicia el juego de Cho Han
            printf("\nQuieres seguir jugando Cho-Han?\nIngresa 1 para Si, cualquier numero para No\n"); // Pregunta si quiere seguir jugando el usuario
            scanf("%f", &keep_playing_game);
            if (money == 0 && keep_playing_game == 1) // Revisa si el usuario aun tiene saldo
              printf("\nTe has quedado sin dinero.\n");
          } while(keep_playing_game == 1 && money > 0); // Condicion para seguir jugando
        break;
        case 3: //  High Card
          do {
            printf("--------------------------------------------------\n"); // Linea para separar
            printf("El juego es quien obtiene la carta mas alta, entre 1 y 13 al azar.\n"); // Explica el juego
            printf("Coloca tu apuesta por favor.\n"); // Pide por la apuesta
            scanf("%f", &Bet);
            High_Card(Bet); // Inicia el juego de carta alta
            printf("\nQuieres seguir jugando carta alta?\nIngresa 1 para Si, cualquier numero para No\n"); // Pregunta si quiere seguir jugando el usuario
            scanf("%f", &keep_playing_game);
            if (money == 0 && keep_playing_game == 1) // Revisa que tenga saldo el usuario
              printf("\nTe has quedado sin dinero.\n");
          } while(keep_playing_game == 1 && money > 0); // Condicion para seguir jugando
        break;
        case 4: // Roulette
          printf("--------------------------------------------------\n"); // Linea para separar
          printf("Bienvenido a la ruleta.\n");
            do {
            printf("Coloca tu apuesta por favor.\n"); // Pide por la apuesta
            scanf("%f", &Bet);
            Roulette(Bet); // Inicia el juego de ruleta
            printf("\nQuieres seguir jugando en la ruleta?\nIngresa 1 para Si, cualquier numero para No\n"); // Pregunta si quiere seguir jugando el usuario
            scanf("%f", &keep_playing_game);
            if (money == 0 && keep_playing_game == 1) // Revisa el saldo del usuario
              printf("\nTe has quedado sin dinero.\n");
          } while(keep_playing_game == 1 && money > 0);
        break;
        default:
          printf("\nValor no valido.\n");
      }
      printf("--------------------------------------------------\n"); // Linea para separar
      printf("\nQuieres seguir jugando en el casino?\nIngresa 1 para Si, cualquier numero para No\n");  // Pregunta si quiere permanecer en el casino
      scanf("%f", &keep_playing_casino);
    } while (keep_playing_casino == 1 && money > 0);  // Condicion para seguir jugando en el casino
  } else {
        printf("--------------------------------------------------\n"); // Linea para separar
    }
    if (keep_playing_casino != 1 || money == 0){  // Condicion para no poder permancer en el casino
      system("cls");
      printf("--------------------------------------------------\n"); // Linea para separar
      if (money == 0 && keep_playing_casino == 1) { // Revisa el saldo del usuario
        printf("\nTe has quedado sin dinero.\n");
      }
      printf("\nQue tengas buen dia.\n");
      printf("\nGracias por visitarnos, hasta la proxima.\n");  // Despedida al usuario
    }
}

// Creando el juego de volado
void flip_coin(float guess, float bet) {  // Aguila es 1, Sol es 2
  srand(time(NULL));
  bet = (int)bet;   // Transforma a entero
  if (money > 0 && bet <= money) {  // Revisa que se tenga para jugar
    if (bet > 0) { // Revisa que la apuesta sea valida
      int result = rand()%2+1; // Se lanza la moneda
      if (guess == 1 || guess == 2){  // Revisa que la decision de apuesta es valida
        if (guess == 1)
          printf("\nApuestas por aguila.\n"); // Le dice al usuario que va por aguila
        else
          printf("\nApuestas por sol.\n");  // Le dice al usuario que va por sol
        if (result == 1)
          printf("Cae aguila.\n"); // Indica que el resultado fue aguila
        else
          printf("Cae sol.\n");  // Indica que el resultado fue sol
        if ((guess == 1 && result == 1) || (guess == 2 && result == 2)){  // Usuario gano
          money += bet;
          printf("\nGanaste.\nTu saldo es de %d.\n", money);
        } else{ // Usuario perdio
          money -= bet;
          printf("\nPerdiste.\nTu saldo es de %d.\n", money);
        }
      } else
        printf("\nEleccion no valida.\n");  // Indica al usuario que no eligio correctamente
    } else
      printf("\nApuesta no valida..\n");  // Indica al usuario que su apuesta no es valida
  } else
      printf("\nNo tienes suficiente saldo.\n");  // Indica al usuario que no tiene el saldo para jugar
}

// Creando el juego de Cho_Han
void Cho_Han(float guess, float bet) { // Suma impar es 1, suma par es 2
  srand(time(NULL));
  bet = (int)bet;   // Transforma a entero
  if (money > 0 && bet <= money) {  // Revisa que se tenga para jugar
    if (bet > 0) { // Revisa que la apuesta sea valida
      int Dice1 = rand()%6+1, Dice2 = rand()%6+1; // Se lanzan los dos dados
      if (guess == 1 || guess == 2){  // Revisa que el usuario ingreso una decision de apuesta valida
        if (guess == 1)
          printf("\nVas por suma impar.\n");  // Indica al usuario que apuesta por suma impar
        else
          printf("\nVas por suma par.\n");  // Indica al usuario que apuesta por suma par
        printf("Los dados salieron %d y %d. Los dados entonces suman: %d.\n", Dice1, Dice2, Dice1 + Dice2); // Imprime el valor de cada dado
        if ((Dice1 + Dice2) % 2 == 0)
          printf("\nLa suma es par.\n");  // Imprime que la suma es par
        else
          printf("\nLa suma es impar.\n");  // Imprime que la suma es impar
        if (((Dice1 + Dice2) % 2 == 0 && (guess == 2)) || ((Dice1 + Dice2) % 2 != 0 && (guess == 1))) { // Usuario gana
          money += bet;
          printf("\nGanaste!.\nTu nuevo saldo es de %d\n", money);
        } else {  // Usuario pierde
          money -= bet;
          printf("\nPerdiste.\nTu nuevo saldo es de %d\n", money);
        }
      } else
        printf("\nEleccion no valida.\n");  // Indica al usuario que su eleccion no es valida
    } else
      printf("\nApuesta no valida.\n"); // Indica al usuario que su apuesta no es valida
  } else
      printf("\nNo tienes suficiente saldo.\n");  // Indica al usuario que no tiene el saldo para jugar
}

//  Creando el juego de carta alta
void High_Card(float bet) {
  bet = (int)bet;   // Transforma a entero
  if (money > 0 && bet <= money) { // Checa que el usuario tenga para jugar
    if (bet > 0) { // Revisa que la apuesta sea valida
        srand(time(NULL));
        int Result = rand()%13+1;  // Resultado de la casa
        int Player_Result = rand()%13+1;   // Resultado del usuario
        printf("\nObtuviste %d.\n", Player_Result); // Indica al usuario que obtuvo
        printf("\nLa casa obtuvo %d.\n", Result); // Indica que obtuvo la casa
        if (Player_Result > Result) { // Usuario gana
            money += bet;
            printf("\nGanaste!\nTu nuevo saldo es de %d.\n", money);
        } else if (Player_Result < Result) { // Usuario pierde
            money -= bet;
            printf("\nPerdiste.\nTu nuevo saldo es de %d.\n", money);
        } else {  // Indica que fue un empate
            printf("\nEs un empate\nTu nuevo saldo es de %d.\n", money);
        }
      } else
          printf("\nApuesta no valida.\n"); // Indica que la apuesta no es valida
  } else
      printf("\nSaldo insuficiente.\n"); // Indica que no tiene suficiente saldo para jugar
}

// Creando el juego de ruleta europea
void Roulette(float bet) {
  bet = (int)bet;   // Transforma a entero
  int i;
  float Player_guess = 0, roulette_guess_type = 0, winner  = 0;
  int column1[12] = {1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34};  // Primera columna del tapete
  int column2[12] = {2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 35};  // Segunda columna del tapete
  int column3[12] = {3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36};  // Tercera columna del tapete
  int red[18] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};  // Rojos del tapete
  int black[18] = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35};  // Negros del tapete
  if (money > 0 && bet <= money) { // Revisa que el usuario tenga para jugar
      if (bet > 0) { // Revisa que la apuesta sea valida
        printf("\n  Primera columna \t Segunda Columna \t Tercera columna\n");  // Letrero del tapete
        printf(RED"\t %d"RESET"\t\t\t%d"RESET RED"\t\t\t%d"RESET" \t\t\t\n", column1[0], column2[0], column3[0]);
        printf("\t %d\t\t\t"RED"%d"RESET"\t\t\t%d\t\t\t\n", column1[1], column2[1], column3[1]);
        printf(RED"\t %d"RESET"\t\t\t%d\t\t\t"RED"%d"RESET" \t\t\t\n", column1[2], column2[2], column3[2]);
        printf("\t %d\t\t\t%d\t\t\t"RED"%d"RESET" \t\t\t\n", column1[3], column2[3], column3[3]);      // Primeras cuatro columnas
        printf("  --------------------------------------------------------------\n"); // Linea para separar
        printf("\t %d\t\t\t"RED"%d"RESET"\t\t\t%d\t\t\t\n", column1[4], column2[4], column3[4]);
        printf(RED"\t %d"RESET"\t\t\t%d"RESET RED"\t\t\t%d"RESET" \t\t\t\n", column1[5], column2[5], column3[5]);
        printf(RED"\t %d"RESET"\t\t\t%d"RESET RED"\t\t\t%d"RESET" \t\t\t\n", column1[6], column2[6], column3[6]);
        printf("\t %d\t\t\t"RED"%d"RESET"\t\t\t%d\t\t\t\n", column1[7], column2[7], column3[7]);     // Segundas cuatro columnas
        printf("  --------------------------------------------------------------\n"); // Linea para separar
        printf(RED"\t %d"RESET"\t\t\t%d"RESET RED"\t\t\t%d"RESET" \t\t\t\n", column1[8], column2[8], column3[8]);
        printf("\t %d\t\t\t%d\t\t\t"RED"%d"RESET" \t\t\t\n", column1[9], column2[9], column3[9]);
        printf("\t %d\t\t\t"RED"%d"RESET"\t\t\t%d\t\t\t\n", column1[10], column2[10], column3[10]);
        printf(RED"\t %d"RESET"\t\t\t%d"RESET RED"\t\t\t%d"RESET" \t\t\t\n", column1[11], column2[11], column3[11]);
        printf("\nIngresa el numero del caso por el que apuestas\n 1. Un numero\n 2. Par\n 3. Impar\n 4. Primera columna\n 5. Segunda columna\n 6. Tercera columna\n 7. Rojo \n 8. Blanco\n"); // Imprime las elecciones de caso para jugar
        scanf("%f", &roulette_guess_type);
        roulette_guess_type = (int)roulette_guess_type;
        srand(time(NULL));
        int Result = rand()%38; // Se lanza la bola sobre la ruleta entre 0 y 36
        switch ((int)roulette_guess_type) {  // Caso de apuesta
          case 1: // Apostando por un solo numero
            printf("\nPor acierto, se paga 36 a 1.\n");
            printf("Elige un numero entre 0 y 36\n");
            scanf("%f", &Player_guess);
            while (Player_guess < 0 || Player_guess > 36) {
              printf("Ese numero no existe en este juego. Por favor ingresa el correcto.\n");
              scanf("%f", &Player_guess);
            }
            Player_guess = (int)Player_guess;
            printf("\nLa bola cae en %d.\n", Result);  // Indica en cual numero cayo la bola
            if (Player_guess == Result){  // Usuario gana
              money += (bet * 36);  // Paga 36 a 1
              printf("\nGanaste.\nTu nuevo saldo es de %d.\n", money);
            } else {  // Usuario pierde
              money -= bet;
              printf("\nPerdiste.\nTu nuevo saldo es de %d.\n", money);
            }
          break;
          case 2: // Apuesta por numero par
            printf("\nPor acierto se paga 2 a 1.\n");
            printf("La bola cae en %d.\n", Result);  // Indica en cual numero cayo la bola
            if (Result % 2 == 0){ // Usuario gana
              money += (bet * 2); // Paga 2 a 1
              printf("\nGanaste.\nTu nuevo saldo es de %d.\n", money);
            } else {  // Usuario pierde
              money -= bet;
              printf("\nPerdiste.\nTu nuevo saldo es de %d.\n", money);
            }
          break;
          case 3: // Apuesta por numero impar
            printf("\nPor acierto se paga 2 a 1.\n");
            printf("La bola cae en %d.\n", Result);  // Indica en cual numero cayo la bola
            if (Result % 2 != 0){ // Usuario gana
              money += (bet * 2); // Paga 2 a 1
              printf("\nGanaste.\nTu nuevo saldo es de %d.\n", money);
            } else {  // Usuario pierde
              money -= bet;
              printf("\nPerdiste.\nTu nuevo saldo es de %d.\n", money);
            }
          break;
          case 4: // Apuesta por primera columna
            printf("\nPor acierto se paga 3 a 1.\n");
            printf("La bola cae en %d.\n", Result);  // Indica en cual numero cayo la bola
            for(i = 0; i<12; i++){
              if (Result == column1[i]){  // Usuario gana
                money += (bet * 3); // Paga 3 a 1
                printf("\nGanaste.\nTu nuevo saldo es de %d.\n", money);
                winner = 1; // Se marca que usuario gano
              }
            }
            if (winner != 1){
              money -= bet;
              printf("\nPerdiste.\nTu nuevo saldo es de %d.\n", money);
          }
          break;
          case 5: // Apuesta por segunda columna
            printf("\nPor acierto se paga 3 a 1.\n");
            printf("La bola cae en %d.\n", Result);  // Indica en cual numero cayo la bola
            for(i = 0; i<12; i++){
              if(Result == column2[i]){ // Usuario gana
                money += (bet * 3); // Paga 3 a 1
                printf("\nGanaste.\nTu nuevo saldo es de %d.\n", money);
                winner = 1; // Se marca que usuario gano
              }
            }
            if (winner != 1){
              money -= bet;
              printf("\nPerdiste.\nTu nuevo saldo es de %d.\n", money);
          }
          break;
          case 6: // Apuesta por tercera columna
            printf("\nPor acierto se paga 3 a 1.\n");
            printf("La bola cae en %d.\n", Result);  // Indica en cual numero cayo la bola
            for(i = 0; i<12; i++){
              if(Result == column3[i]){ // Usuario gana
                money += (bet * 3); // Paga 3 a 1
                printf("\nGanaste.\nTu nuevo saldo es de %d.\n", money);
                winner = 1; // Se marca que usuario gano
              }
            }
            if (winner != 1){
              money -= bet;
              printf("\nPerdiste.\nTu nuevo saldo es de %d.\n", money);
          }
          break;
          case 7: // Apuesta por rojo
            printf("\nPor acierto se paga 2 a 1.\n");
            printf("La bola cae en %d.\n", Result);  // Indica en cual numero cayo la bola
            for(i = 0; i<18; i++){
              if(Result == red[i]){ // Usuario gana
                money += (bet * 2); // Paga 2 a 1
                printf("\nGanaste.\nTu nuevo saldo es de %d.\n", money);
                winner = 1; // Se marca que usuario gano
              }
            }
            if (winner != 1){
              money -= bet;
              printf("\nPerdiste.\nTu nuevo saldo es de %d.\n", money);
          }
          break;
          case 8: // Apuesta por blanco
            printf("\nPor acierto se paga 2 a 1.\n");
            printf("La bola cae en %d.\n", Result);  // Indica en cual numero cayo la bola
            for(i = 0; i<18; i++){
              if(Result == black[i]){ // Usuario gana
                money += (bet * 2); // Paga 2 a 1
                printf("\nGanaste.\nTu nuevo saldo es de %d.\n", money);
                winner = 1; // Se marca que usuario gano
              }
            }
            if (winner != 1){
              money -= bet;
              printf("\nPerdiste.\nTu nuevo saldo es de %d.\n", money);
          }
          break;
          default:
          printf("\nEleccion no valida.\n");
        }
    } else
        printf("\nApuesta no valida.\n"); // Indica al usario que no es valida su apuesta
  } else
  printf("\nSaldo insuficiente.\n");  // Indica al usuario que no tiene suficiente saldo
}
