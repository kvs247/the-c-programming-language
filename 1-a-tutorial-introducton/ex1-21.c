// Write a program `entab` that replaces strings of blanks by the minimum
// number of tabs and blanks to achieve the same spacing. Use the same tab
// stops as for `detab`. When either a tab or a single blank would suffice
// to reach a tab stop, which should be given preference?

#include <stdio.h>

#define TAB_STOP 2

int main()
{
	int c, i;
	int spaceCount = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			spaceCount++;
			if (spaceCount == TAB_STOP)
			{
				putchar('\t');
				spaceCount = 0;
			}
		}
		else
		{
			if (spaceCount > 0)
			{
				while (spaceCount-- > 0)
				{
					putchar(' ');
				}
				spaceCount = 0;
			}
			putchar(c);
		}
	}
}