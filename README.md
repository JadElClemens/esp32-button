# Button press detector

This implements a version of [THE ULTIMATE DEBOUNCER(TM) from hackaday](https://hackaday.com/2015/12/10/embed-with-elliot-debounce-your-noisy-buttons-part-ii/
).

It can monitor multiple pins, and sends button events over a queue for your application to process.

## Changes in Fork

Forked from [craftmetrics's implementation](https://github.com/craftmetrics/esp32-button).

This fork introduces the following changes:
- A [CMakeLists.txt](./CMakeLists.txt) file for compatibility with the new Python/CMake-based ESP-IDF build system
- Added __cplusplus preprocessor check for inclusion in C++ projects
- Posts to the ESP-IDF Default Event Loop instead of a FreeRTOS queue.
- Adds KConfig options for long press duration/repeat time, core affinity, task stack size, and priority

## Available input GPIO pins

Only the following pins can be used as inputs on the ESP32:

0-19, 21-23, 25-27, 32-39


## Example Usage

```
void buttonHandler(void*, esp_event_base_t, int32_t, void*);

ESP_ERROR_CHECK(esp_event_loop_create_default());
button_init(PIN_BIT(BUTTON_1) | PIN_BIT(BUTTON_2));
ESP_ERROR_CHECK(esp_event_handler_register(BUTTON_EVENT, ESP_EVENT_ANY_ID, buttonHandler, nullptr));

void buttonHandler(void* arg, esp_event_base_t eventbase, int32_t eventid, void* data) {
    switch(eventid) {
	    case EVT_BUTTON_UP:
		    ...
			break;
		case EVT_BUTTON_DOWN:
		    ...
			break;
	}
}
```

## Event Types

### EVT\_BUTTON\_DOWN

Triggered when the button is first considered pressed.

Also triggered every 50ms during a long press.

### EVT\_BUTTON\_UP

Triggered when the button is considered released. I recommend using EVT\_BUTTON\_DOWN to check/mark a press vs. a hold and checking this state in EVT\_BUTTON\_UP to perform some action.
