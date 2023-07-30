# Prompts the user to enter their grade 
# and converts the user's input to an integer using the int() function.
grade = int(input("Enter your grade: "))

# Checks the value of the grade variable 
# and prints a corresponding message based on the range in which it falls
if grade <= 40:
    print("Read More")
elif grade <= 60:
    print("Please Try Harder")
elif grade <= 75:
    print("Average Student")
elif grade <= 85:
    print("Excellent")
elif grade <= 100:
    print("Outstanding")
else:
    print("Number entered is invalid")

