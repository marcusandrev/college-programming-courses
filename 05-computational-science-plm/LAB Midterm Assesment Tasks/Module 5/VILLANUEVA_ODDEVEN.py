# Prompts the user to enter an integral number 
# and converts the user's input to an integer using the int() function.
num = int(input("Enter an integral number: "))

# checks whether the integer value stored in the variable num 
# is even or odd using the modulo operator
if num % 2 == 0:
    print(num, "is an even number.")
else:
    print(num, "is an odd number.")

