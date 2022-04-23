/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * FT_PRINTF INTEGRATION TESTS
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include <string.h>
#include <stdio.h>

#include "ft_printf.h"
// Run before start test
void redirect_all_stdout(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

/**
 * FUNCTION OUTPUT
 */
Test(integration_test03_ft_printf, success_cases_return_test)
{
	int result;
	int expected;
	
	result = ft_printf("hello: %d world\n", 123456);
	expected = printf("hello: %d world\n", 123456);
	cr_assert(result == expected, "Expected %d but received %d", expected, result);

	result = ft_printf("hello: %d %d %d world\n", 12, 34, 56);
	expected = printf("hello: %d %d %d world\n", 12, 34, 56);
	cr_assert(result == expected, "Expected %d but received %d", expected, result);
}


/**
 * STDOUT
*/
Test(integration_test01_ft_printf, success_cases_without_args, .init = redirect_all_stdout)
{
	ft_printf("hello world");
	cr_assert_stdout_eq_str("hello world", "expect print => 'hello world'");
}

Test(integration_test02_ft_printf, success_cases_with_int_args, .init = redirect_all_stdout)
{
	ft_printf("hello: %d world\n", 123456);
	cr_assert_stdout_eq_str("hello: 123456 world\n", "expect print => 'hello: 123456 world\n'");
}



Test(integration_test02_ft_printf, success_cases_with_int_multiple_args, .init = redirect_all_stdout)
{
	ft_printf("hello: %d %d %d world\n", 12, 23, 56);
	cr_assert_stdout_eq_str("hello: 12 23 56 world\n", "expect print => 'hello: 12 23 56 world\n'");
}