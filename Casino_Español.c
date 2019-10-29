#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int money = 100; // Inicia el juego con 100 monedas
void flip_coin(int, int); // Prototipo para volado
void Cho_Han(int, int);   // Prototipo para Cho_Han
void High_Card(int);      // Prototipo para carta Alta
void Roulette(int);       // Prototipo para ruleta

int main(void){ // Inician los juegos
  int Guess = 0, Bet = 0, Player_Choice = 0, Game_of_choice = 1, keep_playing_casino = 0, keep_playing_game = 1;
  printf("\t\t\t\tAtento aviso\n\t\t\tPor favor solo ingresar numeros.\n");
  sleep(5);
  system("clear");
  printf("Quieres jugar en el casino?\n Ingresa 1 para Sí, cualquier numero para No\n"); // Pide si quiere jugar
  scanf("%d", &Player_Choice);  // Lee el valor del usuario
  printf("Tu saldo inicial es %d\n", money);  // Indica el saldo inicial para jugar
  if (Player_Choice == 1){  // Revisa que el usuario sí quiere jugar
    do {
      printf("Ingresa el número del juego que quieres jugar.\n 1. Volado \n 2. Cho Han\n 3. Carta Alta\n 4. Ruleta\n"); // Pide por el juego que quiere iniciar
      scanf("%d", &Game_of_choice); // Lee la eleccion de juego
      switch (Game_of_choice) { // Inicia el selector de juegos
        case 1: // Volado
          do {
            printf("--------------------------------------------------\n"); // Linea para separar
            printf("Juega Volado\n");
            printf("Coloca tu apuesta por favor.\n"); // Pide por la apuesta
            scanf("%d", &Bet);  // Lee la apuesta
            printf("Aguila es 1 y Sol es 2.\n");  // Da las instrucciones para el juego
            printf("Aguila o sol?.\n");
            scanf("%d", &Guess);  // Lee la decision de apuesta
            flip_coin(Guess, Bet);  // Inicia el juego de volado
            printf("\nQuieres seguir jugando?\n Ingresa 1 para Sí, cualquier numero para No\n"); // Pregunta si quiere seguir jugando el usuario
            scanf("%d", &keep_playing_game);  // Lee el valor para seguir jugando
            if (money == 0) // Revisa si aun tiene saldo el usuario
              printf("Te has quedado sin dinero.\n");
          } while(keep_playing_game == 1 && money > 0); // Condicion para seguir jugando
        break;
        case 2: // Cho Han
          do {
            printf("--------------------------------------------------\n"); // Linea para separar
            printf("Cho Han es un juego donde se tiran dos dados, y el resultado es la suma de ambos dados, ya sea par o impar.\n"); // Explica el juego
            printf("Coloca tu apuesta por favor.\n"); // Pide la apuesta al usuario
            scanf("%d", &Bet);
            printf("Suma impar es 1\t Suma par es 2\n"); // Indica como ingresar la decision
            printf("Par o impar?\n"); // Pide la decision de apuesta al usuario
            scanf("%d", &Guess);
            Cho_Han(Guess, Bet);  // Inicia el juego de Cho Han
            printf("\nQuieres seguir jugando?\n Ingresa 1 para Sí, cualquier numero para No\n"); // Pregunta si quiere seguir jugando el usuario
            scanf("%d", &keep_playing_game);
            if (money == 0) // Revisa si el usuario aun tiene saldo
              printf("Te has quedado sin dinero.\n");
          } while(keep_playing_game == 1 && money > 0); // Condicion para seguir jugando
        break;
        case 3: //  High Card
          do {
            printf("--------------------------------------------------\n"); // Linea para separar
            printf("El juego es quien obtiene la carta mas alta, entre 1 y 13 al azar.\n"); // Explica el juego
            printf("Coloca tu apuesta por favor.\n"); // Pide por la apuesta
            scanf("%d", &Bet);
            High_Card(Bet); // Inicia el juego de carta alta
            printf("\nQuieres seguir jugando?\n Ingresa 1 para Sí, cualquier numero para No\n"); // Pregunta si quiere seguir jugando el usuario
            scanf("%d", &keep_playing_game);
            if (money == 0) // Revisa que tenga saldo el usuario
              printf("Te has quedado sin dinero.\n");
          } while(keep_playing_game == 1 && money > 0); // Condicion para seguir jugando
        break;
        case 4: // Roulette
          printf("--------------------------------------------------\n"); // Linea para separar
          printf("Bienvenido a la ruleta.\n");
            do {
            printf("Coloca tu apuesta por favor.\n"); // Pide por la apuesta
            scanf("%d", &Bet);
            Roulette(Bet); // Inicia el juego de ruleta
            printf("\nQuieres seguir jugando?\n Ingresa 1 para Sí, cualquier numero para No\n"); // Pregunta si quiere seguir jugando el usuario
            scanf("%d", &keep_playing_game);
            if (money == 0) // Revisa el saldo del usuario
              printf("Te has quedado sin dinero.\n");
          } while(keep_playing_game == 1 && money > 0);
        break;
        default:
          printf("Valor no valido.\n");
      }
      printf("--------------------------------------------------\n"); // Linea para separar
      printf("\nQuieres seguir jugando en el casino?\n Ingresa 1 para Sí, cualquier numero para No\n");  // Pregunta si quiere permanecer en el casino
      scanf("%d", &keep_playing_casino);
    } while (keep_playing_casino == 1 && money > 0);  // Condicion para seguir jugando en el casino
  } else {
        printf("--------------------------------------------------\n"); // Linea para separar
        printf("\nQue tengas buen dia.\n");
    }
    if (keep_playing_casino != 1 || money == 0){  // Condicion para no poder permancer en el casino
      system("clear");
      printf("--------------------------------------------------\n"); // Linea para separar
      if (money == 0) { // Revisa el saldo del usuario
        printf("Te has quedado sin dinero.\n");
      }
      printf("Gracias por visitarnos, hasta la proxima.\n");  // Despedida al usuario
    }
  return 0;
}


// Creando el juego de volad
void flip_coin(int guess, int bet) {  // Aguila es 1, Sol es 2
  srand(time(NULL));
  if (money > 0 && bet <= money) {  // Revisa que se tenga para jugar
    if (bet > 0) { // Revisa que la apuesta sea valida
      int result = rand()%2+1; // Se lanza la moneda
      if (guess == 1 || guess == 2){  // Revisa que la decision de apuesta es valida
        if (guess == 1)
          printf("\nApuestas por aguila.\n"); // Le dice al usuario que va por aguila
        else
          printf("\nApuestas por sol.\n");  // Le dice al usuario que va por sol
        if (result == 1)
          printf("Cayó aguila.\n"); // Indica que el resultado fue aguila
        else
          printf("Cayó sol.\n");  // Indica que el resultado fue sol
        if ((guess == 1 && result == 1) || (guess == 2 && result == 2)){  // Usuario gano
          money += bet;
          printf("Ganaste.\n Tu saldo es de  %d.\n", money);
        } else{ // Usuario perdio
          money -= bet;
          printf("Perdiste.\n Tu saldo es de %d.\n", money);
        }
      } else
        printf("\nEleccion no valida.\n");  // Indica al usuario que no eligio correctamente
    } else
      printf("\nApuesta no valida..\n");  // Indica al usuario que su apuesta no es valida
  } else
      printf("No tienes suficiente saldo.\n");  // Indica al usuario que no tiene el saldo para jugar
}

// Creando el juego de Cho_Han
void Cho_Han(int guess, int bet) { // Suma impar es 1, suma par es 2
  srand(time(NULL));
  if (money > 0 && bet <= money) {  // Revisa que se tenga para jugar
    if (bet > 0) { // Revisa que la apuesta sea valida
      int Dice1 = rand()%6+1, Dice2 = rand()%6+1; // Se lanzan los dos dados
      if (guess == 1 || guess == 2){  // Revisa que el usuario ingreso una decision de apuesta valida
        if (guess == 1)
          printf("\nVas por suma impar.\n");  // Indica al usuario que apuesta por suma impar
        else
          printf("\nVas por suma par.\n");  // Indica al usuario que apuesta por suma par
        printf("Los dados salieron %d y %d\n", Dice1, Dice2); // Imprime el valor de cada dado
        printf("Los dados sumam: %d\n", Dice1 + Dice2); // Imprime el valor de la suma
        if ((Dice1 + Dice2) % 2 == 0)
          printf("La suma es par.\n");  // Imprime que la suma es par
        else
          printf("La suma es impar.\n");  // Imprime que la suma es impar
        if (((Dice1 + Dice2) % 2 == 0 && (guess == 2)) || ((Dice1 + Dice2) % 2 != 0 && (guess == 1))) { // Usuario gana
          printf("Ganaste!.\n");
          money += bet;
          printf("Tu nuevo saldo es de %d\n", money);
        } else {  // Usuario pierde
          printf("Perdiste.\n");
          money -= bet;
          printf("Tu nuevo saldo es de %d\n", money);
        }
      } else
        printf("\nEleccion no valida.\n");  // Indica al usuario que su eleccion no es valida
    } else
      printf("\nApuesta no valida.\n"); // Indica al usuario que su apuesta no es valida
  } else
      printf("No tienes suficiente saldo.\n");  // Indica al usuario que no tiene el saldo para jugar
}


//  Creando el juego de carta alta
void High_Card(int bet) {
  if (money > 0 && bet <= money) { // Checa que el usuario tenga para jugar
    if (bet > 0) { // Revisa que la apuesta sea valida
        srand(time(NULL));
        int Result = rand()%13+1;  // Resultado de la casa
        int Player_Result = rand()%13+1;   // Resultado del usuario
        printf("\nObtuviste %d.\n", Player_Result); // Indica al usuario que obtuvo
        printf("\nLa casa obtuvo %d.\n", Result); // Indica que obtuvo la casa
        if (Player_Result > Result) { // Usuario gana
            printf("Ganaste!\n");
            money += bet;
            printf("Tu nuevo saldo es de %d.\n", money);
        } else if (Player_Result < Result) { // Usuario pierde
            printf("Perdiste.\n");
            money -= bet;
            printf("Tu nuevo saldo es de %d.\n", money);
        } else {  // Indica que fue un empate
            printf("\nEs un empate\n");
            printf("Tu nuevo saldo es de %d.\n", money);
        }
      } else
          printf("\nApuesta no válida.\n"); // Indica que la apuesta no es valida
  } else
      printf("\nSaldo insuficiente.\n"); // Indica que no tiene suficiente saldo para jugar
}

// Creando el juego de ruleta
void Roulette(int bet) {
  int Player_guess = 0, roulette_guess_type = 0;
  int column1[12] = {1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34};  // Primera columna del tapete
  int column2[12] = {2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 35};  // Segunda columna del tapete
  int column3[12] = {3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36};  // Tercera columna del tapete
  printf("  Primera columna \t Segunda Columna \t Tercera columna\n");  // Letrero del tapete
  if (money > 0 && bet <= money) { // Revisa que el usuario tenga para jugar
      if (bet > 0) { // Revisa que la apuesta sea valida
        for (int i=0; i<12; i++) {  // Imprime el tapete
          printf("\t%d\t\t\t %d\t\t\t %d\n", column1[i], column2[i], column3[i]);
        }
        printf("Ingresa el numero del caso por el que apuestas\n 1. Un numero\n 2. Par\n 3. Impar\n 4. Primera columna\n 5. Segunda columna\n 6. Tercera columna\n"); // Imprime las elecciones de caso para jugar
        scanf("%d", &roulette_guess_type);
        srand(time(NULL));
        int Result = rand()%37; // Se lanza la bola sobre la ruleta
        switch (roulette_guess_type) {  // Caso de apuesta
          case 1: // Apostando por un solo numero
            printf("Elige un número entre 0 y 36\n");
            scanf("%d", &Player_guess);
            printf("La bola cae en %d.\n", Result);  // Indica en cual numero cayo la bola
            if (Player_guess == Result){  // Usuario gana
              printf("Ganaste.\n");
              money += (bet * 36);  // Paga 36 a 1
              printf("Tu nuevo saldo es de %d.\n", money);
            } else {  // Usuario pierde
              printf("Perdiste.\n");
              money -= bet;
              printf("Tu nuevo saldo es de %d.\n", money);
            }
          break;
          case 2:
            printf("La bola cae en %d.\n", Result);  // Indica en cual numero cayo la bola
            if (Result % 2 == 0){ // Usuario gana
              printf("Ganaste.\n");
              money += (bet * 2); // Paga 2 a 1
              printf("Tu nuevo saldo es de %d.\n", money);
            } else {  // Usuario pierde
              printf("Perdiste.\n");
              money -= bet;
              printf("Tu nuevo saldo es de %d.\n", money);
            }
          break;
          case 3:
            printf("La bola cae en %d.\n", Result);  // Indica en cual numero cayo la bola
            if (Result % 2 != 0){ // Usuario gana
              printf("Ganaste.\n");
              money += (bet * 2); // Paga 2 a 1
              printf("Tu nuevo saldo es de %d.\n", money);
            } else {  // Usuario pierde
              printf("Perdiste.\n");
              money -= bet;
              printf("Tu nuevo saldo es de %d.\n", money);
            }
          break;
          case 4:
            printf("La bola cae en %d.\n", Result);  // Indica en cual numero cayo la bola
            for(int i = 0; i<=12; i++){
              if (Result == column1[i]){  // Usuario gana
                printf("Ganaste.\n");
                money += (bet * 3); // Paga 3 a 1
                printf("Tu nuevo saldo es de %d.\n", money);
              }
            }
            printf("Perdiste.\n");  // Usuario pierde
            money -= bet;
            printf("Tu nuevo saldo es de %d.\n", money);
          break;
          case 5:
            printf("La bola cae en %d.\n", Result);  // Indica en cual numero cayo la bola
            for(int i = 0; i<=12; i++){
              if(Result == column2[i]){ // Usuario gana
                printf("Ganaste.\n");
                money += (bet * 3); // Paga 3 a 1
                printf("Tu nuevo saldo es de %d.\n", money);
              }
            }
            printf("Perdiste.\n");  // Usuario pierde
            money -= bet;
            printf("Tu nuevo saldo es de %d.\n", money);
          break;
          case 6:
            printf("La bola cae en %d.\n", Result);  // Indica en cual numero cayo la bola
            for(int i = 0; i<=12; i++){
              if(Result == column3[i]){ // Usuario gana
                printf("Ganaste.\n");
                money += (bet * 3); // Paga 3 a 1
                printf("Tu nuevo saldo es de %d.\n", money);
              }
            }
            printf("Perdiste.\n");  // Usuario pierde
            money -= bet;
            printf("Tu nuevo saldo es de %d.\n", money);
          break;
        }
    } else
        printf("\nApuesta no valida.\n"); // Indica al usario que no es valida su apuesta
  } else
  printf("\nSaldo insuficiente.\n");  // Indica al usuario que no tiene suficiente saldo
}
