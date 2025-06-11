import requests
import serial
import time
import os 
from dotenv import load_dotenv
load_dotenv()

API_KEY = os.getenv("WEATHER_API_KEY")
CITY = "Munich"
PORT = "/dev/cu.usbmodem1101"
BAUDRATE = 9600

def get_weather():
    url = f"http://api.openweathermap.org/data/2.5/weather?q={CITY}&appid={API_KEY}&units=metric"
    response = requests.get(url)
    data = response.json()
    if data.get("main") and data.get("weather"):
        temp = data["main"]["temp"]
        desc = data["weather"][0]["main"]
        humidity = data["main"]["humidity"]
        if desc == "Clouds":
            desc = "Cloudy"
        elif desc == "Clear":
            desc = "Sunny"
        elif desc == "Rain":
            desc = "Rainy"
        elif desc == "Snow":
            desc = "Snowy"
        else:
            desc = "Weather not recognized"
        return f"{CITY}: {int(temp)}C     {desc}  Hum: {humidity}%"
    else:
        return "No data"

def send_to_arduino(text):
    with serial.Serial(PORT, BAUDRATE, timeout=2) as ser:
        time.sleep(2)  # Give Arduino time to reset after opening serial
        ser.write((text + "\r").encode('utf-8'))
        print(f"Sent to Arduino: {text}")

if __name__ == "__main__":
    weather = get_weather()
    print(weather)
    send_to_arduino(weather)