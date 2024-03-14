from cs50 import get_string

# prompt user for text
text = get_string("Text: ")

# count number of letters in text
letters = 0
for c in text:
    if c.isalpha():
        letters += 1
# count number of words in text
words = len(text.split())

# count number of sentences
sentences = text.count(".") + text.count("!") + text.count("?")

# calculate average number of letters per 100 words
L = letters / words * 100

# calculate average number of sentences per 100 words
S = sentences / words * 100

# calculate Coleman-Liau index
grade = round(0.0588 * L - 0.296 * S - 15.8)

# print grade level
if grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")
