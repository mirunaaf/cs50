from cs50 import get_string

greeting = get_string("Greeting: ").strip().lower()

if greeting.startswith("hello"):
    print("$0")
elif greeting.startswith("h"):
    print("$20")
else:
    print("$100")


# for word in input.split():
#     if word == "hello":
#         print("$0")
#     if word == {"hi","hey","how"}:
#         print("20$")
# else:
#     print("100$")
