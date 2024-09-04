import time
import random

# Функция для анимации с точками
def animate_message(message, duration):
    dots = [".  ", ".. ", "..."]
    start_time = time.time()
    while time.time() - start_time < duration:
        for dot in dots:
            print(f"{message}{dot}", flush=True, end="\r")
            time.sleep(0.33)

# Список сообщений и их результатов
tasks = [
    ("Получение Даты", "1887"),
    ("Получение Местоположения", "Нью-Лондон"),
    ("Получение Населения", "694 человека"),
    ("Получение температуры воздуха", "-40°C")
]

# Время анимации в секундах
animation_time = random.randint(1, 10)

# Выполнение задач с анимацией
for task in tasks:
    message, result = task
    animate_message(message, animation_time)
    print(" " * len(message + "..."), end="\r")
    print(result)
