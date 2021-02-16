
app.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <main>:
   0:	e92d4800 	push	{fp, lr}
   4:	e28db004 	add	fp, sp, #4
   8:	e59f000c 	ldr	r0, [pc, #12]	; 1c <main+0x1c>
   c:	ebfffffe 	bl	0 <Uart_Send_String>
  10:	e24bd004 	sub	sp, fp, #4
  14:	e8bd4800 	pop	{fp, lr}
  18:	e12fff1e 	bx	lr
  1c:	00000000 	andeq	r0, r0, r0

Disassembly of section .data:

00000000 <msg>:
   0:	74736f4d 	ldrbtvc	r6, [r3], #-3917	; 0xf4d
   4:	20616661 	rsbcs	r6, r1, r1, ror #12
   8:	61666c45 	cmnvs	r6, r5, asr #24
   c:	6c616c6c 	stclvs	12, cr6, [r1], #-432	; 0xfffffe50
	...

Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:	00000067 	andeq	r0, r0, r7, rrx
   4:	00000002 	andeq	r0, r0, r2
   8:	01040000 	mrseq	r0, (UNDEF: 4)
   c:	0000005c 	andeq	r0, r0, ip, asr r0
  10:	00006801 	andeq	r6, r0, r1, lsl #16
  14:	00001700 	andeq	r1, r0, r0, lsl #14
  18:	00000000 	andeq	r0, r0, r0
  1c:	00002000 	andeq	r2, r0, r0
  20:	00000000 	andeq	r0, r0, r0
  24:	6e010200 	cdpvs	2, 0, cr0, cr1, cr0, {0}
  28:	01000000 	mrseq	r0, (UNDEF: 0)
  2c:	00000003 	andeq	r0, r0, r3
  30:	00002000 	andeq	r2, r0, r0
  34:	00000000 	andeq	r0, r0, r0
  38:	51030100 	mrspl	r0, (UNDEF: 19)
  3c:	4a000000 	bmi	44 <.debug_info+0x44>
  40:	04000000 	streq	r0, [r0], #-0
  44:	0000004a 	andeq	r0, r0, sl, asr #32
  48:	040500c7 	streq	r0, [r5], #-199	; 0xc7
  4c:	00000e07 	andeq	r0, r0, r7, lsl #28
  50:	08010500 	stmdaeq	r1, {r8, sl}
  54:	00000000 	andeq	r0, r0, r0
  58:	67736d06 	ldrbvs	r6, [r3, -r6, lsl #26]!
  5c:	3a020100 	bcc	80464 <main+0x80464>
  60:	01000000 	mrseq	r0, (UNDEF: 0)
  64:	00000305 	andeq	r0, r0, r5, lsl #6
  68:	Address 0x00000068 is out of bounds.


Disassembly of section .debug_abbrev:

00000000 <.debug_abbrev>:
   0:	25011101 	strcs	r1, [r1, #-257]	; 0x101
   4:	030b130e 	movweq	r1, #45838	; 0xb30e
   8:	110e1b0e 	tstne	lr, lr, lsl #22
   c:	10011201 	andne	r1, r1, r1, lsl #4
  10:	02000006 	andeq	r0, r0, #6
  14:	0c3f002e 	ldceq	0, cr0, [pc], #-184	; ffffff64 <main+0xffffff64>
  18:	0b3a0e03 	bleq	e8382c <main+0xe8382c>
  1c:	01110b3b 	tsteq	r1, fp, lsr fp
  20:	06400112 			; <UNDEFINED> instruction: 0x06400112
  24:	000c4296 	muleq	ip, r6, r2
  28:	01010300 	mrseq	r0, SP_irq
  2c:	13011349 	movwne	r1, #4937	; 0x1349
  30:	21040000 	mrscs	r0, (UNDEF: 4)
  34:	2f134900 	svccs	0x00134900
  38:	0500000b 	streq	r0, [r0, #-11]
  3c:	0b0b0024 	bleq	2c00d4 <main+0x2c00d4>
  40:	0e030b3e 	vmoveq.16	d3[0], r0
  44:	34060000 	strcc	r0, [r6], #-0
  48:	3a080300 	bcc	200c50 <main+0x200c50>
  4c:	490b3b0b 	stmdbmi	fp, {r0, r1, r3, r8, r9, fp, ip, sp}
  50:	020c3f13 	andeq	r3, ip, #19, 30	; 0x4c
  54:	0000000a 	andeq	r0, r0, sl

Disassembly of section .debug_loc:

00000000 <.debug_loc>:
   0:	00000000 	andeq	r0, r0, r0
   4:	00000004 	andeq	r0, r0, r4
   8:	007d0002 	rsbseq	r0, sp, r2
   c:	00000004 	andeq	r0, r0, r4
  10:	00000008 	andeq	r0, r0, r8
  14:	087d0002 	ldmdaeq	sp!, {r1}^
  18:	00000008 	andeq	r0, r0, r8
  1c:	00000020 	andeq	r0, r0, r0, lsr #32
  20:	047b0002 	ldrbteq	r0, [fp], #-2
	...

Disassembly of section .debug_aranges:

00000000 <.debug_aranges>:
   0:	0000001c 	andeq	r0, r0, ip, lsl r0
   4:	00000002 	andeq	r0, r0, r2
   8:	00040000 	andeq	r0, r4, r0
	...
  14:	00000020 	andeq	r0, r0, r0, lsr #32
	...

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	00000031 	andeq	r0, r0, r1, lsr r0
   4:	001c0002 	andseq	r0, ip, r2
   8:	01020000 	mrseq	r0, (UNDEF: 2)
   c:	000d0efb 	strdeq	r0, [sp], -fp
  10:	01010101 	tsteq	r1, r1, lsl #2
  14:	01000000 	mrseq	r0, (UNDEF: 0)
  18:	00010000 	andeq	r0, r1, r0
  1c:	2e707061 	cdpcs	0, 7, cr7, cr0, cr1, {3}
  20:	00000063 	andeq	r0, r0, r3, rrx
  24:	05000000 	streq	r0, [r0, #-0]
  28:	00000002 	andeq	r0, r0, r2
  2c:	4b4b1400 	blmi	12c5034 <main+0x12c5034>
  30:	01000802 	tsteq	r0, r2, lsl #16
  34:	Address 0x00000034 is out of bounds.


Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	69736e75 	ldmdbvs	r3!, {r0, r2, r4, r5, r6, r9, sl, fp, sp, lr}^
   4:	64656e67 	strbtvs	r6, [r5], #-3687	; 0xe67
   8:	61686320 	cmnvs	r8, r0, lsr #6
   c:	69730072 	ldmdbvs	r3!, {r1, r4, r5, r6}^
  10:	7974657a 	ldmdbvc	r4!, {r1, r3, r4, r5, r6, r8, sl, sp, lr}^
  14:	44006570 	strmi	r6, [r0], #-1392	; 0x570
  18:	6d455c3a 	stclvs	12, cr5, [r5, #-232]	; 0xffffff18
  1c:	64646562 	strbtvs	r6, [r4], #-1378	; 0x562
  20:	732d6465 	teqvc	sp, #1694498816	; 0x65000000
  24:	65747379 	ldrbvs	r7, [r4, #-889]!	; 0x379
  28:	4b5c736d 	blmi	171cde4 <main+0x171cde4>
  2c:	202e532e 	eorcs	r5, lr, lr, lsr #6
  30:	72756f43 	rsbsvc	r6, r5, #268	; 0x10c
  34:	725c6573 	subsvc	r6, ip, #482344960	; 0x1cc00000
  38:	5c6f7065 	stclpl	0, cr7, [pc], #-404	; fffffeac <main+0xfffffeac>
  3c:	696c6e4f 	stmdbvs	ip!, {r0, r1, r2, r3, r6, r9, sl, fp, sp, lr}^
  40:	645f656e 	ldrbvs	r6, [pc], #-1390	; 48 <.debug_str+0x48>
  44:	6f6c7069 	svcvs	0x006c7069
  48:	455c616d 	ldrbmi	r6, [ip, #-365]	; 0x16d
  4c:	6465626d 	strbtvs	r6, [r5], #-621	; 0x26d
  50:	20646564 	rsbcs	r6, r4, r4, ror #10
  54:	656c5c43 	strbvs	r5, [ip, #-3139]!	; 0xc43
  58:	00322063 	eorseq	r2, r2, r3, rrx
  5c:	20554e47 	subscs	r4, r5, r7, asr #28
  60:	2e342043 	cdpcs	0, 3, cr2, cr4, cr3, {2}
  64:	00322e37 	eorseq	r2, r2, r7, lsr lr
  68:	2e707061 	cdpcs	0, 7, cr7, cr0, cr1, {3}
  6c:	616d0063 	cmnvs	sp, r3, rrx
  70:	Address 0x00000070 is out of bounds.


Disassembly of section .comment:

00000000 <.comment>:
   0:	43434700 	movtmi	r4, #14080	; 0x3700
   4:	4728203a 			; <UNDEFINED> instruction: 0x4728203a
   8:	2029554e 	eorcs	r5, r9, lr, asr #10
   c:	2e372e34 	mrccs	14, 1, r2, cr7, cr4, {1}
  10:	Address 0x00000010 is out of bounds.


Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00002f41 	andeq	r2, r0, r1, asr #30
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000025 	andeq	r0, r0, r5, lsr #32
  10:	4d524105 	ldfmie	f4, [r2, #-20]	; 0xffffffec
  14:	4d445437 	cfstrdmi	mvd5, [r4, #-220]	; 0xffffff24
  18:	02060049 	andeq	r0, r6, #73	; 0x49
  1c:	01090108 	tsteq	r9, r8, lsl #2
  20:	01140412 	tsteq	r4, r2, lsl r4
  24:	03170115 	tsteq	r7, #1073741829	; 0x40000005
  28:	01190118 	tsteq	r9, r8, lsl r1
  2c:	061e011a 			; <UNDEFINED> instruction: 0x061e011a

Disassembly of section .debug_frame:

00000000 <.debug_frame>:
   0:	0000000c 	andeq	r0, r0, ip
   4:	ffffffff 			; <UNDEFINED> instruction: 0xffffffff
   8:	7c020001 	stcvc	0, cr0, [r2], {1}
   c:	000d0c0e 	andeq	r0, sp, lr, lsl #24
  10:	00000018 	andeq	r0, r0, r8, lsl r0
	...
  1c:	00000020 	andeq	r0, r0, r0, lsr #32
  20:	8b080e42 	blhi	203930 <main+0x203930>
  24:	42018e02 	andmi	r8, r1, #2, 28
  28:	00040b0c 	andeq	r0, r4, ip, lsl #22
