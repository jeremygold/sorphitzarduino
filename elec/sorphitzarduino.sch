EESchema Schematic File Version 4
LIBS:sorphitzarduino-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Sorphitzarduino"
Date "2018-11-25"
Rev "1"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:GND #PWR01
U 1 1 5BF9F106
P 7100 4950
F 0 "#PWR01" H 7100 4700 50  0001 C CNN
F 1 "GND" H 7100 4800 50  0000 C CNN
F 2 "" H 7100 4950 50  0000 C CNN
F 3 "" H 7100 4950 50  0000 C CNN
	1    7100 4950
	1    0    0    -1  
$EndComp
$Comp
L sorphitzarduino-rescue:ARDUINO_MICRO_SHIELD-sorphitzarduino-rescue U1
U 1 1 5BF9F1BE
P 5500 2900
F 0 "U1" V 7250 3300 60  0000 C CNN
F 1 "ARDUINO_MICRO_SHIELD" H 6350 3500 60  0000 C CNN
F 2 "arduino_micro_shield:ARDUINO_MICRO_SHIELD" H 5900 2850 60  0001 C CNN
F 3 "" H 5900 2850 60  0000 C CNN
	1    5500 2900
	0    1    1    0   
$EndComp
$Comp
L sorphitzarduino-rescue:CONN_01X02-sorphitzarduino-rescue J1
U 1 1 5BF9F43C
P 8150 3200
F 0 "J1" H 8150 3350 50  0000 C CNN
F 1 "9V_BATT" V 8250 3200 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 8150 3200 50  0001 C CNN
F 3 "" H 8150 3200 50  0000 C CNN
	1    8150 3200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5BF9F4FC
P 7100 3350
F 0 "#PWR02" H 7100 3100 50  0001 C CNN
F 1 "GND" H 7100 3200 50  0000 C CNN
F 2 "" H 7100 3350 50  0000 C CNN
F 3 "" H 7100 3350 50  0000 C CNN
	1    7100 3350
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR03
U 1 1 5BF9F94F
P 6850 4800
F 0 "#PWR03" H 6850 4650 50  0001 C CNN
F 1 "+5V" H 6850 4940 50  0000 C CNN
F 2 "" H 6850 4800 50  0000 C CNN
F 3 "" H 6850 4800 50  0000 C CNN
	1    6850 4800
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR04
U 1 1 5BF9F98F
P 6850 3450
F 0 "#PWR04" H 6850 3300 50  0001 C CNN
F 1 "+5V" H 6850 3590 50  0000 C CNN
F 2 "" H 6850 3450 50  0000 C CNN
F 3 "" H 6850 3450 50  0000 C CNN
	1    6850 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 3450 6850 3450
Wire Wire Line
	7950 3150 7550 3150
Wire Wire Line
	7050 2800 7250 2800
Wire Wire Line
	6650 3250 7100 3250
Wire Wire Line
	7100 3350 7100 3250
Connection ~ 7100 3250
Wire Wire Line
	6850 4800 7050 4800
$Comp
L sorphitzarduino-rescue:CONN_01X02-sorphitzarduino-rescue J2
U 1 1 5BF9FCCD
P 8150 2550
F 0 "J2" H 8150 2700 50  0000 C CNN
F 1 "SWITCH" V 8250 2550 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 8150 2550 50  0001 C CNN
F 3 "" H 8150 2550 50  0000 C CNN
	1    8150 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 2600 7550 2600
Wire Wire Line
	7550 2600 7550 3150
Wire Wire Line
	7950 2500 7400 2500
Wire Wire Line
	7400 2500 7400 2800
Wire Wire Line
	7050 4350 7050 4800
Wire Wire Line
	7050 4350 6650 4350
Connection ~ 7050 4800
Wire Wire Line
	7050 2800 7050 3150
Wire Wire Line
	7050 3150 6650 3150
$Comp
L sorphitzarduino-rescue:CP-Bourne_PTA6043 C1
U 1 1 5BFA0508
P 7250 3000
F 0 "C1" H 7275 3100 50  0000 L CNN
F 1 "10uF" H 7275 2900 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L11_P2" H 7288 2850 50  0001 C CNN
F 3 "" H 7250 3000 50  0000 C CNN
	1    7250 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 2850 7250 2800
Connection ~ 7250 2800
Wire Wire Line
	7250 3150 7250 3250
Connection ~ 7250 3250
$Comp
L sorphitzarduino-rescue:C-Bourne_PTA6043 C2
U 1 1 5BFA0990
P 4050 4600
F 0 "C2" H 4075 4700 50  0000 L CNN
F 1 "4.7nF" H 4075 4500 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D6_P5" H 4088 4450 50  0001 C CNN
F 3 "" H 4050 4600 50  0000 C CNN
	1    4050 4600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5BFA09E9
P 4050 4850
F 0 "#PWR05" H 4050 4600 50  0001 C CNN
F 1 "GND" H 4050 4700 50  0000 C CNN
F 2 "" H 4050 4850 50  0000 C CNN
F 3 "" H 4050 4850 50  0000 C CNN
	1    4050 4850
	1    0    0    -1  
$EndComp
$Comp
L sorphitzarduino-rescue:CONN_01X03-sorphitzarduino-rescue J3
U 1 1 5BFA0BF7
P 3050 4350
F 0 "J3" H 3050 4550 50  0000 C CNN
F 1 "AUDIO_JACK" V 3150 4350 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03" H 3050 4350 50  0001 C CNN
F 3 "" H 3050 4350 50  0000 C CNN
	1    3050 4350
	-1   0    0    1   
$EndComp
Wire Wire Line
	3850 4200 4050 4200
Wire Wire Line
	3250 4450 3850 4450
Wire Wire Line
	3850 4450 3850 4800
Wire Wire Line
	3850 4800 4050 4800
Connection ~ 4050 4800
$Comp
L sorphitzarduino-rescue:LED-Bourne_PTA6043 D1
U 1 1 5BFA0F30
P 4900 5150
F 0 "D1" H 4900 5250 50  0000 C CNN
F 1 "LED" H 4900 5050 50  0000 C CNN
F 2 "LEDs:LED-5MM" H 4900 5150 50  0001 C CNN
F 3 "" H 4900 5150 50  0000 C CNN
	1    4900 5150
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR06
U 1 1 5BFA10FE
P 4900 5850
F 0 "#PWR06" H 4900 5600 50  0001 C CNN
F 1 "GND" H 4900 5700 50  0000 C CNN
F 2 "" H 4900 5850 50  0000 C CNN
F 3 "" H 4900 5850 50  0000 C CNN
	1    4900 5850
	1    0    0    -1  
$EndComp
$Comp
L sorphitzarduino-rescue:R-Bourne_PTA6043 R4
U 1 1 5BFA11AE
P 4900 5600
F 0 "R4" V 4980 5600 50  0000 C CNN
F 1 "290" V 4900 5600 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 4830 5600 50  0001 C CNN
F 3 "" H 4900 5600 50  0000 C CNN
	1    4900 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 5350 4900 5450
Wire Wire Line
	4900 5750 4900 5850
Text Notes 4700 6200 0    60   ~ 0
POWER_LED
$Comp
L sorphitzarduino-rescue:Bourne_Slider-Bourne_PTA6043 RV1
U 1 1 5BFA5669
P 7750 4600
F 0 "RV1" H 7750 4400 60  0000 C CNN
F 1 "10k" H 7750 4500 60  0000 C CNN
F 2 "Bourne_PTA6043:Bourne PTA6043" V 7700 4450 60  0001 C CNN
F 3 "" V 7700 4450 60  0000 C CNN
	1    7750 4600
	1    0    0    -1  
$EndComp
$Comp
L sorphitzarduino-rescue:Bourne_Slider-Bourne_PTA6043 RV2
U 1 1 5BFA57ED
P 8450 4600
F 0 "RV2" H 8450 4400 60  0000 C CNN
F 1 "10k" H 8450 4500 60  0000 C CNN
F 2 "Bourne_PTA6043:Bourne PTA6043" V 8400 4450 60  0001 C CNN
F 3 "" V 8400 4450 60  0000 C CNN
	1    8450 4600
	1    0    0    -1  
$EndComp
$Comp
L sorphitzarduino-rescue:Bourne_Slider-Bourne_PTA6043 RV3
U 1 1 5BFA5836
P 9150 4600
F 0 "RV3" H 9150 4400 60  0000 C CNN
F 1 "10k" H 9150 4500 60  0000 C CNN
F 2 "Bourne_PTA6043:Bourne PTA6043" V 9100 4450 60  0001 C CNN
F 3 "" V 9100 4450 60  0000 C CNN
	1    9150 4600
	1    0    0    -1  
$EndComp
$Comp
L sorphitzarduino-rescue:Bourne_Slider-Bourne_PTA6043 RV4
U 1 1 5BFA58DD
P 9850 4600
F 0 "RV4" H 9850 4400 60  0000 C CNN
F 1 "10k" H 9850 4500 60  0000 C CNN
F 2 "Bourne_PTA6043:Bourne PTA6043" V 9800 4450 60  0001 C CNN
F 3 "" V 9800 4450 60  0000 C CNN
	1    9850 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 4350 7750 4250
Wire Wire Line
	7750 4250 6650 4250
Wire Wire Line
	8450 4350 8450 4150
Wire Wire Line
	8450 4150 6650 4150
Wire Wire Line
	9150 4350 9150 4050
Wire Wire Line
	9150 4050 6650 4050
Wire Wire Line
	9850 4350 9850 3950
Wire Wire Line
	9850 3950 6650 3950
Wire Wire Line
	7100 4950 8000 4950
Wire Wire Line
	10100 4950 10100 4600
Wire Wire Line
	9400 4600 9400 4950
Connection ~ 9400 4950
Wire Wire Line
	8700 4600 8700 4950
Connection ~ 8700 4950
Wire Wire Line
	8000 4600 8000 4950
Connection ~ 8000 4950
Wire Wire Line
	7050 4900 7500 4900
Wire Wire Line
	9600 4900 9600 4600
Wire Wire Line
	8900 4600 8900 4900
Connection ~ 8900 4900
Wire Wire Line
	8200 4600 8200 4900
Connection ~ 8200 4900
Wire Wire Line
	7500 4600 7500 4900
Connection ~ 7500 4900
$Comp
L power:GND #PWR07
U 1 1 5BFA60DB
P 4950 3500
F 0 "#PWR07" H 4950 3250 50  0001 C CNN
F 1 "GND" H 4950 3350 50  0000 C CNN
F 2 "" H 4950 3500 50  0000 C CNN
F 3 "" H 4950 3500 50  0000 C CNN
	1    4950 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 3450 4950 3450
Wire Wire Line
	4950 3450 4950 3500
Wire Wire Line
	5300 4450 4900 4450
Wire Wire Line
	4900 4450 4900 4950
$Comp
L sorphitzarduino-rescue:R-Bourne_PTA6043 R1
U 1 1 5BFA081C
P 4500 4200
F 0 "R1" V 4580 4200 50  0000 C CNN
F 1 "3.9k" V 4500 4200 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 4430 4200 50  0001 C CNN
F 3 "" H 4500 4200 50  0000 C CNN
	1    4500 4200
	0    1    1    0   
$EndComp
$Comp
L sorphitzarduino-rescue:R-Bourne_PTA6043 R2
U 1 1 5C037AD8
P 4500 4350
F 0 "R2" V 4580 4350 50  0000 C CNN
F 1 "1M" V 4500 4350 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 4430 4350 50  0001 C CNN
F 3 "" H 4500 4350 50  0000 C CNN
	1    4500 4350
	0    1    1    0   
$EndComp
$Comp
L sorphitzarduino-rescue:R-Bourne_PTA6043 R3
U 1 1 5C037B46
P 4500 4500
F 0 "R3" V 4580 4500 50  0000 C CNN
F 1 "1M" V 4500 4500 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 4430 4500 50  0001 C CNN
F 3 "" H 4500 4500 50  0000 C CNN
	1    4500 4500
	0    1    1    0   
$EndComp
Wire Wire Line
	5300 4350 4650 4350
Wire Wire Line
	4650 4350 4650 4500
Wire Wire Line
	4050 4200 4050 4350
Wire Wire Line
	4050 4750 4050 4800
Wire Wire Line
	3250 4350 4050 4350
Wire Wire Line
	4350 4350 4350 4500
Wire Wire Line
	4650 4200 4900 4200
Wire Wire Line
	4900 4200 4900 4250
Wire Wire Line
	4900 4250 5300 4250
Connection ~ 4050 4200
Connection ~ 4050 4350
Wire Wire Line
	3250 4250 3850 4250
Wire Wire Line
	3850 4250 3850 4200
Wire Wire Line
	7100 3250 7250 3250
Wire Wire Line
	7050 4800 7050 4900
Wire Wire Line
	7250 2800 7400 2800
Wire Wire Line
	7250 3250 7950 3250
Wire Wire Line
	4050 4800 4050 4850
Wire Wire Line
	9400 4950 10100 4950
Wire Wire Line
	8700 4950 9400 4950
Wire Wire Line
	8000 4950 8700 4950
Wire Wire Line
	8900 4900 9600 4900
Wire Wire Line
	8200 4900 8900 4900
Wire Wire Line
	7500 4900 8200 4900
Wire Wire Line
	4050 4200 4350 4200
Wire Wire Line
	4050 4350 4050 4450
Wire Wire Line
	4050 4350 4350 4350
$Comp
L Connector_Generic:Conn_01x01 J4
U 1 1 5C079185
P 3000 2000
F 0 "J4" H 3079 2042 50  0000 L CNN
F 1 "Mounting Hole" H 3079 1951 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 3000 2000 50  0001 C CNN
F 3 "~" H 3000 2000 50  0001 C CNN
	1    3000 2000
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J?
U 1 1 5C07ACAF
P 3000 2250
F 0 "J?" H 3079 2292 50  0000 L CNN
F 1 "Mounting Hole" H 3079 2201 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 3000 2250 50  0001 C CNN
F 3 "~" H 3000 2250 50  0001 C CNN
	1    3000 2250
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J?
U 1 1 5C07AD05
P 3000 2450
F 0 "J?" H 3079 2492 50  0000 L CNN
F 1 "Mounting Hole" H 3079 2401 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 3000 2450 50  0001 C CNN
F 3 "~" H 3000 2450 50  0001 C CNN
	1    3000 2450
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J?
U 1 1 5C07AD41
P 3000 2650
F 0 "J?" H 3079 2692 50  0000 L CNN
F 1 "Mounting Hole" H 3079 2601 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 3000 2650 50  0001 C CNN
F 3 "~" H 3000 2650 50  0001 C CNN
	1    3000 2650
	1    0    0    -1  
$EndComp
$EndSCHEMATC
