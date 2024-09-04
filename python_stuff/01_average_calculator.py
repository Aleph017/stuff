num_count = int(input("Сколько чисел вы хотите ввести?"))

numbers = []

for i in range(num_count):
    number = float(input(f"Введите число {i + 1}:"))
    numbers.append(number)

total = sum(numbers)
average = total / num_count

print(f"Среднее арифметическое введенных чисел равно {average}")
