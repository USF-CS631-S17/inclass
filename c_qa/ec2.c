/* Convert inches to centimeters */
#include <stdio.h>

/* #define INCH2CM 2.54 */
const float INCH2CM = 2.54;

int main(void) {
    float inch = 5.5;
    float cm;

    // INCH2CM = 3.99; BAD
    
    cm = inch * INCH2CM;

    // 5.5 inches
    printf("%f inches = %f cm\n", inch, cm);

    return 0;
}
