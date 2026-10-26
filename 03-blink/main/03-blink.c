#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define LED_GPIO 2

static const char *TAG = "blink";

void app_main(void)
{
	gpio_config_t io_conf = {
		.pin_bit_mask = 1ULL << LED_GPIO,
		.mode = GPIO_MODE_OUTPUT,
		// more options
		// .pull_up_en = GPIO_PULLUP_DISABLE,
		// .pull_down_en = GPIO_PULLDOWN_DISABLE,
		// .intr_type = GPIO_INTR_DISABLE
	};
	gpio_config(&io_conf);

	int level = 0;
	while (1) {
		level = !level;
		gpio_set_level(LED_GPIO,level);
		ESP_LOGI(TAG, "LED = %d", level);
		vTaskDelay(pdMS_TO_TICKS(500));
	}
}
