# Определяем клавиатуры
keyboard_en = "qwertyuiopasdfghjklzxcvbnm"
keyboard_ru = "йцукенгшщзхъфывапролджэячсмитьбю"

# Спрашиваем пользователя, какую клавиатуру он хочет использовать
select = input("Do you want to encrypt an English or a Russian text? Answer EN or RU: ").strip().upper()

# Функция для сдвига текста
def shift_text(text, keyboard, shift):
    result = ""  # Переменная для хранения зашифрованного текста
    for char in text:  # Проходимся по каждому символу в исходном тексте
        if char in keyboard:  # Проверяем, есть ли символ в клавиатуре
            index = keyboard.index(char)  # Находим индекс символа в строке клавиатуры
            new_index = (index + shift) % len(keyboard)  # Вычисляем новый индекс, сдвигая на заданное количество шагов
            result += keyboard[new_index]  # Добавляем символ с нового индекса в результат
        else:
            result += char  # Если символа нет в клавиатуре, добавляем его в результат без изменений
    return result  # Возвращаем зашифрованный текст

# Ввод сообщения и шага сдвига
if select == "RU":
    text = input("Введите ваше сообщение: ").strip().lower()
    keyboard = keyboard_ru
elif select == "EN":
    text = input("Enter your message: ").strip().lower()
    keyboard = keyboard_en
else:
    print("Invalid selection.")
    exit()

shift = int(input("Enter the shift value: "))

# Зашифровываем текст и выводим результат
encrypted_text = shift_text(text, keyboard, shift)
print("Encrypted text:", encrypted_text)
