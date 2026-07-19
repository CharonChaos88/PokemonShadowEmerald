	.arch armv4t
	.fpu softvfp
	.file	"main.c"
	.text
	.section	.text.memcpy,"ax",%progbits
	.align	1
	.p2align 2,,3
	.global	memcpy
	.syntax unified
	.code	16
	.thumb_func
	.type	memcpy, %function
memcpy:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, lr}
	cmp	r2, #0
	beq	.L2
	movs	r3, #0
.L3:
	ldrb	r4, [r1, r3]
	strb	r4, [r0, r3]
	adds	r3, r3, #1
	cmp	r3, r2
	bne	.L3
.L2:
	@ sp needed
	pop	{r4}
	pop	{r1}
	bx	r1
	.size	memcpy, .-memcpy
	.section	.text.memset,"ax",%progbits
	.align	1
	.p2align 2,,3
	.global	memset
	.syntax unified
	.code	16
	.thumb_func
	.type	memset, %function
memset:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, lr}
	movs	r4, r0
	cmp	r2, #0
	beq	.L12
	movs	r3, #255
	ands	r1, r3
	bl	memset
.L12:
	@ sp needed
	movs	r0, r4
	pop	{r4}
	pop	{r1}
	bx	r1
	.size	memset, .-memset
	.section	.text.DrawChar,"ax",%progbits
	.align	1
	.p2align 2,,3
	.global	DrawChar
	.syntax unified
	.code	16
	.thumb_func
	.type	DrawChar, %function
DrawChar:
	@ Function supports interworking.
	@ args = 4, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	lsls	r3, r3, #16
	lsrs	r3, r3, #16
	mov	ip, r3
	movs	r3, #240
	push	{r4, r5, r6, r7, lr}
	mov	r7, r9
	mov	r6, r8
	mov	lr, r10
	lsls	r3, r3, #3
	mov	r9, r3
	mov	r8, r0
	movs	r4, #1
	push	{r6, r7, lr}
	ldr	r7, [sp, #32]
	lsls	r5, r1, #4
	ldr	r6, .L22
	lsls	r2, r2, #24
	subs	r5, r5, r1
	lsls	r7, r7, #16
	lsrs	r2, r2, #21
	lsls	r5, r5, #4
	lsrs	r7, r7, #16
	adds	r6, r2, r6
	add	r9, r9, r5
.L14:
	mov	r3, r8
	adds	r2, r5, r3
	movs	r3, #192
	lsls	r3, r3, #19
	mov	r10, r3
	lsls	r2, r2, #1
	movs	r3, #0
	ldrb	r0, [r6]
	add	r2, r2, r10
	b	.L17
.L21:
	mov	r1, ip
	adds	r3, r3, #1
	strh	r1, [r2]
	adds	r2, r2, #2
	cmp	r3, #8
	beq	.L20
.L17:
	movs	r1, r0
	asrs	r1, r1, r3
	tst	r4, r1
	bne	.L21
	adds	r3, r3, #1
	strh	r7, [r2]
	adds	r2, r2, #2
	cmp	r3, #8
	bne	.L17
.L20:
	adds	r5, r5, #240
	adds	r6, r6, #1
	cmp	r9, r5
	bne	.L14
	@ sp needed
	pop	{r5, r6, r7}
	mov	r10, r7
	mov	r9, r6
	mov	r8, r5
	pop	{r4, r5, r6, r7}
	pop	{r0}
	bx	r0
.L23:
	.align	2
.L22:
	.word	font8x8_basic
	.size	DrawChar, .-DrawChar
	.section	.text.DrawString,"ax",%progbits
	.align	1
	.p2align 2,,3
	.global	DrawString
	.syntax unified
	.code	16
	.thumb_func
	.type	DrawString, %function
DrawString:
	@ Function supports interworking.
	@ args = 4, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, r5, r6, r7, lr}
	mov	lr, r8
	push	{lr}
	sub	sp, sp, #4
	ldr	r6, [sp, #28]
	movs	r4, r2
	ldrb	r2, [r2]
	lsls	r7, r3, #16
	lsls	r6, r6, #16
	movs	r5, r0
	mov	r8, r1
	lsrs	r7, r7, #16
	lsrs	r6, r6, #16
	cmp	r2, #0
	beq	.L24
.L26:
	movs	r0, r5
	movs	r3, r7
	mov	r1, r8
	str	r6, [sp]
	adds	r4, r4, #1
	bl	DrawChar
	ldrb	r2, [r4]
	adds	r5, r5, #8
	cmp	r2, #0
	bne	.L26
.L24:
	add	sp, sp, #4
	@ sp needed
	pop	{r7}
	mov	r8, r7
	pop	{r4, r5, r6, r7}
	pop	{r0}
	bx	r0
	.size	DrawString, .-DrawString
	.section	.text.DrawScreenColor,"ax",%progbits
	.align	1
	.p2align 2,,3
	.global	DrawScreenColor
	.syntax unified
	.code	16
	.thumb_func
	.type	DrawScreenColor, %function
DrawScreenColor:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	movs	r3, #192
	lsls	r2, r0, #16
	ldr	r1, .L33
	lsrs	r2, r2, #16
	lsls	r3, r3, #19
.L31:
	strh	r2, [r3]
	adds	r3, r3, #2
	cmp	r3, r1
	bne	.L31
	@ sp needed
	bx	lr
.L34:
	.align	2
.L33:
	.word	100740096
	.size	DrawScreenColor, .-DrawScreenColor
	.section	.rodata.PayloadMain.str1.4,"aMS",%progbits,1
	.align	2
.LC1:
	.ascii	"Select Event to Distribute:\000"
	.align	2
.LC3:
	.ascii	"Press A to Confirm\000"
	.align	2
.LC5:
	.ascii	"DISTRIBUTION READY\000"
	.align	2
.LC7:
	.ascii	"Current Event:\000"
	.align	2
.LC9:
	.ascii	"Connect Client GBA\000"
	.align	2
.LC11:
	.ascii	"with a Link Cable.\000"
	.align	2
.LC13:
	.ascii	"Press START to Begin.\000"
	.align	2
.LC15:
	.ascii	"Press B to Cancel\000"
	.align	2
.LC17:
	.ascii	"SEARCHING FOR CLIENT...\000"
	.align	2
.LC19:
	.ascii	"Turn on Client GBA now\000"
	.align	2
.LC21:
	.ascii	"(hold START+SELECT on boot)\000"
	.align	2
.LC23:
	.ascii	"TRANSMITTING...\000"
	.align	2
.LC25:
	.ascii	"Do NOT turn off\000"
	.align	2
.LC27:
	.ascii	"either GBA!\000"
	.align	2
.LC29:
	.ascii	"Err:\000"
	.align	2
.LC31:
	.ascii	"Prb:\000"
	.align	2
.LC33:
	.ascii	"Cli:\000"
	.align	2
.LC35:
	.ascii	"SIO:\000"
	.align	2
.LC37:
	.ascii	"SUCCESS!\000"
	.align	2
.LC39:
	.ascii	"Payload transmitted.\000"
	.align	2
.LC41:
	.ascii	"Press START for next.\000"
	.align	2
.LC43:
	.ascii	"Press B for Menu\000"
	.align	2
.LC51:
	.ascii	"0123456789ABCDEF\000"
	.section	.text.PayloadMain,"ax",%progbits
	.align	1
	.p2align 2,,3
	.global	PayloadMain
	.syntax unified
	.code	16
	.thumb_func
	.type	PayloadMain, %function
PayloadMain:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 216
	@ frame_needed = 0, uses_anonymous_args = 0
	movs	r3, #128
	push	{r4, r5, r6, r7, lr}
	mov	lr, fp
	mov	r7, r10
	mov	r6, r9
	mov	r5, r8
	ldr	r2, .L197
	lsls	r3, r3, #19
	push	{r5, r6, r7, lr}
	strh	r2, [r3]
	movs	r3, #192
	movs	r1, #0
	ldr	r2, .L197+4
	sub	sp, sp, #220
	lsls	r3, r3, #19
.L36:
	strh	r1, [r3]
	adds	r3, r3, #2
	cmp	r3, r2
	bne	.L36
	ldr	r3, .L197+8
	ldr	r2, .L197+12
	ldrh	r7, [r3]
	ldr	r3, .L197+16
	str	r3, [r2]
	movs	r2, #1
	movs	r0, #8
	ldr	r3, .L197+20
	ldr	r1, .L197+24
	strh	r2, [r3]
	ldrh	r3, [r1]
	orrs	r3, r0
	strh	r3, [r1]
	ldr	r3, .L197+28
	strh	r2, [r3]
	movs	r3, #0
	str	r3, [sp, #20]
	subs	r3, r3, #1
	str	r3, [sp, #4]
	movs	r3, #0
	str	r3, [sp, #8]
	ldr	r3, .L197+32
	str	r3, [sp, #12]
	ldr	r3, .L197+36
	str	r3, [sp, #36]
	ldr	r3, .L197+40
	str	r3, [sp, #44]
	ldr	r3, .L197+44
	str	r3, [sp, #28]
	ldr	r3, .L197+48
	str	r3, [sp, #16]
	ldr	r3, .L197+52
	str	r3, [sp, #32]
	ldr	r3, .L197+56
	str	r3, [sp, #48]
	ldr	r3, .L197+60
	str	r3, [sp, #56]
	ldr	r3, .L197+64
	str	r3, [sp, #60]
	ldr	r3, .L197+68
	str	r3, [sp, #52]
	ldr	r3, .L197+72
	str	r3, [sp, #64]
	ldr	r3, .L197+76
	str	r3, [sp, #68]
	ldr	r3, .L197+80
	movs	r1, #2
	str	r3, [sp, #40]
	ldr	r3, .L197+84
	str	r3, [sp, #124]
	ldr	r3, .L197+88
	str	r3, [sp, #104]
	ldr	r3, .L197+92
	str	r3, [sp, #108]
	ldr	r3, .L197+96
	str	r3, [sp, #112]
	ldr	r3, .L197+100
	str	r3, [sp, #116]
	ldr	r3, .L197+104
	str	r3, [sp, #120]
	ldr	r3, .L197+108
	str	r3, [sp, #24]
	ldr	r3, .L197+112
	str	r3, [sp, #72]
	ldr	r3, .L197+116
	str	r3, [sp, #76]
	ldr	r3, .L197+120
	str	r3, [sp, #80]
	ldr	r3, .L197+124
	str	r3, [sp, #84]
	ldr	r3, .L197+128
	str	r3, [sp, #88]
	ldr	r3, .L197+132
	str	r3, [sp, #92]
	ldr	r3, .L197+136
	str	r3, [sp, #96]
	ldr	r3, .L197+140
	ldr	r4, .L197+144
	str	r3, [sp, #100]
	rsbs	r1, r1, #0
.L38:
	ldrh	r3, [r4]
	cmp	r3, #159
	bhi	.L38
.L39:
	ldrh	r3, [r4]
	cmp	r3, #159
	bls	.L39
	ldr	r3, .L197+8
	ldrh	r5, [r3]
	bics	r7, r5
	lsls	r7, r7, #16
	lsrs	r3, r7, #16
	mov	fp, r3
	ldr	r3, [sp, #4]
	adds	r3, r3, #1
	beq	.L189
	ldr	r3, [sp, #4]
	cmp	r3, #0
	beq	.LCB346
	b	.L65	@long jump
.LCB346:
	cmp	r1, #0
	beq	.LCB348
	b	.L115	@long jump
.LCB348:
.L77:
	mov	r3, fp
	lsls	r3, r3, #28
	bpl	.LCB356
	b	.L67	@long jump
.LCB356:
	movs	r1, #0
.L101:
	mov	r3, fp
	lsls	r7, r3, #30
	bpl	.L57
	movs	r3, #1
	movs	r1, #2
	rsbs	r3, r3, #0
	str	r3, [sp, #4]
	rsbs	r1, r1, #0
.L57:
	movs	r7, r5
	b	.L38
.L189:
	adds	r1, r1, #1
	beq	.LCB380
	b	.L107	@long jump
.LCB380:
	ldr	r3, [sp, #12]
	ldr	r6, [r3]
	ldr	r3, [sp, #8]
	cmp	r3, #0
	bne	.LCB385
	b	.L190	@long jump
.LCB385:
.L183:
	ldrb	r2, [r6]
	cmp	r2, #0
	beq	.L51
	ldr	r3, .L197+148
	mov	r10, r3
.L47:
	movs	r3, #0
	mov	r9, r5
	movs	r7, #20
	mov	r8, r3
	mov	r5, r10
.L50:
	mov	r3, r8
	movs	r0, r7
	str	r3, [sp]
	movs	r1, #30
	movs	r3, r5
	adds	r6, r6, #1
	bl	DrawChar
	ldrb	r2, [r6]
	adds	r7, r7, #8
	cmp	r2, #0
	bne	.L50
	mov	r5, r9
.L51:
	ldr	r3, [sp, #8]
	cmp	r3, #1
	bne	.LCB417
	b	.L191	@long jump
.LCB417:
.L49:
	ldr	r3, .L197+148
	mov	r10, r3
.L48:
	ldr	r3, [sp, #12]
	ldr	r6, [r3, #4]
	movs	r3, #0
	ldrb	r2, [r6]
	movs	r7, #20
	mov	r9, r3
	cmp	r2, #0
	beq	.L55
	mov	r8, r5
	mov	r5, r10
.L52:
	mov	r3, r9
	movs	r0, r7
	str	r3, [sp]
	movs	r1, #42
	movs	r3, r5
	adds	r6, r6, #1
	bl	DrawChar
	ldrb	r2, [r6]
	adds	r7, r7, #8
	cmp	r2, #0
	bne	.L52
	mov	r5, r8
.L55:
	movs	r3, #128
	mov	r2, fp
	ands	r3, r2
	lsls	r2, r2, #25
	bpl	.L54
	ldr	r2, [sp, #8]
	subs	r2, r2, #1
	bpl	.LCB463
	b	.L192	@long jump
.LCB463:
	str	r2, [sp, #8]
.L54:
	cmp	r3, #0
	beq	.L56
	movs	r1, #0
	movs	r0, #1
	ldr	r2, [sp, #8]
	adds	r2, r2, #1
	lsrs	r3, r2, #31
	cmp	r0, r2
	adcs	r3, r3, r1
	rsbs	r3, r3, #0
	ands	r2, r3
	str	r2, [sp, #8]
.L56:
	movs	r3, #1
	mov	r2, fp
	tst	r3, r2
	beq	.L113
	ldr	r3, [sp, #28]
	ldr	r0, [r3]
	movs	r3, #0
	cmp	r0, #0
	beq	.L61
	ldr	r1, [sp, #16]
	ldr	r6, [sp, #32]
	b	.L58
.L193:
	ldr	r2, .L197+152
	adds	r2, r3, r2
	cmp	r2, #0
	beq	.L128
.L58:
	ldrb	r2, [r6, r3]
	strb	r2, [r1, r3]
	adds	r3, r3, #1
	cmp	r3, r0
	bcc	.L193
.L128:
	cmp	r0, #8
	beq	.L188
.L61:
	movs	r3, #0
	ldr	r2, [sp, #16]
	subs	r0, r0, #8
	b	.L59
.L63:
	adds	r2, r2, #1
	cmp	r0, r3
	bls	.L188
.L59:
	ldrb	r6, [r2]
	movs	r1, r3
	adds	r3, r3, #1
	cmp	r6, #17
	bne	.L63
	ldrb	r6, [r2, #1]
	cmp	r6, #34
	bne	.L63
	ldrb	r6, [r2, #2]
	cmp	r6, #51
	bne	.L63
	ldrb	r6, [r2, #3]
	cmp	r6, #68
	bne	.L63
	ldrb	r6, [r2, #4]
	cmp	r6, #85
	bne	.L63
	ldrb	r6, [r2, #5]
	cmp	r6, #102
	bne	.L63
	ldrb	r6, [r2, #6]
	cmp	r6, #119
	bne	.L63
	ldrb	r6, [r2, #7]
	cmp	r6, #136
	bne	.L63
	ldr	r3, [sp, #8]
	ldr	r2, [sp, #48]
	lsls	r3, r3, #2
	ldr	r0, [r2, r3]
	ldr	r2, [sp, #16]
	mov	ip, r2
	movs	r3, #0
	adds	r1, r1, #8
	add	r1, r1, ip
.L64:
	ldrb	r2, [r0, r3]
	strb	r2, [r1, r3]
	adds	r3, r3, #1
	cmp	r3, #100
	bne	.L64
.L188:
	movs	r1, #1
	movs	r3, #0
	movs	r7, r5
	str	r3, [sp, #4]
	rsbs	r1, r1, #0
	b	.L38
.L65:
	ldr	r3, [sp, #4]
	cmp	r3, #1
	bne	.LCB586
	b	.L194	@long jump
.LCB586:
	ldr	r3, [sp, #4]
	cmp	r3, #2
	beq	.LCB589
	b	.L57	@long jump
.LCB589:
	cmp	r1, #2
	beq	.LCB591
	b	.L125	@long jump
.LCB591:
.L106:
	mov	r3, fp
	movs	r1, #2
	lsls	r3, r3, #28
	bmi	.LCB600
	b	.L101	@long jump
.LCB600:
	movs	r3, #0
	rsbs	r1, r1, #0
	str	r3, [sp, #4]
	b	.L101
.L113:
	movs	r1, #1
	movs	r7, r5
	rsbs	r1, r1, #0
	b	.L38
.L107:
	movs	r3, #192
	movs	r1, #0
	ldr	r2, .L197+4
	lsls	r3, r3, #19
.L41:
	strh	r1, [r3]
	adds	r3, r3, #2
	cmp	r3, r2
	bne	.L41
	movs	r3, #0
	movs	r6, #10
	movs	r2, #83
	mov	r8, r3
	ldr	r7, [sp, #36]
.L44:
	mov	r3, r8
	movs	r0, r6
	str	r3, [sp]
	movs	r1, #10
	ldr	r3, .L197+148
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L44
	movs	r3, #0
	movs	r6, #10
	mov	r8, r3
	ldr	r7, [sp, #44]
	adds	r2, r2, #80
.L45:
	mov	r3, r8
	movs	r0, r6
	str	r3, [sp]
	movs	r1, #140
	ldr	r3, .L197+148
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L45
	ldr	r3, [sp, #12]
	ldr	r6, [r3]
	ldr	r3, [sp, #8]
	cmp	r3, #0
	beq	.LCB665
	b	.L183	@long jump
.LCB665:
.L190:
	movs	r3, #248
	ldrb	r2, [r6]
	lsls	r3, r3, #2
	mov	r10, r3
	cmp	r2, #0
	beq	.LCB672
	b	.L47	@long jump
.LCB672:
	b	.L49
.L198:
	.align	2
.L197:
	.word	1027
	.word	100740096
	.word	67109168
	.word	67108860
	.word	IntrMain
	.word	67109376
	.word	67108868
	.word	67109384
	.word	options
	.word	.LC1
	.word	.LC3
	.word	gMultibootEventPayloadSize
	.word	gPatchedPayload
	.word	gMultibootEventPayload
	.word	dataPointers
	.word	.LC5
	.word	.LC7
	.word	.LC9
	.word	.LC11
	.word	.LC13
	.word	.LC15
	.word	.LC17
	.word	.LC19
	.word	.LC21
	.word	.LC23
	.word	.LC25
	.word	.LC27
	.word	.LC51
	.word	.LC29
	.word	.LC31
	.word	.LC33
	.word	.LC35
	.word	.LC37
	.word	.LC39
	.word	.LC41
	.word	.LC43
	.word	67108870
	.word	32767
	.word	-4096
.L194:
	cmp	r1, #1
	beq	.LCB722
	b	.L195	@long jump
.LCB722:
.L79:
	movs	r3, #2
	mov	r6, fp
	mov	r2, fp
	ands	r6, r3
	tst	r3, r2
	beq	.LCB731
	b	.L119	@long jump
.LCB731:
	movs	r1, #8
	ldr	r2, .L199
	ldrh	r3, [r2]
	orrs	r3, r1
	strh	r3, [r2]
	add	r0, sp, #144
	bl	MultiBootMain
	ldr	r3, .L199+4
	str	r3, [sp, #128]
	add	r3, sp, #124
	ldr	r2, [sp, #24]
	strb	r6, [r3, #8]
	lsls	r3, r0, #24
	lsrs	r3, r3, #28
	ldrb	r3, [r2, r3]
	add	r1, sp, #124
	strb	r3, [r1, #6]
	movs	r3, #15
	ands	r3, r0
	ldrb	r3, [r2, r3]
	add	r2, sp, #124
	strb	r3, [r2, #7]
	movs	r3, #0
	mov	r8, r0
	movs	r6, #10
	movs	r2, #69
	mov	r9, r3
	ldr	r7, [sp, #72]
.L89:
	mov	r3, r9
	movs	r0, r6
	str	r3, [sp]
	movs	r1, #60
	ldr	r3, .L199+8
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L89
	movs	r3, #0
	movs	r6, #42
	mov	r9, r3
	add	r7, sp, #128
	adds	r2, r2, #48
.L90:
	mov	r3, r9
	movs	r0, r6
	str	r3, [sp]
	movs	r1, #60
	ldr	r3, .L199+12
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L90
	adds	r2, r2, #44
	add	r3, sp, #124
	adds	r3, r3, r2
	ldrb	r2, [r3]
	ldr	r1, [sp, #24]
	lsrs	r3, r2, #4
	ldrb	r3, [r1, r3]
	add	r0, sp, #124
	strb	r3, [r0, #6]
	movs	r3, #15
	ands	r3, r2
	ldrb	r3, [r1, r3]
	strb	r3, [r0, #7]
	movs	r3, #0
	movs	r6, #10
	movs	r2, #80
	mov	r9, r3
	ldr	r7, [sp, #76]
.L91:
	mov	r3, r9
	movs	r0, r6
	str	r3, [sp]
	movs	r1, #70
	ldr	r3, .L199+8
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L91
	movs	r3, #0
	movs	r6, #42
	mov	r9, r3
	add	r7, sp, #128
	adds	r2, r2, #48
.L92:
	mov	r3, r9
	movs	r0, r6
	str	r3, [sp]
	movs	r1, #70
	ldr	r3, .L199+12
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L92
	adds	r2, r2, #50
	add	r3, sp, #124
	adds	r3, r3, r2
	ldrb	r2, [r3]
	ldr	r1, [sp, #24]
	lsrs	r3, r2, #4
	ldrb	r3, [r1, r3]
	add	r0, sp, #124
	strb	r3, [r0, #6]
	movs	r3, #15
	ands	r3, r2
	ldrb	r3, [r1, r3]
	strb	r3, [r0, #7]
	movs	r3, #0
	movs	r6, #10
	movs	r2, #67
	mov	r9, r3
	ldr	r7, [sp, #80]
.L93:
	mov	r3, r9
	movs	r0, r6
	str	r3, [sp]
	movs	r1, #80
	ldr	r3, .L199+8
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L93
	movs	r3, #0
	movs	r6, #42
	mov	r9, r3
	add	r7, sp, #128
	adds	r2, r2, #48
.L94:
	mov	r3, r9
	movs	r0, r6
	str	r3, [sp]
	movs	r1, #80
	ldr	r3, .L199+12
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L94
	ldr	r3, .L199
	ldrh	r3, [r3]
	mov	r9, r3
	lsrs	r2, r3, #4
	movs	r3, #15
	ldr	r1, [sp, #24]
	ands	r2, r3
	ldrb	r2, [r1, r2]
	add	r0, sp, #124
	strb	r2, [r0, #6]
	mov	r2, r9
	ands	r3, r2
	ldrb	r3, [r1, r3]
	strb	r3, [r0, #7]
	movs	r3, #0
	movs	r6, #10
	movs	r2, #83
	mov	r10, r3
	ldr	r7, [sp, #84]
.L95:
	mov	r3, r10
	movs	r0, r6
	str	r3, [sp]
	movs	r1, #90
	ldr	r3, .L199+8
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L95
	movs	r3, #0
	movs	r6, #42
	mov	r10, r3
	add	r7, sp, #128
	adds	r2, r2, #48
.L96:
	mov	r3, r10
	movs	r0, r6
	str	r3, [sp]
	movs	r1, #90
	ldr	r3, .L199+12
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L96
	ldr	r3, .L199+4
	str	r3, [sp, #136]
	add	r3, sp, #124
	strb	r2, [r3, #16]
	mov	r3, r9
	ldr	r2, [sp, #24]
	lsrs	r3, r3, #12
	ldrb	r3, [r2, r3]
	add	r1, sp, #124
	strb	r3, [r1, #14]
	mov	r3, r9
	lsls	r3, r3, #20
	lsrs	r3, r3, #28
	ldrb	r3, [r2, r3]
	strb	r3, [r1, #15]
	movs	r3, #0
	movs	r6, #74
	movs	r2, #48
	mov	r9, r3
	add	r7, sp, #136
.L97:
	mov	r3, r9
	movs	r0, r6
	str	r3, [sp]
	movs	r1, #90
	ldr	r3, .L199+12
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L97
	add	r0, sp, #144
	bl	MultiBootCheckComplete
	cmp	r0, #0
	beq	.LCB1000
	b	.L120	@long jump
.LCB1000:
	ldr	r3, [sp, #28]
	ldr	r2, [r3]
	mov	r3, r8
	cmp	r3, #0
	beq	.LCB1005
	b	.L196	@long jump
.LCB1005:
	ldr	r3, [sp, #20]
	cmp	r3, #0
	beq	.LCB1008
	b	.L121	@long jump
.LCB1008:
	movs	r1, #50
	add	r3, sp, #124
	adds	r3, r3, r1
	ldrb	r3, [r3]
	subs	r1, r1, #49
	cmp	r3, #0
	bne	.LCB1015
	b	.L57	@long jump
.LCB1015:
	movs	r6, #20
	adds	r1, r1, #43
	add	r3, sp, #124
	add	r0, sp, #124
	adds	r3, r3, r1
	adds	r0, r0, r6
	adds	r1, r1, #30
	ldrb	r1, [r0, r1]
	ldrb	r3, [r3]
	orrs	r3, r1
	ldr	r1, [sp, #4]
	beq	.LCB1030
	b	.L57	@long jump
.LCB1030:
	ldr	r3, [sp, #20]
	ldr	r1, [sp, #16]
	str	r3, [sp]
	add	r0, sp, #144
	movs	r3, #4
	bl	MultiBootStartMaster
	movs	r2, #44
	add	r3, sp, #124
	adds	r3, r3, r2
	ldrb	r3, [r3]
	cmp	r3, #208
	beq	.LCB1042
	b	.L99	@long jump
.LCB1042:
	movs	r1, #2
	ldr	r3, [sp, #4]
	movs	r7, r5
	str	r3, [sp, #20]
	rsbs	r1, r1, #0
	b	.L38
.L67:
	add	r0, sp, #144
	bl	MultiBootInit
	movs	r3, #0
	movs	r1, #2
	str	r3, [sp, #20]
	adds	r3, r3, #1
	str	r3, [sp, #4]
	rsbs	r1, r1, #0
	b	.L101
.L115:
	movs	r3, #192
	movs	r1, #0
	ldr	r2, .L199+16
	lsls	r3, r3, #19
.L66:
	strh	r1, [r3]
	adds	r3, r3, #2
	cmp	r3, r2
	bne	.L66
	ldr	r3, [sp, #56]
	mov	r8, r3
	movs	r3, #0
	movs	r6, #10
	movs	r2, #68
	mov	r9, r3
	mov	r7, r8
.L69:
	mov	r3, r9
	str	r3, [sp]
	movs	r3, #248
	movs	r0, r6
	movs	r1, #10
	lsls	r3, r3, #2
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L69
	ldr	r3, [sp, #60]
	mov	r8, r3
	movs	r3, #0
	movs	r6, #10
	mov	r9, r3
	mov	r7, r8
	adds	r2, r2, #67
.L70:
	mov	r3, r9
	movs	r0, r6
	str	r3, [sp]
	movs	r1, #30
	ldr	r3, .L199+8
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L70
	ldr	r3, [sp, #8]
	ldr	r2, [sp, #12]
	lsls	r3, r3, #2
	ldr	r6, [r2, r3]
	movs	r3, #120
	mov	r8, r3
	movs	r3, #0
	ldrb	r2, [r6]
	mov	r9, r3
	mov	r7, r8
	cmp	r2, #0
	beq	.L73
.L71:
	mov	r3, r9
	str	r3, [sp]
	movs	r3, #248
	movs	r0, r7
	movs	r1, #30
	lsls	r3, r3, #2
	adds	r6, r6, #1
	bl	DrawChar
	ldrb	r2, [r6]
	adds	r7, r7, #8
	cmp	r2, #0
	bne	.L71
.L73:
	ldr	r3, [sp, #52]
	mov	r8, r3
	movs	r3, #0
	movs	r6, #10
	movs	r2, #67
	mov	r9, r3
	mov	r7, r8
.L72:
	mov	r3, r9
	movs	r0, r6
	str	r3, [sp]
	movs	r1, #50
	ldr	r3, .L199+8
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L72
	ldr	r3, [sp, #64]
	mov	r8, r3
	movs	r3, #0
	movs	r6, #10
	mov	r9, r3
	mov	r7, r8
	adds	r2, r2, #119
.L74:
	mov	r3, r9
	movs	r0, r6
	str	r3, [sp]
	movs	r1, #60
	ldr	r3, .L199+8
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L74
	ldr	r3, [sp, #68]
	mov	r8, r3
	movs	r3, #0
	movs	r6, #10
	mov	r9, r3
	mov	r7, r8
	adds	r2, r2, #80
.L75:
	mov	r3, r9
	movs	r0, r6
	str	r3, [sp]
	movs	r1, #80
	ldr	r3, .L199+8
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L75
	ldr	r3, [sp, #40]
	mov	r8, r3
	movs	r3, #0
	movs	r6, #10
	mov	r9, r3
	mov	r7, r8
	adds	r2, r2, #80
.L76:
	mov	r3, r9
	movs	r0, r6
	str	r3, [sp]
	movs	r1, #140
	movs	r3, #31
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L76
	b	.L77
.L191:
	movs	r3, #248
	lsls	r3, r3, #2
	mov	r10, r3
	b	.L48
.L192:
	rsbs	r2, r3, #0
	adcs	r2, r2, r3
	str	r2, [sp, #8]
	b	.L56
.L200:
	.align	2
.L199:
	.word	67109160
	.word	808482864
	.word	32767
	.word	1023
	.word	100740096
.L119:
	movs	r1, #2
	movs	r3, #0
	movs	r7, r5
	str	r3, [sp, #4]
	rsbs	r1, r1, #0
	b	.L38
.L195:
	movs	r3, #192
	movs	r1, #0
	ldr	r2, .L201
	lsls	r3, r3, #19
.L80:
	strh	r1, [r3]
	adds	r3, r3, #2
	cmp	r3, r2
	bne	.L80
	ldr	r3, [sp, #20]
	cmp	r3, #0
	beq	.LCB1271
	b	.L118	@long jump
.LCB1271:
	ldr	r3, [sp, #124]
	mov	r8, r3
	movs	r3, #0
	movs	r6, #10
	movs	r2, #83
	mov	r9, r3
	mov	r7, r8
.L82:
	mov	r3, r9
	movs	r0, r6
	str	r3, [sp]
	movs	r1, #10
	ldr	r3, .L201+4
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L82
	ldr	r3, [sp, #104]
	mov	r8, r3
	movs	r3, #0
	movs	r6, #10
	mov	r9, r3
	mov	r7, r8
	adds	r2, r2, #84
.L83:
	mov	r3, r9
	movs	r0, r6
	str	r3, [sp]
	movs	r1, #30
	ldr	r3, .L201+8
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L83
	ldr	r3, [sp, #108]
	mov	r8, r3
	movs	r3, #0
	movs	r6, #10
	mov	r9, r3
	mov	r7, r8
	adds	r2, r2, #40
.L84:
	mov	r3, r9
	movs	r0, r6
	str	r3, [sp]
	movs	r1, #40
	ldr	r3, .L201+8
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L84
.L85:
	ldr	r3, [sp, #40]
	mov	r8, r3
	movs	r3, #0
	movs	r6, #10
	movs	r2, #80
	mov	r9, r3
	mov	r7, r8
.L88:
	mov	r3, r9
	movs	r0, r6
	str	r3, [sp]
	movs	r1, #140
	movs	r3, #31
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L88
	b	.L79
.L125:
	movs	r3, #192
	movs	r1, #0
	ldr	r2, .L201
	lsls	r3, r3, #19
.L100:
	strh	r1, [r3]
	adds	r3, r3, #2
	cmp	r3, r2
	bne	.L100
	ldr	r3, [sp, #88]
	mov	r8, r3
	movs	r3, #0
	movs	r6, #10
	movs	r2, #83
	mov	r9, r3
	mov	r7, r8
.L102:
	mov	r3, r9
	str	r3, [sp]
	movs	r3, #248
	movs	r0, r6
	movs	r1, #10
	lsls	r3, r3, #2
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L102
	ldr	r3, [sp, #92]
	mov	r8, r3
	movs	r3, #0
	movs	r6, #10
	mov	r9, r3
	mov	r7, r8
	adds	r2, r2, #80
.L103:
	mov	r3, r9
	movs	r0, r6
	str	r3, [sp]
	movs	r1, #30
	ldr	r3, .L201+8
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L103
	ldr	r3, [sp, #96]
	mov	r8, r3
	movs	r3, #0
	movs	r6, #10
	mov	r9, r3
	mov	r7, r8
	adds	r2, r2, #80
.L104:
	mov	r3, r9
	movs	r0, r6
	str	r3, [sp]
	movs	r1, #60
	ldr	r3, .L201+8
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L104
	ldr	r3, [sp, #100]
	mov	r8, r3
	movs	r3, #0
	movs	r6, #10
	mov	r9, r3
	mov	r7, r8
	adds	r2, r2, #80
.L105:
	mov	r3, r9
	movs	r0, r6
	str	r3, [sp]
	movs	r1, #140
	ldr	r3, .L201+8
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L105
	b	.L106
.L120:
	movs	r1, #2
	movs	r3, #2
	movs	r7, r5
	str	r3, [sp, #4]
	rsbs	r1, r1, #0
	bl	.L38	@ far jump
.L118:
	ldr	r3, [sp, #112]
	mov	r8, r3
	movs	r3, #0
	movs	r6, #10
	movs	r2, #84
	mov	r9, r3
	mov	r7, r8
.L81:
	mov	r3, r9
	movs	r0, r6
	str	r3, [sp]
	movs	r1, #10
	ldr	r3, .L201+4
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L81
	ldr	r3, [sp, #116]
	mov	r8, r3
	movs	r3, #0
	movs	r6, #10
	mov	r9, r3
	mov	r7, r8
	adds	r2, r2, #68
.L86:
	mov	r3, r9
	movs	r0, r6
	str	r3, [sp]
	movs	r1, #30
	ldr	r3, .L201+8
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L86
	ldr	r3, [sp, #120]
	mov	r8, r3
	movs	r3, #0
	movs	r6, #10
	mov	r9, r3
	mov	r7, r8
	adds	r2, r2, #101
.L87:
	mov	r3, r9
	movs	r0, r6
	str	r3, [sp]
	movs	r1, #40
	ldr	r3, .L201+8
	adds	r7, r7, #1
	bl	DrawChar
	ldrb	r2, [r7]
	adds	r6, r6, #8
	cmp	r2, #0
	bne	.L87
	b	.L85
.L196:
	add	r0, sp, #144
	bl	MultiBootInit
.L99:
	movs	r3, #0
	movs	r1, #1
	movs	r7, r5
	str	r3, [sp, #20]
	bl	.L38	@ far jump
.L121:
	ldr	r3, [sp, #20]
	movs	r7, r5
	movs	r1, r3
	str	r3, [sp, #4]
	bl	.L38	@ far jump
.L202:
	.align	2
.L201:
	.word	100740096
	.word	1023
	.word	32767
	.size	PayloadMain, .-PayloadMain
	.global	dataPointers
	.section	.data.dataPointers,"aw"
	.align	2
	.type	dataPointers, %object
	.size	dataPointers, 8
dataPointers:
	.word	auraMew
	.word	pcnySeviper
	.global	options
	.section	.rodata.str1.4,"aMS",%progbits,1
	.align	2
.LC54:
	.ascii	"Aura Mew\000"
	.align	2
.LC55:
	.ascii	"PCNY Seviper\000"
	.section	.data.options,"aw"
	.align	2
	.type	options, %object
	.size	options, 8
options:
	.word	.LC54
	.word	.LC55
	.global	pcnySeviper
	.section	.rodata.pcnySeviper,"a"
	.align	2
	.type	pcnySeviper, %object
	.size	pcnySeviper, 100
pcnySeviper:
	.ascii	"\000\000\000\000nN\000\000\315\331\352\335\336\331\314"
	.ascii	"\377\000\000\002\002\312\275\316\315\377\000\000\000"
	.ascii	"`\237\000\000P\001\000\000\342\004\000\000\000x\000"
	.ascii	"\000\001\000\000\000\000\000\000\000#\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000\000\000\000\000\377"
	.ascii	"\012\"\000\000\000\000\000\000\000\000\000\000\000\000"
	.ascii	"\012\000(\000(\000\031\000\031\000\031\000\031\000\031"
	.ascii	"\000"
	.global	auraMew
	.section	.rodata.auraMew,"a"
	.align	2
	.type	auraMew, %object
	.size	auraMew, 100
auraMew:
	.ascii	"\000\000\000\000nN\000\000\301\277\321\377\000\000\000"
	.ascii	"\000\000\000\002\002\273\357\314\273\377\000\000\000"
	.ascii	"7\251\000\000\227\000\000\000\342\004\000\000\000x\000"
	.ascii	"\000\001\000\220\000\000\000\000\000#\012\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000\000\000\000\000\377"
	.ascii	"\012\"\000\000\000\000\000\000\000\000\000\000\000\000"
	.ascii	"\012\000(\000(\000\031\000\031\000\031\000\031\000\031"
	.ascii	"\000"
	.global	gPatchedPayload
	.section	.bss.gPatchedPayload,"aw",%nobits
	.align	2
	.type	gPatchedPayload, %object
	.size	gPatchedPayload, 4096
gPatchedPayload:
	.space	4096
	.global	font8x8_basic
	.section	.rodata.font8x8_basic,"a"
	.align	2
	.type	font8x8_basic, %object
	.size	font8x8_basic, 1024
font8x8_basic:
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ascii	"\030<<\030\030\000\030\000"
	.ascii	"66\000\000\000\000\000\000"
	.ascii	"66\1776\17766\000"
	.ascii	"\014>\003\0360\037\014\000"
	.ascii	"\000c3\030\014fc\000"
	.ascii	"\0346\034n;3n\000"
	.ascii	"\006\006\003\000\000\000\000\000"
	.ascii	"\030\014\006\006\006\014\030\000"
	.ascii	"\006\014\030\030\030\014\006\000"
	.ascii	"\000f<\377<f\000\000"
	.ascii	"\000\014\014?\014\014\000\000"
	.ascii	"\000\000\000\000\000\014\014\006"
	.ascii	"\000\000\000?\000\000\000\000"
	.ascii	"\000\000\000\000\000\014\014\000"
	.ascii	"`0\030\014\006\003\001\000"
	.ascii	">cs{og>\000"
	.ascii	"\014\016\014\014\014\014?\000"
	.ascii	"\03630\034\0063?\000"
	.ascii	"\03630\03403\036\000"
	.ascii	"8<63\1770x\000"
	.ascii	"?\003\037003\036\000"
	.ascii	"\034\006\003\03733\036\000"
	.ascii	"?30\030\014\014\014\000"
	.ascii	"\03633\03633\036\000"
	.ascii	"\03633>0\030\016\000"
	.ascii	"\000\014\014\000\000\014\014\000"
	.ascii	"\000\014\014\000\000\014\014\006"
	.ascii	"\030\014\006\003\006\014\030\000"
	.ascii	"\000\000?\000\000?\000\000"
	.ascii	"\006\014\0300\030\014\006\000"
	.ascii	"\03630\030\014\000\014\000"
	.ascii	">c{{{\003\036\000"
	.ascii	"\014\03633?33\000"
	.ascii	"?ff>ff?\000"
	.ascii	"<f\003\003\003f<\000"
	.ascii	"\0376fff6\037\000"
	.ascii	"\177F\026\036\026F\177\000"
	.ascii	"\177F\026\036\026\006\017\000"
	.ascii	"<f\003\003sf|\000"
	.ascii	"333?333\000"
	.ascii	"\036\014\014\014\014\014\036\000"
	.ascii	"x00033\036\000"
	.ascii	"gf6\0366fg\000"
	.ascii	"\017\006\006\006Ff\177\000"
	.ascii	"cw\177\177kcc\000"
	.ascii	"cgo{scc\000"
	.ascii	"\0346ccc6\034\000"
	.ascii	"?ff>\006\006\017\000"
	.ascii	"\036333;\0368\000"
	.ascii	"?ff>6fg\000"
	.ascii	"\0363\007\01683\036\000"
	.ascii	"?-\014\014\014\014\036\000"
	.ascii	"333333?\000"
	.ascii	"33333\036\014\000"
	.ascii	"ccck\177wc\000"
	.ascii	"cc6\034\0346c\000"
	.ascii	"333\036\014\014\036\000"
	.ascii	"\177c1\030Lf\177\000"
	.ascii	"\036\006\006\006\006\006\036\000"
	.ascii	"\003\006\014\0300`@\000"
	.ascii	"\036\030\030\030\030\030\036\000"
	.ascii	"\010\0346c\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\377"
	.ascii	"\014\014\030\000\000\000\000\000"
	.ascii	"\000\000\0360>3n\000"
	.ascii	"\007\006\006>ff;\000"
	.ascii	"\000\000\0363\0033\036\000"
	.ascii	"800>33n\000"
	.ascii	"\000\000\0363?\003\036\000"
	.ascii	"\0346\006\017\006\006\017\000"
	.ascii	"\000\000n33>0\037"
	.ascii	"\007\0066nffg\000"
	.ascii	"\014\000\016\014\014\014\036\000"
	.ascii	"0\00000033\036"
	.ascii	"\007\006f6\0366g\000"
	.ascii	"\016\014\014\014\014\014\036\000"
	.ascii	"\000\0003\177\177kc\000"
	.ascii	"\000\000\0373333\000"
	.ascii	"\000\000\036333\036\000"
	.ascii	"\000\000;ff>\006\017"
	.ascii	"\000\000n33>0x"
	.ascii	"\000\000;nf\006\017\000"
	.ascii	"\000\000>\003\0360\037\000"
	.ascii	"\010\014>\014\014,\030\000"
	.ascii	"\000\0003333n\000"
	.ascii	"\000\000333\036\014\000"
	.ascii	"\000\000ck\177\1776\000"
	.ascii	"\000\000c6\0346c\000"
	.ascii	"\000\000333>0\037"
	.ascii	"\000\000?\031\014&?\000"
	.ascii	"8\014\014\007\014\0148\000"
	.ascii	"\030\030\030\000\030\030\030\000"
	.ascii	"\007\014\0148\014\014\007\000"
	.ascii	"n;\000\000\000\000\000\000"
	.ascii	"\000\000\000\000\000\000\000\000"
	.ident	"GCC: (15:13.2.rel1-2) 13.2.1 20231009"
