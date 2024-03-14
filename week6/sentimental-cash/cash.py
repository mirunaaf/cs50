from cs50 import get_float

# prompt the user for a positive value
while True:
    change = get_float("Change: ")
    if change > 0:
        break

# convert the change owed to cents( multiply by 100)
change_cents = round(change * 100)

# initialize coins to 0
num_coins = 0

# calculate number of coins needed
while change_cents > 0:
    if change_cents >= 25:
        change_cents -= 25
        num_coins += 1
    elif change_cents >= 10:
        change_cents -= 10
        num_coins += 1
    elif change_cents >= 5:
        change_cents -= 5
        num_coins += 1
    else:
        change_cents -= 1
        num_coins += 1

print(num_coins)
