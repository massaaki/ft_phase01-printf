
<p align="center"><img src="./images/ft_printfn.png"/></p>
<h1 align="center">ft_printf (in progress)</h1>
<p align="center">
<img src="https://img.shields.io/badge/Mandatory-OK-brightgreen"/>
<img src="https://img.shields.io/badge/Bonus-Not implemented-orange"/>
<img src="https://img.shields.io/badge/Final%20Score-100-brightgreen"/>
</p>
<p align="center">Function that mimic the printf() function from libc</p>

<br/>
<h1>Useful Links</h1>
<ul>
	<li><a href="https://github.com/massaaki/42School-progress/tree/main/00-study-reference/03-ft_printf/Tests">Printf Tester(my tests)</a></li>
	<li><a href="https://github.com/Tripouille/printfTester">Printf Tester(tripoille)</a></li>
	<li><a href="https://linux.die.net/man/3/va_arg">va_start, va_arg, va_end manual</a></li>

</ul>
<br/>
<h1>Learned concepts</h1>
<ul>
	<li>Variable arguments</li>
	<li>Makefile</li>
</ul>

<br/>
<h1>Flags implemented</h1>
<ul>
	<li>%u - Unsigned Int</li>
	<li>%i or %d - Signed int</li>
	<li>%c - Char</li>
	<li>%s - String</li>
	<li>%p - Pointer</li>
	<li>%x - Hex upper</li>
	<li>%X - Hex lower</li>
	<li>%% - Percent</li>
</ul>

<br/>
<h1>Getting starded</h1>

<h2>Generate compiled files with Makefile</h2>

```bash
make
```

<h2>Import create a main file and import ft_printf.h</h2>

```c
#import "<path>/ft_printf.h"

int main(void)
{
	ft_printf("hello world \n");
	return (0);
}
```
<br/>

<h1>Running my tests</h1>
<h2>1. Copy tests into project root path - <a href="https://github.com/massaaki/42School-progress/tree/main/00-study-reference/03-ft_printf/Tests">(link here)</a></h2>

<h2>2. Generate compiled files</h2>

```bash
make
```

<h2>3. Enter in tests folder and run</h2>

```bash
make integration

or 

make unit
```

<br/>
<br/>

<h1>License</h1>
<p>This project(ft_printf) is <a href="https://github.com/massaaki/massaaki/blob/main/license/mit">MTI Licensed</a></p>