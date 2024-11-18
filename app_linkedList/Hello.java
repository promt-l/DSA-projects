MAIN: LXI SP, 2093H
CALL INPUT
CPI 0AH
JC DSPLAY
JZ ADD
CPI 0BH
JZ SUB
CPI 0CH
JZ STORE
CPI 0DH
JZ REKALL
CPI 0EH
JZ CLEAR
CPI 0FH
JZ END
JP MAIN

INPUT: 
IN 00H
CPI 00H 
JZ S7
CPI 01H 
JZ S8
CPI 02H 
JZ S9
CPI 03H 
JZ SA
CPI 10H 
JZ S4
CPI 11H 
JZ S5
CPI 12H 
JZ S6
CPI 13H 
JZ SB
CPI 20H 
JZ S1
CPI 21H 
JZ S2
CPI 22H 
JZ S3
CPI 23H 
JZ SC
CPI 30H 
JZ S0
CPI 31H 
JZ SF
CPI 32H 
JZ SE
CPI 33H 
JZ SD


S0: MVI A, 00H
RET
S1: MVI A, 01H
RET
S2: MVI A, 02H
RET
S3: MVI A, 03H
RET
S4: MVI A, 04H
RET
S5: MVI A, 05H
RET
S6: MVI A, 06H
RET
S7: MVI A, 07H
RET
S8: MVI A, 08H
RET
S9: MVI A, 09H
RET
SA: MVI A, 0AH
RET
SB: MVI A, 0BH
RET
SC: MVI A, 0CH
RET
SD: MVI A, 0DH
RET
SE: MVI A, 0EH
RET
SF: MVI A, 0FH
RET

DSPLAY: OUT 01H
JMP MAIN

ADD:
CALL INPUT
MOV B,A
CALL INPUT
ADD B
MOV C,A
STA 4093H
JMP MAIN

SUB:
CALL INPUT
MOV D,A
CALL INPUT
MOV B,A
MOV A,D
SUB B
MOV C,A
STA 4093H
JMP MAIN

STORE:
LXI SP, 2093H
CALL INPUT
STA 5093H
JMP MAIN

REKALL: LDA 4093H
OUT 01H
JMP MAIN

CLEAR: MVI A, 00H
OUT 01H
JMP MAIN


END: HLT
 