#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "../bblogger.h"
#include "switching.h"
#include "../module.h"

#define BBSWITCH_PATH "/proc/acpi/bbswitch"

/**
 * Reports the status of the nvidia driver to conform with the expectations for bbswitch
 *
 * @return SWITCH_OFF if card is off, SWITCH_ON if card is on.
 */
enum switch_state linux_native_status(void) {
  //TODO: Don't hardcode nvidia driver, allow for all other drivers
  //can take advantage of the already-written "module_is_loaded"
  bb_log(LOG_INFO, "Switch method native, querying status");
  if(module_is_loaded("nvidia")){
  	bb_log(LOG_INFO, "Switch method native, status ON");
  	return SWITCH_ON;
  } else {
  	bb_log(LOG_INFO, "Switch method native, status OFF");
  	return SWITCH_OFF;
  }
}//linux_native_status
/**
 * whether or not the linux pcie power management method is available
 * If your kernel is above version 4.8, it just is.
 * Leaving this in as a short-term hack for conformance.  
 * TODO: remove
 */
int linux_native_is_available(struct switch_info info) {
  bb_log(LOG_INFO, "Checking if linux_native is available");
  return 1;
}

/**
 * Leaving this in as a short-term hack for conformance. 
 * TODO: remove
 */
void linux_native_on(void) {
  bbswitch_write("ON\n");
}//bbswitch_on

/**
 * Leaving this in as a short-term hack for conformance. 
 * TODO: remove
 */
void linux_native_off(void) {
  bbswitch_write("OFF\n");
}//bbswitch_off
