import random

num_otd = random.randint(1, 1000)
mod = random.randint(1, 10)

operations = ["+", "-", "*", "/"]
oper = random.choice(operations)

if oper == "+":
    total = num_otd + mod
elif oper == "-":
    total = num_otd - mod
elif oper == "*":
    total = num_otd * mod
elif oper == "/":
    if mod != 0:
        total = num_otd / mod
    else:
        total = "ошибка"
else:
    total = "ошибка"

if total >= 1000:
    total = num_otd / 2

print(f"Число дня равно {total}!")
