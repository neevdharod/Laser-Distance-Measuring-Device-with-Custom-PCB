# Lazer
I am using an custom PCB and TF-Luna LiDAR distance sensor to create a mini-remote like device where I can point at something and it will tell me the distance from me (the remote) to the thing the laser hits/distance sensor hits. I will also have a button to change units between inches, feet, cm, meters, etc.
EasyEDA link: https://oshwlab.com/neev.dharod/project_gzbygltd

# CAD
Cad includes a case and the assembly with all the components
Onshape Link: https://cad.onshape.com/documents/f80bec2007e088d53cc4834f/w/b8e88e60027bd973f5c0f030/e/42a9ab1853702a9d150cec3e?renderMode=0&uiState=6a29a9b1212ee6bf563aff10

<img src="https://cdn.hackclub.com/019eb2bd-9743-7b35-a0be-08274caf9515/Screenshot%202026-06-10%2011.12.13%20AM.png" alt="image"/>

# PCB
<img src="https://cdn.hackclub.com/019eaf57-ab8f-7ddb-bbdb-af7e37aa1d20/third.png" alt="image"/>

<img src="https://cdn.hackclub.com/019eaf57-1f73-725e-a29b-83fa8442b77d/second.png" alt="image"/>

<img src="https://cdn.hackclub.com/019eaf57-dd29-7241-a01a-d3114ac259ec/fourth.png" alt="image"/>

# Electronic Schematic

<img src="https://cdn.hackclub.com/019ea96a-e71e-71b5-bf03-a1bb8c2f093d/Screenshot%202026-06-08%2012.53.35%20PM.png" alt="image"/>

Video:  https://drive.google.com/file/d/1bs6KxktJZmoDuON8fRyiX__gwQNDUmAN/view?usp=sharing

# Why/How

I created this project to learn more about PCBs, soldering, and using new sensors like a lidar sensor, as well as simple buttons and a screen. This project just seemed like a cool idea in my head, so I decided to create it.

I will create this project in a few steps:
1. order the parts
2. Use the components on a breadboard, and use a simple program for testing to see if the components work
3. Solder the components onto the PCB and do the same test there
4. Create a final program that does everything and upload it on.
5. Use digital caliper to make sure my measurements in CAD are correct and then print the CAD out.
6. Final assembly and finished product

# Challenges
Some challenges I might face when creating this project is if my PCB for some reason does not work due to some wiring concerns or other things. Additionally, there could be an issue with the CAD case, which is why I am using a digital caliper to make sure that wont cause major issues. 

# Key Features
- Custom PCB
- TF-Luna LiDAR sensor for 8m of range
- 2 buttons
- Mini OLED screen

# BOM

| Part                                 | Qty    | Link                             | Cost   |
|--------------------------------------|--------|----------------------------------|--------|
| TF-Luna LiDAR sensor                 | 1      | AliExpress TF-Luna 8m LiDAR      | $18.30 |
| Seeed XIAO ESP32S3                   | 1      | AliExpress XIAO ESP32S3          | $15.07 |
| 0.96"" SSD1306 I2C OLED              | 1      | AliExpress 0.96 inch OLED        | $2.61  |
| 12mm momentary push buttons          | 1 pack | AliExpress 12mm push buttons     | $3.00  |
| JST PH 2.0 2-pin connector kit       | 1 pack | AliExpress JST PH 2.0 kit        | $1.84  |
| SS12D00G3 slide switch               | 1 pack | AliExpress SS12D00G3 switch      | $0.91  |
| 3.7V 500mAh LiPo battery with JST PH | 1      | AliExpress 3.7V 500mAh LiPo      | $4.00  |
| 2.54mm pin header kit                | 1 kit  | AliExpress 2.54mm pin header kit | $4.00  |
| Dupont jumper wire kit               | 1 kit  | AliExpress jumper wires          | $2.74  |
| Custom PCB                           |        | JLCPCB                           | $9.50  |
|                                      |        | total                            | $59.60 |

