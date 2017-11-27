EESchema Schematic File Version 2
LIBS:ArduProMiniTKB
LIBS:freetronics_schematic
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:FRTOSlight-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Q_NMOS_GSD Q2
U 1 1 5A1AC65F
P 10250 2000
F 0 "Q2" H 10550 2050 50  0000 R CNN
F 1 "si2302" H 10700 1950 50  0000 R CNN
F 2 "FRTOSlight:SOT23-3" H 10450 2100 50  0001 C CNN
F 3 "" H 10250 2000 50  0000 C CNN
	1    10250 2000
	1    0    0    -1  
$EndComp
$Comp
L Q_NMOS_GSD Q1
U 1 1 5A1AC72E
P 8250 2000
F 0 "Q1" H 8550 2050 50  0000 R CNN
F 1 "si2302" H 8700 1950 50  0000 R CNN
F 2 "FRTOSlight:SOT23-3" H 8450 2100 50  0001 C CNN
F 3 "" H 8250 2000 50  0000 C CNN
	1    8250 2000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 5A1AC783
P 10350 2550
F 0 "#PWR01" H 10350 2300 50  0001 C CNN
F 1 "GND" H 10350 2400 50  0000 C CNN
F 2 "" H 10350 2550 50  0000 C CNN
F 3 "" H 10350 2550 50  0000 C CNN
	1    10350 2550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 5A1AC7A9
P 8350 2550
F 0 "#PWR02" H 8350 2300 50  0001 C CNN
F 1 "GND" H 8350 2400 50  0000 C CNN
F 2 "" H 8350 2550 50  0000 C CNN
F 3 "" H 8350 2550 50  0000 C CNN
	1    8350 2550
	1    0    0    -1  
$EndComp
$Comp
L R_Small R5
U 1 1 5A1AC80F
P 9800 2300
F 0 "R5" H 9830 2320 50  0000 L CNN
F 1 "4k7" H 9830 2260 50  0000 L CNN
F 2 "FRTOSlight:1206" H 9800 2300 50  0001 C CNN
F 3 "" H 9800 2300 50  0000 C CNN
	1    9800 2300
	1    0    0    -1  
$EndComp
$Comp
L R_Small R4
U 1 1 5A1AC842
P 9600 2000
F 0 "R4" H 9630 2020 50  0000 L CNN
F 1 "180" H 9630 1960 50  0000 L CNN
F 2 "FRTOSlight:0805" H 9600 2000 50  0001 C CNN
F 3 "" H 9600 2000 50  0000 C CNN
	1    9600 2000
	0    1    1    0   
$EndComp
$Comp
L R_Small R3
U 1 1 5A1AC881
P 7650 2300
F 0 "R3" H 7680 2320 50  0000 L CNN
F 1 "4k7" H 7680 2260 50  0000 L CNN
F 2 "FRTOSlight:1206" H 7650 2300 50  0001 C CNN
F 3 "" H 7650 2300 50  0000 C CNN
	1    7650 2300
	1    0    0    -1  
$EndComp
$Comp
L R_Small R2
U 1 1 5A1AC8C2
P 7450 2000
F 0 "R2" H 7480 2020 50  0000 L CNN
F 1 "180" H 7480 1960 50  0000 L CNN
F 2 "FRTOSlight:0805" H 7450 2000 50  0001 C CNN
F 3 "" H 7450 2000 50  0000 C CNN
	1    7450 2000
	0    1    1    0   
$EndComp
Text Label 6700 2000 0    60   ~ 0
LED_WIDE_PWM
Text Label 8750 2000 0    60   ~ 0
LED_SPOT_PWM
$Comp
L CONN_01X05 P1
U 1 1 5A1ACA67
P 6300 1100
F 0 "P1" H 6300 1400 50  0000 C CNN
F 1 "CONN_01X05" V 6400 1100 50  0000 C CNN
F 2 "FRTOSlight:1X05" H 6300 1100 50  0001 C CNN
F 3 "" H 6300 1100 50  0000 C CNN
	1    6300 1100
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 P2
U 1 1 5A1ACCD9
P 6300 1900
F 0 "P2" H 6300 2100 50  0000 C CNN
F 1 "CONN_01X03" V 6400 1900 50  0000 C CNN
F 2 "FRTOSlight:1X03" H 6300 1900 50  0001 C CNN
F 3 "" H 6300 1900 50  0000 C CNN
	1    6300 1900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 5A1ACD9C
P 6000 2150
F 0 "#PWR03" H 6000 1900 50  0001 C CNN
F 1 "GND" H 6000 2000 50  0000 C CNN
F 2 "" H 6000 2150 50  0000 C CNN
F 3 "" H 6000 2150 50  0000 C CNN
	1    6000 2150
	1    0    0    -1  
$EndComp
Text Label 5250 1800 0    60   ~ 0
BATERIA_3_7_V
Text Label 5250 1900 0    60   ~ 0
BATERIA_7_4_V
Text Label 5250 1300 0    60   ~ 0
BATERIA_3_7_V
Text Label 5250 1200 0    60   ~ 0
BATERIA_7_4_V
Text Label 5250 1100 0    60   ~ 0
SENSOR
Text Label 5250 1000 0    60   ~ 0
LED_SPOT-
Text Label 5250 900  0    60   ~ 0
LED_WIDE-
Text Label 8500 1450 0    60   ~ 0
LED_WIDE-
Text Label 10450 1450 0    60   ~ 0
LED_SPOT-
$Comp
L R_Small R6
U 1 1 5A1AD59B
P 10350 4150
F 0 "R6" H 10380 4170 50  0000 L CNN
F 1 "10k" H 10380 4110 50  0000 L CNN
F 2 "FRTOSlight:1206" H 10350 4150 50  0001 C CNN
F 3 "" H 10350 4150 50  0000 C CNN
	1    10350 4150
	1    0    0    -1  
$EndComp
Text Label 10450 3700 0    60   ~ 0
SENSOR
$Comp
L GND #PWR04
U 1 1 5A1AD684
P 10350 4500
F 0 "#PWR04" H 10350 4250 50  0001 C CNN
F 1 "GND" H 10350 4350 50  0000 C CNN
F 2 "" H 10350 4500 50  0000 C CNN
F 3 "" H 10350 4500 50  0000 C CNN
	1    10350 4500
	1    0    0    -1  
$EndComp
Text Label 9850 3950 0    60   ~ 0
AD0
Text Label 3550 2550 0    60   ~ 0
AD0
Text Label 3550 2950 0    60   ~ 0
LED_WIDE_PWM
Text Label 1200 2950 0    60   ~ 0
LED_SPOT_PWM
Text Label 3550 1850 0    60   ~ 0
BATERIA_7_4_V
$Comp
L CONN_01X04 P3
U 1 1 5A1AE117
P 6300 3000
F 0 "P3" H 6300 3250 50  0000 C CNN
F 1 "CONN_01X04" V 6400 3000 50  0000 C CNN
F 2 "FRTOSlight:1X04" H 6300 3000 50  0001 C CNN
F 3 "" H 6300 3000 50  0000 C CNN
	1    6300 3000
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR05
U 1 1 5A1AE1B3
P 5800 2750
F 0 "#PWR05" H 5800 2600 50  0001 C CNN
F 1 "VCC" H 5800 2900 50  0000 C CNN
F 2 "" H 5800 2750 50  0000 C CNN
F 3 "" H 5800 2750 50  0000 C CNN
	1    5800 2750
	1    0    0    -1  
$EndComp
Text Label 1850 1850 0    60   ~ 0
TX
Text Label 1850 1950 0    60   ~ 0
RX
Text Label 1850 2050 0    60   ~ 0
RST
Wire Wire Line
	8350 2200 8350 2550
Wire Wire Line
	10350 2200 10350 2550
Wire Wire Line
	7550 2000 8050 2000
Wire Wire Line
	7650 2200 7650 2000
Connection ~ 7650 2000
Wire Wire Line
	7650 2400 7650 2500
Wire Wire Line
	7650 2500 8350 2500
Connection ~ 8350 2500
Wire Wire Line
	9800 2400 9800 2500
Wire Wire Line
	9800 2500 10350 2500
Connection ~ 10350 2500
Wire Wire Line
	9700 2000 10050 2000
Wire Wire Line
	9800 2000 9800 2200
Connection ~ 9800 2000
Wire Wire Line
	8750 2000 9500 2000
Wire Wire Line
	6700 2000 7350 2000
Wire Wire Line
	6100 900  5250 900 
Wire Wire Line
	5250 1000 6100 1000
Wire Wire Line
	6100 1100 5250 1100
Wire Wire Line
	5250 1200 6100 1200
Wire Wire Line
	5250 1300 6100 1300
Wire Wire Line
	8350 1800 8350 1450
Wire Wire Line
	10350 1800 10350 1450
Wire Wire Line
	6100 1800 5250 1800
Wire Wire Line
	6100 1900 5250 1900
Wire Wire Line
	6100 2000 6000 2000
Wire Wire Line
	6000 2000 6000 2150
Wire Wire Line
	8350 1450 8500 1450
Wire Wire Line
	10350 1450 10450 1450
Wire Wire Line
	10350 3700 10350 4050
Wire Wire Line
	10350 3700 10450 3700
Wire Wire Line
	10350 4250 10350 4500
Wire Wire Line
	10350 3950 9850 3950
Connection ~ 10350 3950
Wire Wire Line
	3250 2550 3550 2550
Wire Wire Line
	3250 2950 3550 2950
Wire Wire Line
	1200 2950 2050 2950
Wire Wire Line
	3250 1850 3550 1850
Wire Wire Line
	6100 2850 5800 2850
Wire Wire Line
	5800 2850 5800 2750
Wire Wire Line
	2050 1850 1850 1850
Wire Wire Line
	1850 1950 2050 1950
Wire Wire Line
	1850 2050 2050 2050
Wire Wire Line
	6100 2950 5800 2950
Wire Wire Line
	5800 3050 6100 3050
Wire Wire Line
	5800 3150 6100 3150
Text Label 5800 2950 0    60   ~ 0
LED_G
Text Label 5800 3050 0    60   ~ 0
LED_R
Text Label 5800 3150 0    60   ~ 0
LED_B
Wire Wire Line
	2050 2550 1700 2550
Wire Wire Line
	1700 2650 2050 2650
Text Label 1700 2550 0    60   ~ 0
LED_B
Text Label 1700 2650 0    60   ~ 0
LED_G
Wire Wire Line
	3250 1950 3950 1950
Wire Wire Line
	3950 1950 3950 2050
$Comp
L GND #PWR06
U 1 1 5A1AF4A6
P 3950 2050
F 0 "#PWR06" H 3950 1800 50  0001 C CNN
F 1 "GND" H 3950 1900 50  0000 C CNN
F 2 "" H 3950 2050 50  0000 C CNN
F 3 "" H 3950 2050 50  0000 C CNN
	1    3950 2050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 5A1AF52A
P 1350 2250
F 0 "#PWR07" H 1350 2000 50  0001 C CNN
F 1 "GND" H 1350 2100 50  0000 C CNN
F 2 "" H 1350 2250 50  0000 C CNN
F 3 "" H 1350 2250 50  0000 C CNN
	1    1350 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 2150 2050 2150
Wire Wire Line
	1350 2250 1350 2150
Wire Wire Line
	3250 2850 3550 2850
Text Label 3550 2850 0    60   ~ 0
MODE_BUTTON
$Comp
L SW_PUSHBUTTON SW1
U 1 1 5A1AF85E
P 1050 4800
F 0 "SW1" H 900 4910 50  0000 C CNN
F 1 "SW_PUSHBUTTON" H 1050 4720 50  0000 C CNN
F 2 "FRTOSlight:SW_PUSHBUTTON_PTH" H 1050 4800 60  0001 C CNN
F 3 "" H 1050 4800 60  0000 C CNN
	1    1050 4800
	0    1    1    0   
$EndComp
$Comp
L R R1
U 1 1 5A1AF9C8
P 1050 3900
F 0 "R1" V 1130 3900 50  0000 C CNN
F 1 "R" V 1050 3900 50  0000 C CNN
F 2 "FRTOSlight:1206" H 1050 3900 60  0001 C CNN
F 3 "" H 1050 3900 60  0000 C CNN
	1    1050 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 4150 1050 4500
Wire Wire Line
	1050 5100 1050 5300
Wire Wire Line
	1050 3650 1050 3500
$Comp
L VCC #PWR08
U 1 1 5A1AFCBA
P 1050 3500
F 0 "#PWR08" H 1050 3350 50  0001 C CNN
F 1 "VCC" H 1050 3650 50  0000 C CNN
F 2 "" H 1050 3500 50  0000 C CNN
F 3 "" H 1050 3500 50  0000 C CNN
	1    1050 3500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 5A1AFD7E
P 1050 5300
F 0 "#PWR09" H 1050 5050 50  0001 C CNN
F 1 "GND" H 1050 5150 50  0000 C CNN
F 2 "" H 1050 5300 50  0000 C CNN
F 3 "" H 1050 5300 50  0000 C CNN
	1    1050 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 4350 1400 4350
Connection ~ 1050 4350
Text Label 1400 4350 0    60   ~ 0
MODE_BUTTON
Wire Wire Line
	3250 2450 3550 2450
Text Label 3550 2450 0    60   ~ 0
BATERIA_3_7_V
$Comp
L ARDUPROMINI-6 uP1
U 1 1 5A1AED2F
P 3250 750
F 0 "uP1" H 3150 550 60  0000 C CNN
F 1 "ARDUPROMINI-6" H 2650 200 60  0000 C CNN
F 2 "ArduProMiniTKB:ArduProMini-6" H 3250 750 60  0001 C CNN
F 3 "" H 3250 750 60  0000 C CNN
	1    3250 750 
	1    0    0    -1  
$EndComp
$EndSCHEMATC