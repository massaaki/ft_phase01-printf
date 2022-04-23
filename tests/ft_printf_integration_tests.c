#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include <string.h>

#include "ft_printf.h"

// Run before start test
void redirect_all_stdout(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}
/*
 * INTEGRATION TESTS
 */
Test(integration_test01_ft_printf, success_cases_without_args, .init = redirect_all_stdout)
{
	ft_printf("hello world");
	cr_assert_stdout_eq_str("hello world", "");
}