#include "operations.h"
#include "logger.h"
#include <windows.h>

void perform_operation(const char *mode, int retries) {
    log_info("Operation started: mode=%s, retries=%d", mode, retries);

    for (int i = 0; i < retries; i++) {
        Sleep(100);
        log_info("Retry %d/%d completed.", i + 1, retries);
    }

    log_info("Operation completed.");
}
