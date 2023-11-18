#include "main.h"
/**
 * parse_specifiers - parses characters that follow the % character
 * @inv: the arguments inventory
 */
void parsespec(list_t *dime)
{
	int j, i = dime->i + 1, space = 0;
	static const char flags[] = "hl+#";

	dime->space = 0;
	while (dime->f[i] == ' ')
		i++, dime->i++, space = 1;

	dime->c1 = dime->f[i++];
	if (space && dime->c1 != '+')
	{
		space = 0, dime->space = 1, dime->c0 = ' ';
		write_buffer(dime);
	}
	for (j = 0; flags[j] != '\0'; j++)
	{
		if (dime->c1 == flags[j])
		{
			while (dime->f[i] == ' ')
				i++, dime->i++, space = 1;
			if (space && dime->c1 != '+')
			{
				dime->c0 = ' ';
				write_buffer(dime);
			}
			break;
		}
	}
	dime->c2 = dime->c1 ? dime->f[i++] : '\0';
	dime->c3 = dime->c2 ? dime->f[i] : '\0';
}
