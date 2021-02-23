/* startup_cortexM3.s
Eng Mostafa-Elfallal
*/
/*SRAM 0x20000000 */
.section .vectors



.word 0x20001000
.word _reset
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.section .text
_reset:
	bl main
	b .
.thumb_func
Vector_handler:
	b _reset
