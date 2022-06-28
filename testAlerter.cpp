#include "testAlerter.hpp"

int alerter_stub::networkAlertStub(float celcius) {

    std::cout << "ALERT: Temperature is " << celcius << " celcius." << std::endl;

    if(celcius <= TEMP_THRESHOLD) {
        return ALERT_OK;
    }
    return ALERT_ERR;
}