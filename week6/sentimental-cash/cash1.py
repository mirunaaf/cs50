from cs50 import get_float

# prompt user for positive input
while True:
    change = get_float("Change: ")
    if change > 0:
        break

# convert the change owed to cents
change_cents = change * 100

# define coin denominations
coins = [25, 10, 5, 1]

#initialize coins count to 0
num_coins = 0

# calculate number of coins needed
for coin in coins:
    num_coins += change_cents // coin
    change_cents %= coin

# print number of coins
print(num_coins)
