.data
_prompt: .asciiz "Enter an integer:"
_ret: .asciiz "\n"
.globl main
.text
read:
li $v0, 4
la $a0, _prompt
syscall
li $v0, 5
syscall
jr $ra
write:
li $v0, 1
syscall
li $v0, 4
la $a0, _ret
syscall
move $v0, $0
jr $ra
main:
addi $sp, $sp, -28
li $t0,0
sw $t0, 0($sp)
li $t0,1
sw $t0, 4($sp)
li $t0,0
sw $t0, 8($sp)
addi $sp, $sp, -4
sw $ra, 0($sp)
jal read
lw $ra, 0($sp)
addi $sp, $sp, 4
sw $v0,12($sp)
label0:
lw $t0,8($sp)
lw $t1,12($sp)
blt $t0,$t1,label1
j label2
label1:
lw $t0,0($sp)
lw $t1,4($sp)
add $t0, $t0, $t1
sw $t0, 20($sp)
lw $t0,4($sp)
move $a0, $t0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
lw $t0,4($sp)
sw $t0, 0($sp)
lw $t0,20($sp)
sw $t0, 4($sp)
lw $t0,8($sp)
li $t1,1
add $t0, $t0, $t1
sw $t0, 8($sp)
j label0
label2:
li $t0,0
move $v0,$t0
addi $sp, $sp, 28
jr $ra
