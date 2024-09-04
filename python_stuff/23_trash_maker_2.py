import os

line = input("Введите слово: ")

def get_terminal_size():
    columns, rows = os.get_terminal_size()
    return columns

for letter in line:
    print(letter.upper()*get_terminal_size())

