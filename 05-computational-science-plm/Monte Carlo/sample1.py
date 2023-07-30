import random

def draw_card():
    suits = ['hearts', 'diamonds', 'clubs', 'spades']
    ranks = ['2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A']
    card = random.choice(ranks) + ' of ' + random.choice(suits)
    return card

def estimate_probability(num_trials):
    num_hearts = 0
    for i in range(num_trials):
        card = draw_card()
        if 'hearts' in card:
            num_hearts += 1
    probability = num_hearts / num_trials
    return probability

# Example usage: estimate probability of drawing a heart with 1,000,000 trials
p = estimate_probability(1000)
print(p)
