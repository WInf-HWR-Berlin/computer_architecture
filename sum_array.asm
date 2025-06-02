example:
	.data
n:	.word	5		
a:	.word	1,2,3,4,5

	.text
	lw $a1,n
	la $a0,a	# load address of the array
	add $v0,$zero,$zero
	add $v1,$zero,$zero
for:	bge $v1,$a1,endfor
	sll $t0,$v1,2
	add $t0,$a0,$t0
	lw $t0,0($t0)
	add $v0,$v0,$t0
	addi $v1,$v1,1
	j for
endfor:	addi $s0,$zero,1
	
	
	