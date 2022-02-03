import random

string = ''
for x in range(100):
    string += str(random.randint(-1000000, 1000000))
    if (x != 99):
        string += ' '
print(string)
