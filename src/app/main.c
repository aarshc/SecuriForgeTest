#include <stdio.h>
#include <windows.h>
#include "config.h"
#include "logger.h"
#include "operations.h"

int main() {
    init_logger("app.log");
    log_info("Application started.");

    AppConfig cfg = load_config("default.conf");
    log_info("Loaded config: mode=%s, retries=%d", cfg.mode, cfg.retries);

    SYSTEMTIME t;
    GetLocalTime(&t);
    log_info("Local time: %02d:%02d:%02d", t.wHour, t.wMinute, t.wSecond);

    if (cfg.retries > 0) {
        perform_operation(cfg.mode, cfg.retries);
    } else {
        log_error("Invalid retry count.");
    }

    log_info("Application exiting.");
    close_logger();
    return 0;
}
