import random

def magic_number_game():

    magic_number = random.randint(1, 100)

    print("Я загадал случайное число от 1 до 100. Отгадайте его, я буду говорить, больше или меньше ваша догадка заданного числа.")

    user_input = ""
    input_count = 0

    while user_input != magic_number:
        user_input = int(input("Ваша догадка:"))
        input_count += 1

        if user_input < magic_number:
            print("Больше")
        elif user_input > magic_number:
            print("Меньше")
        else:
            print(f"Поздравляю! Вы отгадали загаданное число! Для этого вам понадобилось {input_count} попыток.")

while True:
    attempt_count = magic_number_game()

    play_again = input("Хотите сыграть ещё раз? (y/n)").lower().strip()
    if play_again != "y":
        print("Спасибо за игру!")
        break
