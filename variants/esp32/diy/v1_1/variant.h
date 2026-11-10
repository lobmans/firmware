#ifndef _VARIANT_DIY_V1_1_
#define _VARIANT_DIY_V1_1_

// ====================================================================
// ИНТЕРФЕЙС И КНОПКИ
// ====================================================================
#define BUTTON_PIN 2              // Кнопка управления нодой
#define BUTTON_NEED_PULLUP
#define EXT_NOTIFY_OUT 12         // Пин для модулей уведомлений

// ====================================================================
// ШИНА SPI (Контроллер ESP32)
// ====================================================================
#undef LORA_SCK
#define LORA_SCK 5                // Тактовый сигнал (SCK)
#undef LORA_MISO
#define LORA_MISO 19              // Вход данных (MISO)
#undef LORA_MOSI
#define LORA_MOSI 27              // Выход данных (MOSI)
#undef LORA_CS
#define LORA_CS 21                // Выбор чипа (NSS) модуля RF96

// ====================================================================
// УДАЛЕНИЕ ОШИБКИ IO 255 (Обман ядра через безопасный пин)
// ====================================================================
#define LORA_DIO0 4               // Ваш белый провод на GPIO 4
#define LORA_RESET 18             // Линия сброса через дорожку платы

#define LORA_DIO1 -1              
#define LORA_DIO2 -1              
#define LORA_DIO3 -1

// Назначаем виртуальное управление на неиспользуемый GPIO 9 (вместо -1/255)
#undef LORA_RXEN
#define LORA_RXEN 9              
#undef LORA_TXEN
#define LORA_TXEN 9              

// Маппинг для RadioLib (теперь digitalWrite(9) пройдет без ошибок periman)
#define RF95_DIO1 -1
#define RF95_TXEN LORA_TXEN        
#define RF95_RXEN LORA_RXEN               

// Принудительно включаем аппаратный автомат чипа (он работает сам под капотом)
#define RADIOLIB_AUTOMATIC_DIO2_TX_SWITCH

               

// ====================================================================
// АКТИВНЫЙ ДРАЙВЕР РАДИОМОДУЛЯ
// ====================================================================
#define USE_RF95                  // Включаем драйвер только для серии SX127x (RF96)

// Принудительно глушим макросы SX126X во избежание коллизий
#undef SX126X_CS
#define SX126X_CS -1
#undef SX126X_DIO1
#define SX126X_DIO1 -1
#undef SX126X_RESET
#define SX126X_RESET -1

// Полностью деактивируем компиляцию кода для SX126X/LLCC68
#undef USE_SX1262
#undef USE_SX1268
#undef USE_LLCC68

// ====================================================================
// ОТКЛЮЧЕНИЕ НЕИСПОЛЬЗУЕМОГО ОБОРУДОВАНИЯ (GPS И ДИСПЛЕЙ)
// ====================================================================
#undef GPS_RX_PIN                 
#undef GPS_TX_PIN
#define HAS_GPS 0                 

#undef HAS_DISPLAY
#define HAS_DISPLAY 0             

#endif /* _VARIANT_DIY_V1_1_ */
