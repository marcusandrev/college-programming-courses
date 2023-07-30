def Abundant(x, y):
    for number in range(x, y):
        if sum(i for i in range(1, number) if number % i == 0) > number:
            print(number)

Abundant(1, 200)
