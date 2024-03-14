#implements get_int

def get_int(prompt):
    # while True:
    #     try:
    #         return int(input(prompt))
    #     except ValueError:
    #         print ("Not an integer")
    return int(input(prompt))

def main():

    x = get_int("x: ")
    y = get_int("y: ")

    print(x + y)

main()

