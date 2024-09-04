import time

def progress_bar(iteration, total, prefix='B', suffix='A', length=30, fill='█'):
    """
    Показывает прогресс выполнения в виде progress bar в консоли.

    Parameters:
    iteration (int): Текущий шаг выполнения.
    total (int): Общее количество шагов.
    prefix (str): Префикс для progress bar.
    suffix (str): Суффикс для progress bar.
    length (int): Длина progress bar в символах.
    fill (str): Символ для заполнения progress bar.

    Returns:
    None
    """
    percent = ("{0:.1f}").format(100 * (iteration / float(total)))
    filled_length = int(length * iteration // total)
    bar = fill * filled_length + '-' * (length - filled_length)
    print(f'\r{prefix} |{bar}| {percent}% {suffix}', end='\r')
    # Печатаем новую строку, если достигли конца
    if iteration == total:
        print()

# Пример использования
total = 100
for i in range(1, total + 1):
    time.sleep(0.1)  # Имитация долгой операции
    progress_bar(i, total, prefix='Progress:', suffix='Complete', length=50)

print("Операция завершена!")

