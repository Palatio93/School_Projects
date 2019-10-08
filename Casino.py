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
            print("New balance is " + str(money))
        else:
            print("You lost.")
            money -= bet
            print("New balance is "+ str(money))
    else:
        print("Bet not valid.")
    return

''' print("Heads is 0 and Tails is 1.")
flip_coin_guess, flip_coin_bet = input("Place your guess and bet like this guess, bet.\n").split()

flip_coin(player_guess, player_bet) '''

def Cho_Han(guess, bet): # Guess should be 1 for going odd and 2 for going even
    global money
    Dice1 = random.randint(1, 6) # Dice going from 1 to 6
    Dice2 = random.randint(1, 6) # Dice going from 1 to 6
    guess = int(guess)
    bet = int(bet)
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
    return

print("Sum odd is 1\t Sum even is 2")
Cho_Han_guess, Cho_Han_bet = input("Place your guess and bet like this format guess, bet.\n").split()
Cho_Han(Cho_Han_guess, Cho_Han_bet)
