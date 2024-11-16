import time
import os
import sys
import multiprocessing as mp
import shutup

shutup.please()
animation = [".  ", ".. ", "..."]

def animate():
    print("\033[?25l", end="")
    try:
        while True:
            for dot in animation:
                print(f"Processing{dot}", end="\r", flush=True)
                time.sleep(0.5)
    except KeyboardInterrupt:
        pass
        #print("\033[?25h", end="")

    finally:
        print("\033[?25h", end="")

def process(a, b, c, d, e):
    arbuz = [a, b, c, d, e]
    arbuz.sort(reverse=True)
    average = sum(arbuz)/len(arbuz)
    f = 0

    while f < 10:
        if arbuz[1] == average:
            print("a)", arbuz, average)
        if arbuz [2] == average:
            print("б)", arbuz, average)
        f += 1

if __name__ == '__main__':
    anim_process = mp.Process(target = animate)
    anim_process.daemon = True
    anim_process.start()

    try:
        with mp.Pool(processes=4) as pool:
            for a in range(50):
                for b in range(50):
                    for c in range(50):
                        for d in range(50):
                            for e in range(50):
                                pool.apply_async(process, args=(a, b, c, d, e))

            pool.close()
            pool.join()

        #while True:
         #   try:
          #      input()
           # except EOFError:
            #    print("Ending process...")
             #   break

    except KeyboardInterrupt:
        print("Ending process...")

    finally:
        sys.stderr = open(os.devnull, 'w')
        anim_process.terminate()
        anim_process.join()
