/* linker script CortexM3
Eng Mostafa-Elfallal
*/

MEMORY
{
	flash(RX) : ORIGIN = 0x08000000 , LENGTH = 128k
	sram(RWX) : ORIGIN = 0x20000000 , LENGTH = 20K
}
SECTIONS
{
	.text : {
			*(.vectors*)
			*(.text*)
			*(.rodata*)
			_E_text = .;
	}> flash
	.data : {
			_S_data = .;
			*(.data)
			. = ALIGN(4);
			_E_data = .;
			
	}> sram AT> flash
	
	.bss : {
			_S_bss = .;
			*(.bss)
			_E_bss = .;
			. = . +0x1000;
	}> sram
}