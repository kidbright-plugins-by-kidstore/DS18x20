#ifndef __DS18x20_CPP__
#define __DS18x20_CPP__

#include <ds18x20.h>

DS18x20::DS18x20(int pin) {
    this->pin = pin;
}

void DS18x20::init(void) {
    this->sensor_count = ds18x20_scan_devices((gpio_num_t)this->pin, addrs, MAX_SENSORS);
    if (this->sensor_count > MAX_SENSORS)
        this->sensor_count = MAX_SENSORS;

	error = false;
	initialized = true;

	tickcnt = get_tickcnt() + 600;

	esp_log_level_set("*", ESP_LOG_INFO);

	ESP_LOGI("DS18x20", "Scan conut is %d", this->sensor_count);
}

int DS18x20::prop_count(void) {
	// not supported
	return 0;
}

bool DS18x20::prop_name(int index, char *name) {
	// not supported
	return false;
}

bool DS18x20::prop_unit(int index, char *unit) {
	// not supported
	return false;
}

bool DS18x20::prop_attr(int index, char *attr) {
	// not supported
	return false;
}

bool DS18x20::prop_read(int index, char *value) {
	// not supported
	return false;
}

bool DS18x20::prop_write(int index, char *value) {
	// not supported
	return false;
}

void DS18x20::process(Driver *drv) {
	if (is_tickcnt_elapsed(tickcnt, 500)) {
        if (this->sensor_count >= 1) {
            ds18x20_measure_and_read_multi((gpio_num_t)this->pin, addrs, sensor_count, temps);
            this->temperature = temps[0];
        }

		// get current tickcnt
		tickcnt = get_tickcnt();
	}
}

float DS18x20::getTemperature() {
	return this->temperature;
}

#endif
