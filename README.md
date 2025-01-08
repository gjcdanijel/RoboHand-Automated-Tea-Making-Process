cat << 'EOF' > README.md
# **Arduino Servo Control - Automated Tea-Making Robot**

This project showcases an Arduino-based robotic arm capable of simulating the process of making tea. Using four servo motors, the system performs precise movements to pick up a cup, add tea, sugar, stir, and discard the spoon, providing a demonstration of basic robotic automation.

---

## **Features**

- **Servo Motor Control**:
  - Implements smooth and precise servo movements to perform tasks.
  - Supports modular control for easy adjustments and scalability.

- **Predefined Actions**:
  - `getFrom(pos)` - Picks up an item from a specified position.
  - `throwAt(pos)` - Places an item at a specified position.
  - `stir()` - Simulates stirring the contents of a cup.

- **Smooth Motion**:
  - The `smoothMoveServo()` function ensures gradual transitions between servo positions, avoiding sudden jerks.

- **Debugging via Serial Monitor**:
  - Displays real-time updates on servo positions and performed actions for easy monitoring and troubleshooting.

---

## **Hardware Requirements**

1. Arduino-compatible microcontroller.
2. Four servo motors.
3. Pins:
   - Servo 1: **D3** (Vertical movement - "Up/Down").
   - Servo 2: **D4** (Alignment).
   - Servo 3: **D5** (Grip).
   - Servo 4: **D6** (Rotation).
4. External power supply for servo motors if required.
5. USB cable for programming and debugging.

---

## **Installation and Usage**

1. **Hardware Setup**:
   - Connect the servo motors to the specified pins.
   - Ensure proper power supply for the Arduino and servos.

2. **Code Upload**:
   - Open the `.ino` file in the Arduino IDE.
   - Select the correct board and port from the IDE.
   - Upload the code to the Arduino.

3. **Running the Robot**:
   - Open the Serial Monitor (115200 baud rate) to observe the robot's actions.
   - The system will execute a predefined sequence simulating the tea-making process.

---

## **How It Works**

1. The program initializes by attaching all servos to their respective pins.
2. A sequence of movements is executed:
   - Picking up the cup.
   - Adding tea and sugar.
   - Stirring the contents.
   - Returning items to their original positions.
3. Each servo movement is controlled smoothly using the `smoothMoveServo()` function, which transitions the motor to the desired position incrementally.

---

## **Future Improvements**

- Add support for more complex tasks and item detection using sensors.
- Implement user input to dynamically change actions or positions.
- Optimize power management for smoother operation of multiple servos.

---

## **License**

This project is open-source and free to use under the MIT License. Contributions are welcome!
EOF
