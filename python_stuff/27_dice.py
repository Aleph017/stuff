import random
import time

def main():
	query = input("Вы хотите кинуть кубик? (Y/N)").lower()
	if query == "y":
		dice_sides = int(input("Введите число сторон кубика: "))
		dice = random.randint(1, dice_sides)
		print("Бросаем кубик...")
		time.sleep(3)
		print(f"Выпало число {dice}!")
	elif query == "n":
		print("иди нахуй")
		exit()

main()

