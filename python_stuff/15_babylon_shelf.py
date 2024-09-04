import random
import string

letters = string.ascii_letters + 'абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ'

print("Добро пожаловать в одну из полок Вавилонской Библиотеки!")

goal_word = input("Какое слово вы хотите найти? ")

def babylon_shelf():

    counter = 0

    while True:
        idk = ""
        for _ in range(len(goal_word)):
            idk += random.choice(letters)
        counter += 1
        # print(idk)
        if idk == goal_word:
            return counter

attempts = babylon_shelf()

print(f"Слово {goal_word} было найдено! Для этого понадобилось перебрать {attempts} символов.")

