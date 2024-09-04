import random
import string

length = int(input("Введите длину пароля: "))
symbols = string.ascii_letters + string.digits + "!@#$%^&*()-_=+[]"

if length < 1:
    print("ты дебил?")

iterations = 0
oborvanus = []

while iterations != length:
    oborvanus.append(random.choice(symbols))
    iterations += 1

print(''.join(oborvanus))
