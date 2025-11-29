#include "config.h"
#include <stdio.h>
#include <string.h>

AppConfig load_config(const char *path) {
    AppConfig cfg;
    strcpy(cfg.mode, "standard");
    cfg.retries = 3;

    FILE *file = fopen(path, "r");
    if (!file) return cfg;

    fscanf(file, "mode=%s\n", cfg.mode);
    fscanf(file, "retries=%d\n", &cfg.retries);
    fclose(file);

    return cfg;
}
