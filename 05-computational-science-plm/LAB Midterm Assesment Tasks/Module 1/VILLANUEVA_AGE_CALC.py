# Prompts the user to enter their age in years
# and stores the input value in a variable called ageInYears
ageInYears = int(input("Enter your age in years: "))

# Calculates the age in months, weeks, days, hours, and minutes
ageInMonths = ageInYears * 12
ageInWeeks = ageInYears * 52
ageInDays = ageInYears * 365
ageInHours = ageInDays * 24
ageInMinutes = ageInHours * 60

# Displays the age in months, weeks, days, hours, and minutes
print("You are", ageInMonths, "months old")
print("You are", ageInWeeks, "weeks old")
print("You are", ageInDays, "days old")
print("You are", ageInHours, "hours old")
print("You are", ageInMinutes, "minutes old")

