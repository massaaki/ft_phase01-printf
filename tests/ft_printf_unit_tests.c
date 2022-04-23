#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include <string.h>

#include "ft_printf.h"

/**
 * UNIT TESTS
 **/
Test(unit_test_01_ft_rule_identify, success_mandatory_cases)
{
	int result;
	int expected;

	// Ensure Return  SIGNED INT correcly
	expected = FORMAT_SIGNED_INT;
	result = ft_rule_identify("%d");
	cr_assert(result == expected, "Expected %d but received %d", expected, result);

	result = ft_rule_identify("%i");
	cr_assert(result == expected, "Expected %d but received %d", expected, result);

	expected = FORMAT_UNSIGNED_INT;
	result = ft_rule_identify("%u");
	cr_assert(result == expected, "Expected %d but received %d", expected, result);

	expected = FORMAT_SINGLE_CHAR;
	result = ft_rule_identify("%c");
	cr_assert(result == expected, "Expected %d but received %d", expected, result);

	expected = FORMAT_STRING;
	result = ft_rule_identify("%s");
	cr_assert(result == expected, "Expected %d but received %d", expected, result);

	expected = FORMAT_POINTER;
	result = ft_rule_identify("%p");
	cr_assert(result == expected, "Expected %d but received %d", expected, result);

	expected = FORMAT_HEX_UPPER;
	result = ft_rule_identify("%X");
	cr_assert(result == expected, "Expected %d but received %d", expected, result);

	expected = FORMAT_HEX_LOWER;
	result = ft_rule_identify("%x");
	cr_assert(result == expected, "Expected %d but received %d", expected, result);

	expected = FORMAT_PERCENT;
	result = ft_rule_identify("%%");
	cr_assert(result == expected, "Expected %d but received %d", expected, result);
}

Test(unit_test_02_ft_rule_identify, error_cases)
{
	int result;
	int expected;

	expected = -1;

	result = ft_rule_identify(NULL);
	cr_assert(result == expected, "Expected to return -1 when arg=NULL");

	result = ft_rule_identify("");
	cr_assert(result == expected, "Expected to return -1 when arg=NULL");

	result = ft_rule_identify("\n");
	cr_assert(result == expected, "Expected to return -1 when arg=NULL");

	result = ft_rule_identify("!");
	cr_assert(result == expected, "Expected to return -1 when arg=NULL");
}