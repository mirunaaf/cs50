from cs50 import get_int

while True:
    n = get_int("Height: ")
    if n >= 1 and n <= 8:
        break

for i in range(1, n + 1):
    print(" " * (n - i), end="")
    print("#" * i)
