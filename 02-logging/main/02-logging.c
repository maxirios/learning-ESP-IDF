#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

static const char *TAG = "logging";

void app_main(void)
{
	int count = 0;
	while (1) {
		ESP_LOGI(TAG, "count = %d", count);
		if (count % 5 == 0) {
			ESP_LOGW(TAG, "multiple of 5");
		}
		if (count % 10 == 0) {
			ESP_LOGE(TAG, "multiple of 10");
		}
		count++;
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}
