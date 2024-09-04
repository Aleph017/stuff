import os
import time

def diary():
    mode = input("w/r ? ").lower()
    if mode == "r":
        read_note()
    elif mode == "w":
        write_note()
    else:
        print("Неправильный режим. Пожалуйста, введите 'w' для записи или 'r' для чтения.")

def write_note():
    note = input("Введите вашу запись: ")
    date_time = time.strftime("%Y-%m-%d_%H-%M-%S")

    if not os.path.exists("diary_entries"):
        os.makedirs("diary_entries")

    file_path = f"diary_entries/{date_time}.txt"

    with open(file_path, "w") as file:
        file.write(note)

    print(f"Запись сохранена в файл {file_path}")

def read_note():
    if not os.path.exists("diary_entries"):
        print("Записей нет.")
        return

    entries = os.listdir("diary_entries")
    if not entries:
        print("Записей нет.")
        return

    print("Доступные записи:")
    for index, entry in enumerate(entries):
        print(f"{index + 1}: {entry}")

    try:
        entry_number = int(input("Введите номер записи для чтения: ")) - 1
        if entry_number < 0 or entry_number >= len(entries):
            print("Неправильный номер записи.")
            return
    except ValueError:
        print("Пожалуйста, введите правильный номер.")
        return

    file_path = f"diary_entries/{entries[entry_number]}"
    with open(file_path, "r") as file:
        print(f"\nЗапись из файла {entries[entry_number]}:\n")
        print(file.read())

# Запуск программы
diary()
