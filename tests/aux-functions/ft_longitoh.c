#include <stdio.h>
#include <stdlib.h>

// 140702036971545
//  0x7ff7beeed019

void ft_set_hex_nums(char *hex_nums);
int ft_num_length(unsigned long long number);
void revert_str(char **str);
size_t ft_strlen(const char *s);

char *ft_llong_i_to_hex(unsigned long long number)
{
  char hex_nums[16];
  unsigned long long rest;
  char *result;
  int result_last_index;
  int index;

  // Initialize
  result_last_index = ft_num_length(number);
  ft_set_hex_nums(hex_nums);
  result = (char *)malloc(result_last_index * sizeof(char) + 1 + 2);
  index = 0;
  while (number / 16 != 0)
  {
    rest = number % 16;
    number /= 16;
    result[index] = hex_nums[rest];
    index++;
  }
  result[index] = hex_nums[number];
  result[index++] = 'x';
  result[index++] = '0';
  result[index++] = '\0';

  revert_str(&result);
  return (result);
}

void revert_str(char **str)
{
  char temp;
  int length;
  int aux_index;

  length = ft_strlen(*str);
  aux_index = length - 1;

  for (int i = 0;( i < (length / 2)); i++)
  {
    temp = (*str)[i];
    (*str)[i] = (*str)[aux_index];
    (*str)[aux_index] = temp;
    aux_index--;
  }
}

int ft_num_length(unsigned long long number)
{
  int qty;

  qty = 0;
  while (number / 16 != 0)
  {
    qty++;
    number /= 16;
  }
  return qty + 1; // rest
}

void ft_set_hex_nums(char *hex_nums)
{
  hex_nums[0] = '0';
  hex_nums[1] = '1';
  hex_nums[2] = '2';
  hex_nums[3] = '3';
  hex_nums[4] = '4';
  hex_nums[5] = '5';
  hex_nums[6] = '6';
  hex_nums[7] = '7';
  hex_nums[8] = '8';
  hex_nums[9] = '9';
  hex_nums[10] = 'a';
  hex_nums[11] = 'b';
  hex_nums[12] = 'c';
  hex_nums[13] = 'd';
  hex_nums[14] = 'e';
  hex_nums[15] = 'f';
}

size_t ft_strlen(const char *s)
{
  size_t cont;

  cont = 0;
  while (s[cont] != '\0')
    cont++;
  return (cont);
}

int main(void)
{
  unsigned long long num = 140702036971545;
  printf("=> %s\n", ft_llong_i_to_hex(num));
  return (0);
}