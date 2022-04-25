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
Test(integration_pt01_test02_ft_printf, success_cases_unsigned_int_return_test)
{
	unsigned int result;
	unsigned int expected;

	unsigned int max_unsigned_value = 4294967295;

	result = ft_printf("hello: %u world\n", max_unsigned_value);
	expected = printf("hello: %u world\n", max_unsigned_value);
	cr_assert(result == expected, "Expected %d but received %d", expected, result);
}

// CHAR - Return correctly value
Test(integration_pt01_test03_ft_printf, success_cases_char_return_test)
{
	unsigned int result;
	unsigned int expected;

	result = ft_printf("hello: %c%c world\n", 'a', 'b');
	expected = printf("hello: %c%c world\n", 'a', 'b');
	cr_assert(result == expected, "Expected %d but received %d", expected, result);
}

// STRING - Return correctly value
Test(integration_pt01_test04_ft_printf, success_cases_string_return_test)
{
	unsigned int result;
	unsigned int expected;

	result = ft_printf("hello: %s world\n", "abcdefg");
	expected = printf("hello: %s world\n", "abcdefg");
	cr_assert(result == expected, "Expected %d but received %d", expected, result);
}
// POINTER - return correct length
Test(integration_pt01_test05_ft_printf, success_cases_pointer_return_test)
{
	char str[] = "abc";
	unsigned int result;
	unsigned int expected;

	result = ft_printf("hello: %p world\n", &str);
	expected = printf("hello: %p world\n", &str);
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

// CHAR - one arg
Test(integration_pt02_test06_ft_printf, success_cases_with_char_args, .init = redirect_all_stdout)
{
	char letter = 'a';
	ft_printf("hello: %c world\n", letter);
	cr_assert_stdout_eq_str("hello: a world\n", "expect print => 'hello: a world\n'");
}

// CHAR - \n
Test(integration_pt02_test07_ft_printf, success_cases_with_special_char_args, .init = redirect_all_stdout)
{
	char letter = '\n';
	ft_printf("hello: %c world\n", letter);
	cr_assert_stdout_eq_str("hello: \n world\n", "expect print => 'hello: \n world\n'");
}

// CHAR - multiple args
Test(integration_pt02_test08_ft_printf, success_cases_with_multiple_char_args, .init = redirect_all_stdout)
{
	ft_printf("hello: %c %c %c %c world\n", 'a', 'b', 'c', 'd');
	cr_assert_stdout_eq_str("hello: a b c d world\n", "expect print => 'hello: a b c d world\n'");
}

// STRING - one arg
Test(integration_pt02_test09_ft_printf, success_cases_with_string_args, .init = redirect_all_stdout)
{
	char str[] = "abcdef";

	ft_printf("hello: %s world\n", str);
	cr_assert_stdout_eq_str("hello: abcdef world\n", "expect print => 'hello: abcdef world\n'");
}

// STRING - multiple args
Test(integration_pt02_test10_ft_printf, success_cases_with_multiple_string_args, .init = redirect_all_stdout)
{
	char str[] = "abcdef";
	char str2[] = "ghij";

	ft_printf("hello: %s world%s\n", str, str2);
	cr_assert_stdout_eq_str("hello: abcdef worldghij\n", "expect print => 'hello: abcdef world\n'");
}

// STRING - one arg
Test(integration_pt02_test10_ft_printf, success_cases_with_pointer_args, .init = redirect_all_stdout)
{
	char str[] = "abcdef";

	// GET PRINTF CONTENT
	char *expected;
	size_t size;
	size = snprintf(NULL, 0, "hello %p world\n", &str);
	expected = (char *)malloc(size + 1);
	snprintf(expected, size + 1, "hello %p world\n", &str);

	// ft_printf("hello: %p world\n", &str);
	ft_printf("hello %p world\n", &str);
	cr_assert_stdout_eq_str(expected, "expect print '%s'", expected);
}