# import termcolor library
from termcolor import colored

# Dictionary of color options
options = {
    'A': {'color': 'yellow', 'meaning': 'YELLOW symbolizes: \nwisdom, joy, happiness, intellectual energy'},
    'B': {'color': 'red', 'meaning': 'RED symbolizes: \naction, confidence, courage, vitality'},
    'C': {'color': 'green', 'meaning': 'GREEN symbolizesL \nlife, nature, fertility, well being'},
    'D': {'color': 'cyan', 'meaning': 'BLUE symbolizes: \nyouth, spirituality, truth, peace'}
}

# Displays a colored menu and prompts the user to select an option, 
# then  displays the meaning of the selected option in a colored output
while True:
    print('\n'.join([colored(f'[{option}] {name}', options[option]['color']) for option, name in [('A', 'YELLOW'), ('B', 'RED'), ('C', 'GREEN'), ('D', 'BLUE')]]))
    print('[E] EXIT')

    choice = input('\nENTER YOUR CHOICE: ').upper()
    if choice == 'E':
        print('GOOD.. You\'ve finished your work')
        break
    elif choice in options:
        print(colored(options[choice]['meaning'], options[choice]['color']) + '\n')

