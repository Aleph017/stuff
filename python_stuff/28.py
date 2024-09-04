import time
import sys
import random


count = 0

def show_animation():
	animation = ["[-]", "[\\]", "[|]", "[/]"]
	for _ in range(random.randint(3, 10)):
		for stage in animation:
			print(stage, end="\r", flush=True)
			# count += 1
			time.sleep(0.1)

print("placeholder", end = "")
show_animation()




# dots()

# def dots():
	# for _ in range(random.randint(3, 10)):
		# for stage in range(4):
			# sys.stdout.write('\r' + "." * stage + " " * (3 - stage))
			# sys.stdout.flush()
			# time.sleep(0.33)
