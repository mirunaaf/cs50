def get_int(prompt):
#keep prompting user for input until positive integer entered
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            #if input not converted to int , print error message and continue loop
            print("invalid input")

#get the height of the pyramid
height = get_int("Height: ")

#validate the height
while height < 1 or height > 8:
    print("invalid height")
    height = get_int ("Height: ")

#generate the pyramid
for i in range(1, height + 1):
    print(" " * (height - i) + "#" * i)

