integration:
	gcc ../libftprintf.a -I ../includes \
	ft_printf_integration_tests.c -lcriterion -o ft_printf_integration_tests
	./ft_printf_integration_tests
	rm -rf ft_printf_integration_tests

unit:
	gcc ../libftprintf.a -I ../includes \
	ft_printf_unit_tests.c -lcriterion -o ft_printf_unit_tests
	./ft_printf_unit_tests
	rm -rf ft_printf_unit_tests

original:
	gcc original_printf_tests.c -o original&& ./original
	rm -rf original