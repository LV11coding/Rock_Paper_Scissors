// WP - Wired Pin       --- this is the absolute pin number
// DP - Digital Pin
// AP - Analog Pin

#define WP00 (0)
#define DP00 WP00
#define RX0 WP00 
#define RX_USB_PIN WP00 

#define WP01 (1)
#define DP01 WP01
#define TX0 WP01
#define TX_USB_PIN WP01

#define WP02 (2)
#define DP02 WP02   // PWM

#define WP03 (3)
#define DP03 WP03   // PWM

#define WP04 (4)
#define DP04 WP04   // PWM

#define WP05 (5)
#define DP05 WP05   // PWM

#define WP06 (6)
#define DP06 WP06   // PWM

#define WP07 (7)
#define DP07 WP07   // PWM

#define WP08 (8)
#define DP08 WP08   // PWM

#define WP09 (9)
#define DP09 WP09   // PWM

#define WP10 (10)
#define DP10 WP10   // PWM

#define WP11 (11)
#define DP11 WP11   // PWM

#define WP12 (12)
#define DP12 WP12   // PWM
#define BUZZER_PIN WP12

#define WP13 (13)
#define DP13 WP13   // PWM

#define WP14 (14)
#define DP14 WP14
#define TX3 WP14
#define TX_NEXTION_PIN WP14

#define WP15 (15)
#define DP15 WP15
#define RX3 WP15 
#define RX_NEXTION_PIN WP15 

#define WP16 (16)
#define DP16 WP16
#define TX2 WP16
#define TX_HC12_PIN WP16 // HC-12 WiFi

#define WP17 (17)
#define DP17 WP17
#define RX2 WP17
#define RX_HC12_PIN WP17 // HC-12 WiFi

#define WP18 (18)
#define DP18 WP18
#define TX1 WP18
#define TX_BLUETOOTH_PIN WP18

#define WP19 (19)
#define DP19 WP19
#define RX1 WP19
#define RX_BLUETOOTH_PIN WP19

#define WP20 (20)
#define DP20 WP20
#define SDA_I2C_MUX_PIN WP20
// #define SDA WP20 // Already used name in other header

#define WP21 (21)
#define DP21 WP21
#define SCL_I2C_MUX_PIN WP21
// #define SCL WP21 // Already used name in other header

#define WP22 (22)
#define DP22 WP22
#define DHT11_PIN WP22

#define WP23 (23)
#define DP23 WP23
#define TOUCH_PIN WP23

#define WP24 (24) 
#define DP24 WP24
#define RGB_LED_MATRIX_PIN WP24

#define WP25 (25)
#define DP25 WP25
#define PIR_SENSOR_PIN WP25 // IR light difference detection - digital value 0/1

#define WP26 (26)
#define DP26 WP26
#define BIG_BUTTON_PIN WP26

#define WP27 (27)
#define DP27 WP27

#define WP28 (28)
#define DP28 WP28
#define BLUE_LED_PIN WP28

#define WP29 (29)
#define DP29 WP29

#define WP30 (30)
#define DP30 WP30
#define GREEN_LED_PIN WP30

#define WP31 (31)
#define DP31 WP31
#define SS_RELAY_PIN WP31 // Solid State Relay

#define WP32 (32)
#define DP32 WP32
#define SERVO1_PIN WP32

#define WP33 (33)
#define DP33 WP33
#define RED_LED_PIN WP33

#define WP34 (34)
#define DP34 WP34
#define SERVO2_PIN WP34

#define WP35 (35)
#define DP35 WP35
#define DIP1_PIN WP35

#define WP36 (36)
#define DP36 WP36
#define SERVO3_PIN WP36

#define WP37 (37)
#define DP37 WP37
#define DIP2_PIN WP37

#define WP38 (38)
#define DP38 WP38
#define JOYSTICK_BTN_PIN WP38

#define WP39 (39)
#define DP39 WP39
#define DIP3_PIN WP39

#define WP40 (40)
#define DP40 WP40
#define DS18B20_T_PIN WP40 // Temperature sensor analog pin

#define WP41 (41)
#define DP41 WP41
#define DIP4_PIN WP41

#define WP42 (42)
#define DP42 WP42

#define WP43 (43)
#define DP43 WP43

#define WP44 (44)
#define DP44 WP44   // PWM
#define SEGMENT_DISPLAY_CLK_PIN WP44

#define WP45 (45)
#define DP45 WP45   // PWM
#define ULTRASOUND_ECHO_PIN WP45   // Input signal HC-SR04 Ultrasound sensor


#define WP46 (46)
#define DP46 WP46   // PWM
#define SEGMENT_DISPLAY_DIO_PIN WP46

#define WP47 (47)
#define DP47 WP47
#define SET_HC12_PIN WP47 // HC-12 WiFi

#define WP48 (48)
#define DP48 WP48

#define WP49 (49)
#define DP49 WP49
#define ULTRASOUND_TRIG_PIN WP49 // Output signal HC-SR04 Ultrasound sensor

#define WP50 (50)
#define DP50 WP50
#define MICRO_SD_MISO_PIN WP50
// #define SPI_MISO WP50

#define WP51 (51)
#define DP51 WP51
#define MICRO_SD_MOSI_PIN WP51
// #define SPI_MOSI WP51

#define WP52 (52)
#define DP52 WP52
#define MICRO_SD_SCK_PIN WP52
// #define SPI_SCK WP52

#define WP53 (53)
#define DP53 WP53
#define MICRO_SD_CS_PIN WP53
// #define SPI_SS WP53

/*
#define WPIN_A0   (54)
#define WPIN_A1   (55)
#define WPIN_A2   (56)
#define WPIN_A3   (57)
#define WPIN_A4   (58)
#define WPIN_A5   (59)
#define WPIN_A6   (60)
#define WPIN_A7   (61)
#define WPIN_A8   (62)
#define WPIN_A9   (63)
#define WPIN_A10  (64)
#define WPIN_A11  (65)
#define WPIN_A12  (66)
#define WPIN_A13  (67)
#define WPIN_A14  (68)
#define WPIN_A15  (69)
*/
#define WP54 (54)
#define AP00 WP54

#define WP55 (55)
#define AP01 WP55
#define ML8511_UV_SENSOR_PIN WP55

#define WP56 (56)
#define AP02 WP56

#define WP57 (57)
#define AP03 WP57
#define ML8511_UV_SENSOR_REF_PIN WP57

#define WP58 (58)
#define AP04 WP58

#define WP59 (59)
#define AP05 WP59
#define JOYSTICK_Y_PIN WP59

#define WP60 (60)
#define AP06 WP60

#define WP61 (61)
#define AP07 WP61
#define JOYSTICK_X_PIN WP61

#define WP62 (62)
#define AP08 WP62

#define WP63 (63)
#define AP09 WP63
#define TRIMMER_PIN WP63

#define WP64 (64)
#define AP10 WP64

#define WP65 (65)
#define AP11 WP65
#define LIGHT_SENSOR_TEMT_6000_PIN WP65

#define WP66 (66)
#define AP12 WP66

#define WP67 (67)
#define AP13 WP67
#define TMP36_T_SENSOR_PIN WP67

#define WP68 (68)
#define AP14 WP68

#define WP69 (69)
#define AP15 WP69
#define LIGHT_SENSOR_LDR_PIN WP69