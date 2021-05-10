from time import sleep
import sys

import cv2
import serial

arduino_serial_data = serial.Serial("/dev/ttyACM0", 9600)

cascPath = sys.argv[1]
faceCascade = cv2.CascadeClassifier(cascPath)

video_capture = cv2.VideoCapture(0)

while True:
    # Capture frame by frame
    ret, frame = video_capture.read()

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    faces = faceCascade.detectMultiScale(
        gray,
        scaleFactor = 1.2,
        minNeighbors = 6,
        minSize = (30, 30),
        flags = cv2.CASCADE_SCALE_IMAGE
    )

    # Draw a rectangle around the face
    for (x, y, w, h) in faces:
        servo_x = int(48 * x / 640) + 64
        servo_y = int(36 * y / 480) + 75
        print(servo_x, servo_y)
        arduino_serial_data.write(bytes("X" + str(servo_x) + "Y" + str(servo_y), encoding="ascii"))
        sleep(.025)
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)

    # Display the resulting frame
    cv2.imshow("Video", frame)

    if cv2.waitKey(1) & 0xFF == ord("q"):
        break

video_capture.release()
cv2.destroyAllWindows()
