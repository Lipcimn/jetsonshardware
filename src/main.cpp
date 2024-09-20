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
  displayBTCheck();
  ledFunctionality(500);
  servoFunctionality(5000);
}