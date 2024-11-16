import requests

API_KEY = ""
API_URL = ""

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
		print("dammit")

if __name__ == "__main__":
	get_weather()
