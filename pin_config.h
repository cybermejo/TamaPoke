#pragma once

// Pines oficiales de la Waveshare ESP32-S3-Touch-AMOLED-1.8
// Fuente: github.com/waveshareteam/ESP32-S3-Touch-AMOLED-1.8
// (examples/arduino-v2/libraries/Mylibrary/pin_config.h para la V2,
//  examples/arduino/libraries/Mylibrary/pin_config.h para la V1).
// Ambas revisiones comparten pines; solo cambian driver de pantalla y tactil:
//   V1 (hasta 05/2026): SH8601 + FT3168 (tactil en 0x38)
//   V2 (desde 05/2026): CO5300 + CST820 (tactil en 0x15) <- revision actual
//
// El firmware detecta la revision solo, al arrancar, por la direccion I2C del
// tactil (igual que el proyecto esp32-fluid-cube): no hay que configurar nada.

#define XPOWERS_CHIP_AXP2101

// Pantalla AMOLED 368x448 por QSPI (sin pin RST dedicado: el reset lo hace el
// expansor XCA9554; ver setup() en TamaPoke.ino)
#define LCD_SDIO0 4
#define LCD_SDIO1 5
#define LCD_SDIO2 6
#define LCD_SDIO3 7
#define LCD_SCLK 11
#define LCD_CS 12
#define LCD_WIDTH 368
#define LCD_HEIGHT 448

// Táctil capacitivo por I2C (V2: CST820, V1: FT3168; ambos en 0xxx segun
// libreria Arduino_DriveBus)
#define IIC_SDA 15
#define IIC_SCL 14
#define TP_INT 21

// Expansor GPIO XCA9554 (0x20): resetea LCD/tactil y alimenta la SD
#define EXPANDER_ADDR 0x20

// Audio ES8311 (MCLK en GPIO16 en la 1.8; en la 1.75 era GPIO42).
// El codec se configura con reloj derivado del BCLK, asi que el MCLK apenas
// importa, pero el pin debe ser el correcto para I2S.
#define I2S_MCK_IO 16
#define I2S_BCK_IO 9
#define I2S_DI_IO 10
#define I2S_WS_IO 45
#define I2S_DO_IO 8
#define PA 46

// Ranura TF (no usada todavía)
#define SDMMC_CLK 2
#define SDMMC_CMD 1
#define SDMMC_DATA 3
