# 1. Code in Python or Jupiter program to allow the user 
# to input two float values and then the program adds the two values together.

a = float(input("Enter value of a: "))
b = float(input("Enter value of b: "))
sum = a + b
print("The sum of", a, "and", b, "is", sum)

# 2. Code in Python or Jupiter program to allow the user 
# to input his/her age and the program will show if the person is eligible to vote. 
# A person who is eligible to vote must be older than or equal to 18 years old.

age = int(input("Enter your age: "))
result = "You are eligible to vote." if age >= 18 else "You are not eligible to vote yet."
print(result)

# 3. Code in Python or Jupiter program to determine whether an input number is an even number.

number = int(input("Enter a number: "))
result = "even" if number % 2 == 0 else "odd"
print("The number", number, "is", result)