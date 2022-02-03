import random

string = ''
c = 500
for x in range(c):
    string += str(random.randint(-1000000, 1000000))
    if (x != c - 1):
        string += ' '
print(string)
