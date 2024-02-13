
#include <driver/gpio.h>

#include <iostream>
#include <chrono>
#include <thread>

enum class Led {
    Red = GPIO_NUM_45,
    Green = GPIO_NUM_17,
    Blue = GPIO_NUM_46,
    Yellow = GPIO_NUM_15,
};

enum class ButtonPin {
    Left = GPIO_NUM_18,
    Middle = GPIO_NUM_16,
    Right = GPIO_NUM_42,
};

struct Button {
    const ButtonPin pin;
    bool lastState = false;
    bool state = false;

    void init() {
        gpio_config_t io_conf = {
            .pin_bit_mask = 1ULL << static_cast<gpio_num_t>(pin),
            .mode = GPIO_MODE_INPUT,
            .pull_up_en = GPIO_PULLUP_ENABLE,
            .pull_down_en = GPIO_PULLDOWN_DISABLE,
            .intr_type = GPIO_INTR_DISABLE,
        };

        gpio_config(&io_conf);
    }

    bool isPressed() {
        return gpio_get_level(static_cast<gpio_num_t>(pin)) == 0;
    }

    void update() {
        lastState = state;
        state = isPressed();
    }

    bool changed() {
        return lastState != state;
    }

    bool isRisingEdge() {
        return changed() && state == false;
    }

    bool isFallingEdge() {
        return changed() && state == true;
    }

};

void initLeds() {
    gpio_config_t io_conf = {
        .pin_bit_mask = 1ULL << g_ledRed | 1ULL << g_ledGreen | 1ULL << g_ledBlue | 1ULL << g_ledYellow,
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };

    gpio_config(&io_conf);
}

void setLed(Led led, bool on) {
    gpio_set_level(static_cast<gpio_num_t>(led), on);
}

void showOutput(int state) {
    setLed(Led::Red, state == 0);
    setLed(Led::Green, state == 1);
    setLed(Led::Blue, state == 2);
    setLed(Led::Yellow, state == 3);
}

extern "C" void app_main(void) {
    using namespace std::chrono_literals;

    initLeds();

    Button a{ButtonPin::Left};
    Button b{ButtonPin::Middle};
    Button c{ButtonPin::Right};

    a.init();
    b.init();
    c.init();

    int state = 0;
    while (true) {
        state = 0;
        state |= a.isPressed() << 0;
        state |= b.isPressed() << 1;

        showOutput(state);

        std::this_thread::sleep_for(10ms);
    }
}
