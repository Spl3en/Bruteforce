#pragma once

#include "../Utils/Utils.h"

/**
 * Iterate through a sequence of string and check the validity of the generated
 * string.
 *
 * @param maxSize : The max size of the generated string
 * @param arg     : A user argument
 * @param compare   : The compare function; First argument, the generated string, the second is the size,
 * the third the user argument
 * @return        : the string generated which returned true
 */
char * bruteforce (
	int maxSize,
	void *arg,
	bool (*compare) (char *str, int size, void *arg)
);

