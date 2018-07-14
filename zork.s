.comment"
#fsfsf
fsfsdd"

#.comment ""

.name""

#k;lskd;alksd
;skla;dkas;lkd


		hello:
sti:
				   100000000000009: #hello
live:				sti r1, %:100000000000009, %-100000000009
		and :sti	, %0 , r1

sti r1, :comment   , %2

comment: 


name:	live %1
		zjmp %1

r1:

live:	live %:r1 
		ld %01, r1
		zjmp %:live

l2:	#WORKING



	sti r1, %:l2, %1
		and r1, %0, r1
		
		st r1, r1
		st r1, :l2
		st r1, 5
		live %5
		live %:l2
		ld %5, r1
		ld %:l2, r1
		ld 5, r1
		ld :l2, r1
		add r00, r1,r2
		sub r00, r1,r2



# ERROR

		and r1, r1, r1
		and 5, 5, r1
		and %5, %5, r1
		and :l2, %:l2, r1
		or r1, r1, r1
		or 5, 5, r1
		or %5, %5, r1
		or :l2, %:l2, r1
		xor r1, r1, r1
		xor 5, 5, r1
		xor %5, %5, r1
		xor :l2, %:l2, r1




		zjmp  %-6




		zjmp %:hello 
		fork  %-6
		fork %:hello 
		lfork  %-6
		lfork %:hello 
		ldi r1, r1, r1
		ldi 5, r5, r1
		ldi %5, %5, r1
		ldi :l2, %:l2, r1
		lldi r1, r1, r1
		lldi 5, r5, r1
		lldi %5, %5, r1
		lldi :l2, %:l2, r1
		sti r1, r1, r1
		sti r2, 5, r1
		sti r2, %5, r1
		sti r2, %:l2, r1
		sti r1, r1, %5
		sti r4, 5, %:hello
		aff r1
		lld 5, r1
		lld %5, r4
		lld %:hello, r5
		lld :hello, r54





# ERROR

		# st r1, 5,
		# st r1,, 5
		# st r1,
		# st r1 # ERROR!!! SHOULD NOT BE WORKING
		# st 10, r1
		# st :r1, r00
		# st %-5, 3
		# st %:l2, r4
		# st r2, %4
		# st r2,
		# add %5, r1,r1
		# add r2, 5, r3
		# add r2, 5
		# add r2, r1, :l2
		# sub %5, r1,r1
		# sub %5, r1
		# sub r2, 5, r3
		# sub r2, r1, :l2
		# sub r00, r1,r2,
		# sub r00,, r1,r2
		# add r00, r1,,r2
		# add r00, r1, r2,
		# and r1, r1, 5
		# and r1, r1 , %:l2
		# and r1   ,   r1, :l2
		# and r4, r4, 2
		# and r5, r4, %5
		# and %l, %5, r1
		# and %5, %5 HERE
		# and %5, %5,
		# and %5, %5, r1, r1
		# or r1, r1, 5
		# or r1, r1 , %:l2
		# or r1   ,   r1, :l2
		# or r4, r4, 2
		# or r5, r4, %5
		# or %l, %5, r1
		# or %5, %5
		# or %5, %5,
		# or %5, %5, r1, r1
		# xor r1, r1, 5
		# xor r1, r1 , %:l2
		# xor r1   ,   r1, :l2
		# xor r4, r4, 2
		# xor r5, r4, %5
		# xor %l, %5, r1
		# xor %5, %5
		# xor %5, %5,
		# xor %5, %5, r1, r1
		# zjmp %6, %6
		# zjmp
		# zjmp ,,
		# zjmp r2
		# zjmp 6
		# zjmp :hello
		# fork %6, %6
		# fork
		# fork ,,
		# fork r2
		# fork 6
		# fork :hello
		# lfork %6, %6
		# lfork
		# lfork ,,
		# lfork r2
		# lfork 6
		# lfork :hello
		# ldi r1, r1 , %:l2
		# ldi r1   ,   r1, :l2
		# ldi r4, r4, 2
		# ldi r5, r4, %5
		# ldi %l, %5, r1
		# ldi %5, %5
		# ldi %5, %5,
		# ldi %5, %5, r1, r1
		# ldi r1, 5, r1
		# ldi r1, :hello, r1
		# lldi r1, r1 , %:l2
		# lldi r1   ,   r1, :l2
		# lldi r4, r4, 2
		# lldi r5, r4, %5
		# lldi %l, %5, r1
		# lldi %5, %5
		# lldi %5, %5,
		# lldi %5, %5, r1, r1
		# lldi r1, 5, r1
		# lldi r1, :hello, r1
		# sti 5, 5, r5
		# sti %5, %5, r5
		# sti :1, 5, r5
		# sti %:1, %5, r5
		# sti r1, r1, :hello
		# sti r1, r1, 5
		# sti r1, r1, %5,
		# sti r4, 5
		# sti r1, r1, %5, r1
		# sti r4, 5,,
		# aff
		# aff ,,
		# aff %2
		# aff 6
		# aff :hello
		# aff r1, r1
		# lld r5, r1
		# lld %5, 5
		# lld %:hello, %:hello
		# lld :hello, %6
		# lld %:hello, :hello
		# lld %:hello, r5,,
		# lld %:hello, r5, r4
		# lld %:hello
