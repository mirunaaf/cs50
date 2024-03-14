# s = input("Do you agree? ").lower()

# #s = s.lower()

# if s in ["y", "yes"]:
#     print("agreed")
# elif s in ["n", "no"]:
#     print("not agreed")

from cs50 import get_string

s = get_string("Do you agree? ")

if s.lower() in["y", "yes"]:
    print("Agreed.")
elif s.lower in["n", "no"]:
    print("Not agreed.")
