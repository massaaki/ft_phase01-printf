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

// INT - Return correctly value for SIGNED INT values
Test(integration_pt01_test01_ft_printf, success_cases_int_return_test)
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

// UNSIGNED INT - Return correctly value for UNSIGNED INT values
Test(integration_pt01_test02_ft_printf, success_cases_unsigned_intreturn_test)
{
	unsigned int result;
	unsigned int expected;

	unsigned int max_unsigned_value = 4294967295;

	result = ft_printf("hello: %u world\n", max_unsigned_value);
	expected = printf("hello: %u world\n", max_unsigned_value);
	cr_assert(result == expected, "Expected %d but received %d", expected, result);
}

/**
 * STDOUT
 */
// WITHOUT ARGS
Test(integration_pt02_test01_ft_printf, success_cases_without_args, .init = redirect_all_stdout)
{
	ft_printf("hello world");
	cr_assert_stdout_eq_str("hello world", "expect print => 'hello world'");
}

// INT - Positive
Test(integration_pt02_test02_ft_printf, success_cases_with_int_args, .init = redirect_all_stdout)
{
	ft_printf("hello: %d world\n", 123456);
	cr_assert_stdout_eq_str("hello: 123456 world\n", "expect print => 'hello: 123456 world\n'");
}

// INT - Negative
Test(integration_pt02_test03_ft_printf, success_cases_with_int_negative_args, .init = redirect_all_stdout)
{
	ft_printf("hello: %d world\n", -123456);
	cr_assert_stdout_eq_str("hello: -123456 world\n", "expect print => 'hello: -123456 world\n'");
}

// INT - Multiple values
Test(integration_pt02_test04_ft_printf, success_cases_with_int_multiple_args, .init = redirect_all_stdout)
{
	ft_printf("hello: %d %d %d world\n", 12, 23, 56);
	cr_assert_stdout_eq_str("hello: 12 23 56 world\n", "expect print => 'hello: 12 23 56 world\n'");
}

// UNSIGNED INT - max unsigned value
Test(integration_pt02_test05_ft_printf, success_cases_with_unsigned_int_args, .init = redirect_all_stdout)
{
	unsigned int max_unsigned_value = 4294967295;
	ft_printf("hello: %u world\n", max_unsigned_value);
	cr_assert_stdout_eq_str("hello: 4294967295 world\n", "expect print => 'hello: 123456 world\n'");
}