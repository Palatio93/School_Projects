import random

money = 100

# Creating the flipping coin game
def flip_coin(guess, bet):
    global money
    result = random.randint(0, 1) # Heads will be 0, and Tails will be 1
    guess = int(guess)
    bet = int(bet)
    if (bet <= money and bet > 0): #Check if bet is valid
        if guess == 1:
            print("You're rolling for Tails.")
        else:
            print("You're rolling for Heads.")
        if result == 1:
            print("The coin fell on Tails.")
        else:
            print("The coinf fell on Heads.")
        if (result == 1 and guess == 1) or (result == 0 and guess == 0):
            print("You won.")
            money += bet
            print("New balance is {money}".format(money = money))
        else:
            print("You lost.")
            money -= bet
            print("New balance is {money}".format(money = money))
    else:
        print("Bet not valid.")
    return

# Creating Cho Han game
def Cho_Han(guess, bet): # Guess should be 1 for going odd and 2 for going even
    global money
    Dice1 = random.randint(1, 6) # Dice going from 1 to 6
    Dice2 = random.randint(1, 6) # Dice going from 1 to 6
    guess = int(guess)
    bet = int(bet)
    if (money > 0):
        if (bet <= money and bet > 0): #Check if bet is valid
            if ((Dice1 + Dice2) % 2 == 0):
                print("The sum is even.")
            else:
                print("The sum is odd.")
            if (guess == 2):
                print("You're going for even.")
            else:
                print("You're going for odd.")
            if (((Dice1 + Dice2) % 2 == 0 and (guess == 2)) or ((Dice1 + Dice2) % 2 != 0 and (guess == 1))):
                print("You won.")
                money += bet
                print("New balance is {money}".format(money = money))
            else:
                print("You lost.")
                money -= bet
                print("New balance is {money}".format(money = money))
        else:
            print("Bet not valid.")
    else:
        print("You don't have enough money to play.")
    return

''' print("Sum odd is 1\t Sum even is 2")
Cho_Han_guess, Cho_Han_bet = input("Place your guess and bet like this format guess, bet.\n").split()
Cho_Han(Cho_Han_guess, Cho_Han_bet) '''

# Creating High Card game
def High_Card(bet):
    global money
    bet = int(bet)
    if (money > 0): # Checking if player has money to play
        if (bet <= money and bet > 0): # Checking if bet is valid
            Result = random.randint(1, 13)  # House pick
            Player_Result = random.randint(1, 13)   #Player pick
            print("You picked {guess}".format(guess = Player_Result))
            print("House picked {guess}".format(guess = Result))
            if (Player_Result > Result):    # Player wins
                print("You won!")
                money += bet
                print("New balance is {money}".format(money = money))
            elif (Player_Result < Result):  # Player loses
                print("You lost.")
                money -= bet
                print("New balance is {money}".format(money = money))
            else:
                print("That's a tie!")
                print("New balance is {money}".format(money = money))
        else:
            print("You don't have enough money to play.")
    else:
        print("You don't have enough money to play.")
    return

'''print("Game is pick a card from the deck, values between 1 and 13.")
High_Card_Guess = input("Place your bet on the table\n")
High_Card(High_Card_Guess) '''

# Creating roulette game
def Roulette(guess, bet):
    return

Player_Choice = input("You wanna play in the casino? \n1 for Yes \nAny key for No\n")
Player_Choice = int(Player_Choice)
if (Player_Choice == 1):
    print("What game you wanna play?")
    print("\t1. Flip a coin\n\t 2. Cho Han\n\t 3. High Card\n\t 4. European Roulette")
    Game_of_choice = input()
    Game_of_choice = int(Game_of_choice)
    if (Game_of_choice == 1):
        print("Welcome to the table of the coins.")
        print("Heads is 0 and Tails is 1.")
        flip_coin_bet = input("Place your bet plz.\n")
        flip_coin_guess = input("Place your guess plz.\n")
        flip_coin(flip_coin_guess, flip_coin_bet)
else:
    print("Have a nice day.")
