# Prompts the user to enter a number
number = int(input("Enter a number: "))

# Initialize the sum and count variables
sum = 0
count = 0

# Loop until the user enters 1,  
# while accumulating a running total of the numbers entered and 
# counting the total number of entries
while number != 1:
    sum += number
    count += 1
    number = int(input("Enter a number: "))

# Display the results and adding 1 to the count and sum to include the number 1 input
print(f"The numbers entered is {count + 1}")
print(f"The sum of all the numbers entered are {sum +1}")

