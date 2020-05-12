#include <stdint.h>
#include <freertos/FreeRTOS.h>
#include <esp_event.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PIN_BIT(x) (1ULL<<x)

	ESP_EVENT_DECLARE_BASE(BUTTON_EVENT);

	enum {
		EVT_BUTTON_DOWN = 1,
		EVT_BUTTON_UP,
	};

	typedef struct {
		uint8_t pin;
		uint8_t event;
		/* uint32_t length; */
	} button_event_t;

	void button_init(unsigned long long pin_select);

#ifdef __cplusplus
}
#endif
