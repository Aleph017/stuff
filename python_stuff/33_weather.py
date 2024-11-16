import requests

API_KEY = "228c05c4c4mshd04d269955da4d3p105e19jsn25914e1ae4ea"
API_URL = "https://yahoo-weather5.p.rapidapi.com/weather?location=velikooktyabrsky&format=json&u=c"

headers = {
    "X-RapidAPI-Key": API_KEY,
    "X-RapidAPI-Host": "yahoo-weather5.p.rapidapi.com"
}

def get_weather():
	response = requests.get(API_URL, headers=headers)
	data = response.json()

	if response.status_code == 200:
		current_observation = data.get('current_observation', {})
		condition = current_observation.get('condition', {})
		temp = condition.get('temperature', 'N/A')
		wttr = condition.get('text', 'N/A')

		print(f"{temp}°C")
		print(f"{wttr}")

	else:
		print("fuck you")

if __name__ == "__main__":
	get_weather()
