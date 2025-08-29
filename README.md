# Smart Blind Stick

An assistive device designed to help visually impaired individuals navigate more safely and independently.  
This stick uses multiple sensors to detect obstacles, monitor environmental temperature, and provide feedback through vibration, sound, and light.

## Features
- **Obstacle Detection** – Ultrasonic and IR sensors detect objects ahead and trigger alerts.
- **Multi-Modal Alerts** – Vibration motor, buzzer, and LED for different feedback types.
- **Adaptive Alert Speed** – Beep frequency changes depending on how close the obstacle is.
- **Temperature Warning** – LM35 sensor warns if ambient temperature exceeds a safe level.
- **One-Button Control** – Easily turn the system on/off with a single button.
- **Welcome Melody** – Plays a short tune when powered on.

## Components Used
- Arduino (compatible board)
- Ultrasonic Sensor (HC-SR04)
- IR Proximity Sensor
- LM35 Temperature Sensor
- Vibration Motor
- Buzzer
- LED
- Push Button
- Jumper Wires & Breadboard

## How It Works
1. **Power On** – Press and hold the button to turn on the stick.
2. **Scanning** – Ultrasonic and IR sensors check for obstacles.
3. **Alerting** – Based on the distance, the buzzer beeps faster and the vibration motor activates.
4. **Temperature Check** – If the environment is too hot (>40°C), it triggers a warning.
5. **Power Off** – Press and hold the button again to turn off the system.

## Circuit Diagram
![Cirucuit Diagram](/images/Circuit_Diagram.png)

## Code
The project is programmed in **Arduino C/C++**. You can find the full code in the repository.

## Future Improvements
- Add GPS for navigation assistance.
- Include voice feedback for distance readings.
- Rechargeable battery integration.

## Author
**Mohamed Zain**
