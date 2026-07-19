	.arch armv4t
	.fpu softvfp
	.file	"multiboot.c"
	.text
	.section	.text.MultiBootWaitCycles,"ax",%progbits
	.align	1
	.p2align 2,,3
	.syntax unified
	.code	16
	.thumb_func
	.type	MultiBootWaitCycles, %function
MultiBootWaitCycles:
	@ Function supports interworking.
	@ Naked Function: prologue and epilogue provided by programmer.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	.syntax divided
@ 507 "multiboot.c" 1
	.syntax unified
    mov  r2, pc
    lsrs r2, #24
    movs r1, #12
    cmp  r2, #2
    beq  MultiBootWaitCyclesLoop
    movs r1, #13
    cmp  r2, #8
    beq  MultiBootWaitCyclesLoop
    movs r1, #4
MultiBootWaitCyclesLoop:
    subs r0, r0, r1
    bgt  MultiBootWaitCyclesLoop
    bx   lr
    .syntax divided
@ 0 "" 2
	.thumb
	.syntax unified
	.size	MultiBootWaitCycles, .-MultiBootWaitCycles
	.section	.text.MultiBootInit,"ax",%progbits
	.align	1
	.p2align 2,,3
	.global	MultiBootInit
	.syntax unified
	.code	16
	.thumb_func
	.type	MultiBootInit, %function
MultiBootInit:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	movs	r3, #0
	@ sp needed
	movs	r2, #74
	movs	r1, #15
	strb	r3, [r0, #30]
	strb	r3, [r0, #24]
	strb	r3, [r0, #29]
	strb	r1, [r0, r2]
	subs	r2, r2, #2
	strb	r3, [r0, r2]
	ldr	r2, .L4
	strh	r3, [r0, #22]
	strh	r3, [r2]
	ldr	r3, .L4+4
	ldr	r2, .L4+8
	strh	r2, [r3]
	movs	r2, #0
	ldr	r3, .L4+12
	strb	r2, [r3]
	bx	lr
.L5:
	.align	2
.L4:
	.word	67109172
	.word	67109160
	.word	8195
	.word	67109162
	.size	MultiBootInit, .-MultiBootInit
	.section	.text.MultiBootMain,"ax",%progbits
	.align	1
	.p2align 2,,3
	.global	MultiBootMain
	.syntax unified
	.code	16
	.thumb_func
	.type	MultiBootMain, %function
MultiBootMain:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, r5, r6, r7, lr}
	mov	lr, r10
	mov	r7, r9
	mov	r6, r8
	push	{r6, r7, lr}
	ldrb	r3, [r0, #24]
	movs	r4, r0
	cmp	r3, #233
	bne	.LCB58
	b	.L29	@long jump
.LCB58:
	movs	r2, #74
	ldrb	r3, [r0, r2]
	movs	r5, #72
	cmp	r3, #15
	bls	.LCB63
	b	.L178	@long jump
.LCB63:
.L8:
	ldrb	r3, [r4, r5]
	cmp	r3, #0
	bne	.L179
.L10:
	ldrb	r3, [r4, #24]
	cmp	r3, #223
	bls	.LCB71
	b	.L180	@long jump
.LCB71:
	cmp	r3, #2
	bne	.LCB73
	b	.L30	@long jump
.LCB73:
	bls	.L181
	cmp	r3, #208
	bne	.LCB77
	b	.L34	@long jump
.LCB77:
	cmp	r3, #209
	beq	.LCB79
	b	.L182	@long jump
.LCB79:
	movs	r3, #73
	movs	r0, #1
	ldrb	r5, [r4, r3]
	subs	r3, r3, #70
.L65:
	ldr	r1, .L193
	mov	ip, r1
	movs	r1, r5
	asrs	r1, r1, r3
	lsls	r2, r3, #1
	add	r2, r2, ip
	ldrh	r2, [r2]
	tst	r0, r1
	beq	.L64
	asrs	r2, r2, #8
	cmp	r2, #3
	beq	.LCB99
	b	.L171	@long jump
.LCB99:
.L64:
	subs	r3, r3, #1
	cmp	r3, #0
	bne	.L65
	movs	r0, r4
	movs	r1, #1
	.syntax divided
@ 64 "multiboot.c" 1
	swi 0x25
@ 0 "" 2
	.thumb
	.syntax unified
	cmp	r0, #0
	bne	.LCB109
	b	.L183	@long jump
.LCB109:
	movs	r2, #72
	strb	r3, [r4, #30]
	strb	r3, [r4, #24]
	strb	r3, [r4, #29]
	strb	r3, [r4, r2]
	ldr	r2, .L193+4
	strh	r3, [r4, #22]
	strh	r3, [r2]
	ldr	r3, .L193+8
	ldr	r2, .L193+12
	strh	r2, [r3]
	movs	r2, #0
	ldr	r3, .L193+16
	strb	r2, [r3]
	movs	r3, #74
	movs	r2, #30
	movs	r0, #112
	strb	r2, [r4, r3]
	b	.L6
.L179:
	movs	r3, #0
	movs	r0, #248
	strb	r3, [r4, r5]
	ldr	r2, .L193+8
	ldrh	r1, [r2]
	ands	r0, r1
	cmp	r0, #8
	beq	.L10
	movs	r1, #74
	movs	r5, #15
	strb	r3, [r4, #30]
	strb	r3, [r4, #24]
	strb	r3, [r4, #29]
	strb	r5, [r4, r1]
	b	.L174
.L181:
	cmp	r3, #0
	bne	.LCB155
	b	.L184	@long jump
.LCB155:
	ldrb	r5, [r4, #29]
.L45:
	movs	r3, #73
	movs	r2, #0
	strb	r2, [r4, r3]
	ldr	r3, .L193+20
	mov	r8, r3
	movs	r3, #1
	movs	r6, #0
	mov	ip, r3
	ldr	r1, .L193+24
	adds	r2, r2, #3
.L51:
	ldrh	r3, [r1]
	movs	r7, r2
	asrs	r0, r3, #8
	subs	r2, r2, #1
	cmp	r0, #0
	bne	.L49
	mov	r0, r8
	strh	r3, [r0, r1]
	mov	r0, ip
	lsls	r0, r0, r7
	cmp	r0, r3
	bne	.L49
	movs	r3, #73
	orrs	r6, r0
	lsls	r6, r6, #24
	lsrs	r6, r6, #24
	strb	r6, [r4, r3]
.L49:
	subs	r1, r1, #2
	cmp	r2, #0
	bne	.L51
	cmp	r5, r6
	bne	.LCB196
	b	.L52	@long jump
.LCB196:
.L170:
	ldrb	r5, [r4, #30]
.L46:
	movs	r0, #136
	ldr	r2, .L193+8
	ldrh	r3, [r2]
	ands	r0, r3
	movs	r3, #0
	cmp	r0, #8
	beq	.LCB211
	b	.L176	@long jump
.LCB211:
	ldr	r3, .L193+16
	lsls	r5, r5, #24
	lsrs	r5, r5, #24
	strb	r5, [r3]
	ldr	r3, .L193+28
	strh	r3, [r2]
	movs	r3, #72
	movs	r2, #1
	strb	r2, [r4, r3]
.L29:
	movs	r0, #0
.L6:
	@ sp needed
	pop	{r5, r6, r7}
	mov	r10, r7
	mov	r9, r6
	mov	r8, r5
	pop	{r4, r5, r6, r7}
	pop	{r1}
	bx	r1
.L180:
	cmp	r3, #224
	bne	.LCB243
	b	.L12	@long jump
.LCB243:
	movs	r2, r3
	adds	r2, r2, #25
	lsls	r2, r2, #24
	ldrb	r7, [r4, #30]
	lsrs	r2, r2, #24
	cmp	r2, #1
	bls	.LCB250
	b	.L13	@long jump
.LCB250:
	movs	r2, #3
	movs	r6, #1
.L14:
	ldr	r0, .L193
	mov	ip, r0
	movs	r0, r7
	asrs	r0, r0, r2
	lsls	r1, r2, #1
	add	r1, r1, ip
	ldrh	r1, [r1]
	tst	r6, r0
	beq	.L22
	ldr	r0, [r4, #4]
	cmp	r0, r1
	beq	.LCB268
	b	.L185	@long jump
.LCB268:
.L22:
	subs	r2, r2, #1
	cmp	r2, #0
	bne	.L14
	adds	r3, r3, #1
	lsls	r3, r3, #24
	lsrs	r3, r3, #24
	strb	r3, [r4, #24]
	cmp	r3, #233
	beq	.L29
	ldr	r3, [r4, #40]
	adds	r2, r2, #174
	ldrb	r2, [r3, r2]
	adds	r3, r3, #174
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #8
	orrs	r3, r2
	str	r3, [r4]
	str	r3, [r4, #4]
.L20:
	movs	r0, #136
	ldr	r1, .L193+8
	ldrh	r2, [r1]
	ands	r0, r2
	cmp	r0, #8
	bne	.LCB301
	b	.L21	@long jump
.LCB301:
	movs	r3, #0
.L175:
	movs	r2, #74
	movs	r5, #15
	strb	r3, [r4, #30]
	strb	r3, [r4, #24]
	strb	r3, [r4, #29]
	strb	r5, [r4, r2]
	subs	r2, r2, #2
	strb	r3, [r4, r2]
	ldr	r2, .L193+4
	strh	r3, [r4, #22]
	strh	r3, [r2]
	ldr	r3, .L193+12
	strh	r3, [r1]
.L173:
	movs	r2, #0
	ldr	r3, .L193+16
	strb	r2, [r3]
	movs	r3, #8
	eors	r0, r3
	b	.L6
.L178:
	subs	r3, r3, #1
	strb	r3, [r0, r2]
	b	.L29
.L184:
	ldr	r2, .L193+24
	ldr	r1, .L193+32
	ldrh	r2, [r2]
	cmp	r2, r1
	beq	.LCB342
	b	.L77	@long jump
.LCB342:
	ldr	r1, .L193+36
	ldrh	r1, [r1]
	cmp	r1, r2
	beq	.LCB347
	b	.L78	@long jump
.LCB347:
	ldr	r2, .L193+40
	ldrh	r2, [r2]
	movs	r5, #0
	movs	r0, #0
	cmp	r2, r1
	beq	.LCB355
	b	.L186	@long jump
.LCB355:
.L37:
	strb	r5, [r4, #29]
	ldr	r2, .L193+24
	ldrb	r1, [r4, #30]
	ldrh	r2, [r2]
	lsls	r6, r1, #28
	bpl	.L38
	cmp	r2, #8
	beq	.LCB369
	b	.L169	@long jump
.LCB369:
.L38:
	ldr	r2, .L193+36
	ldrh	r2, [r2]
	lsls	r6, r1, #29
	bpl	.L40
	cmp	r2, #4
	beq	.LCB381
	b	.L169	@long jump
.LCB381:
.L40:
	ldr	r2, .L193+40
	ldrh	r2, [r2]
	lsls	r6, r1, #30
	bpl	.LCB391
	b	.L187	@long jump
.LCB391:
.L42:
	movs	r3, r1
	ands	r3, r5
	strb	r3, [r4, #30]
	cmp	r0, #0
	bne	.LCB399
	b	.L80	@long jump
.LCB399:
	movs	r2, #74
	ldrb	r2, [r4, r2]
	cmp	r2, #0
	beq	.LCB403
	b	.L188	@long jump
.LCB403:
	cmp	r3, r5
	bne	.LCB405
	b	.L46	@long jump
.LCB405:
	movs	r3, #1
	strb	r2, [r4, #30]
	strb	r3, [r4, #24]
	b	.L45
.L34:
	movs	r2, #1
	movs	r3, #73
	mov	r9, r2
	ldr	r2, .L193+20
	movs	r6, r4
	mov	ip, r2
	ldrb	r7, [r4, r3]
	ldr	r1, .L193+24
	subs	r3, r3, #72
	mov	r10, r3
	adds	r6, r6, #25
	adds	r3, r3, #2
.L60:
	mov	r8, r3
	movs	r0, r7
	mov	r5, r8
	asrs	r0, r0, r5
	mov	r5, r9
	ldrh	r2, [r1]
	subs	r3, r3, #1
	strb	r2, [r6, r3]
	tst	r5, r0
	beq	.L57
	asrs	r0, r2, #8
	beq	.L58
	cmp	r0, #3
	beq	.LCB450
	b	.L171	@long jump
.LCB450:
.L58:
	mov	r0, ip
	ldrh	r0, [r0, r1]
	subs	r2, r0, r2
	subs	r0, r2, #1
	sbcs	r2, r2, r0
	mov	r0, r10
	rsbs	r2, r2, #0
	ands	r0, r2
	mov	r10, r0
.L57:
	subs	r1, r1, #2
	cmp	r3, #0
	bne	.L60
	mov	r2, r10
	cmp	r2, #0
	bne	.LCB468
	b	.L189	@long jump
.LCB468:
	movs	r2, #209
	movs	r0, #136
	strb	r2, [r4, #24]
	ldrb	r2, [r4, #27]
	ldrb	r1, [r4, #26]
	adds	r2, r2, #17
	adds	r1, r1, r2
	ldrb	r2, [r4, #25]
	adds	r2, r2, r1
	strb	r2, [r4, #20]
	ldr	r1, .L193+8
	ldrh	r5, [r1]
	ands	r0, r5
	cmp	r0, #8
	beq	.LCB487
	b	.L175	@long jump
.LCB487:
	ldr	r3, .L193+16
	lsls	r2, r2, #24
	lsrs	r2, r2, #24
	strb	r2, [r3]
	ldr	r3, .L193+28
	movs	r2, #1
	strh	r3, [r1]
	movs	r3, #72
	strb	r2, [r4, r3]
	b	.L29
.L13:
	movs	r2, #3
	movs	r6, #1
.L18:
	ldr	r0, .L193
	mov	ip, r0
	movs	r0, r7
	asrs	r0, r0, r2
	lsls	r1, r2, #1
	add	r1, r1, ip
	ldrh	r1, [r1]
	tst	r6, r0
	beq	.L17
	ldr	r0, [r4, #4]
	cmp	r0, r1
	bne	.L12
.L17:
	subs	r2, r2, #1
	cmp	r2, #0
	bne	.L18
	adds	r3, r3, #1
	strb	r3, [r4, #24]
	ldr	r3, [r4]
	lsls	r2, r3, #16
	lsrs	r2, r2, #16
	str	r2, [r4, #4]
	cmp	r3, #0
	bne	.L19
	movs	r2, #172
	ldr	r3, [r4, #40]
	ldrb	r2, [r3, r2]
	adds	r3, r3, #172
	ldrb	r3, [r3, #1]
	lsls	r3, r3, #8
	orrs	r3, r2
	str	r3, [r4, #4]
	lsls	r3, r3, #5
.L19:
	lsrs	r3, r3, #5
	str	r3, [r4]
	b	.L20
.L176:
	movs	r1, #74
	movs	r5, #15
	strb	r3, [r4, #30]
	strb	r3, [r4, #24]
	strb	r3, [r4, #29]
	strb	r5, [r4, r1]
	subs	r1, r1, #2
	strb	r3, [r4, r1]
.L174:
	ldr	r1, .L193+4
	strh	r3, [r4, #22]
	strh	r3, [r1]
	ldr	r3, .L193+12
	strh	r3, [r2]
	b	.L173
.L194:
	.align	2
.L193:
	.word	67109152
	.word	67109172
	.word	67109160
	.word	8195
	.word	67109162
	.word	MultiBoot_required_data-67109154
	.word	67109158
	.word	8323
	.word	65535
	.word	67109156
	.word	67109154
.L12:
	movs	r3, #225
	movs	r2, #128
	strb	r3, [r4, #24]
	movs	r0, #136
	movs	r3, #0
	lsls	r2, r2, #13
	str	r2, [r4]
	ldr	r2, .L195
	ldrh	r1, [r2]
	str	r3, [r4, #4]
	ands	r0, r1
	cmp	r0, #8
	bne	.L176
	ldr	r1, .L195+4
	strb	r3, [r1]
	ldr	r3, .L195+8
	strh	r3, [r2]
.L16:
	movs	r3, #72
	movs	r2, #1
	strb	r2, [r4, r3]
	adds	r3, r3, #3
	ldrb	r3, [r4, r3]
	ldrb	r2, [r4, #24]
	cmp	r3, #1
	beq	.LCB619
	b	.L24	@long jump
.LCB619:
	movs	r3, r2
	subs	r3, r3, #233
	rsbs	r1, r3, #0
	adcs	r3, r3, r1
	cmp	r3, #0
	beq	.LCB626
	b	.L24	@long jump
.LCB626:
	cmp	r2, #225
	bhi	.LCB632
	b	.L24	@long jump
.LCB632:
	movs	r1, #128
	ldr	r3, .L195+12
	ldr	r0, .L195
	b	.L26
.L25:
	subs	r3, r3, #1
	cmp	r3, #0
	beq	.L27
.L26:
	ldrh	r2, [r0]
	tst	r1, r2
	bne	.L25
.L27:
	movs	r0, #150
	lsls	r0, r0, #2
	bl	MultiBootWaitCycles
	b	.L8
.L30:
	movs	r3, #73
	ldr	r2, .L195+16
	movs	r0, #3
	movs	r7, #1
	mov	r8, r2
	ldrb	r3, [r4, r3]
	ldr	r6, .L195+20
.L55:
	movs	r2, r3
	asrs	r2, r2, r0
	movs	r1, r0
	subs	r0, r0, #1
	tst	r7, r2
	beq	.L54
	ldrh	r2, [r6]
	mov	r9, r2
	mov	r2, r8
	ldrh	r2, [r2, r6]
	cmp	r2, r9
	beq	.L54
	movs	r2, r7
	lsls	r2, r2, r1
	eors	r3, r2
	movs	r2, #73
	lsls	r3, r3, #24
	lsrs	r3, r3, #24
	strb	r3, [r4, r2]
.L54:
	subs	r6, r6, #2
	cmp	r0, #0
	bne	.L55
	cmp	r3, #0
	bne	.LCB698
	b	.L75	@long jump
.LCB698:
	movs	r3, #4
	movs	r2, #4
	strb	r3, [r4, #24]
.L72:
	movs	r0, #136
	ldr	r3, [r4, #40]
	adds	r3, r3, r2
	subs	r2, r3, #3
	ldrb	r2, [r2]
	subs	r3, r3, #4
	ldrb	r3, [r3]
	ldr	r6, .L195
	lsls	r2, r2, #8
	orrs	r3, r2
	ldrh	r2, [r6]
	lsls	r3, r3, #16
	asrs	r3, r3, #16
	ands	r0, r2
	cmp	r0, #8
	beq	.L73
	movs	r3, #0
	movs	r2, #74
	movs	r1, #15
	strb	r3, [r4, #30]
	strb	r3, [r4, #24]
	strb	r3, [r4, #29]
	strb	r1, [r4, r2]
	subs	r2, r2, #2
	strb	r3, [r4, r2]
	ldr	r2, .L195+24
	strh	r3, [r4, #22]
	strh	r3, [r2]
	ldr	r3, .L195+28
	strh	r3, [r6]
	b	.L173
.L73:
	ldr	r2, .L195+4
	lsls	r3, r3, #24
	lsrs	r3, r3, #24
	strb	r3, [r2]
	ldr	r3, .L195+8
	movs	r2, #1
	strh	r3, [r6]
	movs	r3, #72
	strb	r2, [r4, r3]
	adds	r3, r3, #3
	ldrb	r3, [r4, r3]
	cmp	r3, #1
	beq	.LCB754
	b	.L29	@long jump
.LCB754:
	movs	r1, #128
	ldr	r3, .L195+12
	b	.L74
.L190:
	subs	r3, r3, #1
	cmp	r3, #0
	beq	.L27
.L74:
	ldrh	r2, [r6]
	tst	r1, r2
	bne	.L190
	movs	r0, #150
	lsls	r0, r0, #2
	bl	MultiBootWaitCycles
	b	.L8
.L182:
	movs	r1, #3
	movs	r0, #73
	lsrs	r2, r3, #1
	subs	r2, r1, r2
	mov	ip, r2
	movs	r2, #73
	movs	r7, #1
	mov	r8, r0
	ldrb	r1, [r4, r2]
	subs	r2, r2, #70
.L69:
	movs	r0, r1
	asrs	r0, r0, r2
	tst	r7, r0
	beq	.L67
	ldr	r6, .L195+32
	mov	r9, r6
	lsls	r0, r2, #1
	add	r0, r0, r9
	ldrh	r6, [r0]
	movs	r0, r7
	lsls	r0, r0, r2
	mov	r10, r0
	asrs	r0, r6, #8
	cmp	r0, ip
	beq	.L191
.L68:
	mov	r0, r10
	eors	r0, r1
	lsls	r0, r0, #24
	lsrs	r1, r0, #24
	mov	r0, r8
	strb	r1, [r4, r0]
.L67:
	subs	r2, r2, #1
	cmp	r2, #0
	bne	.L69
	cmp	r3, #196
	bne	.LCB824
	b	.L192	@long jump
.LCB824:
.L70:
	cmp	r1, #0
	bne	.LCB827
	b	.L75	@long jump
.LCB827:
	adds	r3, r3, #2
	lsls	r2, r3, #24
	lsrs	r2, r2, #24
	strb	r2, [r4, #24]
	cmp	r2, #196
	bne	.L72
	b	.L170
.L21:
	ldr	r2, .L195+4
	lsls	r3, r3, #24
	lsrs	r3, r3, #24
	strb	r3, [r2]
	ldr	r3, .L195+8
	strh	r3, [r1]
	b	.L16
.L24:
	cmp	r2, #233
	bne	.LCB849
	b	.L29	@long jump
.LCB849:
	ldrh	r3, [r4, #22]
	cmp	r3, #0
	beq	.L172
	subs	r3, r3, #1
	strh	r3, [r4, #22]
	b	.L29
.L191:
	movs	r0, #255
	ands	r6, r0
	cmp	r6, r10
	bne	.L68
	b	.L67
.L187:
	cmp	r2, #2
	bne	.LCB870
	b	.L42	@long jump
.LCB870:
.L169:
	movs	r2, #0
	strb	r2, [r4, #30]
.L80:
	movs	r2, #14
.L41:
	movs	r1, #74
	movs	r5, r3
	strb	r2, [r4, r1]
	b	.L46
.L183:
	adds	r3, r3, #224
	strb	r3, [r4, #24]
	adds	r3, r3, #176
	strh	r3, [r4, #22]
	b	.L29
.L52:
	movs	r3, #2
	movs	r0, #136
	strb	r3, [r4, #24]
	ldr	r3, .L195
	ldrh	r1, [r3]
	ands	r0, r1
	cmp	r0, #8
	beq	.L53
	movs	r1, #74
	movs	r5, #15
	strb	r2, [r4, #30]
	strb	r2, [r4, #24]
	strb	r2, [r4, #29]
	strb	r5, [r4, r1]
	subs	r1, r1, #2
	strb	r2, [r4, r1]
	ldr	r1, .L195+24
	strh	r2, [r4, #22]
	strh	r2, [r1]
	ldr	r2, .L195+28
	strh	r2, [r3]
	b	.L173
.L185:
	movs	r3, #0
.L172:
	movs	r2, #74
	movs	r1, #15
	strb	r3, [r4, #30]
	strb	r3, [r4, #24]
	strb	r3, [r4, #29]
	strb	r1, [r4, r2]
	subs	r2, r2, #2
	strb	r3, [r4, r2]
	ldr	r2, .L195+24
	strh	r3, [r4, #22]
	strh	r3, [r2]
	ldr	r3, .L195
	ldr	r2, .L195+28
	strh	r2, [r3]
	movs	r2, #0
	ldr	r3, .L195+4
	movs	r0, #113
	strb	r2, [r3]
	b	.L6
.L53:
	ldr	r2, .L195+4
	lsls	r5, r5, #24
	lsrs	r5, r5, #24
	strb	r5, [r2]
.L168:
	ldr	r2, .L195+8
	strh	r2, [r3]
	movs	r3, #72
	movs	r2, #1
	strb	r2, [r4, r3]
	b	.L29
.L189:
	movs	r0, #136
	ldr	r3, .L195
	ldrh	r1, [r3]
	ldrb	r2, [r4, #28]
	ands	r0, r1
	cmp	r0, #8
	beq	.L62
	mov	r2, r10
	movs	r1, #15
	strb	r2, [r4, #30]
	strb	r2, [r4, #24]
	strb	r2, [r4, #29]
	movs	r2, #74
	strb	r1, [r4, r2]
	mov	r1, r10
	subs	r2, r2, #2
	strb	r1, [r4, r2]
	ldr	r2, .L195+24
	strh	r1, [r4, #22]
	strh	r1, [r2]
	ldr	r2, .L195+28
	strh	r2, [r3]
	b	.L173
.L171:
	movs	r3, #0
	movs	r2, #74
	movs	r1, #15
	strb	r3, [r4, #30]
	strb	r3, [r4, #24]
	strb	r3, [r4, #29]
	strb	r1, [r4, r2]
	subs	r2, r2, #2
	strb	r3, [r4, r2]
	ldr	r2, .L195+24
	strh	r3, [r4, #22]
	strh	r3, [r2]
	ldr	r3, .L195
	ldr	r2, .L195+28
	strh	r2, [r3]
	movs	r2, #0
	ldr	r3, .L195+4
	movs	r0, #96
	strb	r2, [r3]
	b	.L6
.L62:
	ldr	r1, .L195+4
	strb	r2, [r1]
	b	.L168
.L77:
	movs	r5, #14
	movs	r0, #14
	b	.L37
.L78:
	movs	r5, #6
	movs	r0, #6
	b	.L37
.L186:
	adds	r5, r5, #2
	movs	r0, r5
	b	.L37
.L75:
	movs	r3, #0
	movs	r2, #74
	movs	r1, #15
	strb	r3, [r4, #30]
	strb	r3, [r4, #24]
	strb	r3, [r4, #29]
	strb	r1, [r4, r2]
	subs	r2, r2, #2
	strb	r3, [r4, r2]
	ldr	r2, .L195+24
	strh	r3, [r4, #22]
	strh	r3, [r2]
	ldr	r3, .L195
	ldr	r2, .L195+28
	strh	r2, [r3]
	movs	r2, #0
	ldr	r3, .L195+4
	movs	r0, #80
	strb	r2, [r3]
	b	.L6
.L192:
	movs	r5, #14
	ands	r5, r1
	strb	r5, [r4, #30]
	strb	r2, [r4, #24]
	b	.L46
.L188:
	subs	r2, r2, #1
	lsls	r2, r2, #24
	lsrs	r2, r2, #24
	b	.L41
.L196:
	.align	2
.L195:
	.word	67109160
	.word	67109162
	.word	8323
	.word	31069
	.word	MultiBoot_required_data-67109154
	.word	67109158
	.word	67109172
	.word	8195
	.word	67109152
	.size	MultiBootMain, .-MultiBootMain
	.section	.text.MultiBootStartProbe,"ax",%progbits
	.align	1
	.p2align 2,,3
	.global	MultiBootStartProbe
	.syntax unified
	.code	16
	.thumb_func
	.type	MultiBootStartProbe, %function
MultiBootStartProbe:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldrb	r3, [r0, #24]
	cmp	r3, #0
	bne	.L200
	movs	r2, #74
	strb	r3, [r0, r2]
	strb	r3, [r0, #30]
	movs	r3, #1
	strb	r3, [r0, #24]
.L197:
	@ sp needed
	bx	lr
.L200:
	movs	r3, #0
	movs	r2, #74
	movs	r1, #15
	strb	r3, [r0, #30]
	strb	r3, [r0, #24]
	strb	r3, [r0, #29]
	strb	r1, [r0, r2]
	subs	r2, r2, #2
	strb	r3, [r0, r2]
	ldr	r2, .L201
	strh	r3, [r0, #22]
	strh	r3, [r2]
	ldr	r3, .L201+4
	ldr	r2, .L201+8
	strh	r2, [r3]
	movs	r2, #0
	ldr	r3, .L201+12
	strb	r2, [r3]
	b	.L197
.L202:
	.align	2
.L201:
	.word	67109172
	.word	67109160
	.word	8195
	.word	67109162
	.size	MultiBootStartProbe, .-MultiBootStartProbe
	.section	.text.MultiBootStartMaster,"ax",%progbits
	.align	1
	.p2align 2,,3
	.global	MultiBootStartMaster
	.syntax unified
	.code	16
	.thumb_func
	.type	MultiBootStartMaster, %function
MultiBootStartMaster:
	@ Function supports interworking.
	@ args = 4, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, r5, r6, r7, lr}
	mov	lr, r9
	mov	r7, r8
	push	{r7, lr}
	ldr	r4, [sp, #28]
	ldrb	r5, [r0, #24]
	lsls	r3, r3, #24
	lsls	r4, r4, #24
	lsrs	r3, r3, #24
	asrs	r4, r4, #24
	cmp	r5, #0
	bne	.L204
	ldrb	r5, [r0, #30]
	cmp	r5, #0
	beq	.L204
	movs	r6, #74
	ldrb	r5, [r0, r6]
	cmp	r5, #0
	bne	.L204
	movs	r7, #15
	adds	r2, r2, #15
	bics	r2, r7
	mov	r9, r7
	subs	r7, r2, #1
	subs	r7, r7, #255
	mov	r8, r7
	ldr	r7, .L222
	str	r1, [r0, #32]
	cmp	r8, r7
	bhi	.L221
	adds	r1, r1, r2
	str	r1, [r0, #36]
	cmp	r4, #0
	beq	.L208
	bgt	.L209
	adds	r2, r4, #4
	lsls	r2, r2, #24
	lsrs	r2, r2, #24
	cmp	r2, #3
	bhi	.L214
	movs	r2, #3
	lsls	r3, r3, #3
	subs	r2, r2, r4
	orrs	r2, r3
	movs	r3, #127
	lsls	r2, r2, #1
	rsbs	r3, r3, #0
	orrs	r3, r2
	lsls	r3, r3, #24
	lsrs	r3, r3, #24
	b	.L210
.L204:
	movs	r3, #0
	movs	r2, #74
	movs	r1, #15
	strb	r3, [r0, #30]
	strb	r3, [r0, #24]
	strb	r3, [r0, #29]
	strb	r1, [r0, r2]
	subs	r2, r2, #2
	strb	r3, [r0, r2]
	ldr	r2, .L222+4
	strh	r3, [r0, #22]
	strh	r3, [r2]
.L220:
	ldr	r3, .L222+8
	ldr	r2, .L222+12
	strh	r2, [r3]
	movs	r2, #0
	ldr	r3, .L222+16
	strb	r2, [r3]
.L203:
	@ sp needed
	pop	{r6, r7}
	mov	r9, r7
	mov	r8, r6
	pop	{r4, r5, r6, r7}
	pop	{r0}
	bx	r0
.L221:
	mov	r3, r9
	strb	r5, [r0, #30]
	strb	r5, [r0, #24]
	strb	r5, [r0, #29]
	strb	r3, [r0, r6]
	adds	r3, r3, #57
	strb	r5, [r0, r3]
	ldr	r3, .L222+4
	strh	r5, [r0, #22]
	strh	r5, [r3]
	b	.L220
.L209:
	subs	r4, r4, #1
	lsls	r2, r4, #24
	lsrs	r2, r2, #24
	cmp	r2, #3
	bhi	.L214
	movs	r2, #127
	lsls	r3, r3, #3
	orrs	r3, r4
	lsls	r3, r3, #1
	rsbs	r2, r2, #0
	orrs	r3, r2
	lsls	r3, r3, #24
	lsrs	r3, r3, #24
.L210:
	strb	r3, [r0, #28]
	movs	r3, #208
	strb	r3, [r0, #24]
	b	.L203
.L214:
	movs	r3, #129
	b	.L210
.L208:
	lsls	r2, r3, #1
	movs	r3, #15
	rsbs	r3, r3, #0
	orrs	r3, r2
	lsls	r3, r3, #24
	lsrs	r3, r3, #24
	b	.L210
.L223:
	.align	2
.L222:
	.word	261888
	.word	67109172
	.word	67109160
	.word	8195
	.word	67109162
	.size	MultiBootStartMaster, .-MultiBootStartMaster
	.section	.text.MultiBootCheckComplete,"ax",%progbits
	.align	1
	.p2align 2,,3
	.global	MultiBootCheckComplete
	.syntax unified
	.code	16
	.thumb_func
	.type	MultiBootCheckComplete, %function
MultiBootCheckComplete:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldrb	r0, [r0, #24]
	@ sp needed
	subs	r0, r0, #233
	rsbs	r3, r0, #0
	adcs	r0, r0, r3
	bx	lr
	.size	MultiBootCheckComplete, .-MultiBootCheckComplete
	.section	.bss.MultiBoot_required_data,"aw",%nobits
	.align	2
	.type	MultiBoot_required_data, %object
	.size	MultiBoot_required_data, 6
MultiBoot_required_data:
	.space	6
	.ident	"GCC: (15:13.2.rel1-2) 13.2.1 20231009"
