#uppercases string all at once
before = input("Before: ")
# after = before.upper()
# print(f"After: {after}")
print(f"After: {before.upper()}")

#uppercases string one character at a time
before = input("Before: ")
print("After: ")
for c in before:
    print(c.upper())
