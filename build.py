import serial.tools.list_ports
import sys
import subprocess

script = ""
serial_listen = "--listen" in sys.argv

for arg in sys.argv:
    if arg.endswith(".ino"):
        script = arg

if script == "":
    print("Error building! Please specify script to build.")
    sys.exit(0)

print("Building script " + script + "...")

serial_ports = [tuple(p) for p in list(serial.tools.list_ports.comports())]
#arduino_ports = [port[0] for port in serial_ports if port[0].startswith("/dev/ttyACM")]
arduino_ports = [port[0] for port in serial_ports[0].startswith("COM")]


if len(arduino_ports) == 0:
    print("Error encountered on build! Could not discover any serial devices.")
    sys.exit(0)
elif len(arduino_ports) > 1:
    print("Warning! There are multiple serial devices attached to this device")

chosen_port = arduino_ports[0]
print("Compiling to " + chosen_port + "...")

subprocess.run(["/opt/arduino-1.8.10/arduino", "--board", "arduino:avr:uno", "--port", chosen_port, "--upload", script])

if serial_listen:
    print("Beginning serial listen...")
    ser = serial.Serial("/dev/ttyACM0", 9600, timeout=1)
    while True:
        data = ser.read(100)
        data_string = str(data)[2:len(data) - 1]
        print(str(data))
