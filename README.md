# SMS-BASED-THRESHOLD-MONITORING-AND-THERMAL-MANAGMENT
This project checks the temperature in places like server rooms or cold storage. If the temperature goes too high, it sends a warning through SMS. You can also set or change the temperature limit by sending an SMS, making it easy to control from anywhere.

**REQUIREMENTS:**

**HARDWARE REQUIREMENTS:**
➢ LPC 2148
➢ GSM MODULE (M660A)
➢ 16X2 LCD
➢ LM35
➢ BUZZER
➢ AT25LC512
  
**SOFTWARE REQUIREMENTS:**

➢ PROGRAMMING IN EMBEDDED C
➢ KEIL-C COMPILER
➢ FLASH MAGIC

**Project Workflow and Steps** 

1. Project Setup

    Create a new folder named after your project.

    Copy all the required module files into the folder:

        lcd.c, lcd.h
        delay.c , delay.h
        uart.c, uart.h
        spi.c,spi_eeprom.c
        

3. Individual Module Testing
✅ LCD Module

    Test LCD by displaying:
       - A single character (e.g., 'A')
       - A string (e.g., "Hello")
       - An integer (e.g., 25)

✅ EEPROM (AT25LC512)
    Write n bytes into EEPROM.
    Read n bytes back and display them on LCD.
    Use BYTE WRITE and BYTE READ functions.

✅ UART Module

    Transmit:
        A character (e.g., 'X')
        A string (e.g., "UART OK")

    Receive: String input using UART interrupts.        

✅ RTC (Real-Time Clock)
    Read current date and time from inbuilt RTC.
    Display them on the LCD.

**3. GSM Module Testing**

Connect the GSM module to PC via UART and test using AT Commands:
Command	Purpose

AT	Test module responsiveness
ATE0	Turn off command echo
AT+CMGF=1	Set SMS text mode
AT+CNMI=2,1,0,0,0	Enable new message notifications
AT+CMGD=1	Delete first message from SIM memory
AT+CMGR=1	Read the first SMS
AT+CMGS="+91xxxxxxxxxx"	Send SMS to given mobile number

**📲 Working of the Final System**
    
    The LM35 sensor measures temperature and sends the value to the microcontroller via ADC.
    The temperature is displayed on the LCD.
    If the temperature goes beyond the set limit, the buzzer sounds and an SMS alert is sent.
    Users can send an SMS to change the temperature threshold remotely.
    The threshold can be stored in EEPROM so it's retained after a restart.
    
**Example SMS Commands**
SMS Content	         Action
1234M92xxxxxx70      30	Sets temperature threshold to 30°C
1234I	             Replies with current temperature reading

**File Structure**
/SMS_Temp_Monitoring
├── lcd.c / lcd.h          # LCD driver
├── delay.c / delay.h      # Microsecond/millisecond delays
├── uart.c / uart.h        # UART driver with interrupt
├── spi.c / spi.h          # SPI communication with EEPROM
├── adc.c / adc.h          # ADC handling for LM35
├── main.c                 # Main logic, integration of all modules
├── gsm.c / gsm.h          # GSM communication logic (AT commands)
├── rtc.c / rtc.h          # RTC date/time reading
├── README.md              # Project documentation (this file)

**Testing Tips**

    Test each module separately before integrating.
    Use serial terminal for GSM testing.
    Ensure proper baud rate for UART (typically 9600 for GSM).

