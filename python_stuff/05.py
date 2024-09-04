import datetime
current_datetime = datetime.datetime.now()
weekday = current_datetime.strftime("%A")

if weekday == "Wednesday":
    print("It is wednesday, my dudes")
