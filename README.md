# AVR-Atmega32-Fan-Speed-Controller
This embedded project enables the control of a fan's speed based on temperature readings from an LM35 sensor using an AVR Atmega32 microcontroller. The system dynamically adjusts the fan speed to maintain optimal thermal conditions in the environment.

# Project Components:
1. Application Layer (APP)
  - **Main Function**: Controls the main program flow.
    
2. Hardware Abstraction Layer (HAL)
  - **LCD Driver**: Facilitates communication with the LCD display to visualize temperature readings and fan status.
  - **DC Motor Driver**: Controls the rotation of the fan motor in different states (off, clockwise, counter-clockwise).
  - **LM35 Sensor Driver**: Calculates temperature from the ADC digital value obtained from the LM35 sensor.

3. Microcontroller Abstraction Layer (MCAL)
  - **ADC Driver**: Initializes and reads analog data from the LM35 temperature sensor.
  - **PWM Driver**: Manages Pulse Width Modulation (PWM) signals to adjust the fan speed.
  - **GPIO Driver**: Manages the MCU PINS and PORTS and the communcation between any external device.
    
# Project Workflow:

1. The ADC driver initializes the ADC module for reading analog data from the LM35 sensor.
2. The LM35 sensor driver calculates the temperature based on the ADC readings.
3. The main program continuously monitors the temperature and adjusts the fan speed accordingly.
4. Fan speed is dynamically controlled based on predefined temperature thresholds, ensuring efficient cooling while minimizing power consumption.
5. Temperature readings and fan status are displayed in real-time on the connected LCD display.

# How to Use:

1. Clone the repository to your local environment.
2. Set up an AVR microcontroller development environment.
3. Compile and flash the project onto the microcontroller.
4. Connect the LM35 sensor and the fan motor to the appropriate pins of the microcontroller.
5. Power on the system and observe the fan speed adjustments based on temperature variations.
6. You can run the simulation for the project using Proteus software.
