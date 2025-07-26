# SMS-Based Threshold Monitoring and Thermal Management System
This project monitors temperature in environments such as server rooms, cold storage units, or industrial setups. When the temperature crosses a predefined threshold, the system sends an SMS alert. Additionally, users can remotely update the temperature threshold by sending an SMS to the system, enabling real-time thermal management from anywhere.

**🚀 Features**
- Real-time temperature monitoring using LM35 sensor
- SMS alerts sent automatically when the threshold is breached
- Remotely update threshold values via SMS
- Threshold value stored in EEPROM for persistence after power restart
- Buzzer alarm on temperature breach
- Display current temperature on 16x2 LCD
- Accurate timestamp logging using RTC module

**REQUIREMENTS:**

**🔌 Hardware**

- LPC2148 Microcontroller (ARM7)
- GSM Module (SIM800L / M660A)
- 16x2 LCD Display
- LM35 Temperature Sensor
- AT25LC512 EEPROM
- Optional: RTC Module

**💻 Software**

- Embedded C
- Keil uVision (C Compiler)
- Flash Magic (Hex file programmer)

**📁File Structure**

/SMS_Temp_Monitoring
├── lcd.c / lcd.h           # LCD driver
├── delay.c / delay.h       # Delay utilities (µs/ms)
├── uart.c / uart.h         # UART driver with interrupt support
├── spi.c / spi.h           # SPI communication for EEPROM
├── adc.c / adc.h           # ADC handling for LM35 temperature sensor
├── gsm.c / gsm.h           # GSM communication logic (AT commands)
├── rtc.c / rtc.h           # Real-Time Clock reading
├── main.c                  # Main application logic
├── README.md               # Project documentation


**✅ Module Testing**

**LCD Module**
- Display:
 - A single character (e.g., 'A')
 - A string (e.g., "Hello")
 - An integer (e.g., 25)

**EEPROM (AT25LC512)**
- Write and read n bytes using:
 - BYTE_WRITE()
 - BYTE_READ()
 - Display data on LCD

**UART**
- Transmit:
 - A character (e.g., 'X')
 - A string (e.g., "UART OK")
 - Receive:
   String input using UART interrupts

**RTC**
- Read current date and time
- Display on LCD

**📞 GSM Module Testing (AT Commands)**
Connect GSM module to PC and test using serial terminal:

| Command                   | Description                     |
| ------------------------- | ------------------------------- |
| `AT`                      | Check module responsiveness     |
| `ATE0`                    | Disable echo                    |
| `AT+CMGF=1`               | Set SMS mode to text            |
| `AT+CNMI=2,1,0,0,0`       | Enable new message notification |
| `AT+CMGD=1`               | Delete 1st message from memory  |
| `AT+CMGR=1`               | Read 1st message                |
| `AT+CMGS="+91xxxxxxxxxx"` | Send SMS to a given number      |

**📲 System Working**
1.LM35 measures temperature and sends analog voltage to microcontroller via ADC.
2.Temperature is displayed on the LCD.
3.If the temperature exceeds the set threshold:
   - Buzzer is activated.
   - SMS alert is sent.
4.Users can send SMS commands to:
   - Update threshold temperature.
   - Request current temperature.

**💬 SMS Commands**
| SMS Content         | Description                            |
| ------------------- | -------------------------------------- |
| `1234M92xxxxxx7030` | Set temperature threshold to `30°C`    |
| `1234I`             | Reply with current temperature reading |

**🔧 Testing Tips**
- Test each module individually before integration.
- Use a serial terminal (e.g., RealTerm, Tera Term) for GSM testing.
- Ensure correct UART baud rate (usually 9600 for GSM).
- Store and verify EEPROM data using separate test code.

**✅ Completion Indicator**
- Once all components behave as expected and SMS commands function as designed, your project is complete.

"All the best!"

