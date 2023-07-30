# import math module
import math

# for loop to iterate over the range of integers from 0 to 100, in increments of 10
for fahrenheit in range(0, 101, 10):

    # convert fahrenheit to celsius
    celsius = (fahrenheit - 32) * 5 / 9

    # if else statement to round up if celsius is negative or 
    # round down if celsius is positive
    if celsius < 0:
        celsius = math.ceil(celsius)
    else:
        celsius = math.floor(celsius)

    # print the results
    print(f"{fahrenheit} degrees F = {celsius} degrees C")


