#include <unistd.h>
//! [Interesting]
#include "mraa/aio.h"

int
main()
{
    mraa_aio_context adc_a0;
    uint16_t adc_value = 0;
    float adc_value_float = 0.0;

    adc_a0 = mraa_aio_init(0);
    if (adc_a0 == NULL) {
        return 1;
    }

    for (;;) {
        adc_value = mraa_aio_read(adc_a0);
        fprintf(stdout, "%d\n", adc_value);
	sleep(1);
    }

    mraa_aio_close(adc_a0);

    return MRAA_SUCCESS;
}

