import multiprocessing as mp
import time

animation = [".  ", ".. ", "..."]

def process_combination(a, b, c, d, e):
    arbuz = [a, b, c, d, e]
    average = sum(arbuz) / len(arbuz)
    chort = sorted(arbuz)

    # Проверяем условие и выводим результат
    for i, pos in enumerate([1, 2]):
        if chort[pos] == average:
            print(f"{chr(1072 + i)})", chort[pos], arbuz, average)

def animate():
    while True:
        for dot in animation:
            print(f"Processing{dot}", end="\r", flush=True)
            time.sleep(0.5)

if __name__ == '__main__':
    # Запускаем анимацию в отдельном процессе
    anim_process = mp.Process(target=animate)
    anim_process.daemon = True  # Процесс будет закрыт при завершении основной программы
    anim_process.start()

    # Создаем пул процессов
    with mp.Pool(processes=4) as pool:  # Подбираем количество потоков под CPU
        for a in range(100):
            for b in range(100):
                for c in range(100):
                    for d in range(100):
                        for e in range(100):
                            # Отправляем задачи в пул для выполнения
                            pool.apply_async(process_combination, args=(a, b, c, d, e))

        # Ждём завершения всех задач
        pool.close()
        pool.join()
