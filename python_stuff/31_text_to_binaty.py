def utf8_to_binary(text):
    binary_result = ' '.join(format(ord(char), '08b') for char in text)
    return binary_result

# Пример использования
input_text = input("Введите текст для перевода в двоичный код: ")
binary_output = utf8_to_binary(input_text)
print(binary_output)

