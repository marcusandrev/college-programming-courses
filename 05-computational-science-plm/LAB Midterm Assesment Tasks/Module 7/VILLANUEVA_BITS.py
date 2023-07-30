# takes a positive integer from the user
num = int(input("Enter a positive integer: "))

# stores num into num1
num1 = num

# initialize bits to 0
bits = 0

# calculate the minimum number of bits needed to store a positive integer
while num > 0:
    bits += 1
    num //= 2

# print the result
print(f"To store {num1} requires {bits}")



