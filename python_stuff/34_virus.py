import tkinter as tk

# Создаем окно
window = tk.Tk()
window.title("Вирус!")

window.geometry("300x400")

# Текст вируса
message = """Здравствуйте, я тверской вирус.

По причине ужасной некомпетентности моего создателя я не способен причинить какой-либо вред вашему компьютеру и был написан нейросетью.

Поэтому очень прошу: разошлите меня по почте другим адресатам или распространите меня другим доступным способом.

Заранее благодарен за понимание и сотрудничество. Хорошего дня!

ÔwÔ"""

# Создаем метку для отображения сообщения
label = tk.Label(window, text=message, padx=10, pady=10, wraplength=280)
label.pack()

# Запуск окна
window.mainloop()
