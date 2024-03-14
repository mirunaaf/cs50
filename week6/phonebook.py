# Implements linear search for names using loop

# A list of names
names = ["Pix", "Peps", "Piu"]

#ask for name
name = input("Name: ").capitalize()

#search for name

for n in names:
    if name == n:
        print("found")
        break
else:
    print("not found")

# Implements linear search for names using `in`

# A list of names
names = ["Carter", "David", "John"]

# Ask for name
name = input("Name: ")

# Search for name
if name in names:
    print("Found")
else:
    print("Not found")
