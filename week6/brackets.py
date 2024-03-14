# text = "In the great green room"
# words = text.split()
# print(words[1:2])
# print(words[1:4])
# print(words[2:])

text = "In the great green room"

for word in text.split()[2:]:
    print(word)

# text = "In the great green room."

# for word in text.split():
#     print(word)
