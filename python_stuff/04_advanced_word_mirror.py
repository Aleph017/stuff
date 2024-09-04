import random
name = input("Введи своё имя:")
second_name = name.lower()[::-1]
stuff = list(second_name)
random.shuffle(stuff)
true_name = "".join(stuff).title()
print("Отныне тебя зовут", true_name)
