# prompts the user to input their total sales amount as a floating-point number
sales = float(input("Enter your total sales amount: "))

# calculates the commission earned by a salesperson 
# based on their total sales amount
if sales <= 2000:
    commission = sales * 0.02
elif sales <= 4000:
    commission = sales * 0.04
elif sales <= 6000:
    commission = sales * 0.07
else:
    commission = sales * 0.1

# format the computed commission to two decimal places
formattedCommission = format(commission, ".2f")

# display the total commission earned by the salesperson
print(f"Total commission you earned is: {formattedCommission}")

