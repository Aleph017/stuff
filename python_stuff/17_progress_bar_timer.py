import time
from tqdm import tqdm

time_input = input("Укажите время в секундах, которое нужно отмерить: ")

if time_input.isdigit():
    time_seconds = int(time_input)
    print(f"Таймер установлен на {time_seconds} секунд.")

    for _ in tqdm(range(time_seconds), desc = "Отсчёт времени", unit = "сек"):
        time.sleep(1)
else:
    print("Ошибка ввода: введено не число")
    exit()
