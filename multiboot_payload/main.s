	.arch armv4t
	.fpu softvfp
	.file	"main.c"
	.text
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
	ldr	r1, .L5
	lsrs	r2, r2, #16
	lsls	r3, r3, #19
.L2:
	strh	r2, [r3]
	adds	r3, r3, #2
	cmp	r3, r1
	bne	.L2
	@ sp needed
	bx	lr
.L6:
	.align	2
.L5:
	.word	100740096
	.size	DrawScreenColor, .-DrawScreenColor
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
	beq	.L8
	movs	r3, #0
.L9:
	ldrb	r4, [r1, r3]
	strb	r4, [r0, r3]
	adds	r3, r3, #1
	cmp	r3, r2
	bne	.L9
.L8:
	@ sp needed
	pop	{r4}
	pop	{r1}
	bx	r1
	.size	memcpy, .-memcpy
	.section	.text.FlashSwitchBank,"ax",%progbits
	.align	1
	.p2align 2,,3
	.global	FlashSwitchBank
	.syntax unified
	.code	16
	.thumb_func
	.type	FlashSwitchBank, %function
FlashSwitchBank:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	movs	r2, #170
	@ sp needed
	movs	r1, #85
	ldr	r3, .L15
	strb	r2, [r3]
	ldr	r2, .L15+4
	strb	r1, [r2]
	movs	r2, #176
	strb	r2, [r3]
	movs	r3, #224
	lsls	r0, r0, #24
	lsrs	r0, r0, #24
	lsls	r3, r3, #20
	strb	r0, [r3]
	bx	lr
.L16:
	.align	2
.L15:
	.word	234902869
	.word	234891946
	.size	FlashSwitchBank, .-FlashSwitchBank
	.section	.text.FlashEraseSector,"ax",%progbits
	.align	1
	.p2align 2,,3
	.global	FlashEraseSector
	.syntax unified
	.code	16
	.thumb_func
	.type	FlashEraseSector, %function
FlashEraseSector:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, r5, r6, lr}
	movs	r1, #85
	movs	r4, #170
	movs	r6, #176
	ldr	r3, .L20
	ldr	r2, .L20+4
	strb	r4, [r3]
	strb	r1, [r2]
	strb	r6, [r3]
	movs	r6, #224
	lsls	r5, r0, #20
	lsrs	r5, r5, #24
	lsls	r6, r6, #20
	strb	r5, [r6]
	movs	r5, #128
	mov	ip, r6
	strb	r4, [r3]
	strb	r1, [r2]
	strb	r5, [r3]
	strb	r4, [r3]
	movs	r3, #48
	strb	r1, [r2]
	lsls	r2, r0, #28
	lsrs	r2, r2, #16
	add	r2, r2, ip
	strb	r3, [r2]
.L18:
	ldrb	r3, [r2]
	cmp	r3, #255
	bne	.L18
	@ sp needed
	pop	{r4, r5, r6}
	pop	{r0}
	bx	r0
.L21:
	.align	2
.L20:
	.word	234902869
	.word	234891946
	.size	FlashEraseSector, .-FlashEraseSector
	.section	.text.FlashWriteSector,"ax",%progbits
	.align	1
	.p2align 2,,3
	.global	FlashWriteSector
	.syntax unified
	.code	16
	.thumb_func
	.type	FlashWriteSector, %function
FlashWriteSector:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, r5, r6, r7, lr}
	mov	r7, r8
	mov	lr, r9
	movs	r4, #170
	movs	r3, r0
	lsls	r2, r0, #20
	ldr	r0, .L27
	ldr	r5, .L27+4
	push	{r7, lr}
	strb	r4, [r0]
	subs	r4, r4, #85
	strb	r4, [r5]
	adds	r4, r4, #91
	strb	r4, [r0]
	movs	r4, #224
	lsls	r3, r3, #28
	lsrs	r3, r3, #16
	lsls	r4, r4, #20
	lsrs	r2, r2, #24
	strb	r2, [r4]
	adds	r2, r3, r4
	ldr	r4, .L27+8
	mov	r8, r4
	movs	r4, #170
	add	r8, r8, r3
	mov	ip, r4
	subs	r4, r1, r3
	movs	r3, #242
	lsls	r3, r3, #24
	mov	r9, r3
	movs	r7, #85
	movs	r6, #160
	add	r4, r4, r9
.L24:
	mov	r3, ip
	strb	r3, [r0]
	strb	r7, [r5]
	strb	r6, [r0]
	ldrb	r1, [r4, r2]
	strb	r1, [r2]
.L23:
	ldrb	r3, [r2]
	cmp	r1, r3
	bne	.L23
	adds	r2, r2, #1
	cmp	r2, r8
	bne	.L24
	@ sp needed
	pop	{r6, r7}
	mov	r9, r7
	mov	r8, r6
	pop	{r4, r5, r6, r7}
	pop	{r0}
	bx	r0
.L28:
	.align	2
.L27:
	.word	234902869
	.word	234891946
	.word	234885120
	.size	FlashWriteSector, .-FlashWriteSector
	.section	.text.CalculateChecksum,"ax",%progbits
	.align	1
	.p2align 2,,3
	.global	CalculateChecksum
	.syntax unified
	.code	16
	.thumb_func
	.type	CalculateChecksum, %function
CalculateChecksum:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	lsls	r1, r1, #16
	movs	r2, r0
	push	{r4, lr}
	lsrs	r0, r1, #18
	beq	.L30
	movs	r1, #0
	movs	r3, #0
.L31:
	ldmia	r2!, {r4}
	adds	r3, r3, #1
	lsls	r3, r3, #16
	adds	r1, r1, r4
	lsrs	r3, r3, #16
	cmp	r3, r0
	bne	.L31
	lsrs	r0, r1, #16
	adds	r0, r0, r1
	lsls	r0, r0, #16
	lsrs	r0, r0, #16
.L30:
	@ sp needed
	pop	{r4}
	pop	{r1}
	bx	r1
	.size	CalculateChecksum, .-CalculateChecksum
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
	push	{r4, r5, r6, r7, lr}
	mov	r7, r9
	mov	lr, r10
	mov	r6, r8
	push	{r6, r7, lr}
	ldr	r7, [sp, #32]
	lsls	r2, r2, #24
	mov	ip, r0
	lsls	r3, r3, #16
	lsrs	r0, r2, #24
	lsls	r7, r7, #16
	lsrs	r4, r3, #16
	lsrs	r7, r7, #16
	lsls	r0, r0, #3
	cmp	r2, #0
	bge	.L37
	movs	r0, #252
	lsls	r0, r0, #1
.L37:
	lsls	r3, r1, #4
	subs	r3, r3, r1
	lsls	r3, r3, #4
	mov	r9, r3
	ldr	r3, .L45
	adds	r0, r0, r3
	movs	r3, #8
	mov	r8, r3
	movs	r5, #1
	add	r8, r8, r0
.L40:
	movs	r3, #192
	mov	r1, r9
	lsls	r3, r3, #19
	mov	r10, r3
	movs	r3, #0
	add	r1, r1, ip
	lsls	r1, r1, #1
	add	r1, r1, r10
.L39:
	ldrb	r2, [r0]
	asrs	r2, r2, r3
	movs	r6, r4
	tst	r5, r2
	bne	.L38
	movs	r6, r7
.L38:
	adds	r3, r3, #1
	strh	r6, [r1]
	adds	r1, r1, #2
	cmp	r3, #8
	bne	.L39
	adds	r3, r3, #232
	mov	r10, r3
	adds	r0, r0, #1
	add	r9, r9, r10
	cmp	r0, r8
	bne	.L40
	@ sp needed
	pop	{r5, r6, r7}
	mov	r10, r7
	mov	r9, r6
	mov	r8, r5
	pop	{r4, r5, r6, r7}
	pop	{r0}
	bx	r0
.L46:
	.align	2
.L45:
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
	ldr	r7, [sp, #28]
	movs	r5, r2
	lsls	r3, r3, #16
	ldrb	r2, [r2]
	lsrs	r3, r3, #16
	lsls	r7, r7, #16
	movs	r4, r0
	movs	r6, r1
	mov	r8, r3
	lsrs	r7, r7, #16
	cmp	r2, #0
	beq	.L47
.L50:
	movs	r0, r4
	mov	r3, r8
	movs	r1, r6
	str	r7, [sp]
	adds	r4, r4, #8
	bl	DrawChar
	cmp	r4, #239
	ble	.L49
	movs	r4, #0
	adds	r6, r6, #8
.L49:
	ldrb	r2, [r5, #1]
	adds	r5, r5, #1
	cmp	r2, #0
	bne	.L50
.L47:
	add	sp, sp, #4
	@ sp needed
	pop	{r7}
	mov	r8, r7
	pop	{r4, r5, r6, r7}
	pop	{r0}
	bx	r0
	.size	DrawString, .-DrawString
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
	@ args = 0, pretend = 0, frame = 56
	@ frame_needed = 0, uses_anonymous_args = 0
	movs	r3, #128
	push	{r4, r5, r6, r7, lr}
	mov	lr, fp
	mov	r7, r10
	mov	r6, r9
	mov	r5, r8
	ldr	r2, .L94
	lsls	r3, r3, #19
	push	{r5, r6, r7, lr}
	movs	r1, #248
	strh	r2, [r3]
	movs	r3, #192
	ldr	r2, .L94+4
	sub	sp, sp, #56
	lsls	r3, r3, #19
	lsls	r1, r1, #7
.L55:
	strh	r1, [r3]
	adds	r3, r3, #2
	cmp	r3, r2
	bne	.L55
	movs	r3, #0
	str	r3, [sp, #20]
	str	r3, [sp, #16]
	str	r3, [sp, #24]
	adds	r3, r3, #170
	mov	r9, r3
	ldr	r3, .L94+8
	mov	r0, sp
	mov	r8, r3
	movs	r3, #85
	strb	r3, [r0]
	movs	r3, #224
	lsls	r3, r3, #20
	mov	r10, r3
	movs	r3, #15
	movs	r2, #0
	movs	r4, #14
	movs	r7, #176
	mov	fp, r3
	ldr	r1, .L94+12
	str	r2, [sp, #12]
.L56:
	movs	r3, r4
	movs	r2, #0
	subs	r3, r3, #14
	lsls	r3, r3, #16
	str	r2, [sp, #8]
	str	r2, [sp, #4]
	ldr	r6, .L94+16
	lsrs	r3, r3, #16
	b	.L59
.L57:
	adds	r3, r3, #1
	lsls	r3, r3, #16
	lsrs	r3, r3, #16
	cmp	r3, r4
	beq	.L91
.L59:
	mov	r0, r9
	mov	r5, sp
	strb	r0, [r1]
	mov	r0, r8
	ldrb	r5, [r5]
	strb	r5, [r0]
	mov	r0, r10
	lsls	r2, r3, #20
	lsrs	r2, r2, #24
	strb	r7, [r1]
	strb	r2, [r0]
	movs	r0, #224
	mov	r2, fp
	lsls	r0, r0, #20
	mov	ip, r0
	ands	r2, r3
	lsls	r2, r2, #12
	add	r2, r2, ip
	ldr	r0, [r2, r6]
	ldr	r5, .L94+20
	cmp	r0, r5
	bne	.L57
	ldr	r0, .L94+24
	ldr	r2, [r2, r0]
	ldr	r0, [sp, #4]
	cmp	r0, r2
	bcs	.L58
	str	r2, [sp, #4]
.L58:
	movs	r2, #1
	adds	r3, r3, #1
	lsls	r3, r3, #16
	str	r2, [sp, #8]
	lsrs	r3, r3, #16
	cmp	r3, r4
	bne	.L59
.L91:
	ldr	r3, [sp, #4]
	ldr	r2, [sp, #16]
	cmp	r3, r2
	bcc	.L60
	ldr	r2, [sp, #8]
	cmp	r2, #0
	beq	.L60
	str	r3, [sp, #16]
	movs	r3, #1
	ldr	r2, [sp, #12]
	str	r3, [sp, #20]
	str	r2, [sp, #24]
.L60:
	adds	r4, r4, #14
	ldr	r3, [sp, #12]
	lsls	r4, r4, #16
	lsrs	r4, r4, #16
	cmp	r3, #0
	bne	.L61
	adds	r3, r3, #1
	str	r3, [sp, #12]
	b	.L56
.L61:
	ldr	r3, [sp, #20]
	cmp	r3, #0
	bne	.L62
	movs	r3, #192
	movs	r1, #31
	ldr	r2, .L94+4
	lsls	r3, r3, #19
.L63:
	strh	r1, [r3]
	adds	r3, r3, #2
	cmp	r3, r2
	bne	.L63
.L64:
	b	.L64
.L62:
	movs	r2, #14
	ldr	r3, [sp, #24]
	lsls	r3, r3, #16
	lsrs	r3, r3, #16
	rsbs	r4, r3, #0
	movs	r7, #28
	ands	r4, r2
	cmp	r3, #0
	bne	.LCB579
	b	.L92	@long jump
.LCB579:
.L66:
	ldr	r3, .L94+28
	str	r3, [sp, #4]
	movs	r3, #170
	mov	fp, r3
	ldr	r3, .L94+8
	mov	r10, r3
	movs	r3, #85
	mov	r9, r3
	movs	r3, #176
	mov	r8, r3
	movs	r3, #224
	movs	r5, #128
	lsls	r7, r7, #16
	lsls	r3, r3, #20
	ldr	r6, .L94+12
	str	r3, [sp]
	lsrs	r7, r7, #16
	lsls	r5, r5, #5
	b	.L69
.L67:
	adds	r4, r4, #1
	lsls	r4, r4, #16
	lsrs	r4, r4, #16
	cmp	r4, r7
	beq	.L93
.L69:
	mov	r2, fp
	mov	r1, r9
	strb	r2, [r6]
	mov	r2, r10
	strb	r1, [r2]
	mov	r2, r8
	strb	r2, [r6]
	ldr	r2, [sp]
	lsls	r3, r4, #20
	lsrs	r3, r3, #24
	strb	r3, [r2]
	movs	r3, #224
	movs	r1, #15
	lsls	r3, r3, #20
	mov	ip, r3
	ands	r1, r4
	ldr	r2, .L94+16
	lsls	r1, r1, #12
	add	r1, r1, ip
	ldr	r3, .L94+20
	ldr	r2, [r1, r2]
	cmp	r2, r3
	bne	.L67
	ldr	r3, .L94+32
	ldrh	r0, [r1, r3]
	cmp	r0, #13
	bhi	.L67
	lsls	r3, r0, #1
	add	r2, sp, #28
	strh	r4, [r2, r3]
	ldr	r3, [sp, #4]
	mov	ip, r3
	movs	r3, #0
	lsls	r0, r0, #12
	add	r0, r0, ip
.L68:
	ldrb	r2, [r1, r3]
	strb	r2, [r0, r3]
	adds	r3, r3, #1
	cmp	r3, r5
	bne	.L68
	b	.L67
.L93:
	movs	r3, #128
	lsls	r3, r3, #5
	mov	ip, r3
	movs	r2, #248
	movs	r7, #141
	ldr	r4, [sp, #4]
	ldr	r5, .L94+36
	add	r4, r4, ip
	movs	r1, r4
	movs	r0, r5
	lsls	r2, r2, #4
	lsls	r7, r7, #2
	bl	memcpy
	ldrb	r6, [r5, r7]
	cmp	r6, #5
	bls	.L70
	movs	r3, #192
	movs	r1, #31
	ldr	r2, .L94+4
	lsls	r3, r3, #19
.L71:
	strh	r1, [r3]
	adds	r3, r3, #2
	cmp	r3, r2
	bne	.L71
.L72:
	b	.L72
.L70:
	movs	r3, #142
	movs	r2, #100
	lsls	r3, r3, #2
	mov	ip, r3
	movs	r0, r2
	muls	r0, r6
	add	r0, r0, ip
	ldr	r1, .L94+40
	adds	r0, r0, r5
	bl	memcpy
	movs	r2, #248
	movs	r1, r5
	lsls	r2, r2, #4
	movs	r0, r4
	adds	r6, r6, #1
	strb	r6, [r5, r7]
	bl	memcpy
	add	r3, sp, #28
	ldrh	r5, [r3, #2]
	movs	r3, #252
	lsls	r3, r3, #5
	mov	ip, r3
	movs	r2, #0
	ldr	r0, [sp, #4]
	add	r0, r0, ip
.L73:
	ldmia	r4!, {r3}
	adds	r2, r2, r3
	cmp	r4, r0
	bne	.L73
	lsrs	r3, r2, #16
	adds	r3, r3, r2
	ldr	r1, [sp, #4]
	ldr	r2, .L94+44
	movs	r0, r5
	strh	r3, [r1, r2]
	bl	FlashEraseSector
	ldr	r1, .L94+48
	movs	r0, r5
	bl	FlashWriteSector
	movs	r3, #192
	movs	r1, #248
	ldr	r2, .L94+4
	lsls	r3, r3, #19
	lsls	r1, r1, #2
.L74:
	strh	r1, [r3]
	adds	r3, r3, #2
	cmp	r3, r2
	bne	.L74
.L75:
	b	.L75
.L92:
	adds	r7, r2, #0
	b	.L66
.L95:
	.align	2
.L94:
	.word	1027
	.word	100740096
	.word	234891946
	.word	234902869
	.word	4088
	.word	134291493
	.word	4092
	.word	gSaveSectors
	.word	4084
	.word	gPokemonStorageBuffer
	.word	gEventMonData+8
	.word	8182
	.word	gSaveSectors+4096
	.size	PayloadMain, .-PayloadMain
	.global	gEventMonData
	.section	.rodata,"a"
	.align	2
	.type	gEventMonData, %object
	.size	gEventMonData, 108
gEventMonData:
	.ascii	"\021\"3DUfw\210\000\000"
	.space	98
	.global	font8x8_basic
	.section	.data.font8x8_basic,"aw"
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
	.global	gPokemonStorageBuffer
	.section	.bss.gPokemonStorageBuffer,"aw",%nobits
	.align	2
	.type	gPokemonStorageBuffer, %object
	.size	gPokemonStorageBuffer, 35712
gPokemonStorageBuffer:
	.space	35712
	.global	gSaveSectors
	.section	.bss.gSaveSectors,"aw",%nobits
	.align	2
	.type	gSaveSectors, %object
	.size	gSaveSectors, 57344
gSaveSectors:
	.space	57344
	.ident	"GCC: (15:13.2.rel1-2) 13.2.1 20231009"
