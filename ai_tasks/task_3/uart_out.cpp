void printTemperatures(const TMP102& sensor) {
    const int16_t* readings = sensor.raw();
    for (int i = 0; i < 10; ++i) {
        printf("Raw: 0x%04X\n", readings[i]);
    }
    printf("Average: %.2f °C\n", sensor.average());
}

