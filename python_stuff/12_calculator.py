print("Это калькулятор.")

first_number = float(input("Введите первое число:"))
second_number = float(input("Введите второе число:"))
operation = input("Какую операцию вы хотите провести? (+, -, *, /) ")

if operation == "+":
    total = first_number + second_number
elif operation == "-":
    total = first_number - second_number
elif operation == "*":
    total = first_number * second_number
elif operation == "/":
    if second_number != 0:
        total = first_number / second_number
    else:
        total = "ошибка"
else:
    total = "ошибка"

print(total)
