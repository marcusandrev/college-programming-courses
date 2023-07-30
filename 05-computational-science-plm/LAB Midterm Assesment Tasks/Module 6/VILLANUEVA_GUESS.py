# import random module
import random

# generate a random number from 1 to 10
randomNumber = random.randint(1, 10)

# ask the user to guess the random number and will exit if the guess was correct
while True:
    guess = int(input("\nI am thinking of a number between 1 and 10. \nEnter your guess, please...\n"))
    if guess == randomNumber:
        print("Incredible, you are correct!")
        break
    else:
        print("Enter another guess, please... \n")


