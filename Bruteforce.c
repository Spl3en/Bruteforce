#include "Bruteforce.h"

#define FIRST_CHAR ' '
#define LAST_CHAR '~'
#define LAST_CHAR_INDEX (LAST_CHAR - FIRST_CHAR)

static bool bruteforceEx (
	char *str,
	unsigned int pos,
	unsigned int size,
	void *arg,
	bool (*compare) (char *str, int size, void *arg)
);

/**
 * Iterate through a sequence of string and check the validity of the generated
 * string.
 *
 * @param maxSize
 *		The max size of the generated string
 * @param arg
 *		A user argument
 * @param compare
 *		The comparison function
 *			The first argument is the generated string
 *			The second one is the size of the generated string
 *			The third one is the user argument
 *
 * @return
 *		The string generated which returned true
 */
char * bruteforce (
	int maxSize,
	void *arg,
	bool (*compare) (char *str, int size, void *arg)
) {
	char str[100] = {0};

	for (unsigned int curSize = 1; curSize < maxSize; curSize++)
	{
		memset (str, FIRST_CHAR, curSize);
		if (bruteforceEx (str, 0, curSize, arg, compare)) {
			return strdup(str);
		}
	}

	return NULL;
}


static bool bruteforceEx (
	char *str,
	unsigned int pos,
	unsigned int size,
	void *arg,
	bool (*compare) (char *str, int size, void *arg)
) {
	for (unsigned int index = 0; index <= LAST_CHAR_INDEX; index++)
	{
		str[pos] = FIRST_CHAR + index;
		if (pos + 1 < size) {
			if (bruteforceEx (str, pos + 1, size, arg, compare)) {
				return true;
			}
		}
		else if (compare (str, size, arg)) {
			return true;
		}
	}

	return false;
}
