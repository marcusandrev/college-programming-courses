import random

def roll_dice():
    return random.randint(1, 6) + random.randint(1, 6)
num_simulations = 100
num_sevens = 0
rolls = []
for i in range(100):
    rolls.append(roll_dice())
for j in rolls:
    if j == 7:
        num_sevens += 1
probability = num_sevens / num_simulations
print("Estimated probability of getting a seven on a dice roll:", probability)  