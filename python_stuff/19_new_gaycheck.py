import time
import random

gay_true = "[x] Проверка не пройдена, Вы гей."
gay_false = "[✓] Проверка пройдена, Вы не гей."
animation = ["[|]", "[/]", "[-]", "[\\]"]
result = random.choice([gay_false, gay_false, gay_false, gay_true])

def asking_user():
    query = input("Вы хотите пройти проверку на гейство? (Y/N) ").lower()
    if query == "n":
        print("иди нахуй")
        exit()
    elif query == "y":
        gaycheck(result)

def gaycheck(result):
    username = input("Введите своё имя: ").lower()
    if username == "влад" or username == "капуста":
        show_animation(animation)
        print("[x] Проверка не пройдена, вы гей.")
    else:
        show_animation(animation)
        print(result)

def show_animation(animation):
    check_time = random.randint(1, 25)
    for _ in range(check_time):
        for stage in animation:
            print(stage, end = "\r", flush=True)
            time.sleep(0.1)

asking_user()
