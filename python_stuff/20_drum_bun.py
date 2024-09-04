import time

animation = ["[-]", "[\\]", "[|]", "[/]"]
count = 0
bads = ["Drugs", "Cringe", "Fatherless", "Hungarian"]
goods = ["Patriotic", "Respect", "Gigachad", "Romanian"]

def progress(animation, count):
    while count != 24:
        for stage in animation:
            print(stage, end = "\r", flush = True)
            count += 1
            time.sleep(0.14)

def analysis(bads, goods):
    song = input("What song would you like to analyse? ").lower()
    if song == "drum bun":
        for bad in bads:
            progress(animation, count)
            print(f"[✔] {bad} - 0%")

        for good in goods:
            progress(animation, count)
            print(f"[✔] {good} - 100%")



analysis(bads, goods)
