import time
import serial   # `pip install pyserial`
import keyboard # `pip install keyboard`

tagUID = '00 00 00 00'
password = 'your-super-secure-password' # Password in plantext...
serialInterface = '/dev/ttyACM0'
baudRate = 115200

tagData = "b' " + tagUID + "'"

with serial.Serial(serialInterface, baudRate) as ser:
    while True:
        data = ser.read(12)

        if str(data) == tagData and ser.name == serialInterface:
            keyboard.write(password)
            keyboard.press_and_release('enter')
            print('Authorized')
            time.sleep(3)

        else:
            print('Unauthorized')
            time.sleep(5)

        ser.flush()
        ser.flushInput()
        ser.flushOutput()
