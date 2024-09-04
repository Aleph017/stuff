# 21_you_spin_me_round.py

import time

animation = ["[-]", "[\\]", "[|]", "[/]"]

count = 0

while True:
    for stage in animation:
        print(stage, end="\r", flush=True)
        # count += 1
        time.sleep(0.1)

        # if count == 40:
            # print("[✔] процесс завершен!")
            # exit()

