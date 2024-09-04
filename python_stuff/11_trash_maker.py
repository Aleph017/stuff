import random
import time
number = random.randint(1, 1000)
user_input = input("Какое сообщение вы хотите продублировать? ")
count = 0
while count != number:
    print(user_input)
    count += 1
    time.sleep(0.015)

print(f"{user_input} был написан {number} раз.")
