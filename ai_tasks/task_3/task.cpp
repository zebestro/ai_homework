void TMP102::startSampling() {
    xTaskCreate([](void* arg) {
        auto* self = static_cast<TMP102*>(arg);
        while (true) {
            float temp = self->readTemperature();
            self->buffer_.push(temp);
            vTaskDelay(pdMS_TO_TICKS(500));
        }
    }, "TMP102_Task", 512, this, 1, nullptr);
}

