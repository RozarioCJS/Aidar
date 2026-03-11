import serial
import time




if __name__ == "__main__":
    while True:
        arduino = serial.Serial(port='/dev/ttyUSB0', baudrate=9600, timeout=1)
        time.sleep(1)
        response = arduino.readline().decode().strip()
        print(response)
