#include <stdio.h>
#include <limits.h>
#include "printf.h"

/*
** Appelle ft_printf puis printf avec les memes arguments,
** affiche les deux sorties entre [] et compare les valeurs de retour.
** fflush(stdout) est indispensable : ft_printf utilise write()
** directement, alors que printf est bufferise.
*/
#define TEST(...) \
	do { \
		int r1; \
		int r2; \
		printf("ft : ["); fflush(stdout); \
		r1 = ft_printf(__VA_ARGS__); \
		printf("]\n"); \
		printf("std: ["); \
		r2 = printf(__VA_ARGS__); \
		printf("]\n"); \
		if (r1 == r2) \
			printf("OK  (retour = %d)\n\n", r1); \
		else \
			printf("KO  (ft = %d / std = %d)\n\n", r1, r2); \
		fflush(stdout); \
	} while (0)

int	main(void)
{
	int		x = 42;
	char	*null_str = NULL;
	void	*null_ptr = NULL;

	/* %c */
	TEST("%c", 'A');
	TEST("%c%c%c", 'a', 'b', 'c');

	/* %s */
	TEST("%s", "hello");
	TEST("%s", "");
	TEST("%s", null_str);

	/* %p */
	TEST("%p", &x);
	TEST("%p", null_ptr);

	/* %d / %i */
	TEST("%d", 0);
	TEST("%d", 42);
	TEST("%d", -42);
	TEST("%d", INT_MAX);
	TEST("%d", INT_MIN);
	TEST("%i", 123456);

	/* %u */
	TEST("%u", 0u);
	TEST("%u", UINT_MAX);

	/* %x / %X */
	TEST("%x", 0);
	TEST("%x", 255);
	TEST("%X", 255);
	TEST("%x", UINT_MAX);

	/* %% */
	TEST("%%");
	TEST("100%%");

	/* melange */
	TEST("%c|%s|%p|%d|%i|%u|%x|%X|%%",
		'A', "test", &x, INT_MIN, 42, UINT_MAX, 255, 255);

	/* sans conversion */
	TEST("juste du texte\n");

	return (0);
}