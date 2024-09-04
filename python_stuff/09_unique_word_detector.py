message = input("Напишите здесь предложение: ").lower().string()

def unique_word_detector(message):
    words = message.split()
    unique_words = set(words)
    return list(unique_words)

print(unique_word_detector(message))
