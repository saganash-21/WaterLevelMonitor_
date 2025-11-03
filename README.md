# Arduino-Based Water Level Monitoring for a Horizontal Cylindrical Tank

## Author
**Jeremy Ndirangu**

## Overview
This project implements a real-time water level monitoring system for a horizontally oriented cylindrical tank using an Arduino-based approach. It leverages geometry, embedded systems, and PCB design to accurately calculate water volume and provide visual level indicators.

## Features
- Simulates analog water level sensor using a 3296 trimpot
- Calculates water height and volume using circular segment geometry
- LED indicators for Empty, Refill, and Full water levels
- Optional 16x2 LCD display for live monitoring (Serial Monitor used in testing)
- Custom-designed PCB using Eagle CAD

## Folder Structure
```
├── README.md                         # This file
├── Arduino/                          # Arduino source code
├── Schematics/                       # Eagle CAD schematic and PCB layout
├── Images/                           # Test setup and PCB photos
├── Math/                             # Mathematical calculations
├── Documentation/                   # Full report PDF
└── LICENSE                           # MIT License (optional but recommended)
```

## Hardware Used
- Arduino Uno
- 3296 multi-turn potentiometer (0–5 V simulation)
- Red, Yellow, and Green LEDs
- Resistors (220Ω)
- 16x2 LCD Display (I2C) [optional]
- Custom PCB (designed in Eagle CAD)

## System Functionality
1. Read analog voltage from the potentiometer.
2. Map voltage to water height.
3. Compute segment area and tank volume using trigonometry.
4. Convert volume to liters.
5. Display volume on Serial Monitor.
6. Trigger LEDs based on threshold values.

## Mathematical Model
For a horizontally laid cylindrical tank:

- Segment Area:
- Volume:
- Convert to Litres:


See [`Math/Calculations.pdf`](./Math/Calculations.pdf) for derivations.

## Testing & Results
- Real-time volume displayed via Serial Monitor
- LED indicators respond at:
  - Red: ≤ 1000 L (Empty)
  - Yellow: 1000 L < volume < 2000 L (Refill)
  - Green: ≥ 4500 L (Full)
- LCD display functionality was provisioned but not tested

## Documentation
Detailed report available in [`Documentation/Water_Tank_Arduino_Report.pdf`](./Documentation/Water_Tank_Arduino_Report.pdf).

## License
This project is licensed under the [MIT License](./LICENSE). You are free to use, modify, and distribute it.

---

*Designed with engineering precision and practical application in mind.*
