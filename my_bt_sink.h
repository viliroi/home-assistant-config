#include "esphome.h"
#include "BluetoothA2DPSink.h"

class MyBTSink : public Component {
 public:
  void setup() override {
    // Инициализация здесь, если нужно
  }
  void loop() override {
    // Можно оставить пустым
  }
  void start_sink() {
    static i2s_pin_config_t pin_config = {
        .bck_io_num = 14,  // Ваш BCLK пин (GPIO14)
        .ws_io_num = 13,   // Ваш LRCLK пин (GPIO13)
        .data_out_num = 15,// Ваш DOUT пин (GPIO15)
        .data_in_num = I2S_PIN_NO_CHANGE
    };
    a2dp_sink.set_pin_config(pin_config);
    a2dp_sink.start("Smart Speaker S3 Ultra"); // Имя Bluetooth-устройства
  }
  void stop_sink() {
    a2dp_sink.end();
  }
 private:
  BluetoothA2DPSink a2dp_sink;
};