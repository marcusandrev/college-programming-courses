# Prompts the user to enter a word and stores it in a variable called word
word = input("Enter a word: ")

# Reverses the input string by slicing it in reverse order, 
# concatenate the sliced string with space as separator, 
# and store the resulting string in a variable called reversedWord 
reversedWord = " ".join(word[::-1])

# Prints the reversed word
print(reversedWord)

