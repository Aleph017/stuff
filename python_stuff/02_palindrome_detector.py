original_word = input("Введите строку:")
normalized_word = original_word.lower().replace(" ","")

if normalized_word == normalized_word[::-1]:
    print("Строка является палиндромом")
else:
    print("Строка не является палиндромом")
