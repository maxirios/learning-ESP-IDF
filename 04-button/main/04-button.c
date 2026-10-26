#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define BUTTON_GPIO 0

static const char *TAG = "button";

void app_main(void)
{
	gpio_config_t io_conf = {
		.pin_bit_mask = 1ULL << BUTTON_GPIO,
		.mode = GPIO_MODE_INPUT,
		.pull_up_en = GPIO_PULLUP_ENABLE,
	};
	gpio_config(&io_conf);

	while (1) {
		int level = gpio_get_level(BUTTON_GPIO);
		ESP_LOGI(TAG, "button = %d", level);
		vTaskDelay(pdMS_TO_TICKS(200));
	}
}
