#include "variables/variables.h"
#include "functions/functions.h"
#include "classes/classes.h"
#include "setup/setup.h"

#include <stdint.h>

void setup()
{
  projectSetup();
}

void loop()
{
  touch();
  alarm((uint16_t)8000);
  temperatureAndHumidity((uint16_t)2000);
}